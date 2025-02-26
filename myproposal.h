/* $OpenBSD: myproposal.h,v 1.71 2022/03/30 21:13:23 djm Exp $ */

/*
 * Copyright (c) 2000 Markus Friedl.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// OQS-TODO: can we #ifdef the PQ defs in the following #define's
// OQS-TODO: should I add the PQ auth methods here? they were not added in 7.9 branch...

#define KEX_SERVER_KEX	\
	"curve25519-sha256," \
	"curve25519-sha256@libssh.org," \
	"ecdh-sha2-nistp256," \
	"ecdh-sha2-nistp384," \
	"ecdh-sha2-nistp521," \
	"diffie-hellman-group-exchange-sha256," \
	"diffie-hellman-group16-sha512," \
	"diffie-hellman-group18-sha512," \
	"diffie-hellman-group14-sha256," \
/*/// OQS_TEMPLATE_FRAGMENT_ADD_SERVER_KEXS_START */ \
	"frodokem-640-aes-sha256," \
	"ecdh-nistp256-frodokem-640-aesr2-sha256@openquantumsafe.org," \
	"x25519-frodokem-640-aesr2-sha256@openquantumsafe.org," \
	"frodokem-976-aes-sha384," \
	"ecdh-nistp384-frodokem-976-aesr2-sha384@openquantumsafe.org," \
	"frodokem-1344-aes-sha512," \
	"ecdh-nistp521-frodokem-1344-aesr2-sha512@openquantumsafe.org," \
	"frodokem-640-shake-sha256," \
	"ecdh-nistp256-frodokem-640-shaker2-sha256@openquantumsafe.org," \
	"x25519-frodokem-640-shaker2-sha256@openquantumsafe.org," \
	"frodokem-976-shake-sha384," \
	"ecdh-nistp384-frodokem-976-shaker2-sha384@openquantumsafe.org," \
	"frodokem-1344-shake-sha512," \
	"ecdh-nistp521-frodokem-1344-shaker2-sha512@openquantumsafe.org," \
	"kyber-512-sha256," \
	"ecdh-nistp256-kyber-512r3-sha256-d00@openquantumsafe.org," \
	"x25519-kyber-512r3-sha256-d00@amazon.com," \
	"kyber-768-sha384," \
	"ecdh-nistp384-kyber-768r3-sha384-d00@openquantumsafe.org," \
	"kyber-1024-sha512," \
	"ecdh-nistp521-kyber-1024r3-sha512-d00@openquantumsafe.org," \
	"bike-l1-sha512," \
	"ecdh-nistp256-bike-l1r4-sha512@openquantumsafe.org," \
	"x25519-bike-l1r4-sha512@openquantumsafe.org," \
	"bike-l3-sha512," \
	"ecdh-nistp384-bike-l3r4-sha512@openquantumsafe.org," \
	"bike-l5-sha512," \
	"ecdh-nistp521-bike-l5r4-sha512@openquantumsafe.org," \
	"classic-mceliece-348864-sha256," \
	"ecdh-nistp256-classic-mceliece-348864r4-sha256@openquantumsafe.org," \
	"x25519-classic-mceliece-348864r4-sha256@openquantumsafe.org," \
	"classic-mceliece-348864f-sha256," \
	"ecdh-nistp256-classic-mceliece-348864fr4-sha256@openquantumsafe.org," \
	"x25519-classic-mceliece-348864fr4-sha256@openquantumsafe.org," \
	"classic-mceliece-460896-sha512," \
	"ecdh-nistp384-classic-mceliece-460896r4-sha512@openquantumsafe.org," \
	"classic-mceliece-460896f-sha512," \
	"ecdh-nistp384-classic-mceliece-460896fr4-sha512@openquantumsafe.org," \
	"classic-mceliece-6688128-sha512," \
	"ecdh-nistp521-classic-mceliece-6688128r4-sha512@openquantumsafe.org," \
	"classic-mceliece-6688128f-sha512," \
	"ecdh-nistp521-classic-mceliece-6688128fr4-sha512@openquantumsafe.org," \
	"classic-mceliece-6960119-sha512," \
	"ecdh-nistp521-classic-mceliece-6960119r4-sha512@openquantumsafe.org," \
	"classic-mceliece-6960119f-sha512," \
	"ecdh-nistp521-classic-mceliece-6960119fr4-sha512@openquantumsafe.org," \
	"classic-mceliece-8192128-sha512," \
	"ecdh-nistp521-classic-mceliece-8192128r4-sha512@openquantumsafe.org," \
	"classic-mceliece-8192128f-sha512," \
	"ecdh-nistp521-classic-mceliece-8192128fr4-sha512@openquantumsafe.org," \
	"hqc-128-sha256," \
	"ecdh-nistp256-hqc-128r3-sha256@openquantumsafe.org," \
	"x25519-hqc-128r3-sha256@openquantumsafe.org," \
	"hqc-192-sha384," \
	"ecdh-nistp384-hqc-192r3-sha384@openquantumsafe.org," \
	"hqc-256-sha512," \
	"ecdh-nistp521-hqc-256r3-sha512@openquantumsafe.org," \
	"ml-kem-512-sha256," \
	"ecdh-nistp256-ml-kem-512-sha256@openquantumsafe.org," \
	"x25519-ml-kem-512-sha256@openquantumsafe.org," \
	"ml-kem-768-sha256," \
	"mlkem768nistp256-sha256," \
	"mlkem768x25519-sha256," \
	"ml-kem-1024-sha384," \
	"mlkem1024nistp384-sha384," \
	"sntrup761-sha512," \
	"sntrup761x25519-sha512@openssh.com"
/*/// OQS_TEMPLATE_FRAGMENT_ADD_SERVER_KEXS_END */

#define KEX_CLIENT_KEX KEX_SERVER_KEX

#define	KEX_DEFAULT_PK_ALG	\
	"ssh-ed25519-cert-v01@openssh.com," \
	"ecdsa-sha2-nistp256-cert-v01@openssh.com," \
	"ecdsa-sha2-nistp384-cert-v01@openssh.com," \
	"ecdsa-sha2-nistp521-cert-v01@openssh.com," \
	"sk-ssh-ed25519-cert-v01@openssh.com," \
	"sk-ecdsa-sha2-nistp256-cert-v01@openssh.com," \
	"rsa-sha2-512-cert-v01@openssh.com," \
	"rsa-sha2-256-cert-v01@openssh.com," \
	"ssh-ed25519," \
	"ecdsa-sha2-nistp256," \
	"ecdsa-sha2-nistp384," \
	"ecdsa-sha2-nistp521," \
	"sk-ssh-ed25519@openssh.com," \
	"sk-ecdsa-sha2-nistp256@openssh.com," \
	"rsa-sha2-512," \
	"rsa-sha2-256"

#define	KEX_SERVER_ENCRYPT \
	"chacha20-poly1305@openssh.com," \
	"aes128-ctr,aes192-ctr,aes256-ctr," \
	"aes128-gcm@openssh.com,aes256-gcm@openssh.com"

#define KEX_CLIENT_ENCRYPT KEX_SERVER_ENCRYPT

#define	KEX_SERVER_MAC \
	"umac-64-etm@openssh.com," \
	"umac-128-etm@openssh.com," \
	"hmac-sha2-256-etm@openssh.com," \
	"hmac-sha2-512-etm@openssh.com," \
	"hmac-sha1-etm@openssh.com," \
	"umac-64@openssh.com," \
	"umac-128@openssh.com," \
	"hmac-sha2-256," \
	"hmac-sha2-512," \
	"hmac-sha1"

#define KEX_CLIENT_MAC KEX_SERVER_MAC

/* Not a KEX value, but here so all the algorithm defaults are together */
#define	SSH_ALLOWED_CA_SIGALGS	\
	"ssh-ed25519," \
	"ecdsa-sha2-nistp256," \
	"ecdsa-sha2-nistp384," \
	"ecdsa-sha2-nistp521," \
	"sk-ssh-ed25519@openssh.com," \
	"sk-ecdsa-sha2-nistp256@openssh.com," \
	"rsa-sha2-512," \
	"rsa-sha2-256"

#define	KEX_DEFAULT_COMP	"none,zlib@openssh.com"
#define	KEX_DEFAULT_LANG	""

#define KEX_CLIENT \
	KEX_CLIENT_KEX, \
	KEX_DEFAULT_PK_ALG, \
	KEX_CLIENT_ENCRYPT, \
	KEX_CLIENT_ENCRYPT, \
	KEX_CLIENT_MAC, \
	KEX_CLIENT_MAC, \
	KEX_DEFAULT_COMP, \
	KEX_DEFAULT_COMP, \
	KEX_DEFAULT_LANG, \
	KEX_DEFAULT_LANG

#define KEX_SERVER \
	KEX_SERVER_KEX, \
	KEX_DEFAULT_PK_ALG, \
	KEX_SERVER_ENCRYPT, \
	KEX_SERVER_ENCRYPT, \
	KEX_SERVER_MAC, \
	KEX_SERVER_MAC, \
	KEX_DEFAULT_COMP, \
	KEX_DEFAULT_COMP, \
	KEX_DEFAULT_LANG, \
	KEX_DEFAULT_LANG
