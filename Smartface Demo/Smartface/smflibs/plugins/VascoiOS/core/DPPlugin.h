//
//  DPPlugin.h
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//



#ifndef __Smartface__DPPlugin__
#define __Smartface__DPPlugin__

#include <map>
#include <iostream>
#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

#include "DP4Capi.h"
#ifdef ANDROID_NDK
#include <jni.h>
#endif
#define DBFINGERPRINT "smartfacefingerprint2013"
#define FILESTATICVECTORLENGTH "sl.txt"     // filename for storing static vector length
#define FILEDYNAMICVECTORLENGTH "dl.txt"    // filename for storing dynamic vector length
#define KEY_STATIC_VECTOR "staticVector"        // key for static vector storate (SecurStorageSDK)
#define KEY_DYNAMIC_VECTOR "dynamicVector"      // key for dymanic vector storate (SecurStorageSDK)





struct DPInfo{
    vds_byte status;
    vds_byte version;
    vds_byte fatalCounter;
    vds_word32 appEventCounter;
    std::string serial;
};

/*
 
 @desc Digipass Plugin class
 
*/

class DPPlugin {
public:
    DPPlugin();
    ~DPPlugin();
#ifdef ANDROID_NDK
	jobject pluginImpObject;
	jmethodID getBytes;
	jmethodID putBytes;
	jmethodID initializeRegistrationDataV2JavaFunction;
	jmethodID decryptActivationDataJavaFunction;
	jmethodID validateSharedDataChecksumJavaFunction;
	std::map<pthread_t,JNIEnv*> *envMap;
	JNIEnv* GetJNIEnv();
#endif
    static DPPlugin* getInstance();
    
    static bool saveFileToDocuments(const char* filename, char* data, int len);
    static char* readFileFromDocuments(const char* filename);
    static void secureSave(const char* key, vds_byte* data, int len);
    static char* secureRead(const char* key);
    static bool readVectors(vds_byte* staticVector, int* staticVectorLength,vds_byte* dynamicVector, int* dynamicVectorLength);
    static const char* generateErrorMessage(int errorCode);
    
    
    void activateOnline(char* password, char* xfad, char* xerc, char* activationPassword, char* nonce, char* platformFingerprint);
    void validatePassword(char* pwd,char* platformFingerprint);
    void genereateOTP(char* pwd, char* timeShift, char* platformFingerprint);
    void changePassword(char* oldPwd, char* newPwd, char* platformFingerprint);
    void generateDerivationCode(char* pwd, char* timeShift, char* platformFingerprint, char* challenge);
    void getInfo();
    int computeTimeShift(char* serverTime);
    void initializeRegistrationDataV2(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError);
    /**
     * onError can be null. all other params will be non null parameter
     * onsuccess json sample is:
     *
     *  {
         fad:"",
		 erc:"",
		 encryptedServerNonce:"",
		 centInitialVector:""
		}

	 * on error json sample is:
	 *  {
	 *    message:""
	 *  }
     *
     */
    void decryptActivationData(const char* chsKey,const char* clientPrivateKey,const char* encryptedServerPublicKey,const char* encryptedNonces,const char* xfad,const char* xerc,const char* clientNonce,const char* serverInitialVector,JSObjectRef onSuccess,JSObjectRef onError);
    /**
     * activationPassword and onSuccess will be always non null
     * onError can be null
     *
     * onSuccess json is empty
     *
     * onError sample is:
     * {
     *    message:""
     * }
     */
    void validateSharedDataChecksum(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError);
    
    void protectCallbackOnMainThread(JSObjectRef objectRef);
    void unProtectCallbackOnMainThread(JSObjectRef objectRef);
public:
    JSContextRef jsContext;                     // JSContext for communication between plugin and player
    
    std::map<int, JSObjectRef> functionObjectMap;
    
    static bool hasJSArrayProperty(JSContextRef ctx, JSObjectRef arrObject, const char* propertyName);
    static JSObjectRef getJSArrayObject(JSContextRef ctx, JSObjectRef arrObject, const char* propertyName);
    static char* getJSArrayString(JSContextRef ctx, JSObjectRef arrObject, const char* propertyName, const char* defaultValue);

};


#endif /* defined(__Smartface__DPPlugin__) */
