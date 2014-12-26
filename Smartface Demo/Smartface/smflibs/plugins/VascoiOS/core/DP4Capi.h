/* Copyright(c) 2013 VASCO Data Security, Inc, VASCO Data Security        */
/* International GmbH. All rights reserved. VASCO(R), VACMAN(R),          */
/* IDENTIKEY(R), aXsGUARD(TM), DIGIPASS(R), and "VASCO 'V' logo"(R) are   */
/* registered or unregistered trademarks of VASCO Data Security, Inc.     */
/* and/or VASCO Data Security International GmbH. in the U.S. and other   */
/* countries.                                                             */

#ifndef DP4CAPI_H
#define DP4CAPI_H

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

/*!
 * \file DP4Capi.h
 * \brief The file exposes the methods and the constants provided by the DIGIPASS SDK.
 */


//--------------------------------------------------------------------------
//--- CONSTANTS ------------------------------------------------------------
//--------------------------------------------------------------------------

#define DIGIPASS_SDK_VERSION "4.2.0"                 //!< DIGIPASS SDK current version<br/><br/>

#define STATUS_NOT_ACTIVATED        0	             //!<  The DIGIPASS is not activated. An activation must be performed.
#define STATUS_ACTIVATED            1	             //!<  The DIGIPASS is activated. The DIGIPASS is ready to generate OTP or signature.
#define STATUS_LOCKED               2	             //!<  The DIGIPASS is locked. The DIGIPASS could not generate OTP or signature. DIGIPASS must be re-activated.
#define STATUS_GENERATE_INVALID_OTP 3	             //!<  The DIGIPASS generates invalid OTP or invalid signature.<br/><br/>

#define CRYPTO_APPLICATION_INDEX_APP_1 1             //!<  Index of the first crypto application
#define CRYPTO_APPLICATION_INDEX_APP_2 2             //!<  Index of the second crypto application
#define CRYPTO_APPLICATION_INDEX_APP_3 3             //!<  Index of the third crypto application
#define CRYPTO_APPLICATION_INDEX_APP_4 4             //!<  Index of the fourth crypto application
#define CRYPTO_APPLICATION_INDEX_APP_5 5             //!<  Index of the fifth crypto application
#define CRYPTO_APPLICATION_INDEX_APP_6 6             //!<  Index of the sixth crypto application
#define CRYPTO_APPLICATION_INDEX_APP_7 7             //!<  Index of the seventh crypto application
#define CRYPTO_APPLICATION_INDEX_APP_8 8             //!<  Index of the eighth crypto application<br/><br/>

#define LENGTH_STATIC_VECTOR_V7        56            //!< Static vector length when using a static vector version lower or equal to 7
#define LENGTH_STATIC_VECTOR_V8_MAX    845           //!< Static vector maximal length when using a static vector version higher or equal to 8
#define LENGTH_DYNAMIC_VECTOR_V7       56            //!< Dynamic vector length when using a static vector version lower or equal to 7
#define LENGTH_DYNAMIC_VECTOR_V8_MAX   232           //!< Dynamic vector maximal length when using a static vector version higher or equal to 8
#define LENGTH_DATA_FIELD_MAX          16            //!< Data field maximal length
#define LENGTH_DATA_FIELD_MAX_ENHANCED_SECURITY 32000 //!< Data field maximal length for enhanced security
#define LENGTH_RESPONSE_MAX            16            //!< Response maximal length
#define LENGTH_HOST_CODE_MAX           10            //!< Host code maximal length
#define LENGTH_ENCRYPTION_KEY          16            //!< Encryption key length
#define LENGTH_SERIAL_NUMBER           10            //!< Serial number length
#define LENGTH_CRYPTO_APPLICATION_NAME 12            //!< Crypto application name length
#define LENGTH_DERIVATION_CODE_MAX     26            //!< Derivation code maximal length
#define LENGTH_SHARED_SECRET_MAX       512           //!< Shared secret maximal length
#define LENGTH_SERVER_PUBLIC_KEY_MAX   1024          //!< Server public key maximal length
#define LENGTH_MASTER_KEY              16            //!< Master key length
#define LENGTH_CODEWORD                4             //!< Codeword length
#define LENGTH_AUTHENTICATION_MODE     2             //!< Authentication mode length<br/><br/>

#define NUMBER_DATA_FIELD_MAX        8	             //!<  Maximum number of data fields<br/><br/>

#define PROPERTY_VERSION 0                           //!< Property used to get the version number contained in the static vector
#define PROPERTY_STATUS 1                            //!< Property used to get the DIGIPASS status (see \ref STATUS_NOT_ACTIVATED, \ref STATUS_ACTIVATED ...)
#define PROPERTY_SERIAL_NUMBER 2                     //!< Property used to get the DIGIPASS serial number
#define PROPERTY_PASSWORD_ENABLED 3                  //!< \deprecated See \ref PROPERTY_PASSWORD_MANDATORY and \ref PROPERTY_PASSWORD_PROTECTED
#define PROPERTY_PASSWORD_MIN_LENGTH 4               //!< Property used to get the password minimal length
#define PROPERTY_PASSWORD_MAX_LENGTH 5               //!< Property used to get the password maximal length
#define PROPERTY_WEAK_PASSWORD_CONTROL 6             //!< Property used to know if the weak password control is enabled in the DIGIPASS settings
#define PROPERTY_PASSWORD_CHECK_LEVEL 7              //!< Property used to get the password check level
#define PROPERTY_PENALTY_RESET_ACTION 8              //!< Property used to know if a reset action must be applied when the penalty threshold is reached
#define PROPERTY_PASSWORD_FATAL 9                    //!< Property used to get the password fatal. This is a static value extracted from the static vector. It represents the password configured number of retries.
#define PROPERTY_PASSWORD_FATAL_COUNTER 10           //!< Property used to get the password fatal counter. This is a dynamic value extracted from the dynamic vector. It represents the password remaining number of retries.
#define PROPERTY_REACTIVATION_FATAL 11               //!< Property used to get the reactivation fatal. This is a static value extracted from the static vector. It represents the reactivation configured number of retries. The reactivation fatal functionality is available only if the version is lower or equals to 7 (\ref PROPERTY_VERSION).
#define PROPERTY_REACTIVATION_FATAL_COUNTER 12       //!< Property used to get the reactivation fatal counter. This is a dynamic value extracted from the dynamic vector. It represents the reactivation remaining number of retries. The reactivation fatal functionality is available only if the version is lower or equals to 7 (\ref PROPERTY_VERSION).
#define PROPERTY_TOKEN_DERIVATION_SUPPORTED 13       //!< Property used to know if the token derivation is supported
#define PROPERTY_HIGH_SECURITY 14                    //!< Property used to know if the DIGIPASS is in a high security mode
#define PROPERTY_DP_PLUS_HIGH_SECURITY 15            //!< Property used to know if the DP+ application is in a high security mode
#define PROPERTY_ACTIVATION_CODE_HEXA_FORMAT 16      //!< Property used to know if the activation code is in hexadecimal format. Also applied for the event reactivation counter.
#define PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE 17 //!< Property used to know if a checksum is included in the activation code
#define PROPERTY_CRYPTO_APP_NUMBER 18                //!< Property used to get the number of crypto application from the DIGIPASS settings
#define PROPERTY_APP_INDEX 19                        //!< Property used to get unique application index. See \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8.
#define PROPERTY_APP_NAME 20                         //!< Property used to get the name of a crypto application
#define PROPERTY_APP_ENABLED 21                      //!< Property used to know if a crypto application is enabled. The application needs to be enabled in order to generate OTP.
#define PROPERTY_APP_DP_PLUS 22                      //!< Property used to know if a crypto application is a DP+ application
#define PROPERTY_APP_RESPONSE_LENGTH 23              //!< Property used to get the length of the response (OTP) generated by the crypto application
#define PROPERTY_APP_HOST_CODE_LENGTH 24             //!< Property used to get the length of the host code generated by the crypto application. If the length is 0, no host code is returned during the OTP generation.
#define PROPERTY_APP_CHECK_DIGIT 25                  //!< Property used to know if a check digit is included in the generated response
#define PROPERTY_APP_DTF_NUMBER 26                   //!< Property used to get the number of data fields supported by the crypto application
#define PROPERTY_APP_DATA_FIELD_MIN_LENGTH 27        //!< Property used to get the data fields minimal length
#define PROPERTY_APP_DATA_FIELD_MAX_LENGTH 28        //!< Property used to get the data fields maximal length
#define PROPERTY_APP_EVENT_COUNTER 29                //!< Property used to get the crypto application counter. It represents the counter used by the application to generate the OTP if the application is event-based (\ref PROPERTY_APP_EVENT_BASED).
#define PROPERTY_APP_LAST_TIME_USED 30               //!< Property used to get the last time used for a crypto application in seconds. It is updated each time an OTP is generated.
#define PROPERTY_APP_TIME_BASED 31                   //!< Property used to know if the DIGIPASS is time based
#define PROPERTY_APP_EVENT_BASED 32                  //!< Property used to know if the DIGIPASS is event based
#define PROPERTY_UTC_TIME 33                         //!< Property used to get the current device UTC time in seconds
#define PROPERTY_PASSWORD_MANDATORY 34               //!< Property used to know if a password is mandatory to activate the DIGIPASS
#define PROPERTY_PASSWORD_PROTECTED 35               //!< Property used to know if the DIGIPASS is password protected. If true, a password is required to perform sensible action.
#define PROPERTY_MASTER_KEY 36                       //!< Property used to get the master key used during the activation process.
#define PROPERTY_ITERATION_NUMBER 37                 //!< Property used to get the iteration number used during the encryption key computation.
#define PROPERTY_USE_SECRET_DERIVATION 38            //!< Property used to know if the secret must be derived for each application.
#define PROPERTY_STORAGE_VERSION 39                  //!< Property used to get the storage version.
#define PROPERTY_APP_OUTPUT_TYPE 40                  //!< Property used to get the output type of the generated one-time password: 1 for hexadecimal, 2 for decimal.
#define PROPERTY_APP_CODEWORD 41                     //!< Property used to get the codeword used during the one-time password computation.
#define PROPERTY_APP_TIME_STEP 42                    //!< Property used to get the time step used during the one-time password computation.
#define PROPERTY_ITERATION_POWER 43                  //!< Property used to get the iteration power used during the encryption key computation.
#define PROPERTY_CREATION_VERSION 44                 //!< Property used to get the creation version for the storage.
#define PROPERTY_TOKEN_DERIVATION_ACTIVATED 45       //!< Property used to know if the token derivation feature is activated.
#define PROPERTY_PASSWORD_DERIVATION_ACTIVATED 46    //!< Property used to know if the password derivation feature is activated.
#define PROPERTY_APP_AUTHENTICATION_MODE 47    		 //!< Property used to get the authentication mode used during the one-time password computation.<br/><br/>

#define HASH_MD5     1                               //!< MD5 hash
#define HASH_SHA_1   2                               //!< SHA-1 hash
#define HASH_SHA_256 3                               //!< SHA-256 hash<br/><br/>

#define CIPHER_MECHANISM_DES  1                      //!< DES cipher mechanism
#define CIPHER_MECHANISM_DES3 2                      //!< Triple DES cipher mechanism
#define CIPHER_MECHANISM_AES  3                      //!< AES cipher mechanism<br/><br/>

#define CIPHER_MODE_ECB 1                            //!< ECB cipher mode
#define CIPHER_MODE_CBC 2                            //!< CBC cipher mode
#define CIPHER_MODE_CFB 3                            //!< CFB cipher mode<br/><br/>


//--------------------------------------------------------------------------
//--- RETURN CODES ---------------------------------------------------------
//--------------------------------------------------------------------------

#define RETURN_CODE_SUCCESS									0     //!< Operation successful
#define RETURN_CODE_STATIC_VECTOR_NULL						-4001 //!< The static vector is null
#define RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH			-4002 //!< The static vector length is incorrect 
#define RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT			-4003 //!< The static vector format is incorrect 
#define RETURN_CODE_DYNAMIC_VECTOR_NULL						-4004 //!< The dynamic vector is null
#define RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH			-4005 //!< The dynamic vector length is incorrect
#define RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT			-4006 //!< The dynamic vector format is incorrect
#define RETURN_CODE_ENCRYPTION_KEY_NULL						-4007 //!< The encryption key is null
#define RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH			-4008 //!< The encryption key length is incorrect 
#define RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL				-4009 //!< The serial number suffix is null
#define RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH	-4010 //!< The serial number suffix length is incorrect 
#define RETURN_CODE_ACTIVATION_CODE_NULL					-4011 //!< The activation code is null
#define RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH		-4012 //!< The activation code length is incorrect 
#define RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT		-4013 //!< The activation code format is incorrect 
#define RETURN_CODE_ERC_INCORRECT_LENGTH					-4014 //!< The event reactivation counter length is incorrect 
#define RETURN_CODE_ERC_INCORRECT_FORMAT					-4015 //!< The event reactivation counter format is incorrect 
#define RETURN_CODE_ERC_INVALID								-4016 //!< The event reactivation counter is invalid
#define RETURN_CODE_XFAD_NULL								-4017 //!< The XFAD is null
#define RETURN_CODE_XFAD_INCORRECT_LENGTH					-4018 //!< The XFAD length is incorrect 
#define RETURN_CODE_XFAD_INCORRECT_FORMAT					-4019 //!< The XFAD format is incorrect 
#define RETURN_CODE_XERC_INCORRECT_LENGTH					-4020 //!< The XERC length is incorrect 
#define RETURN_CODE_XERC_INCORRECT_FORMAT					-4021 //!< The XERC format is incorrect 
#define RETURN_CODE_SHARED_SECRET_TOO_LONG					-4022 //!< The cumulative size of the activation password and the nonce is too high (limit: 512 bytes)
#define RETURN_CODE_ACTIVATION_CODE_INVALID					-4023 //!< The activation code is invalid
#define RETURN_CODE_REACTIVATION_LOCK						-4024 //!< The application has been locked in a reactivation case
#define RETURN_CODE_PASSWORD_NULL							-4025 //!< The password is null
#define RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT				-4026 //!< The password is too short
#define RETURN_CODE_PASSWORD_LENGTH_TOO_LONG				-4027 //!< The password is too long
#define RETURN_CODE_PASSWORD_WEAK							-4028 //!< The password is weak
#define RETURN_CODE_PASSWORD_WRONG							-4029 //!< The password cannot be validated
#define RETURN_CODE_PASSWORD_LOCK							-4030 //!< The application is locked after too many tries with a wrong password
#define RETURN_CODE_STATUS_INVALID							-4031 //!< The DIGIPASS status is invalid (not activated or locked)
#define RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID		-4032 //!< The crypto application index is invalid
#define RETURN_CODE_APPLICATION_DISABLED					-4033 //!< The crypto application is disabled
#define RETURN_CODE_CHALLENGE_NULL							-4034 //!< The challenge is null
#define RETURN_CODE_CHALLENGE_INCORRECT_LENGTH				-4035 //!< The challenge length is incorrect 
#define RETURN_CODE_DATA_FIELDS_ARRAY_NULL					-4036 //!< The data fields array is null
#define RETURN_CODE_DATA_FIELDS_NUMBER_INVALID				-4037 //!< The number of data fields to sign is invalid
#define RETURN_CODE_DATA_FIELD_NULL							-4038 //!< One of the data fields to sign is null
#define RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH				-4039 //!< One of the data fields to sign length is incorrect 
#define RETURN_CODE_RESPONSE_NULL							-4040 //!< The response is null
#define RETURN_CODE_RESPONSE_INCORRECT_LENGTH				-4041 //!< The response length is incorrect 
#define RETURN_CODE_HOST_CODE_NULL							-4042 //!< The host code is null
#define RETURN_CODE_HOST_CODE_INCORRECT_LENGTH				-4043 //!< The host code length is incorrect 
#define RETURN_CODE_CHALLENGE_CHARACTER_INVALID				-4044 //!< One of the data fields to sign contains invalid characters
#define RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH		-4045 //!< The server public key length is incorrect 
#ifndef _DOC
#define RETURN_CODE_EBD_SECRET_KEY_NULL						-4046 //!< The secret key is null
#define RETURN_CODE_EBD_SECRET_KEY_INCORRECT_LENGTH			-4047 //!< The secret key length is incorrect 
#define RETURN_CODE_EBD_SESSION_ID_NULL						-4048 //!< The session identifier is null
#define RETURN_CODE_EBD_KEY_HANDLE_NULL						-4049 //!< The key handle is null
#define RETURN_CODE_EBD_ENCRYPT_FUNCTION_NULL				-4050 //!< The encrypt function array is null
#endif
#define RETURN_CODE_CRYPTO_MECANISM_INVALID					-4051 //!< The crypto mechanism is invalid
#define RETURN_CODE_CRYPTO_MODE_INVALID						-4052 //!< The crypto mode is invalid
#define RETURN_CODE_KEY_NULL								-4053 //!< The key is null
#define RETURN_CODE_KEY_INCORRECT_LENGTH					-4054 //!< The key length is incorrect 
#define RETURN_CODE_INPUT_DATA_NULL							-4055 //!< The input data is null
#define RETURN_CODE_INPUT_DATA_INCORRECT_LENGTH				-4056 //!< The input data length is incorrect 
#define RETURN_CODE_OUTPUT_DATA_NULL						-4057 //!< The output data is null
#define RETURN_CODE_OUTPUT_DATA_INCORRECT_LENGTH			-4058 //!< The output data length is incorrect 
#define RETURN_CODE_INITIAL_VECTOR_INCORRECT_LENGTH			-4059 //!< The initial vector length is incorrect 
#define RETURN_CODE_UNKNWON_PROPERTY						-4060 //!< The property is unknown
#define RETURN_CODE_DERIVATION_CODE_NULL					-4061 //!< The derivation code is null
#define RETURN_CODE_DERIVATION_CODE_INCORRECT_LENGTH		-4062 //!< The derivation code length is incorrect
#define RETURN_CODE_TOKEN_DERIVATION_NOT_SUPPORTED		    -4063 //!< The token derivation is not supported
#define RETURN_CODE_PLATFORM_FINGERPRINT_NOT_DEFINED    	-4064 //!< The platform fingerprint is not defined
#define RETURN_CODE_DATA_FIELDS_NOT_CONTIGUOUS    	        -4065 //!< The data fields are not contiguous
#define RETURN_CODE_NOT_PASSWORD_PROTECTED    	            -4066 //!< The DIGIPASS is not password protected<br/><br/>


//--------------------------------------------------------------------------
//--- TYPES ----------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef  VDSTYPES_H
#ifndef  _DOC
#define  VDSTYPES_H

#if defined(WIN32)
#include <windows.h>
#ifndef VDS_EXPORT
#define VDS_EXPORT(type) type __stdcall
#endif
#else
#ifndef VDS_EXPORT
#define VDS_EXPORT(type) type
#endif
#endif	// WIN32

#if defined(__MVS__) || defined(__OS400__)
#ifndef _EBCDIC
#define _EBCDIC
#endif
#ifndef WORDS_BIGENDIAN
#define WORDS_BIGENDIAN
#endif
#endif	// __MVS__ __OS400__
#endif

#ifdef _EBCDIC
typedef unsigned char         vds_ascii;
#else
typedef char                  vds_ascii;	//!< DIGIPASS SDK internal type, represents a character
#endif	// _EBCDIC

typedef unsigned char vds_byte;        //!< DIGIPASS SDK internal type, represents a byte
typedef short int vds_bool;            //!< DIGIPASS SDK internal type, represents a boolean
typedef short int vds_int16;           //!< DIGIPASS SDK internal type, represents a signed short
typedef unsigned short int vds_uint16; //!< DIGIPASS SDK internal type, represents an unsigned short

#if defined(_64BIT) || defined(SOLARIS64BIT) || (defined(__alpha) && defined(__osf__))
typedef int           vds_int32;
typedef unsigned int  vds_word32;
#else
typedef long          vds_int32;	//!< DIGIPASS SDK internal type, represents a signed integer
typedef unsigned long vds_word32; //!< DIGIPASS SDK internal type, represents an unsigned integer
#endif	// _64BIT ...

#if defined(WIN32) /* For windows 64 bit : long is still coded on 4 bytes as the int */
typedef __int64          vds_int64; /* NEW */
typedef unsigned __int64 vds_word64; /* NEW */
#define atoint64         _atoi64
#define strtol64         _strtoi64
#else
typedef long long          vds_int64; /* NEW */
typedef unsigned long long vds_word64; /* NEW */
#define atoint64           atoll
#define strtol64           strtoll
#endif

#define vds_false 0 //!< DIGIPASS SDK internal type, represents the FALSE boolean
#define vds_true  1 //!< DIGIPASS SDK internal type, represents the TRUE boolean

#endif	// vdsTypes_H

#ifdef  _DOC
#define SDK_IMPORT(type) type
#elif defined(WIN32)
#ifndef SDK_IMPORT
#define SDK_IMPORT(type) type __stdcall
#endif
#ifndef SDK_EXPORT
#define SDK_EXPORT(type) type __stdcall
#endif
#elif defined(__SYMBIAN32__)
#ifndef IMPORT_C
#define IMPORT_C __declspec(dllimport)
#endif
#ifndef SDK_IMPORT
#define SDK_IMPORT(type) IMPORT_C type
#endif
#ifndef SDK_EXPORT
#define SDK_EXPORT(type) EXPORT_C type
#endif
#else
#ifndef SDK_IMPORT
#define SDK_IMPORT(type) type
#endif
#ifndef SDK_EXPORT
#define SDK_EXPORT(type) type
#endif
#endif


//--------------------------------------------------------------------------
//--- METHODS --------------------------------------------------------------
//--------------------------------------------------------------------------


////////////////////////////////////////////////////////
/////                                              /////
/////  STANDARD METHODS WITH PASSWORD MANAGEMENT   /////
/////                                              /////
////////////////////////////////////////////////////////

/**
 * Offline activation / reactivation process:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 * 	<li>Checks and formats the activation data.</li>
 * 	<li>Extracts DIGIPASS secrets from the activation data and encrypts them by using a key derived from the password.</li>
 * 	<li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param password Password used to encrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_MANDATORY)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 *  <li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WEAK  if the password is weak</li>
 *  <li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineWithFingerprint(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_ascii* password,
		vds_ascii* platformFingerprint,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

//! \deprecated Use \ref DPSDK_ActivateOfflineWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ActivateOffline(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_ascii* password,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * Online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.</li>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks, formats and decrypts the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and encrypts them by using a key derived from the password.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param password Password used to encrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_MANDATORY)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WEAK  if the password is weak</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineWithFingerprint(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_ascii* password,
		vds_ascii* platformFingerprint,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

//! \deprecated Use \ref DPSDK_ActivateOnlineWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ActivateOnline(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_ascii* password,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * Response Only process:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It generates an OTP.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseOnly(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Challenge Response process:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It generates a response by signing the challenge.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param challenge Challenge to sign, up to 16 valid characters, MANDATORY can be empty but not null, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseFromChallenge(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* challenge,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Signature process:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It generates a signature by signing the data fields.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dataFields Data fields to sign, up to 8 characters array having up to 16 valid characters (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param dataFieldsNumber Data fields number, must not exceed the data fields number contained in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_DATA_FIELD_NUMBER)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (signature), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_ARRAY_NULL if the data fields array is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NUMBER_INVALID if the number of data fields is incorrect according to the DIGIPASS settings (see PROPERTY_APP_DTF_NUMBER)</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_NULL if one of the data fields to sign is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH if one of the data fields to sign length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NOT_CONTIGUOUS if one of the data fields is empty between two not empty data fields</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateSignature(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii dataFields[NUMBER_DATA_FIELD_MAX][LENGTH_DATA_FIELD_MAX + 1],
		vds_int32 dataFieldsNumber,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Password validation process:
 * <ul>
 *  <li>It validates the password</li>
 *  <li>It updates the application data (status and counters) according to the validation result.</li>
 *  <li>Generates an encryption key which can be used in the xxxWithKey methods in order to avoid the use of the password.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \param encryptionKey OUTPUT PARAMETER Encryption key required to decrypt DIGIPASS secret
 * \param encryptionKeyLength 16 bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ValidatePasswordWithFingerprint(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* password,
		vds_ascii* platformFingerprint,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength);

//! \deprecated Use \ref DPSDK_ValidatePasswordWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ValidatePassword(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* password,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength);

/**
 * Password change process:
 * <ul>
 *  <li>It validates the old password.</li>
 *  <li>It migrates the application sensitive data by using the passwords.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param oldPassword Old password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param newPassword New password used to encrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if one of the passwords is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if one of the passwords is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries with the old password</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the old password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WEAK  if the new password is weak</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ChangePasswordWithFingerprint(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* oldPassword,
		vds_ascii* newPassword,
		vds_ascii* platformFingerprint);

//! \deprecated Use \ref DPSDK_ChangePasswordWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ChangePassword(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* oldPassword,
		vds_ascii* newPassword);


///////////////////////////////////////////////////
/////                                         /////
/////  STANDARD METHODS WITH ENCRYPTION KEY   /////
/////                                         /////
///////////////////////////////////////////////////

/**
 * Offline activation / reactivation process:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks and formats the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and encrypts them by using the encryptionKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param encryptionKey Encryption key used to encrypt DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineWithKey(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * Online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.</li>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks, formats and decrypts the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and encrypts them by using the encryptionKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param encryptionKey Encryption key used to encrypt DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineWithKey(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * Response Only process:
 * <ul>
 *  <li>It generates an OTP.</li>
 *  <li>It updates the application data (counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseOnlyWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Challenge Response process:
 * <ul>
 *  <li>It generates a response by signing the challenge.</li>
 *  <li>It updates the application data (counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param challenge Challenge to sign, up to 16 valid characters, MANDATORY can be empty but not null, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassPropert, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseFromChallengeWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* challenge,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Signature process:
 * <ul>
 *  <li>It generates a signature by signing the data fields.</li>
 *  <li>It updates the application data (counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dataFields Data fields to sign, up to 8 characters array having up to 16 valid characters (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param dataFieldsNumber Data fields number, must not exceed the data fields number contained in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_DATA_FIELD_NUMBER)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (signature), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_ARRAY_NULL if the data fields array is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NUMBER_INVALID if the number of data fields is incorrect according to the DIGIPASS settings (see PROPERTY_APP_DTF_NUMBER)</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_NULL if one of the data fields to sign is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH if one of the data fields to sign length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NOT_CONTIGUOUS if one of the data fields is empty between two not empty data fields</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateSignatureWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii dataFields[NUMBER_DATA_FIELD_MAX][LENGTH_DATA_FIELD_MAX + 1],
		vds_int32 dataFieldsNumber,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength); //! <br/>

/**
 * Encryption key change process: it migrates the application sensitive data by using the encryption keys.
 * <b>CAUTION</b>: The old encryption key is not verified. If it is wrong, the DIGIPASS secrets will be corrupted and a reactivation will be required.<br/><br/>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param oldEncryptionKey Old encryption key used to decrypt the DIGIPASS secrets, 16 bytes, MANDATORY
 * \param oldEncryptionKeyLength LENGTH_ENCRYPTION_KEY bytes
 * \param newEncryptionKey New encryption key used to encrypt the DIGIPASS secrets, 16 bytes, MANDATORY
 * \param newEncryptionKeyLength LENGTH_ENCRYPTION_KEY bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if one of the encryption keys is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if one of the encryption keys length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ChangeEncryptionKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_byte* oldEncryptionKey,
		vds_int32 oldEncryptionKeyLength,
		vds_byte* newEncryptionKey,
		vds_int32 newEncryptionKeyLength);


/////////////////////////////////////////////////////////////////////////////////
/////                                                                       /////
/////  ENHANCED SECURITY METHODS (MITMA) METHODS WITH PASSWORD MANAGEMENT   /////
/////                                                                       /////
/////////////////////////////////////////////////////////////////////////////////

/**
 * Response Only process with enhanced security:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It computes a challenge by using the server public key.</li>
 *  <li>It generates an OTP.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseOnlyES(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Challenge Response process with enhanced security:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It computes a challenge by using the server public key and the provided challenge.</li>
 *  <li>It generates a response by signing the challenge.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param challenge Challenge to sign, up to 16 valid characters, MANDATORY can be empty but not null, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassPropert, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseFromChallengeES(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* challenge,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Signature process with enhanced security:
 * <ul>
 *  <li>It validates the password.</li>
 *  <li>It Concatenates the data to sign.</li>
 *  <li>It computes a challenge by using the server public key and the data to sign.</li>
 *  <li>It generates a signature by signing the data fields.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dataFields Data fields to sign, up to 8 characters array having up to 32000 valid characters
 * \param dataFieldsNumber Data fields number, must not exceed the data fields number contained in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_DATA_FIELD_NUMBER)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption and for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (signature), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_ARRAY_NULL if the data fields array is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NUMBER_INVALID if the number of data fields is incorrect according to the DIGIPASS settings (see PROPERTY_APP_DTF_NUMBER)</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_NULL if one of the data fields to sign is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH if one of the data fields to sign length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NOT_CONTIGUOUS if one of the data fields is empty between two not empty data fields</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateSignatureES(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* dataFields[NUMBER_DATA_FIELD_MAX],
		vds_int32 dataFieldsNumber,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);


////////////////////////////////////////////////////////////////////////////
/////                                                                  /////
/////  ENHANCED SECURITY METHODS (MITMA) METHODS WITH ENCRYPTION KEY   /////
/////                                                                  /////
////////////////////////////////////////////////////////////////////////////

/**
 * Response Only process with enhanced security:
 * <ul>
 *  <li>It computes a challenge by using the server public key.</li>
 *  <li>It generates an OTP.</li>
 *  <li>It updates the application data (status and counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseOnlyESWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Challenge Response process with enhanced security:
 * <ul>
 *  <li>It computes a challenge by using the server public key and the provided challenge.</li>
 *  <li>It generates a response by signing the challenge.</li>
 *  <li>It updates the application data (status and counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param challenge Challenge to sign, up to 16 valid characters, MANDATORY can be empty but not null, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassPropert, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseFromChallengeESWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* challenge,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength); //! <br/>

/**
 * Signature process with enhanced security:
 * <ul>
 *  <li>It Concatenates the data to sign.</li>
 *  <li>It computes a challenge by using the server public key and the data to sign.</li>
 *  <li>It generates a signature by signing the data fields.</li>
 *  <li>It updates the application data (status and counters) according to the generation result.</li>
 * </ul>
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dataFields Data fields to sign, up to \ref NUMBER_DATA_FIELD_MAX characters array having up to \ref LENGTH_DATA_FIELD_MAX_ENHANCED_SECURITY valid characters
 * \param dataFieldsNumber Data fields number, must not exceed the data fields number contained in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_DATA_FIELD_NUMBER)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param serverPublicKey Server public key, up to 1024 characters, OPTIONAL
 * \param response OUTPUT PARAMETER Generated response (signature), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_ARRAY_NULL if the data fields array is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NUMBER_INVALID if the number of data fields is incorrect according to the DIGIPASS settings (see PROPERTY_APP_DTF_NUMBER)</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_NULL if one of the data fields to sign is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH if one of the data fields to sign length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NOT_CONTIGUOUS if one of the data fields is empty between two not empty data fields</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_SERVER_PUBLIC_KEY_INCORRECT_LENGTH if the server public key length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateSignatureESWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* dataFields[NUMBER_DATA_FIELD_MAX],
		vds_int32 dataFieldsNumber,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* serverPublicKey,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

///////////////////////////////////
/////                         /////
/////  DP+ ACTIVATION METHODS /////
/////                         /////
///////////////////////////////////

/**
 * Offline activation / reactivation process:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 * 	<li>Checks and formats the activation data.</li>
 * 	<li>Extracts DIGIPASS+ secrets from the activation data and encrypts them by using a key derived from the password.</li>
 * 	<li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param password Password used to encrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_MANDATORY)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 *  <li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WEAK  if the password is weak</li>
 *  <li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineDPPlusWithFingerprint(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_ascii* password,
		vds_ascii* platformFingerprint,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

//! \deprecated Use \ref DPSDK_ActivateOfflineDPPlusWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineDPPlus(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_ascii* password,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * Offline activation / reactivation process:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks and formats the activation data.</li>
 *  <li>Extracts DIGIPASS+ secrets from the activation data and encrypts it by using the encryptionKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param encryptionKey Encryption key used to encrypt DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineDPPlusWithKey(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * DP+ online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.
 *  <li>Parses the DIGIPASS settings.
 *  <li>Checks, formats and decrypts the activation data.
 *  <li>Extracts DIGIPASS secrets from the activation data and encrypts them by using a key derived from the password.
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.
 * </ul>
 * The DP+ activation in only available in online mode. See the DIGIPASS SDK product guide for more details.<br/><br/>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param password Password used to encrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_MANDATORY)
 * \param platformFingerprint Platform fingerprint used for the DIGIPASS secrets encryption, OPTIONAL but strongly recommended, no specific length, must be null if not used
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WEAK  if the password is weak</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineDPPlusWithFingerprint(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_ascii* password,
		vds_ascii* platformFingerprint,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

//! \deprecated Use \ref DPSDK_ActivateOnlineDPPlusWithFingerprint
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineDPPlus(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_ascii* password,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);

/**
 * DP+ online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.</li>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks, formats and decrypts the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and encrypts them by using the encryptionKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * The DP+ activation in only available in online mode. See the DIGIPASS SDK product guide for more details.<br/><br/>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param encryptionKey Encryption key used to encrypt DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineDPPlusWithKey(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength);


//////////////////////////////
/////                    /////
/////  EMBEDDED METHODS  /////
/////                    /////
//////////////////////////////

#ifndef _DOC

/**
 * Offline activation / reactivation process:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks and formats the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and copies them in the secretKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param secretKey OUTPUT PARAMETER DIGIPASS secret
 * \param secretKeyLength 16 bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_NULL if the secret key is null</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_INCORRECT_LENGTH if the secret key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineEmbedded(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength,
		vds_byte* secretKey,
		vds_int32* secretKeyLength);

/**
 * Offline activation / reactivation process of DIGIPASS+ Secret:
 * <ul>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks and formats the activation data.</li>
 *  <li>Extracts DIGIPASS+ secret from the activation data and copy it in the secretKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param staticVectorInput Static vector, contains the DIGIPASS settings, MANDATORY, from 182 to 1690 hexadecimal characters (112 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param serialNumberSuffix Serial number suffix, 7 last characters of the token serial number, MANDATORY
 * \param activationCode Activation code, used to activate the DIGIPASS, MANDATORY, from 20 to 41 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT and \ref PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE)
 * \param erc Event reactivation counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, up to 512 characters, must be null if the activation data are not encrypted
 * \param staticVectorOutput OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param secretKey OUTPUT PARAMETER DIGIPASS+ secret
 * \param secretKeyLength 16 bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_NULL if the serial number suffix is null</li>
 * 	<li>\ref RETURN_CODE_SERIAL_NUMBER_SUFFIX_INCORRECT_LENGTH if the serial number suffix is incorrect</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_NULL if the secret key is null</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_INCORRECT_LENGTH if the secret key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_NULL if the activation code is null</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 *  <li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the size of the activation password is too high</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOfflineDPPlusEmbedded(vds_ascii* staticVectorInput,
		vds_ascii* serialNumberSuffix,
		vds_ascii* activationCode,
		vds_ascii* erc,
		vds_ascii* activationPassword,
		vds_byte* staticVectorOutput,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength,
		vds_byte* secretKey,
		vds_int32* secretKeyLength);

/**
 * Online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.</li>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks, formats and decrypts the activation data.</li>
 *  <li>Extracts DIGIPASS secrets from the activation data and copies them in the secretKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param secretKey OUTPUT PARAMETER DIGIPASS secret
 * \param secretKeyLength 16 bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_NULL if the secret key is null</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_INCORRECT_LENGTH if the secret key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineEmbedded(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength,
		vds_byte* secretKey,
		vds_int32* secretKeyLength);

/**
 * Online activation / reactivation process:
 * <ul>
 *  <li>Extracts the activation data from the XFAD.</li>
 *  <li>Parses the DIGIPASS settings.</li>
 *  <li>Checks, formats and decrypts the activation data.</li>
 *  <li>Extracts DIGIPASS+ secret from the activation data and copy it in the secretKey.</li>
 *  <li>Updates a DIGIPASS counters if an event reactivation counter is provided.</li>
 * </ul>
 * \param xfad Encrypted Full Activation Data, contains the activation data, MANDATORY, from 205 to 1738 hexadecimal characters (from 139 to 166 characters if static vector version < 8, see  \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION))
 * \param xerc Encrypted Event Reactivation Counter, contains the applications counters, OPTIONAL, only required for the reactivation of an event-based DIGIPASS, else must be null, from 3 to 91 decimal or hexadecimal characters according to the DIGIPASS settings (see see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_ACTIVATION_CODE_HEXA_FORMAT)
 * \param activationPassword Activation password, used to decrypt the activation data, generated by the server, OPTIONAL, must be null if the activation data are not encrypted.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param nonce Number used once, can be used for the activation data encryption: generated by the client (random or a time-dependent value), transmitted by to the server for the activation data encryption and provided to the DIGIPASS SDK for the decryption, OPTIONAL, can be used to avoid the generation of the same activation data successively.<br/>The cumulative size of the activationPassword and nonce parameters must not exceed 512 characters.
 * \param staticVector OUTPUT PARAMETER Static vector generated during the activation process, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector OUTPUT PARAMETER Dynamic vector generated during the activation process and ready to be stored, contains the DIGIPASS data, MANDATORY.<br/>
 * For an activation purpose, supply a zero valued bytes array (memset with 0).<br/>
 * For a reactivation purpose, supply the dynamic vector previously stored.
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param secretKey OUTPUT PARAMETER DIGIPASS secret
 * \param secretKeyLength 16 bytes
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_NULL if the XFAD parameter is null</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_LENGTH if the XFAD length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XFAD_INCORRECT_FORMAT if the XFAD format is incorrect</li>
 * 	<li>\ref RETURN_CODE_SHARED_SECRET_TOO_LONG if the cumulative size of the activation password and the nonce is too high</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_NULL if the secret key is null</li>
 * 	<li>\ref RETURN_CODE_EBD_SECRET_KEY_INCORRECT_LENGTH if the secret key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_LENGTH if the activation code length is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INCORRECT_FORMAT if the activation code format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ACTIVATION_CODE_INVALID if the activation code is invalid</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_LENGTH if the event reactivation counter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_XERC_INCORRECT_FORMAT if the event reactivation counter format is incorrect</li>
 * 	<li>\ref RETURN_CODE_ERC_INVALID if the event reactivation counter is invalid</li>
 * 	<li>\ref RETURN_CODE_REACTIVATION_LOCK if the application has been locked in a reactivation case</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_ActivateOnlineDPPlusEmbedded(vds_ascii* xfad,
		vds_ascii* xerc,
		vds_ascii* activationPassword,
		vds_ascii* nonce,
		vds_byte* staticVector,
		vds_int32* staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32* dynamicVectorLength,
		vds_byte* secretKey,
		vds_int32* secretKeyLength);

/**
 * Response Only process:
 * <ul>
 *  <li>It generates an OTP by using the provided ciphering functions.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param sessionId Session ID
 * \param keyHandle Key handle
 * \param cryptoInfo Reserved for future use
 * \param encryptFunction Handle on the callback functions
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_EBD_SESSION_ID_NULL if the session identifier is null</li>
 * 	<li>\ref RETURN_CODE_EBD_KEY_HANDLE_NULL if the key handle is null</li>
 * 	<li>\ref RETURN_CODE_EBD_ENCRYPT_FUNCTION_NULL if the encryptFunction parameter is null</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseOnlyEmbedded(void* sessionId,
		void* keyHandle,
		void* cryptoInfo,
		void* encryptFunction[],
		vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Challenge Response process:
 * <ul>
 *  <li>It generates a response by signing the challenge and by using the provided ciphering functions.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param sessionId Session ID
 * \param keyHandle Key handle
 * \param cryptoInfo Reserved for future use
 * \param encryptFunction Handle on the callback functions
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param challenge Challenge to sign, up to 16 valid characters, MANDATORY can be empty but not null, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassPropert, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref DPSDK_GetDigipassProperty( \ref PROPERTY_CREATION_VERSION ) < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (OTP), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_EBD_SESSION_ID_NULL if the session identifier is null</li>
 * 	<li>\ref RETURN_CODE_EBD_KEY_HANDLE_NULL if the key handle is null</li>
 * 	<li>\ref RETURN_CODE_EBD_ENCRYPT_FUNCTION_NULL if the encryptFunction parameter is null</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateResponseFromChallengeEmbedded(void* sessionId,
		void* keyHandle,
		void* cryptoInfo,
		void* encryptFunction[],
		vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* challenge,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

/**
 * Signature process:
 * <ul>
 *  <li>It generates a signature by signing the data fields and by using the provided ciphering functions.</li>
 *  <li>It updates the application data (status and counters) according to the validation and generation results.</li>
 * </ul>
 * \param sessionId Session ID
 * \param keyHandle Key handle
 * \param cryptoInfo Reserved for future use
 * \param encryptFunction Handle on the callback functions
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dataFields Data fields to sign, up to 8 characters array having up to 16 valid characters (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param dataFieldsNumber Data fields number, must not exceed the data fields number contained in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_DATA_FIELD_NUMBER)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the response, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \param platformFingerprint Platform fingerprint used for the token derivation if supported, OPTIONAL but strongly recommended, no specific length, must be null if not used.<br/>
 * The platform fingerprint is used to perform the token derivation only if the \ref DPSDK_GenerateDerivationCode has already been called.<br/>
 * For a DIGIPASS created by a DIGIPASS SDK 4.0 (<=> \ref PROPERTY_CREATION_VERSION < 3), the platform fingerprint is used to perform the token derivation even if if the \ref DPSDK_GenerateDerivationCode has not been called.
 * \param response OUTPUT PARAMETER Generated response (signature), characters array null terminated, MANDATORY
 * \param responseLength Length of the supplied "response" parameter, (\ref LENGTH_RESPONSE_MAX + 1) characters
 * \param hostCode OUTPUT PARAMETER Generated host code, characters array null terminated, MANDATORY if host code must be generated for the selected crypto application (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_APP_HOST_CODE_LENGTH)
 * \param hostCodeLength Length of the supplied "hostCode" parameter, (\ref LENGTH_HOST_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_ARRAY_NULL if the data fields array is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELDS_NUMBER_INVALID if the number of data fields is incorrect according to the DIGIPASS settings (see PROPERTY_APP_DTF_NUMBER)</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_NULL if one of the data fields to sign is null</li>
 * 	<li>\ref RETURN_CODE_DATA_FIELD_INCORRECT_LENGTH if one of the data fields to sign length is incorrect</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_NULL if the response parameter is null</li>
 * 	<li>\ref RETURN_CODE_RESPONSE_INCORRECT_LENGTH if the response parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_NULL if the hostCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_HOST_CODE_INCORRECT_LENGTH if the hostCode parameter length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_EBD_SESSION_ID_NULL if the session identifier is null</li>
 * 	<li>\ref RETURN_CODE_EBD_KEY_HANDLE_NULL if the key handle is null</li>
 * 	<li>\ref RETURN_CODE_EBD_ENCRYPT_FUNCTION_NULL if the encryptFunction parameter is null</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateSignatureEmbedded(void* sessionId,
		void* keyHandle,
		void* cryptoInfo,
		void* encryptFunction[],
		vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii dataFields[NUMBER_DATA_FIELD_MAX][LENGTH_DATA_FIELD_MAX + 1],
		vds_int32 dataFieldsNumber,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* response,
		vds_int32 responseLength,
		vds_ascii* hostCode,
		vds_int32 hostCodeLength);

#endif

/////////////////////////////
/////                   /////
/////  CRYPTO METHODS   /////
/////                   /////
/////////////////////////////

/**
 * Hash function which can be used during the integration to hash data.
 * \param mechanism Hash mechanism (\ref HASH_MD5, \ref HASH_SHA_1 or \ref HASH_SHA_256)
 * \param dataIn Data to hash, MANDATORY, cannot be null
 * \param dataInLength Input bytes array length
 * \param dataOut Output bytes array which will contain the hashed data
 * \param dataOutLength 16 bytes for MD5, 20 for SHA1 and 32 for SHA-256
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_MECANISM_INVALID if the mechanism is not managed</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_NULL if the input bytes array is null</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_NULL if the output bytes array is null</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_INCORRECT_LENGTH if the output bytes array length is incorrect according to the selected mechanism</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_Hash(vds_int32 mechanism,
		vds_byte* dataIn,
		vds_int32 dataInLength,
		vds_byte* dataOut,
		vds_int32* dataOutLength);

/**
 * Cipher function which can be used during the integration to encrypt data.
 * \param mechanism Cipher mechanism (\ref CIPHER_MECHANISM_DES, \ref CIPHER_MECHANISM_DES3, \ref CIPHER_MECHANISM_AES)
 * \param mode Cipher mode (\ref CIPHER_MODE_ECB, \ref CIPHER_MODE_CBC, \ref CIPHER_MODE_CFB)
 * \param key Cipher key, MANDATORY, cannot be null
 * \param keyLength 8 bytes for DES, 16/24 bytes for 3DES, 16/24/32 bytes for AES
 * \param initialVector Initial vector used for the CBC and the CFB modes, OPTIONAL, can be null
 * \param initialVectorLength Fixed length in CBC mode (8 bytes for DES/3DES, 16 bytes for AES), variable length in CFB mode
 * \param dataIn Data to process, MANDATORY, cannot be null
 * \param dataInLength No length constraint in CFB mode, length constraint in ECB mode and in CBC mode: 8 bytes multiple for DES/3DES, 16 bytes multiple for AES
 * \param dataOut Processed data, MANDATORY, cannot be null
 * \param dataOutLength Higher or equal to dataInLength
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_MECANISM_INVALID if the mechanism is not managed</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_MODE_INVALID if the mode is not managed</li>
 * 	<li>\ref RETURN_CODE_KEY_NULL if the key is null</li>
 * 	<li>\ref RETURN_CODE_KEY_INCORRECT_LENGTH if key length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_NULL if input bytes array is null</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_INCORRECT_LENGTH if input bytes array length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_NULL if output bytes array is null</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_INCORRECT_LENGTH if output bytes array length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_INITIAL_VECTOR_INCORRECT_LENGTH if the initial vector length is incorrect according to the selected mechanism</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_Encrypt(vds_byte mechanism,
		vds_byte mode,
		vds_byte* key,
		vds_int32 keyLength,
		vds_byte* initialVector,
		vds_int32 initialVectorLength,
		vds_byte* dataIn,
		vds_int32 dataInLength,
		vds_byte* dataOut,
		vds_int32* dataOutLength); //! <br/>

/**
 * Cipher function which can be used during the integration to decrypt data.
 * \param mechanism Cipher mechanism (\ref CIPHER_MECHANISM_DES, \ref CIPHER_MECHANISM_DES3, \ref CIPHER_MECHANISM_AES)
 * \param mode Cipher mode (\ref CIPHER_MODE_ECB, \ref CIPHER_MODE_CBC, \ref CIPHER_MODE_CFB)
 * \param key Cipher key, MANDATORY, cannot be null
 * \param keyLength 8 bytes for DES, 16/24 bytes for 3DES, 16/24/32 bytes for AES
 * \param initialVector Initial vector used for the CBC and the CFB modes, OPTIONAL, can be null
 * \param initialVectorLength Fixed length in CBC mode (8 bytes for DES/3DES, 16 bytes for AES), variable length in CFB mode
 * \param dataIn Data to process, MANDATORY, cannot be null
 * \param dataInLength No length constraint in CFB mode, length constraint in ECB mode and in CBC mode: 8 bytes multiple for DES/3DES, 16 bytes multiple for AES
 * \param dataOut Processed data, MANDATORY, cannot be null
 * \param dataOutLength Higher or equal to dataInLength
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_MECANISM_INVALID if the mechanism is not managed</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_MODE_INVALID if the mode is not managed</li>
 * 	<li>\ref RETURN_CODE_KEY_NULL if the key is null</li>
 * 	<li>\ref RETURN_CODE_KEY_INCORRECT_LENGTH if key length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_NULL if input bytes array is null</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_INCORRECT_LENGTH if input bytes array length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_NULL if output bytes array is null</li>
 * 	<li>\ref RETURN_CODE_OUTPUT_DATA_INCORRECT_LENGTH if output bytes array length is incorrect according to the selected mechanism</li>
 * 	<li>\ref RETURN_CODE_INITIAL_VECTOR_INCORRECT_LENGTH if the initial vector length is incorrect according to the selected mechanism</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_Decrypt(vds_byte mechanism,
		vds_byte mode,
		vds_byte* key,
		vds_int32 keyLength,
		vds_byte* initialVector,
		vds_int32 initialVectorLength,
		vds_byte* dataIn,
		vds_int32 dataInLength,
		vds_byte* dataOut,
		vds_int32* dataOutLength);


////////////////////////////////
/////                      /////
/////  UTILITIES METHODS   /////
/////                      /////
////////////////////////////////

/**
 * Enable a crypto application
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be enabled, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_EnableApplication(vds_byte* staticVector, vds_int32 staticVectorLength, vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength, vds_int32 cryptoApplicationIndex);

/**
 * Disable a crypto application
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be disabled, MANDATORY, from \ref CRYPTO_APPLICATION_INDEX_APP_1 to \ref CRYPTO_APPLICATION_INDEX_APP_8
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 *  <li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_DisableApplication(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_int32 cryptoApplicationIndex);

/**
 * Generates a derivation code.
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param password Password used to decrypt DIGIPASS secrets, MANDATORY if the password is required in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_PASSWORD_PROTECTED)
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the derivation code, MANDATORY
 * \param platformFingerprint Platform fingerprint used to generate the derivation code, MANDATORY, no specific length
 * \param challenge Challenge which could used to generate the derivation code if the used crypto application is challenge/response, up to 16 valid characters, OPTIONAL, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param derivationCode OUTPUT PARAMETER Generated derivation code, characters array null terminated, MANDATORY
 * \param derivationCodeLength Length of the supplied "derivationCode" parameter, (\ref LENGTH_DERIVATION_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_NULL if the password is null</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_SHORT if the password is too short</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LENGTH_TOO_LONG if the password is too long</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_LOCK if the application is locked after too many wrong tries</li>
 * 	<li>\ref RETURN_CODE_PASSWORD_WRONG if the password is cannot be validated</li>
 * 	<li>\ref RETURN_CODE_NOT_PASSWORD_PROTECTED if the DIGIPASS is not password protected</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_TOKEN_DERIVATION_NOT_SUPPORTED if the token derivation is not supported</li>
 * 	<li>\ref RETURN_CODE_PLATFORM_FINGERPRINT_NOT_DEFINED if the platform fingerprint is not defined</li>
 * 	<li>\ref RETURN_CODE_DERIVATION_CODE_NULL if the derivationCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_DERIVATION_CODE_INCORRECT_LENGTH if the derivationCode parameter length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateDerivationCode(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_ascii* password,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* challenge,
		vds_ascii* derivationCode,
		vds_int32 derivationCodeLength);

/**
 * Generates a derivation code with an encryption key.
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, MANDATORY, <b>must be stored after the call</b>
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param encryptionKey Encryption key used to decrypt the DIGIPASS secrets, MANDATORY
 * \param encryptionKeyLength 16 bytes
 * \param clientServerTimeShift Client/Server time shift in seconds, OPTIONAL, recommended if the application to use is time-based, else must be 0, use \ref DPSDK_ComputeClientServerTimeShiftFromServerTime to compute this value
 * \param cryptoApplicationIndex Crypto application index, indicates which application must be used to generate the derivation code, MANDATORY
 * \param platformFingerprint Platform fingerprint used to generate the derivation code, MANDATORY, no specific length
 * \param challenge Challenge which could used to generate the derivation code if the used crypto application is challenge/response, up to 16 valid characters, OPTIONAL, length defined in the DIGIPASS settings (see \ref DPSDK_GetDigipassProperty, \ref PROPERTY_APP_DATA_FIELDS_MIN_LENGTH and \ref PROPERTY_APP_DATA_FIELDS_MAX_LENGTH)
 * \param derivationCode OUTPUT PARAMETER Generated derivation code, characters array null terminated, MANDATORY
 * \param derivationCodeLength Length of the supplied "derivationCode" parameter, (\ref LENGTH_DERIVATION_CODE_MAX + 1) characters
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATUS_INVALID if the status is invalid (not activated or locked), an activation is required</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_NULL if the encryption key is null</li>
 * 	<li>\ref RETURN_CODE_ENCRYPTION_KEY_INCORRECT_LENGTH if the encryption key length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_APPLICATION_DISABLED if the crypto application is disabled in the DIGIPASS settings</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_NULL if the challenge is null</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_INCORRECT_LENGTH if the challenge length is incorrect</li>
 * 	<li>\ref RETURN_CODE_CHALLENGE_CHARACTER_INVALID if one of the data to sign contains invalid characters</li>
 * 	<li>\ref RETURN_CODE_TOKEN_DERIVATION_NOT_SUPPORTED if the token derivation is not supported</li>
 * 	<li>\ref RETURN_CODE_PLATFORM_FINGERPRINT_NOT_DEFINED if the platform fingerprint is not defined</li>
 * 	<li>\ref RETURN_CODE_DERIVATION_CODE_NULL if the derivationCode parameter is null</li>
 * 	<li>\ref RETURN_CODE_DERIVATION_CODE_INCORRECT_LENGTH if the derivationCode parameter length is incorrect</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GenerateDerivationCodeWithKey(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_byte* encryptionKey,
		vds_int32 encryptionKeyLength,
		vds_int32 clientServerTimeShift,
		vds_int32 cryptoApplicationIndex,
		vds_ascii* platformFingerprint,
		vds_ascii* challenge,
		vds_ascii* derivationCode,
		vds_int32 derivationCodeLength);

/**
 * Gets the amount of memory which must be allocated for the dynamic vector.
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVectorLength OUTPUT PARAMETER The dynamic length which must be allocated
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_NULL if the dynamic vector length pointer is null</li>
 * </ul>
 */
SDK_IMPORT(vds_int32) DPSDK_GetDynamicVectorLength(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_int32* dynamicVectorLength);

/**
 * Gets a DIGIPASS property
 * \param staticVector Static vector, contains the DIGIPASS settings, MANDATORY
 * \param staticVectorLength From 91 to 845 bytes (56 characters if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param dynamicVector Dynamic vector, contains the DIGIPASS data, OPTIONAL, see in the table below the cases where the dynamic vector is required
 * \param dynamicVectorLength From 80 to 232 bytes (56 if static vector version < 8, see \ref DPSDK_GetDigipassProperty and \ref PROPERTY_VERSION)
 * \param property Required property, find below the list of the supported properties
 * \param value OUTPUT PARAMETER Value associated with the specified property, find below the list of the required type for each property
 * \param valueLength Value length, find below the list of the required length for each property
 * \param cryptoApplicationIndex  Crypto application index, indicates which application must be used to get a property associated with an application (<=> PROPERTY_APP_xxx)
 * \return A code indicating the process result.
 * <ul>
 * 	<li>\ref RETURN_CODE_SUCCESS in case of success</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_NULL if the value parameter is null</li>
 * 	<li>\ref RETURN_CODE_INPUT_DATA_INCORRECT_LENGTH if the length allocated for the value parameter is incorrect assording to the selected property</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_NULL if the static vector is null</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_LENGTH if the static vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_STATIC_VECTOR_INCORRECT_FORMAT if the static vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_NULL if the dynamic vector is null</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_LENGTH if the dynamic vector length is incorrect</li>
 * 	<li>\ref RETURN_CODE_DYNAMIC_VECTOR_INCORRECT_FORMAT if the dynamic vector format is incorrect</li>
 * 	<li>\ref RETURN_CODE_CRYPTO_APPLICATION_INDEX_INVALID if the crypto application index is invalid, use \ref CRYPTO_APPLICATION_INDEX_APP_1 ... \ref CRYPTO_APPLICATION_INDEX_APP_8</li>
 * 	<li>\ref RETURN_CODE_UNKNWON_PROPERTY if the property is not managed</li>
 * </ul>
 * \see
 * <table>
 *  <tr> <td align="center"><b>PROPERTY</b></td><td align="center"><b>TYPE</b></td><td align="center"><b>SIZE</b></td><td align="center"><b>DYNAMIC VECTOR REQUIRED</b></td></tr>
 *  <tr> <td>PROPERTY_VERSION</td>                          <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_STATUS</td>                           <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_SERIAL_NUMBER</td>                    <td>vds_ascii*</td>  <td>LENGTH_SERIAL_NUMBER + 1</td>                 <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_PASSWORD_ENABLED</td>                 <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_MIN_LENGTH</td>              <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_MAX_LENGTH</td>              <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_WEAK_PASSWORD_CONTROL</td>            <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_CHECK_LEVEL</td>             <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PENALTY_RESET_ACTION</td>             <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_FATAL</td>                   <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_FATAL_COUNTER</td>           <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_REACTIVATION_FATAL</td>               <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_REACTIVATION_FATAL_COUNTER</td>       <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_TOKEN_DERIVATION_SUPPORTED</td>       <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_HIGH_SECURITY</td>                    <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_DP_PLUS_HIGH_SECURITY</td>            <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_ACTIVATION_CODE_HEXA_FORMAT</td>      <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_USE_CHECKSUM_FOR_ACTIVATION_CODE</td> <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_CRYPTO_APP_NUMBER</td>                <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_INDEX</td>                        <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_NAME</td>                         <td>vds_ascii*</td>  <td>LENGTH_CRYPTO_APPLICATION_NAME + 1</td>       <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_ENABLED</td>                      <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_APP_DP_PLUS</td>                      <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_RESPONSE_LENGTH</td>              <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_HOST_CODE_LENGTH</td>             <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_CHECK_DIGIT</td>                  <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_DTF_NUMBER</td>                   <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_DATA_FIELD_MIN_LENGTH</td>        <td>vds_byte*</td>   <td>NUMBER_DATA_FIELD_MAX * sizeof(vds_byte)</td> <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_DATA_FIELD_MAX_LENGTH</td>        <td>vds_byte*</td>   <td>NUMBER_DATA_FIELD_MAX * sizeof(vds_byte)</td> <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_EVENT_COUNTER</td>                <td>vds_word32*</td> <td>sizeof(vds_word32)</td>                       <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_APP_LAST_TIME_USED</td>               <td>vds_word32*</td> <td>sizeof(vds_word32)</td>                       <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_APP_TIME_BASED</td>                   <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_EVENT_BASED</td>                  <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_UTC_TIME</td>                         <td>vds_int32*</td>  <td>sizeof(vds_int32)</td>                        <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_MANDATORY</td>               <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_PASSWORD_PROTECTED</td>               <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_MASTER_KEY</td>                       <td>vds_byte*</td>   <td>LENGTH_MASTER_KEY</td>                        <td>false</td> </tr>
 *  <tr> <td>PROPERTY_ITERATION_NUMBER</td>                 <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_USE_SECRET_DERIVATION</td>            <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_STORAGE_VERSION</td>                  <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_APP_OUTPUT_TYPE</td>                  <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_CODEWORD</td>                     <td>vds_byte*</td>   <td>LENGTH_CODEWORD</td>                          <td>false</td> </tr>
 *  <tr> <td>PROPERTY_APP_TIME_STEP</td>                    <td>vds_int32*</td>  <td>sizeof(vds_int32)</td>                        <td>false</td> </tr>
 *  <tr> <td>PROPERTY_ITERATION_POWER</td>                  <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>false</td> </tr>
 *  <tr> <td>PROPERTY_CREATION_VERSION</td>                 <td>vds_byte*</td>   <td>sizeof(vds_byte)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_TOKEN_DERIVATION_ACTIVATED</td>       <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_PASSWORD_DERIVATION_ACTIVATED</td>    <td>vds_bool*</td>   <td>sizeof(vds_bool)</td>                         <td>true</td>  </tr>
 *  <tr> <td>PROPERTY_APP_AUTHENTICATION_MODE</td>          <td>vds_ascii*</td>  <td>LENGTH_AUTHENTICATION_MODE + 1</td>           <td>false</td> </tr>
 * </table>
 */
SDK_IMPORT(vds_int32) DPSDK_GetDigipassProperty(vds_byte* staticVector,
		vds_int32 staticVectorLength,
		vds_byte* dynamicVector,
		vds_int32 dynamicVectorLength,
		vds_int32 property,
		void* value,
		vds_int32 valueLength,
		vds_int32 cryptoApplicationIndex);

/**
 * Gets the message associated with a return code
 * \param returnCode Return code
 * \return The message associated with the return code
 */
SDK_IMPORT(vds_ascii*) DPSDK_GetMessageForReturnCode(vds_int32 returnCode); //! <br/>

/**
 * Computes the client server time shift by using the server time and the client UTC times (timeShift = serverTime - clientTime)
 * \param serverTimeInSeconds Server time in seconds
 * \return The client server time shift in seconds
 */
SDK_IMPORT(vds_int32) DPSDK_ComputeClientServerTimeShiftFromServerTime(vds_int32 serverTimeInSeconds);


//--------------------------------------------------------------------------
//--- DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED ----
//--- DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED ----
//--- DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED ----
//--------------------------------------------------------------------------

#ifndef _DOC

#if !defined(_DP4IPHONE) && !defined(_DP4BBN)

#define DES          0
#define AES          1
#define MD4          2
#define MD5          3
#define SHA_1        4
#define HMAC         5
#define PRF          6
#define XOR          7
#define WINHASH      8

#endif

#define LANMAN      1
#define NTLM        2
#define NTLM2       4
#define NTLM2USER   8
#define NTLM2DOMAIN 16
#define KRB5        32
#define DPRSP       64
#define CHAP        128
#define MSCHAP      2
#define MSCHAP2     256

#define SERIAL_NUMBER_LEN 10
#define DES_KEY_LENGTH 8
#define DOUBLE_DES_KEY_LENGTH 16

/*Full Activation Data Constant Value*/
#define BASIC_ACTIVATION	0x10 /*Basic Activation Scheme (pseudo TDES)*/
#define HIGH_ACTIVATION	0x20 /*High Activation Scheme (real TDES)*/
#define SNs_IN_FAD		0x40 /*Serial Nb Suffix part of FAD.*/
#define SV_IN_FAD			0x80 /*Static Vector part of FAD.*/

#define FAD_TYPE_CUSTOM_HIGH_HEX		(SV_IN_FAD + SNs_IN_FAD + HIGH_ACTIVATION + HEX)
#define FAD_TYPE_CUSTOM_BASIC_HEX		(SV_IN_FAD + SNs_IN_FAD + BASIC_ACTIVATION + HEX)
#define FAD_TYPE_CUSTOM_HIGH_DEC_2		(SV_IN_FAD + SNs_IN_FAD + HIGH_ACTIVATION + DEC_2)
#define FAD_TYPE_CUSTOM_BASIC_DEC_2		(SV_IN_FAD + SNs_IN_FAD + BASIC_ACTIVATION + DEC_2)

#define LNG_FAD_STD_BASIC_DEC_2 (7*2  + 20)
#define LNG_FAD_STD_HIGH_DEC_2  (7*2  + 20 + 20)
#define LNG_FAD_STD_BASIC_HEX   (7*2  + 16)
#define LNG_FAD_STD_HIGH_HEX    (7*2  + 16 + 16)
#define LNG_HEXA_SV       (56*2)
#define LNG_BYTE_SV       56
#define LNG_BYTE_SDV       56*2


/*Settings Custom = Use HardCoded Static Vector.*/
#define LNG_FAD_CUST_BASIC_DEC_2 (LNG_HEXA_SV + LNG_FAD_STD_BASIC_DEC_2)
#define LNG_FAD_CUST_HIGH_DEC_2  (LNG_HEXA_SV + LNG_FAD_STD_HIGH_DEC_2)
#define LNG_FAD_CUST_BASIC_HEX   (LNG_HEXA_SV + LNG_FAD_STD_BASIC_HEX)
#define LNG_FAD_CUST_HIGH_HEX    (LNG_HEXA_SV + LNG_FAD_STD_HIGH_HEX)


#define LNG_MAX_PWD	4096 	/** Password Max Length is 4096 Character **/
#define LNG_MAX_CHS	4096 	/** Password Max Length is 4096 Character **/
#define LNG_MAX_PIN	32 	/** PIN Max Length is 32 Character **/
#define LNG_MIN_PIN	2 	/** PIN Max Length is 32 Character **/
#define NO_LNG_MIN_PIN 0 	/** PIN Min Length is 0, PIN can be omitted. **/

/*DTF MAx Length*/
#define LNG_DTF_MAX  20
#define LNG_ACTV_PWD 32

#define LNG_MAX_DTF_1	16 	/** Input Length Max for DTF 1*/
#define LNG_MAX_DTF_2	16 	/** Input Length Max for DTF 2*/
#define LNG_MAX_DTF_3	16 	/** Input Length Max for DTF 3*/
#define LNG_MAX_DTF_4	16 	/** Input Length Max for DTF 4*/
#define LNG_MAX_DTF_5	16 	/** Input Length Max for DTF 5*/
#define LNG_MAX_DTF_6	16 	/** Input Length Max for DTF 6*/
#define LNG_MAX_DTF_7 16 	/** Input Length Max for DTF 7*/
#define LNG_MAX_DTF_8	16 	/** Input Length Max for DTF 8*/


/* SECurity Level = PIN Check Level.*/
#define SEC_LVL_NO_CHECK  0 /** no check is performed on pin */
#define SEC_LVL_CHECKSUM  1 /** basic LUHN checksum is performed on pin */
#define SEC_LVL_HASH		2 /** Hash is performed on pin */
#define SEC_LVL_NONE		0x0F /** no pin is used at all */


/* ENCRyption/Decryption Mode.*/
#define ENCR_S  0
#define DECR_S  1
#define ENCR_T  8
#define DECR_T  9
#define KM_DES3_ECB  10
#define KM_DES3_CBC  11
#define KM_AES_ECB   12
#define KM_AES_CBC   13


/*Shift inside Byte Array*/
#define DV_SHIFT  8 /** shift for ivleft/right in dv*/
#define SV_SHIFT	9	/** Static vector shift for application 2 specific settings */
/*Mask*/
#define MSB_MASK  0xF0 /** Most Significant Byte mask */
#define LSB_MASK  0x0F /** Least Significant Byte mask */

#define DISABLED  0x0F /** constant for disabled */

#define DP4C_SUCCESS	 0 /** app is not activated at all */
#define DP4C_KBUG		-5000
#define DP4C_FAIL		DP4C_KBUG-1000

#define DP4C_TRUE		1/** SV Used/Enabled  */
#define DP4C_FALSE	0/** SV not Used/Disabled */

#define PIN_CH_NO     0  /* Pin Change Not Allowed */
#define PIN_CH_YES    1  /* Pin Change Allowed */
#define PIN_CH_WP     2  /* Pin Change Allowed with weak PIN*/

/* APPLET Possible Status = DV[1].*/
//#define STATUS_NOT_ACTIVATED		0 /** app is not activated at all */
//#define STATUS_ACTIVATED			1 /** app is activated */
//#define STATUS_LOCKED				2 /** not used, app is locked */
#define STATUS_LOCKED_WAIT		3 /** not used, RFU */
#define STATUS_LOCKED_UNL_CHAL	4 /** not used, RFU */
#define STATUS_GEN_INVALID_OTP	5 /** app will generate invalid otp/signature */
#define STATUS_REACT_LOCK_GEN_INVALID_OTP	6 /** app is locked due to reactivation threshold. Penalty = Generate Invalid OTP*/

#define PIN_MGT_PIN_OK_RESET_COUNTER		0 /**  PIN Fail => Gen PWD.*/
#define PIN_MGT_PIN_FAIL_COUNTER_MGT		1 /**  PIN Fail => Counter Mgt.*/
#define PIN_MGT_PIN_FAIL_GEN_INVALID_OTP	5 /**  PIN Fail => Gen PWD.*/


/*Application Penalty*/
#define APP_PENALTY_RESET			0 	/** Application penalty : reset DPDes key and application status */
#define APP_PENALTY_GEN_INVALID	1 	/** Application penalty : generate wrong OTP/Signature */


/* Dynamic Vector Index List.*/
#define DV_IDX_LNG							0
#define DV_IDX_STATUS						1 /** App status counter index in dv*/
#define DV_IDX_SNS							2 /** Serial number suffix index in dv. 7 bytes long*/
#define DV_IDX_REACTIVATION_FATAL_COUNTER	9 /** Reactivation fatal counter index in dv*/
#define DV_IDX_DES1KEY						10 /** First DES key index in dv, 8 bytes long*/
#define DV_IDX_DES2KEY						18 /** Second TDES key index in dv, 8 bytes long*/
#define DV_IDX_UNLOCK_KEY					26 /** Unlock key in dv. Not used yet.*/
#define DV_IDX_APPi_IVLEFT					34 /** IVLEFT index in dv, 4 bytes long*/
#define DV_IDX_APPi_IVRIGHT					38 /** IVRIGTH index in dv, 4 bytes long*/
#define DV_IDX_PIN_SECRET					50 /** PIN Check or hash code index in dv. Can be either 1 or 4 bytes long */
#define DV_IDX_PIN_FATAL_COUNTER			54 /** PIN fatal counter index in dv*/
#define DV_IDX_PIN_WAIT_COUNTER				55 /** PIN wait counter index in dv*/

/*Static Vector Index List*/
#define SV_IDX_LNG				0 /** Static vector length */
#define SV_IDX_VER				1 /** Static vector version */
#define SV_IDX_SNP				2 /** Serial number prefix start index. SNP is 3 bytes long */
#define SV_IDX_SERIAL_CODE		5 /** Serial code start index. Serial code is 16 bytes long */
#define SV_IDX_FAD_LENGTH		21 /** FAD length index in static vector*/
#define SV_IDX_FAD_TYPE			22 /** FAD type index in static vector*/
#define SV_IDX_PIN_CHK_LVL		23 /** pin check level index in static vector*/
#define SV_IDX_PIN_MIN_LNG		24 /** pin min length index in static vector*/
#define SV_IDX_PIN_CHG			25 /** pin change allowed index in static vector*/
#define SV_IDX_PIN_FATAL		26 /** pin fatal index in static vector*/
#define SV_IDX_PIN_WAIT			27 /** pin wait index in static vector */
#define SV_IDX_TIMEOUT			28 /** timeout index in static vector*/
#define SV_IDX_PIN_WAIT_TIME	29 /** pin wait time in static vector Pin wait time is most significant byte in SV[29]. Not used yet, will be implemented in future releases.*/
#define SV_IDX_ITERATION_NB		29	/** Iteration number in static vector. Iteration number is least significant byte in SV[29]*/
#define SV_IDX_APP_PENALTY		30 	/** application penatlty index in static vector*/
#define SV_IDX_APPi_CODEWORD	31 	/** application codeword index. 4 bytes long */
#define SV_IDX_APPi_DES			35	/** application tdes flag index*/
#define SV_IDX_APPi_RHC_LNG		36  /** Return Host Code length index. RHC is most significant byte in SV[36]*/
#define SV_IDX_APPi_LNG			36  /** Application response length index. Application response is least significant byte in SV[36]*/
#define SV_IDX_APPi_CHK_DIGIT	37 	/** check digit index*/
#define SV_IDX_APPi_ENABLED		38 	/** application enabled flag index*/
#define SV_IDX_APPi_TYPE		39 	/** application 1 type index*/
#define SV_IDX_DF_NB			48 	/** Number of data field for app2 index*/
#define SV_IDX_APP2_TYPE		49 	/** application 2 type index*/
#define SV_IDX_REACTIVATION_FATAL  50 	/** Reactivation fatal counter index*/
#define SV_IDX_EBANKING_DEF		51 	/** EBANKING Index*/
#define SV_IDX_MSIGNATURE_DEF	52 	/** MSIGNATURE Index*/
#define SV_IDX_ACTIVATION_SERV	53 	/** ACTIVATVATION Index*/

/*--- Activation Error ---*/
#define AC_ERR_INVALID_PART1			-1	/** Invalid Activation Code */
#define AC_ERR_INVALID_PART2			-2	/** Invalid Activation Code (2nd part)*/
#define SN_ERR_INVALID					-3	/** Invalid DIGIPASS Serial Number.*/
/*--- Password Error ---*/
#define PWD_ERR_CHKSUM_INVALID			-4  /** Password Checksum calculation fails. */
#define PWD_ERR_INIT_INVALID			-5  /** Set Initial Password fails : the Old Password value must be null. */
#define DVKEY_ERR_INVALID				-6  /** Change Dynamic Vector Key Fails : application must be activated to change DVKey.*/
/*--- Appli Error ---*/
#define APP_ERR_NOT_ACTIVATED			-7  /** Application Not Activated. Please Run Activation Process and Retry. */
#define OUTPUT_LENGTH_INCONSISTENT		-11 /** Output length Inconsistence between Static Vector and OTP/SG generated.*/
#define RESP_LENGTH_ERR     			-12 /** Server Response Length Inconsistence between Static Vector and RHC/SCC generated. */
#define CHK_DIGIT_NOT_SUPPORTED			-13 /** Response/Signature CheckDigit is not supported with Return Host code. */
/*--- Activation Error ---*/
#define AC_ERR_LENGTH					-20 /**Incorrect Activation Data received for server. The Activation data Length does not correspond with the activation type specified.*/
#define AC1_ERR_LENGTH					-21 /**Incorrect Activation Code 1 length. The Activation data Length does not correspond with the activation type specified.*/
#define AC2_ERR_LENGTH					-22 /**Incorrect Activation Code 2 length. The Activation data Length does not correspond with the activation type specified.*/
#define CHS_ERR_MANDATORY				-23 /**Customer Historical secret is mandatory.*/
#define SV_ERR_HEXA_CHAR				-24 /**Static Vector must be allocated 112 HEXA Characters*/
#define DV_ERR_HEXA_CHAR				-25 /**Dynamic Vector must be allocated 112 HEXA Characters.*/
#define PWD_ERR_INVALID					-26 /**Invalid User Password input length.*/
#define DVKEY_ERR_HEXA_CHAR				-27 /**Incorrect DVKey received in input. It must be a 32 HEXA Characters.*/
#define DV_PWD_ERR_NOT_SUPPORT			-28 /**Activation process can not support both Password and DVKey in input. One of them must be set to NULL.*/
#define FAD_ERR_TYPE_INVALID			-29 /**Invalid Activation Type. FAD Type supported are 0x8E or 0x9E and 0x92 or 0xA2.*/

/*ERROR message related to an incorrect  Static Vector Check content */
#define SV_ERR_WRONG_ITERATION_NUMBER_IN_SV			-30	/** Incorrect iteration number in svf */
#define SV_ERR_WRONG_APPLICATION_PENALTY_IN_SV		-31	/** Incorrect application penalty value in svf */
#define SV_ERR_WRONG_WAIT_TIME_IN_SV				-32	/** Incorrect wait time setting in svf */
#define SV_ERR_SHORT_PIN							-33 /** pin entered is too small */
#define SV_ERR_WRONG_APP1_RSP_LNG_IN_SV				-40 /** app1 response length is wrong */
#define SV_ERR_WRONG_TDES_FLAG_IN_SV				-41 /** app1 TDES flag is not Set up properly. */
#define SV_ERR_APP1_RSP_RHC_TOO_LONG_IN_SV			-43 /** app1 response lenght + rhc length is too big */
#define SV_ERR_WRONG_APP1_CHECK_DIGIT_IN_SV			-44 /** app1 check digit is incompatible with rhc */
#define SV_ERR_WRONG_APP1_RHC_LNG_IN_SV				-45 /** app1 rhc long is too big or too small */
#define SV_ERR_WRONG_APP2_RSP_LNG_IN_SV				-50 /** response length is too big in app2 */
#define SV_ERR_WRONG_APP2_RSP_RHC_LENGTH_IN_SV		-53 /** response + confirmation code is too long in app2 */
#define SV_ERR_WRONG_APP2_CHECK_DIGIT_IN_SV			-54 /** check digit in app2 is incompatible with confirmation code */
#define SV_ERR_WRONG_APP2_RHC_LNG_IN_SV				-55 /** confirmation code length is too big in app2 */
#define SV_ERR_WRONG_APPi_FLAG_IN_SV				-56 /** APPLi Used flag is not Set up properly. */
#define SV_ERR_APPi_TYPE_UNSUPPORTED_IN_SV			-57 /** APPLi type Not supoported.*/
#define SV_ERR_WRONG_DTF_NB_IN_SV					-58 /** Wrong DTF Number set in DV.*/
#define SV_ERR_WRONG_SV_LENGTH_IN_SV				-62 /** wrong sv length in sv */
#define SV_ERR_WRONG_FAD_LENGTH_IN_SV				-63	/** wrong fad length in svf */
#define SV_ERR_WRONG_PIN_CHECK_IN_SV				-64	/** wrong pin check algotythm in svf */
#define SV_ERR_PIN_MIN_LENGTH_OUT_OF_BOUNDS_IN_SV	-65	/** PIN min length out of bounds in svf */
#define SV_ERR_WRONG_PIN_CHANGE_ALLOWED_IN_SV		-66	/** incorrect pin chage allowed value in svf */
#define SV_ERR_WRONG_PIN_FATAL_VALUE_IN_SV			-67	/** incorrect pin fatal value in svf */
#define SV_ERR_WRONG_PIN_WAIT_VALUE_IN_SV			-68	/** incorrect pin wait value in svf */
#define SV_ERR_WRONG_PIN_TIMEOUT_VALUE_IN_SV		-69	/** incorrect pin timeout value in svf */
#define SV_ERR_UNSUPPORTED_SV_VERSION				-70	/** Unsupported SV Version Defintion.*/
#define SV_ERR_UNSUPPORTED_REACTIVATION_FATAL		-71	/** Unsupported Reactivation Fatal Error Count*/
#define SV_ERR_EVENT_REACTIVATION_COUNTER		    -72	/** Unsupported Reactivation Counter Error*/
#define SV_ERR_ONLINE_BANKING_PROFILE			    -73	/** Incorrect online Banking Profile */
#define SV_ERR_ONLINE_BANKING_ACCESS			    -74	/** Incorrect online Banking Access */
#define SV_ERR_ONLINE_SIGNATURE_PROFILE			    -75	/** Incorrect online Signature Profile */
#define SV_ERR_ONLINE_SIGNATURE_ACCESS			    -76	/** Incorrect online Signature Acess */
#define SV_ERR_ONLINE_SERVER_ACTIVATION			    -77	/** Incorrect online Server Activation */

#define INVALID_TDES_DATA_OUT_LENGTH					-99 /** Invalid data output length for TDES decryption*/
#define INVALID_AES_DATA_OUT_LENGTH					-100 /** Invalid data output length for AES decryption*/
#define INVALID_USER_PWD								-101 /** Wrong Weak PWD entered by USER*/
#define INVALID_USER_WEAK_PWD						-102 /** Wrong Weak PWD entered by USER*/
#define INVALID_TDES_MODE							-103 /** INVALID TDES MODE*/
#define INVALID_TDES_DATA_IN_LENGTH					-104 /*  Data In  must be 8 bytes multiple for 3DES cipher*/
#define INVALID_ERC									-105 /*  ERC is Invalid*/
#define INVALID_ENCRYPTION_DECRYPTION_MODE			-106 /** INVALID ENCRYPT/DECRYPT MODE*/
#define INVALID_TDES_KEY_SIZE						-107 /** Cipher key must be 16/24 bytes array for 3DES cipher*/
#define INVALID_AES_DATA_IN_LENGTH					-108 /*  Data In  must be 16 bytes multiple for AES cipher */
#define INVALID_AES_KEY_SIZE							-109 /** Cipher key must be 16/24/32 bytes array for AES cipher*/

#define CHALLENGE_MANDATORY							-110 /*  Challenge is mandatory*/

/*Error message for NULL parameter */
#define INVALID_FULL_ACTIVATION_DATA_POINTER      -130
#define INVALID_STATIC_VECTOR_POINTER             -131
#define INVALID_DYNAMIC_VECTOR_POINTER            -132
#define INVALID_PWD_POINTER                       -133
#define INVALID_DVKEY_POINTER                     -134
#define INVALID_RESP_POINTER                      -135
#define INVALID_RHC_POINTER                       -136
#define INVALID_CHALLENGE_LIST                    -137
#define INVALID_INFO_PARAM_POINTER                -138

#define EBD_INVALID_SESSION_POINTER		-140
#define EBD_INVALID_KEY_HANDLE_POINTER	-141
#define EBD_INVALID_CRYPTO_FCT_POINTER	-142
#define EBD_INVALID_KEY_POINTER			-143

/* Callback Function definition */

#define FCT_POINTER_COUNT 6

#define ENCRYPT_DES            0
#define DECRYPT_DES            1
#define ENCRYPT_3DES           2
#define DECRYPT_3DES           3
#define ENCRYPT_AES128         4
#define DECRYPT_AES128         5


typedef vds_int32 (*pDP4CEBD_Func) (
		void 	*i_pSessionID,
		void 	*i_hKeyHandle,
		void 	*i_pCryptoInfo,
		vds_byte 	*i_Data,
		vds_int32 	i_DataLength,
		vds_byte 	*o_Data,
		vds_int32 	*o_DataLength);

#endif

/*================= Activation Offline =================*/
//! \deprecated Use \ref DPSDK_ActivateOffline or \ref DPSDK_ActivateOfflineWithKey.
SDK_IMPORT(vds_int32) DP4C_Activate(vds_ascii	* i_szStaticVector,
		vds_ascii	* i_szSerialNumberSuffix,
		vds_ascii	* i_szACode1,
		vds_ascii	* i_szACode2,
		vds_ascii	* i_szPWD,
		vds_ascii	* i_szDVKey,
		vds_byte	* io_bXStaticVector,
		vds_byte	* io_bXDynamicVector);

/*================= Activation Offline with ERC =================*/
//! \deprecated Use \ref DPSDK_ActivateOffline or \ref DPSDK_ActivateOfflineWithKey.
SDK_IMPORT(vds_int32) DP4C_ActivateErc(vds_ascii	* i_szStaticVector,
		vds_ascii	* i_szERC,
		vds_ascii	* i_szSerialNumberSuffix,
		vds_ascii	* i_szACode1,
		vds_ascii	* i_szACode2,
		vds_ascii	* i_szPWD,
		vds_ascii	* io_szDVKey,
		vds_byte		* io_bXStaticVector,
		vds_byte		* io_bXDynamicVector);


/*================= Activation Online =================*/
//! \deprecated Use \ref DPSDK_ActivateOnline or \ref DPSDK_ActivateOnlineWithKey.
SDK_IMPORT (vds_int32) DP4C_ActivateEx(	vds_ascii	* i_szXFAD,
		vds_ascii	* i_szCHS,
		vds_ascii	* i_szPWD,
		vds_ascii	* io_szDVKey,
		vds_byte	* io_bXStaticVector,
		vds_byte	* io_bXDynamicVector);


/*================= Activation Online with XERC =================*/
//! \deprecated Use \ref DPSDK_ActivateOnline or \ref DPSDK_ActivateOnlineWithKey.
SDK_IMPORT (vds_int32) DP4C_ActivateXErc(	vds_ascii	* i_szXFAD,
		vds_ascii	* i_szXERC,
		vds_ascii	* i_szCHS,
		vds_ascii	* i_szPWD,
		vds_ascii	* io_szDVKey,
		vds_byte	* io_bXStaticVector,
		vds_byte	* io_bXDynamicVector);


/*================= Generate OTP =================*/
//! \deprecated Use \ref DPSDK_GenerateResponseOnly, \ref DPSDK_GenerateResponseFromChallenge, \ref DPSDK_GenerateResponseOnlyWithKey or \ref DPSDK_GenerateResponseFromChallengeWithKey.
SDK_IMPORT(vds_int32)  DP4C_GenPassword(vds_byte	* i_bXStaticVector,
		vds_byte	* io_bXDynamicVector,
		vds_ascii	* i_Challenge,
		vds_ascii	* i_szDVKey,
		vds_ascii	* o_szResponse,
		vds_ascii	* o_szRHC);

/*================= Generate OTP  with Client/Server Time shift =================*/
//! \deprecated Use \ref DPSDK_GenerateResponseOnly, \ref DPSDK_GenerateResponseFromChallenge, \ref DPSDK_GenerateResponseOnlyWithKey or \ref DPSDK_GenerateResponseFromChallengeWithKey.
SDK_IMPORT(vds_int32)  DP4C_GenPasswordEx(vds_byte	* i_bXStaticVector,
		vds_byte	* io_bXDynamicVector,
		vds_ascii	* i_Challenge,
		vds_ascii	* i_szDVKey,
		vds_int32   i_TimeShiftInSec,
		vds_ascii	* o_szResponse,
		vds_ascii	* o_szRHC);

/*================= Generate OTP with MITMA Challenge=================*/
//! \deprecated Use \ref DPSDK_GenerateResponseOnlyES, \ref DPSDK_GenerateResponseFromChallengeES, \ref DPSDK_GenerateResponseOnlyESWithKey or \ref DPSDK_GenerateResponseFromChallengeESWithKey.
SDK_IMPORT(vds_int32) DP4C_GenPasswordEs(vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*i_Challenge,
		vds_ascii	*i_szDVKey,
		vds_ascii  *i_szSpKey,
		vds_ascii	*o_szResponse,
		vds_ascii	*o_szRHC);

/*================= enerate OTP with MITMA Challenge & Client/Server Time shift =================*/
//! \deprecated Use \ref DPSDK_GenerateResponseOnlyES, \ref DPSDK_GenerateResponseFromChallengeES, \ref DPSDK_GenerateResponseOnlyESWithKey or \ref DPSDK_GenerateResponseFromChallengeESWithKey.
SDK_IMPORT(vds_int32) DP4C_GenPasswordEsEx(	vds_byte	* i_bXStaticVector,
		vds_byte	* io_bXDynamicVector,
		vds_ascii	* i_Challenge,
		vds_ascii	* i_szDVKey,
		vds_ascii   * i_szSpKey,
		vds_int32   i_TimeShiftInSec,
		vds_ascii	* o_szResponse,
		vds_ascii	* o_szRHC);

/*================= Generate Signature =================*/
//! \deprecated Use \ref DPSDK_GenerateSignature or \ref DPSDK_GenerateSignatureWithKey.
SDK_IMPORT(vds_int32)  DP4C_GenSignature(	vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	i_ChallengeList[8][LNG_DTF_MAX],
		vds_ascii	*i_szDVKey,
		vds_ascii	*o_aSignature,
		vds_ascii	*o_aSigConfCode);

/*================= Generate Signature with Client/Server Time shift =================*/
//! \deprecated Use \ref DPSDK_GenerateSignature or \ref DPSDK_GenerateSignatureWithKey.
SDK_IMPORT(vds_int32)  DP4C_GenSignatureEx(	vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	i_ChallengeList[8][LNG_DTF_MAX],
		vds_ascii	*i_szDVKey,
		vds_int32   i_TimeShiftInSec,
		vds_ascii	*o_aSignature,
		vds_ascii	*o_aSigConfCode);


/*================= Generate Signature with MITMA Challenge=================*/
//! \deprecated Use \ref DPSDK_GenerateSignatureES or \ref DPSDK_GenerateSignatureESWithKey.
SDK_IMPORT(vds_int32) DP4C_GenSignatureEs(	vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*i_ChallengeList[8],
		vds_ascii	*i_szDVKey,
		vds_ascii	*i_szSpKey,
		vds_ascii	*o_aSignature,
		vds_ascii	*o_aSigConfCode);

/*================= Generate Signature with MITMA Challenge & Client/Server Time shift =================*/
//! \deprecated Use \ref DPSDK_GenerateSignatureES or \ref DPSDK_GenerateSignatureESWithKey.
SDK_IMPORT(vds_int32) DP4C_GenSignatureEsEx(vds_byte*  i_bXStaticVector,
		vds_byte*  io_bXDynamicVector,
		vds_ascii*  i_ChallengeList[8],
		vds_ascii*  i_szDVKey,
		vds_ascii*  i_szSpKey,
		vds_int32	 i_TimeShiftInSec,
		vds_ascii*	 o_aSignature,
		vds_ascii*	 o_aSigConfCode);

#ifndef _DOC

/*================= Activation Offline embedded cryptographic engine  =================*/
//! \deprecated Use \ref DPSDK_ActivateOfflineEmbedded.
SDK_IMPORT (vds_int32) DP4CEBD_Activate (vds_ascii	*i_szStaticVector,
		vds_ascii	*i_szSerialNumberSuffix,
		vds_ascii	*i_szACode1,
		vds_ascii	*i_szACode2,
		vds_byte	*o_bStaticVector,
		vds_byte	*o_bDynamicVector,
		vds_byte	*o_bKey);


/*================= Activation Online embedded cryptographic engine=================*/
//! \deprecated Use \ref DPSDK_ActivateOnlineEmbedded.
SDK_IMPORT (vds_int32) DP4CEBD_ActivateEx ( vds_ascii	*i_szXFAD,
		vds_ascii	*i_szCHS,
		vds_byte	*o_bKey,
		vds_byte	*o_bStaticVector,
		vds_byte	*o_bDynamicVector);

/*================= Generate Password embedded cryptographic engine =================*/
//! \deprecated Use \ref DPSDK_GenerateResponseOnlyEmbedded or \ref DPSDK_GenerateResponseFromChallengeEmbedded.
SDK_IMPORT(vds_int32) DP4CEBD_GenPassword (void				*i_pSessionID,
		void    			*i_hKeyHandle,
		void				*i_pCryptoInfo,
		void				*i_pDP4CEBD_EncryptFunction[],
		vds_byte			*i_bStaticVector,
		vds_byte			*io_bDynamicVector,
		vds_ascii		*i_szChallenge,
		vds_ascii		*o_szResponse,
		vds_ascii 		*o_szRHC);


/*================= Generate Signature embedded cryptographic engine================*/
//! \deprecated Use \ref DPSDK_GenerateSignatureEmbedded.
SDK_IMPORT(vds_int32) DP4CEBD_GenSignature (void			*i_pSessionID,
		void    		*i_hKeyHandle,
		void			*i_pCryptoInfo,
		void			*i_pDP4CEBD_EncryptFunction[],
		vds_byte		*i_bStaticVector,
		vds_byte		*io_bDynamicVector,
		vds_ascii		i_ChallengeList[8][20],
		vds_ascii		*o_szSignature,
		vds_ascii 		*o_szSigConfCode);

#endif

/*================= Get DP Info =================*/
//! \deprecated Use \ref DPSDK_GetDigipassProperty.
SDK_IMPORT(vds_int32)  DP4C_GetDPInfo(	vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*o_szDPSerNumb,
		vds_ascii	*o_szCounterAPPLI1,
		vds_ascii	*o_szCounterAPPLI2,
		vds_ascii	*o_szdeviceGMTTime);

/*================= Valid and Manage PIN =================*/
//! \deprecated Use \ref DPSDK_ValidatePassword. \warning Password validation is now managed by the DIGIPASS SDK during response generation.
SDK_IMPORT (vds_int32) DP4C_validPWD(vds_byte	*i_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*i_szPWDEntered,
		vds_ascii	*o_szDVKey);

/*================= Change PIN =================*/
//! \deprecated Use \ref DPSDK_ChangePassword.
SDK_IMPORT (vds_int32) DP4C_ChangePWD (	vds_byte	*io_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*i_szOldPWD,
		vds_ascii	*i_szNewPWD );

/*================= Change DVKey =================*/
//! \deprecated Use \ref DPSDK_ChangeEncryptionKey.
SDK_IMPORT(vds_int32) DP4C_ChangeDVKey( vds_byte	*io_bXStaticVector,
		vds_byte	*io_bXDynamicVector,
		vds_ascii	*i_szOldDVKey,
		vds_ascii	*i_szNewDVKey);

/*================= Check if SV is Correct =================*/
//! \deprecated
SDK_IMPORT(vds_int32) DP4C_isSVCorrect( vds_byte	*i_bStaticVector);

//! \deprecated
SDK_IMPORT(vds_int32) DP4C_isSVCorrectEx( vds_ascii	*i_StaticVector);

//! \deprecated Use \ref DPSDK_Encrypt.
SDK_IMPORT(vds_int32) DP4C_vdsTDESCipher (vds_int32 i_Mode,
		vds_byte	*i_bKey,
		vds_byte	*i_bDataIn,
		vds_int32 i_bDataInLength,
		vds_byte	*i_bIV,
		vds_byte	*o_bDataOut);

//! \deprecated Use \ref DPSDK_Encrypt.
SDK_IMPORT(vds_int32) DP4C_Encrypt(void*      ses, /*RFU*/
		vds_int32  mechanism,
		vds_byte  *i_bKey,
		vds_int32  i_bKeyLength,
		vds_byte  *i_bIV,
		vds_int32  i_bIVLength,
		vds_byte  *i_bDataIn,
		vds_int32  i_bDataInLength,
		vds_byte  *o_bDataOut,
		vds_int32 *o_bDataOutLength);

//! \deprecated Use \ref DPSDK_Decrypt.
SDK_IMPORT(vds_int32) DP4C_Decrypt(void*      ses, /*RFU*/
		vds_int32  mechanism,
		vds_byte  *i_bKey,
		vds_int32  i_bKeyLength,
		vds_byte  *i_bIV,
		vds_int32  i_bIVLength,
		vds_byte  *i_bDataIn,
		vds_int32  i_bDataInLength,
		vds_byte  *o_bDataOut,
		vds_int32 *o_bDataOutLength);

//! \deprecated
SDK_IMPORT(vds_int32) DP4C_deriveMKInSV ( vds_byte	*io_bStaticVector,
		vds_ascii	*i_szKey);




/*================= Get Error Text =================*/
//! \deprecated Use \ref DPSDK_GetMessageForReturnCode.
SDK_IMPORT (vds_ascii *)  DP4C_GetErrorText (vds_int32 iErr);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DP4CAPI_H

