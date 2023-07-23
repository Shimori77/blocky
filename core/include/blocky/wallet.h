#pragma once

#include <stdint.h>

typedef struct blocky_wallet_s {
    uint8_t _public_key[32];
    uint8_t _secret_key[64];

    uint8_t (*save_disk)(struct blocky_wallet_s *self, const char *public_key_path, const char *secret_key_path);
} blocky_wallet_t;

/**
 * Create a new blocky wallet.
 * @return Newly created blocky wallet.
 */
blocky_wallet_t *blocky_wallet_create();

/**
 * Loads a blocky wallet from disk.
 * @return Loaded blocky wallet.
 */
blocky_wallet_t *blocky_wallet_load_disk(const char *public_key_path, const char *secret_key_path);