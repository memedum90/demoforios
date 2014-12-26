//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef DSAPPCONSTANTS_H_
#define DSAPPCONSTANTS_H_

/**
 * Constants used by the DSAPP library.
 */

/** Length of the serialized public key */
const int DSAPPConstants_PUBLIC_KEY_LENGTH = 128;

/** Length of the serialized private key */
const int DSAPPConstants_PRIVATE_KEY_LENGTH = 64;

/** Length of the nonce */
const int DSAPPConstants_NONCE_LENGTH = 8;

/** Length of the initial vector */
const int DSAPPConstants_INITIAL_VECTOR_LENGTH = 32;

/** Length of the CHS key */
const int DSAPPConstants_CHS_KEY_LENGTH = 32;

/** Length of the encrypted client + server nonces */
const int DSAPPConstants_ENCRYPTED_NONCES_LENGTH = 32;

/** Shared data min length */
const int DSAPPConstants_SHARED_DATA_MIN_LENGTH = 4;

/** Shared data max length */
const int DSAPPConstants_SHARED_DATA_MAX_LENGTH = 512;

#endif
