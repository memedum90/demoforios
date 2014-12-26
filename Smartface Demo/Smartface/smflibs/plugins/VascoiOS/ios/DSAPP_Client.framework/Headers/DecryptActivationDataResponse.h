//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef DECRYPTACTIVATIONDATARESPONSE_H_
#define DECRYPTACTIVATIONDATARESPONSE_H_

#include <string>
using namespace std;

/**
 * Response class used during the decryption of the activation data.
 */
class DecryptActivationDataResponse
{

public:

	DecryptActivationDataResponse();

	/** DIGIPASS activation data */
	string fad;

	/** Event reactivation counter */
	string erc;

	/** Encrypted server nonce */
	string encryptedServerNonce;

	/** Client initial vector */
	string clientInitialVector;

};

#endif
