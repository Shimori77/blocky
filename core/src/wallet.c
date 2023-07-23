#include <blocky/wallet.h>

#include <rpmalloc.h>
#include <ed25519.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

uint8_t save_disk(struct blocky_wallet_s *self, const char *public_key_path, const char *secret_key_path);
int8_t save_wallet_data_to_disk(const void *data, size_t data_length, const char *file_path);

blocky_wallet_t *blocky_wallet_create() {
    blocky_wallet_t *wallet = rpmalloc(sizeof (blocky_wallet_t));

    uint8_t seed[32];

    ed25519_create_seed(seed);
    ed25519_create_keypair(wallet->_public_key, wallet->_secret_key, seed);

    wallet->save_disk = save_disk;
    return wallet;
}

blocky_wallet_t *blocky_wallet_load_disk(const char *public_key_path, const char *secret_key_path) {
    return NULL;
}

uint8_t save_disk(struct blocky_wallet_s *self, const char *public_key_path, const char *secret_key_path) {
    int8_t status = save_wallet_data_to_disk(self->_public_key, 32, public_key_path);
    if (status != 0) return status;

    status = save_wallet_data_to_disk(self->_secret_key, 64, secret_key_path);

    return status != 0 ? status : 0;
}

int8_t save_wallet_data_to_disk(const void *data, size_t data_length, const char *file_path) {
    FILE *file = fopen(file_path, "wb");
    if (file == NULL) {
        perror("[BLK]::[WALLET]::(save_disk)");
        printf("\tOn file: %s.\n", file_path);
        return 1;
    }

    int8_t status = (int8_t) fwrite(data, data_length, 1, file);
    if (status != 1) {
        perror("[BLK]::[WALLET]::(save_disk)");
        return 1;
    }

    status = (int8_t) fclose(file);
    if (status == EOF) {
        perror("[BLK]::[WALLET]::(save_disk)");
        return 1;
    }

    return 0;
}