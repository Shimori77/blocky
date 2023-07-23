#include <stdio.h>

#include <rpmalloc.h>
#include <blocky/wallet.h>

char *to_hex_str(const void *data, size_t data_length);

int main() {
    rpmalloc_initialize();

    blocky_wallet_t *wallet = blocky_wallet_create();
    wallet->save_disk(wallet, "wallet.pub", "wallet.sec");

    char *public_key_hex_str = to_hex_str(wallet->_public_key, 32);
    char *secret_key_hex_str = to_hex_str(wallet->_secret_key, 64);

    printf("Public Key: 0x%s\n", public_key_hex_str);
    printf("Secret Key: 0x%s\n", secret_key_hex_str);

    rpmalloc_finalize();
    return 0;
}

char *to_hex_str(const void *data, size_t data_length) {
    const uint8_t *data_ptr = (const uint8_t *) data;

    size_t str_len = data_length * 2 + 1;
    char *hex_str = rpmalloc(str_len);

    for (size_t i = 0, j = str_len - 3; i < data_length; i++, j -= 2) {
        uint8_t nibble_h = (data_ptr[i] & 0xF0) >> 4;
        uint8_t nibble_l = (data_ptr[i] & 0x0F);

        if (nibble_h >= 0x0A) {
            hex_str[j] = (char) ('A' + (nibble_h - 0x0A));
        } else {
            hex_str[j] = (char) ('0' + nibble_h);
        }

        if (nibble_l >= 0x0A) {
            hex_str[j + 1] = (char) ('A' + (nibble_l - 0x0A));
        } else {
            hex_str[j + 1] = (char) ('0' + nibble_l);
        }
    }

    hex_str[str_len - 1] = '\0';
    return hex_str;
}