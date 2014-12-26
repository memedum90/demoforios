//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef DSAPPERRORCODES_H_
#define DSAPPERRORCODES_H_

/**
 * Error codes which can be returned by the DSAPP library in case of error.
 */

/** Internal error */
const int DSAPPErrorCodes_INTERNAL_ERROR = -4501;

/** Activation password too long. Limited to {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH} characters. */
const int DSAPPErrorCodes_ACTIVATION_PASSWORD_TOO_LONG = -4502;

/** CHS key null or empty. Must be a {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_CHS_KEY_NULL_OR_EMPTY = -4503;

/** Incorrect CHS key length. Must be a {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string.*/
const int DSAPPErrorCodes_CHS_KEY_INCORRECT_LENGTH = -4504;

/** Incorrect CHS key format. Must be a {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string.*/
const int DSAPPErrorCodes_CHS_KEY_INCORRECT_FORMAT = -4505;

/** Client private key null or empty. Must be a {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_CLIENT_PRIVATE_KEY_NULL_OR_EMPTY = -4506;

/** Incorrect Client private key length. Must be a {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string.*/
const int DSAPPErrorCodes_CLIENT_PRIVATE_KEY_INCORRECT_LENGTH = -4507;

/** Incorrect Client private key format. Must be a {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string.*/
const int DSAPPErrorCodes_CLIENT_PRIVATE_KEY_INCORRECT_FORMAT = -4508;

/** Encrypted server public key null or empty. Must be a {@link DSAPPConstants_PUBLIC_KEY_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_NULL_OR_EMPTY = -4509;

/** Incorrect Encrypted server public key length. Must be a {@link DSAPPConstants_PUBLIC_KEY_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_INCORRECT_LENGTH = -4510;

/** Incorrect Encrypted server public key format. Must be a {@link DSAPPConstants_PUBLIC_KEY_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_INCORRECT_FORMAT = -4511;

/** Encrypted nonces null or empty. Must be a {@link DSAPPConstants_ENCRYPTED_NONCES_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_NONCES_NULL_OR_EMPTY = -4512;

/** Incorrect Encrypted nonces length. Must be a {@link DSAPPConstants_ENCRYPTED_NONCES_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_NONCES_INCORRECT_LENGTH = -4513;

/** Incorrect Encrypted nonces format. Must be a {@link DSAPPConstants_ENCRYPTED_NONCES_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_ENCRYPTED_NONCES_INCORRECT_FORMAT = -4514;

/** Client nonce null or empty. Must be a {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_CLIENT_NONCE_NULL_OR_EMPTY = -4515;

/** Incorrect Client nonce length. Must be a {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_CLIENT_NONCE_INCORRECT_LENGTH = -4516;

/** Incorrect Client nonce format. Must be a {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_CLIENT_NONCE_INCORRECT_FORMAT = -4517;

/** XFAD null or empty. Must be an hexadecimal string. */
const int DSAPPErrorCodes_XFAD_NULL_OR_EMPTY = -4518;

/** Incorrect XFAD format. Must be an hexadecimal string. */
const int DSAPPErrorCodes_XFAD_INCORRECT_FORMAT = -4519;

/** Incorrect XERC format. Must be an hexadecimal string. */
const int DSAPPErrorCodes_XERC_INCORRECT_FORMAT = -4520;

/** Server initial vector null or empty. Must be a {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_SERVER_INITIAL_VECTOR_NULL_OR_EMPTY = -4521;

/** Incorrect Server initial vector length. Must be a {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_SERVER_INITIAL_VECTOR_INCORRECT_LENGTH = -4522;

/** Incorrect Server initial vector format. Must be a {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. */
const int DSAPPErrorCodes_SERVER_INITIAL_VECTOR_INCORRECT_FORMAT = -4523;

/** Error while checking the nonce: the decrypted nonce is not equal to the nonce which is provided in parameter. */
const int DSAPPErrorCodes_CHECK_NONCE_ERROR = -4524;

/** Shared data length null or empty */
const int DSAPPErrorCodes_SHARED_DATA_NULL_OR_EMPTY = -4525;

/** Shared data length too long. Min length is {@link DSAPPConstants_SHARED_DATA_MIN_LENGTH}. */
const int DSAPPErrorCodes_SHARED_DATA_LENGTH_TOO_SHORT = -4526;

/** Shared data length too long. Max length is {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH}.*/
const int DSAPPErrorCodes_SHARED_DATA_LENGTH_TOO_LONG = -4527;

/** The checksum cannot be validated. */
const int DSAPPErrorCodes_CHECKSUM_VALIDATION_FAILED = -4528;

#endif
