/* Copyright(c) 2013 VASCO Data Security, Inc, VASCO Data Security        */
/* International GmbH. All rights reserved. VASCO(R), VACMAN(R),          */
/* IDENTIKEY(R), aXsGUARD(TM), DIGIPASS(R), and "VASCO 'V' logo"(R) are   */
/* registered or unregistered trademarks of VASCO Data Security, Inc.     */
/* and/or VASCO Data Security International GmbH. in the U.S. and other   */
/* countries. 
 */

#import <Foundation/Foundation.h>

static const NSString * SECURESTORAGESDK_VERSION =  @"4.2.0" ;


/**
 * This class provides mecanisms to create a storage, add and remove value, write and delete storage file
 */
@interface SecureStorageSDK : NSObject

/**
 * Initializes a new storage instance by reading an existing storage if available.
 * @param fileName Storage file name. Must not be null nor empty, the max length is 100 and it can only contain alphanumeric characters (along with "-" and "_"). 
 * @param fingerprint Data used to secure the storage. It should be a device-dependent data. Can be null. 
 * @param iterationNumber Indicates the power of the storage encryption. Once set must not be changed. Must be greater than 0.
 * @return A SecureStorageSDK instance.
 * @throws SecureStorageSDKException If an error occurs when initializing the SecureStorageSDK instance.<br/>
 * <br/>The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_NULL if the storage file name is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_INCORRECT_LENGTH if the storage file name has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_INCORRECT_FORMAT if the storage file name contains invalid characters. Must be alphanumeric (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_UNREADABLE_STORAGE if the storage is not readable (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_ITERATION_COUNT_INCORRECT if the iteration number is incorrect, Must be >0 (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(id) initWithFileName:(NSString *)filename useFingerPrint:(NSString *) fingerprint andIterationNumber:(int) iterationNumber ;


/**
 * Writes the storage in the device's persistent memory.
 * @param fingerprint Used to generate an encryption key. Can be null.
 * @param iterationNumber Number of loops used to calculate the encryption key. Must be > 0.
 * @throws SecureStorageSDKException If an error occurs when writing data on the device's persistent storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_ITERATION_COUNT_INCORRECT if the iteration number is incorrect, Must be >0 (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(void) writeWithFingerPrint:(NSString *)fingerPrint andIterationNumber:(int)iterationNumber ;

/**
 * Puts a string into the storage. If the key already exists, the value is updated.
 * @param key Used to identify a storage value. Must not be null nor empty, the max length is 100} and it can only contain alphanumeric characters. 
 * @param value String to store. Must not be null and cannot contain characters "¨" and "§".
 * @throws SecureStorageSDKException If an error occurs when adding a value to the storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_NULL if the key is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_LENGTH if the key has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_FORMAT if the key contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_VALUE_NULL if the value is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_VALUE_INCORRECT_FORMAT if the value contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(void) putString:(NSString *)value forKey:(NSString *)key ;

/**
 * Puts a bytes array into the storage. If the key already exists, the value is updated.
 * @param key Used to identify a storage value. Must not be null nor empty, the max length is 100} and it can only contain alphanumeric characters. 
 * @param value Bytes array to store. Must not be null.
 * @throws SecureStorageSDKException If an error occurs when adding a value to the storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_NULL if the key is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_LENGTH if the key has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_FORMAT if the key contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_VALUE_NULL if the value is null (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(void) putBytes:(NSData *)value forKey:(NSString *)key ;

/**
 * Removes a value from the storage.
 * @param key Key to retrieve value. Must not be null, must not be empty, key.length() must be <= 100} and can only contain alphanumeric characters.
 * @throws SecureStorageSDKException If an error occurs when removing a value from the storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_NULL if the key is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_LENGTH if the key has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_FORMAT if the key contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_UNKNOWN_KEY if the key is unknown (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(void) removeForKey:(NSString *)key  ;

/**
 * Gets a string from the storage.
 * @param key Key to retrieve value. Must not be null, must not be empty, key.length() must be <= 100} and can only contain alphanumeric characters.
 * @return The string value.
 * @throws SecureStorageSDKException If an error occurs when getting a value from the storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_NULL if the key is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_LENGTH if the key has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_FORMAT if the key contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_UNKNOWN_KEY if the key is unknown (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_INCORRECT_GETTER if the requested value is a bytes array (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(NSString *) getStringForKey:(NSString *)key  ;

/**
 * Gets a bytes array from the storage.
 * @param key Key to retrieve value. Must not be null, must not be empty, key.length() must be <= 100} and can only contain alphanumeric characters.
 * @return The bytes array value.
 * @throws SecureStorageSDKException If an error occurs when getting a value from the storage.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_NULL if the key is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_LENGTH if the key has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_KEY_INCORRECT_FORMAT if the key contains invalid characters (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_UNKNOWN_KEY if the key is unknown (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_INCORRECT_GETTER if the requested value is a bytes array (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(NSData *) getBytesForKey:(NSString *)key  ;

/**
 * Gets all the data from the storage.
 * @return The data contained in the storage.
 * @throws SecureStorageSDKException If an error occurs when getting all the data from the storage.<br/>
 * The exception contains the following error code: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
-(NSDictionary *) getAll ;

/**
 * Deletes a Secure Storage instance.
 * @param fileName Name of the data file. Must not be null, must not be empty, filename.length() must be <= 100 and can only contain alphanumeric characters (along with "-" and "_").
 * @throws SecureStorageSDKException If an error occurs when deleting a Secure Storage instance.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>SecureStorageSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_NULL if the storage file name is null (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_INCORRECT_LENGTH if the storage file name has an incorrect length (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_STORAGE_NAME_INCORRECT_FORMAT if the storage file name contains invalid characters. Must be alphanumeric (see SecureStorageSDKErrorCodes.h).</li>
 *  <li>SecureStorageSDKErrorCodes_UNKNOWN_STORAGE if the storage does not exist (see SecureStorageSDKErrorCodes.h).</li>
 * </ul>
 */
+(void) deleteWithFileName:(NSString *)filename ;


/*!
 * \mainpage Secure Storage SDK API - Programmer documentation
 * \brief The SecureStorageSDK object provides the entry points of the Secure Storage SDK framework API:
 * <ul>
 *  <li>Initialize, read and delete a storage (see SecureStorageSDK.h).</li>
 *  <li>Put, get and remove the values in the storage (see SecureStorageSDK.h).</li>
 * </ul>
 * Copyright 1999 - 2013. VASCO DATA SECURITY. All Rights Reserved.
 * @version 4.2.0
 */

@end
