//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef INITIALIZEREGISTRATIONDATA_H_
#define INITIALIZEREGISTRATIONDATA_H_

#include <string>
using namespace std;

/**
 * Response class used during the initialization of the registration data.
 */
class InitializeRegistrationDataResponse
{

public:

	InitializeRegistrationDataResponse();

	/** CHS key */
	string chsKey;

	/** Encrypted concatenation of the client public key and the client nonce */
	string encryptedClientPublicKeyAndNonce;

	/** Client private key */
	string clientPrivateKey;

	/** Client initial vector */
	string clientInitialVector;

	/** Client nonce */
	string clientNonce;

};

#endif
