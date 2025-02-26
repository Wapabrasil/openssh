/* $OpenBSD: sk-api.h,v 1.15 2022/07/20 03:29:14 djm Exp $ */
/*
 * Copyright (c) 2019 Google LLC
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _SK_API_H
#define _SK_API_H 1

#include <stddef.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

/* Flags */
#define SSH_SK_USER_PRESENCE_REQD	0x01
#define SSH_SK_USER_VERIFICATION_REQD	0x04
#define SSH_SK_FORCE_OPERATION		0x10
#define SSH_SK_RESIDENT_KEY		0x20

/* Algs */
#define SSH_SK_ECDSA			0x00
#define SSH_SK_ED25519			0x01
///// OQS_TEMPLATE_FRAGMENT_DEFINE_SSH_SKS_START
#define SSH_SK_FALCON_512 0x02
#define SSH_SK_RSA3072_FALCON_512 0x03
#define SSH_SK_ECDSA_NISTP256_FALCON_512 0x04
#define SSH_SK_FALCON_1024 0x05
#define SSH_SK_ECDSA_NISTP521_FALCON_1024 0x06
#define SSH_SK_SPHINCS_SHA2_128F_SIMPLE 0x07
#define SSH_SK_RSA3072_SPHINCS_SHA2_128F_SIMPLE 0x08
#define SSH_SK_ECDSA_NISTP256_SPHINCS_SHA2_128F_SIMPLE 0x09
#define SSH_SK_SPHINCS_SHA2_256F_SIMPLE 0x0A
#define SSH_SK_ECDSA_NISTP521_SPHINCS_SHA2_256F_SIMPLE 0x0B
#define SSH_SK_ML_DSA_44 0x0C
#define SSH_SK_RSA3072_ML_DSA_44 0x0D
#define SSH_SK_ECDSA_NISTP256_ML_DSA_44 0x0E
#define SSH_SK_ML_DSA_65 0x0F
#define SSH_SK_ECDSA_NISTP384_ML_DSA_65 0x10
#define SSH_SK_ML_DSA_87 0x11
#define SSH_SK_ECDSA_NISTP521_ML_DSA_87 0x12
#define SSH_SK_MAYO_2 0x13
#define SSH_SK_RSA3072_MAYO_2 0x14
#define SSH_SK_ECDSA_NISTP256_MAYO_2 0x15
#define SSH_SK_MAYO_3 0x16
#define SSH_SK_ECDSA_NISTP384_MAYO_3 0x17
#define SSH_SK_MAYO_5 0x18
#define SSH_SK_ECDSA_NISTP521_MAYO_5 0x19
///// OQS_TEMPLATE_FRAGMENT_DEFINE_SSH_SKS_END

/* Error codes */
#define SSH_SK_ERR_GENERAL		-1
#define SSH_SK_ERR_UNSUPPORTED		-2
#define SSH_SK_ERR_PIN_REQUIRED		-3
#define SSH_SK_ERR_DEVICE_NOT_FOUND	-4
#define SSH_SK_ERR_CREDENTIAL_EXISTS	-5

struct sk_enroll_response {
	uint8_t flags;
	uint8_t *public_key;
	size_t public_key_len;
	uint8_t *key_handle;
	size_t key_handle_len;
	uint8_t *signature;
	size_t signature_len;
	uint8_t *attestation_cert;
	size_t attestation_cert_len;
	uint8_t *authdata;
	size_t authdata_len;
};

struct sk_sign_response {
	uint8_t flags;
	uint32_t counter;
	uint8_t *sig_r;
	size_t sig_r_len;
	uint8_t *sig_s;
	size_t sig_s_len;
};

struct sk_resident_key {
	uint32_t alg;
	size_t slot;
	char *application;
	struct sk_enroll_response key;
	uint8_t flags;
	uint8_t *user_id;
	size_t user_id_len;
};

struct sk_option {
	char *name;
	char *value;
	uint8_t required;
};

#define SSH_SK_VERSION_MAJOR		0x000a0000 /* current API version */
#define SSH_SK_VERSION_MAJOR_MASK	0xffff0000

/* Return the version of the middleware API */
uint32_t sk_api_version(void);

/* Enroll a U2F key (private key generation) */
int sk_enroll(uint32_t alg, const uint8_t *challenge, size_t challenge_len,
    const char *application, uint8_t flags, const char *pin,
    struct sk_option **options, struct sk_enroll_response **enroll_response);

/* Sign a challenge */
int sk_sign(uint32_t alg, const uint8_t *data, size_t data_len,
    const char *application, const uint8_t *key_handle, size_t key_handle_len,
    uint8_t flags, const char *pin, struct sk_option **options,
    struct sk_sign_response **sign_response);

/* Enumerate all resident keys */
int sk_load_resident_keys(const char *pin, struct sk_option **options,
    struct sk_resident_key ***rks, size_t *nrks);

#endif /* _SK_API_H */
