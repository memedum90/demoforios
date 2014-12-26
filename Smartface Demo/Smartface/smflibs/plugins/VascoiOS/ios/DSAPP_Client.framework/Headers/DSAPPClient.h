//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef DSAPPCLIENT_H_
#define DSAPPCLIENT_H_

#include <string>
using namespace std;

#include "DSAPPException.h"
#include "DecryptActivationDataResponse.h"
#include "InitializeRegistrationDataResponse.h"

const string DSAPPClient_VERSION = "4.2.0";

/**
 * Provides the entry points of the DSAPP client library:
 * <ul>
 *  <li>Initialize the registration data.</li>
 *  <li>Decrypt the activation data.</li>
 *  <li>Validate the checksum of a shared data (activation password or authorization code).</li>
 * </ul>
 * <br/>The following sequence diagram describes the integration of the DSAPP:<br/><br/>
 * \image html DSAPP_sequence_diagram.png
 * <br/>
 * @version 4.2.0
 */
class DSAPPClient
{

public:

	/**
	 * The DIGIPASS activation data is protected by an asymmetric key encryption mechanism.<br/>
	 * Prior to get the DIGIPASS activation data, the client application must provide the data required to protect the activation data:
	 * <ul>
	 *  <li>The client public key and nonce.</li>
	 *  <li>The initial vector diversifying the encryption.</li>
	 * </ul>
	 *
     * CAUTION: This method must be used to initialize the registration data for DSAPP SDK 4.1+ and DIGIPASS for Mobile 4.1+<br/>
     * For DSAPP SDK 4.0 and DIGIPASS for Mobile 4.0, use {@link DSAPPClient_initializeRegistrationDataV1}
	 *
	 * @param activationPassword Activation password. Alphanumeric string limited to {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH} characters.
	 * @param response A response object that contains:
	 * <ul>
	 *  <li>The encrypted concatenation of the client public key and the client nonce. ({@link DSAPPConstants_PUBLIC_KEY_LENGTH} + {@link DSAPPConstants_NONCE_LENGTH}) hexadecimal characters. Must be sent to the server.</li>
	 *  <li>The initial vector used for public key encryption. {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. Must be sent to the server.</li>
	 *  <li>The key derived from the activation password. {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client private key used for session key calculation. {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client nonce that will be verified against the one received from the server. {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 * </ul>
	 * @throws DSAPPException Exception raised if there is an error during the process. The following codes can be returned:
	 * <ul>
	 *  <li>{@link DSAPPErrorCodes_ACTIVATION_PASSWORD_TOO_LONG}</li>
	 *  <li>{@link DSAPPErrorCodes_INTERNAL_ERROR}</li>
	 * </ul>
	 */
	static void initializeRegistrationDataV2(string activationPassword, InitializeRegistrationDataResponse& response)
			throw (DSAPPException);

	 /**
	 * The DIGIPASS activation data is protected by an asymmetric key encryption mechanism.<br/>
	 * Prior to get the DIGIPASS activation data, the client application must provide the data required to protect the activation data:
	 * <ul>
	 *  <li>The client public key and nonce.</li>
	 *  <li>The initial vector diversifying the encryption.</li>
	 * </ul>
	 *
     * @deprecated Use {@link DSAPPClient_initializeRegistrationDataV2}
	 *
	 * @param activationPassword Activation password. Alphanumeric string limited to {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH} characters.
	 * @param response A response object that contains:
	 * <ul>
	 *  <li>The encrypted concatenation of the client public key and the client nonce. ({@link DSAPPConstants_PUBLIC_KEY_LENGTH} + {@link DSAPPConstants_NONCE_LENGTH}) hexadecimal characters. Must be sent to the server.</li>
	 *  <li>The initial vector used for public key encryption. {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. Must be sent to the server.</li>
	 *  <li>The key derived from the activation password. {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client private key used for session key calculation. {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client nonce that will be verified against the one received from the server. {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 * </ul>
	 * @throws DSAPPException Exception raised if there is an error during the process. The following codes can be returned:
	 * <ul>
	 *  <li>{@link DSAPPErrorCodes_ACTIVATION_PASSWORD_TOO_LONG}</li>
	 *  <li>{@link DSAPPErrorCodes_INTERNAL_ERROR}</li>
	 * </ul>
	 */
	static void initializeRegistrationData(string activationPassword, InitializeRegistrationDataResponse& response)
			throw (DSAPPException);

	 /**
	 * The DIGIPASS activation data is protected by an asymmetric key encryption mechanism.<br/>
	 * Prior to get the DIGIPASS activation data, the client application must provide the data required to protect the activation data:
	 * <ul>
	 *  <li>The client public key and nonce.</li>
	 *  <li>The initial vector diversifying the encryption.</li>
	 * </ul>
	 *
	 * @deprecated CAUTION: This method must be used to initialize the registration data for DSAPP SDK 4.0 and DIGIPASS for Mobile 4.0<br/>
     * From DSAPP SDK 4.1 and DIGIPASS for Mobile 4.1, use {@link DSAPPClient_initializeRegistrationDataV2}
	 *
	 * @param activationPassword Activation password. Alphanumeric string limited to {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH} characters.
	 * @param response A response object that contains:
	 * <ul>
	 *  <li>The encrypted concatenation of the client public key and the client nonce. ({@link DSAPPConstants_PUBLIC_KEY_LENGTH} + {@link DSAPPConstants_NONCE_LENGTH}) hexadecimal characters. Must be sent to the server.</li>
	 *  <li>The initial vector used for public key encryption. {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. Must be sent to the server.</li>
	 *  <li>The key derived from the activation password. {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client private key used for session key calculation. {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 *  <li>The client nonce that will be verified against the one received from the server. {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string. Must be stored on the client side and used for the activation data decryption.</li>
	 * </ul>
	 * @throws DSAPPException Exception raised if there is an error during the process. The following codes can be returned:
	 * <ul>
	 *  <li>{@link DSAPPErrorCodes_ACTIVATION_PASSWORD_TOO_LONG}</li>
	 *  <li>{@link DSAPPErrorCodes_INTERNAL_ERROR}</li>
	 * </ul>
	 */
	static void initializeRegistrationDataV1(string activationPassword, InitializeRegistrationDataResponse& response)
			throw (DSAPPException);

	/**
	 * On client side, the activation data are received encrypted with the session key.<br/>
	 * It must be decrypted to be provided to the DIGIPASS SDK for the DIGIPASS instance activation.<br/>
	 * The DSAPP library will verify the integrity of the decrypted data.
	 * @param chsKey Key derived from activation password. Must be a {@link DSAPPConstants_CHS_KEY_LENGTH} hexadecimal string.
	 * @param clientPrivateKey Client private key used for session key calculation. Must be a {@link DSAPPConstants_PRIVATE_KEY_LENGTH} hexadecimal string.
	 * @param encryptedServerPublicKey Server public key encrypted with chsKey. Must be a {@link DSAPPConstants_PUBLIC_KEY_LENGTH} hexadecimal string.
	 * @param encryptedNonces Concatenation of the serve and client nonces encrypted with the chsKey. Must be a {@link DSAPPConstants_ENCRYPTED_NONCES_LENGTH} hexadecimal string.
	 * @param xfad DIGIPASS activation data encrypted with session key. Must be an hexadecimal string.
	 * @param xerc Event reactivation counter encrypted with session key. Must be an hexadecimal string.
	 * @param clientNonce Client nonce. Must be a {@link DSAPPConstants_NONCE_LENGTH} hexadecimal string.
	 * @param serverInitialVector Server initial vector used for data decryption. Must be a {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string.
	 * @param response A response object that contains:
	 * <ul>
	 *  <li>The DIGIPASS activation data. Must be used to activate the DIGIPASS.</li>
	 *  <li>The Event reactivation counter. Must be used to activate the DIGIPASS.</li>
	 *  <li>The server nonce encrypted with session key. {@link DSAPPConstants_ENCRYPTED_NONCES_LENGTH} hexadecimal string. Must be sent to the server for the server nonce validation.</li>
	 *  <li>The client initial vector used for decryption on server side. {@link DSAPPConstants_INITIAL_VECTOR_LENGTH} hexadecimal string. Must be sent to the server for the server nonce validation.</li>
	 * </ul>
	 * @throws DSAPPException Exception raised if there is an error during the process. The following codes can be returned:
	 * <ul>
	 *  <li>{@link DSAPPErrorCodes_CHS_KEY_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_CHS_KEY_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_CHS_KEY_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_PRIVATE_KEY_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_PRIVATE_KEY_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_PRIVATE_KEY_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_SERVER_PUBLIC_KEY_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_NONCES_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_NONCES_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_ENCRYPTED_NONCES_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_NONCE_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_NONCE_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_CLIENT_NONCE_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_XFAD_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_XFAD_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_XERC_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_SERVER_INITIAL_VECTOR_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_SERVER_INITIAL_VECTOR_INCORRECT_LENGTH}</li>
	 *  <li>{@link DSAPPErrorCodes_SERVER_INITIAL_VECTOR_INCORRECT_FORMAT}</li>
	 *  <li>{@link DSAPPErrorCodes_CHECK_NONCE_ERROR}</li>
	 *  <li>{@link DSAPPErrorCodes_INTERNAL_ERROR}</li>
	 * </ul>
	 **/
	static void decryptActivationData(string chsKey, string clientPrivateKey, string encryptedServerPublicKey,
			string encryptedNonces, string xfad, string xerc, string clientNonce, string serverInitialVector,
			DecryptActivationDataResponse& response) throw (DSAPPException);

	/**
	 * Validates the checksum of a shared data (activation password or authorization code).
	 * @param sharedData Shared data. Alphanumeric string, from {@link DSAPPConstants_SHARED_DATA_MIN_LENGTH} to {@link DSAPPConstants_SHARED_DATA_MAX_LENGTH} characters.
	 * @throws DSAPPException Exception raised if there is an error during the process. The following codes can be returned:
	 * <ul>
	 *  <li>{@link DSAPPErrorCodes_SHARED_DATA_NULL_OR_EMPTY}</li>
	 *  <li>{@link DSAPPErrorCodes_SHARED_DATA_LENGTH_TOO_SHORT}</li>
	 *  <li>{@link DSAPPErrorCodes_SHARED_DATA_LENGTH_TOO_LONG}</li>
	 *  <li>{@link DSAPPErrorCodes_CHECKSUM_VALIDATION_FAILED}</li>
	 *  <li>{@link DSAPPErrorCodes_INTERNAL_ERROR}</li>
	 * </ul>
	 */
	static void validateSharedDataChecksum(string sharedData) throw (DSAPPException);



private:

	static void initializeRegistrationData(string activationPassword, InitializeRegistrationDataResponse& response,
										   bool v2)
	throw (DSAPPException);

};

#endif

/*!
 * \mainpage DSAPP SDK - Programmer documentation
 * \brief This documentation describes the methods and the constants provided by the DSAPP client C++ library.<br/>
 * <br/>
 * They are exposed by the DSAPPClient class.<br/>
 * <br/>
 * Copyright 1999 - 2013. VASCO DATA SECURITY. All Rights Reserved.
 */
