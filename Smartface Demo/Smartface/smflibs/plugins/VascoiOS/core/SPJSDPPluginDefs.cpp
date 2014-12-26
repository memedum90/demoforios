//
//  SPJSDPPluginDefs.cpp
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//

#include <iosfwd>
#include "SPJSDPPluginDefs.h"
#include "DPPlugin.h"

const int kActivateOnline_Success = 1;
const int kActivateOnline_Error = 2;
const int kValidatePassword_Success = 3;
const int kValidatePassword_Error = 4;
const int kGenerateOTP_Success = 5;
const int kGenerateOTP_Error = 6;
const int kGenerateDerivationCode_Success = 7;
const int kGenerateDerivationCode_Error = 8;
const int kGeneratePassword_Success = 9;
const int kGeneratePassword_Error = 10;
const int kGetInfo_Success = 11;
const int kGetInfo_Error = 12;
const int kInitialize_Registration_Data_Success = 13;
const int kInitialize_Registration_Data_Error = 14;
const int kDecrypt_Activation_Data_Success = 15;
const int kDecrypt_Activation_Data_Error = 16;
const int kValidate_Shared_Data_Success = 17;
const int kValidate_Shared_Data_Error = 18;
const int kChange_Password_Success = 19;
const int kChange_Password_Error = 20;

JSValueRef js_activate_online(JSContextRef ctx,
                                JSObjectRef function,
                                JSObjectRef thisObject,
                                size_t argumentCount,
                                const JSValueRef arguments[],
                                JSValueRef* exception){
    DPPlugin* dp = DPPlugin::getInstance();
    if (argumentCount == 1){ // activate online method takes object as a parameter
        // initialization for input parameters
        char *password = NULL, *xfad = NULL, *xerc = NULL, *activationPassword = NULL, *nonce = NULL, *platformFingerPrint = NULL;
        JSObjectRef arrayObject = (JSObjectRef)arguments[0];
        // reading input parameters and setting callback functions
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamPassword)){
            password = DPPlugin::getJSArrayString(ctx, arrayObject, kParamPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamXfad)){
            xfad = DPPlugin::getJSArrayString(ctx, arrayObject, kParamXfad, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamXerc)){
            xerc = DPPlugin::getJSArrayString(ctx, arrayObject, kParamXerc, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamActivationPassword)){
            activationPassword = DPPlugin::getJSArrayString(ctx, arrayObject, kParamActivationPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamNonce)){
            nonce = DPPlugin::getJSArrayString(ctx, arrayObject, kParamNonce, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamPlatformFingerPrint)){
            platformFingerPrint = DPPlugin::getJSArrayString(ctx, arrayObject, kParamPlatformFingerPrint, NULL);
        }
        
        dp->functionObjectMap[kActivateOnline_Success] = NULL;
        dp->functionObjectMap[kActivateOnline_Error] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, arrayObject, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kActivateOnline_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, arrayObject, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kActivateOnline_Error] = callback;
        }
        if (password != NULL && xfad != NULL && xerc != NULL && activationPassword != NULL && nonce != NULL && platformFingerPrint != NULL){
            dp->activateOnline(password, xfad, xerc, activationPassword, nonce, platformFingerPrint);
        } else {
            printf("Error: missing parameters\n");
        }
        delete password; /* delete all args here */
        delete xfad;
        delete xerc;
        delete activationPassword;
        delete nonce;
        delete platformFingerPrint;
    }
    
    return JSValueMakeNull(ctx);
}


JSValueRef js_validate_password(JSContextRef ctx,
                                JSObjectRef function,
                                JSObjectRef thisObject,
                                size_t argumentCount,
                                const JSValueRef arguments[],
                                JSValueRef* exception){
    DPPlugin* dp = DPPlugin::getInstance();
    if (argumentCount == 1){
        char *password = NULL, *platformFingerprint = NULL;
        JSObjectRef arrayObject = (JSObjectRef)arguments[0];
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamPassword)){
            password = DPPlugin::getJSArrayString(ctx, arrayObject, kParamPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamPlatformFingerPrint)){
            platformFingerprint = DPPlugin::getJSArrayString(ctx, arrayObject, kParamPlatformFingerPrint, NULL);
        }
        
        dp->functionObjectMap[kValidatePassword_Error] = NULL;
        dp->functionObjectMap[kValidatePassword_Success] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, arrayObject, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kValidatePassword_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, arrayObject, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, arrayObject, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kValidatePassword_Error] = callback;
        }
        if (password != NULL && platformFingerprint != NULL){
            dp->validatePassword(password,platformFingerprint);
        } else {
            printf("Error: missing parameters\n");
        }
        
        delete password; /* delete all args here */
        delete platformFingerprint;
    }
    
    return JSValueMakeNull(ctx);
}



JSValueRef js_generate_otp(JSContextRef ctx,
                           JSObjectRef function,
                           JSObjectRef thisObject,
                           size_t argumentCount,
                           const JSValueRef arguments[],
                           JSValueRef* exception){
    DPPlugin* dp = DPPlugin::getInstance();
    char *password = NULL, *timeShift = NULL, *fingerPrint = NULL;
    if (argumentCount == 1){
        JSObjectRef ref = (JSObjectRef)arguments[0];
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamPassword)){
            password = DPPlugin::getJSArrayString(ctx, ref, kParamPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamTimeShift)){
            timeShift = DPPlugin::getJSArrayString(ctx, ref, kParamTimeShift, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamPlatformFingerPrint)){
            fingerPrint = DPPlugin::getJSArrayString(ctx, ref, kParamPlatformFingerPrint, NULL);
        }
        
        dp->functionObjectMap[kGenerateOTP_Success] = NULL;
        dp->functionObjectMap[kGenerateOTP_Error] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGenerateOTP_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGenerateOTP_Error] = callback;
        }
        if (password != NULL && timeShift != NULL && fingerPrint != NULL){
            dp->genereateOTP(password, timeShift, fingerPrint);
        }else{
            printf("Error: missing parameters\n");
        }
    }
    delete password;
    delete timeShift;
    delete fingerPrint;
    
    return JSValueMakeNull(ctx);
    
}

JSValueRef js_generate_derivation_code(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception){
    DPPlugin* dp = DPPlugin::getInstance();
    char *password = NULL, *timeShift = NULL, *fingerPrint = NULL, *challenge = NULL;
    if (argumentCount == 1){
        JSObjectRef ref = (JSObjectRef)arguments[0];
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamPassword)){
            password = DPPlugin::getJSArrayString(ctx, ref, kParamPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamTimeShift)){
            timeShift = DPPlugin::getJSArrayString(ctx, ref, kParamTimeShift, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamPlatformFingerPrint)){
            fingerPrint = DPPlugin::getJSArrayString(ctx, ref, kParamPlatformFingerPrint, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamChallenge)){
            challenge = DPPlugin::getJSArrayString(ctx, ref, kParamChallenge, NULL);
        }
        
        dp->functionObjectMap[kGenerateDerivationCode_Success] = NULL;
        dp->functionObjectMap[kGenerateDerivationCode_Error] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGenerateDerivationCode_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGenerateDerivationCode_Error] = callback;
        }
        if (password != NULL && timeShift != NULL && fingerPrint != NULL && challenge != NULL){
            dp->generateDerivationCode(password, timeShift, fingerPrint, challenge);
        }else{
            printf("Error: missing parameters\n");
        }
    }
    delete password;
    delete timeShift;
    delete fingerPrint;
    delete challenge;
    
    return JSValueMakeNull(ctx);
}

JSValueRef js_change_password(JSContextRef ctx,
                               JSObjectRef function,
                               JSObjectRef thisObject,
                               size_t argumentCount,
                               const JSValueRef arguments[],
                               JSValueRef* exception){
    char *oldPwd = NULL, *newPwd = NULL, *platformFingerprint = NULL;
    DPPlugin *dp = DPPlugin::getInstance();
    if (argumentCount == 1){
        JSObjectRef ref = (JSObjectRef)arguments[0];
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOldPassword)){
            oldPwd = DPPlugin::getJSArrayString(ctx, ref, kParamOldPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamNewPassword)){
            newPwd = DPPlugin::getJSArrayString(ctx, ref, kParamNewPassword, NULL);
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamPlatformFingerPrint)){
            platformFingerprint = DPPlugin::getJSArrayString(ctx, ref, kParamPlatformFingerPrint, NULL);
        }
        
        dp->functionObjectMap[kChange_Password_Success] = NULL;
        dp->functionObjectMap[kChange_Password_Error] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kChange_Password_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kChange_Password_Error] = callback;
        }
        if (oldPwd != NULL && newPwd != NULL && platformFingerprint != NULL){
            dp->changePassword(oldPwd, newPwd, platformFingerprint);
        }else{
            printf("Error: missing parameters\n");
        }
    }
    delete oldPwd;
    delete newPwd;
    delete platformFingerprint;
    JSValueRef ref = JSValueMakeNull(ctx);
    return ref;
}

JSValueRef js_get_info(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception){
    DPPlugin *dp = DPPlugin::getInstance();
    if (argumentCount == 1){
        JSObjectRef ref = (JSObjectRef)arguments[0];
        
        dp->functionObjectMap[kGetInfo_Error] = NULL;
        dp->functionObjectMap[kGetInfo_Success] = NULL;
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnSuccess)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnSuccess);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGetInfo_Success] = callback;
        }
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamOnErrror)){
            JSObjectRef callback = DPPlugin::getJSArrayObject(ctx, ref, kParamOnErrror);
            dp->protectCallbackOnMainThread(callback);
            dp->functionObjectMap[kGetInfo_Error] = callback;
        }
        dp->getInfo();
    }
    return JSValueMakeNull(ctx);
}

JSValueRef js_compute_timeshift(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception){
    char *serverTime = NULL;
    DPPlugin *dp = DPPlugin::getInstance();
    int shift;
    if (argumentCount == 1 && JSValueIsObject(ctx,arguments[0])){
        JSObjectRef ref = (JSObjectRef)arguments[0];
        if (DPPlugin::hasJSArrayProperty(ctx, ref, kParamServerTime)){
            serverTime = DPPlugin::getJSArrayString(ctx, ref, kParamServerTime, NULL);
        }
        if (serverTime != NULL){
            shift = dp->computeTimeShift(serverTime);
            return JSValueMakeNumber(ctx, shift);
        }else{
            printf("Error: missing parameters\n");
        }
    }
    delete serverTime;
    return JSValueMakeNull(ctx);
}

JSValueRef js_initialize_registration_dataV2(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception)
{
	JSValueRef retval;
    if (argumentCount == 1 && JSValueIsObject(ctx,arguments[0]))
    {
    	DPPlugin *dp = DPPlugin::getInstance();
    	JSObjectRef obj = JSValueToObject(ctx,arguments[0],0);
    	char* activationPassword = 0;
    	JSObjectRef onSuccess = 0;
    	JSObjectRef onError = 0;
    	if (DPPlugin::hasJSArrayProperty(ctx, obj, kParamActivationPassword)){
			activationPassword = DPPlugin::getJSArrayString(ctx, obj, kParamActivationPassword, NULL);
		}
        
        dp->functionObjectMap[kInitialize_Registration_Data_Success] = NULL;
        dp->functionObjectMap[kInitialize_Registration_Data_Error] = NULL;
    	if (DPPlugin::hasJSArrayProperty(ctx, obj, kParamOnSuccess)){
    		JSValueRef val = DPPlugin::getJSArrayObject(ctx,obj,kParamOnSuccess);
    		if (JSValueIsObject(ctx,val))
    		{
    			onSuccess = JSValueToObject(ctx,val,0);
                dp->protectCallbackOnMainThread(onSuccess);
                dp->functionObjectMap[kInitialize_Registration_Data_Success] = onSuccess;
    		}
    	}
    	if (DPPlugin::hasJSArrayProperty(ctx, obj, kParamOnErrror)){
			JSValueRef val = DPPlugin::getJSArrayObject(ctx,obj,kParamOnErrror);
			if (JSValueIsObject(ctx,val))
			{
				onError = JSValueToObject(ctx,val,0);
                dp->protectCallbackOnMainThread(onError);
                dp->functionObjectMap[kInitialize_Registration_Data_Error] = onError;
			}
		}
    	if (activationPassword)
    	{
    		dp->initializeRegistrationDataV2(activationPassword,onSuccess,onError);
    		delete[] activationPassword;
    	}
    	else
    	{
    		if (onError)
    		{
    			const char* json = "{ message:'activationPassword is not defined.' }";
    			int len = strlen(json) + 40;
				char* buf = new char[len];
				memset(buf,0,len);
				sprintf(buf, "(function(){return %s;})()", json);
				JSStringRef scriptJS = JSStringCreateWithUTF8CString(buf);
				JSValueRef exception = 0;
				JSValueRef cbarguments[] = {JSValueMakeNull(ctx)};
				cbarguments[0] = JSEvaluateScript(ctx,scriptJS,0,0,0,&exception);
    			JSObjectCallAsFunction(ctx,onError,0,1,cbarguments,0);
    			JSStringRelease(scriptJS);
    		}
    	}
    	retval = JSValueMakeBoolean(ctx,true);
    }
    else
    {
    	retval = JSValueMakeBoolean(ctx,false);
    }
    return retval;
}



JSValueRef js_decrypt_activation_data(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception)
{
	JSValueRef retval;
	if (argumentCount == 1 && JSValueIsObject(ctx,arguments[0]))
	{
        DPPlugin *dp = DPPlugin::getInstance();
		JSObjectRef arrObj = JSValueToObject(ctx,arguments[0],0);
		char* chsKey = dp->getJSArrayString(ctx,arrObj,"chsKey",0);
		char* clientPrivateKey = dp->getJSArrayString(ctx,arrObj,"clientPrivateKey",0);
		char* encryptedServerPublicKey = dp->getJSArrayString(ctx,arrObj,"encryptedServerPublicKey",0);
		char* encryptedNonces = dp->getJSArrayString(ctx,arrObj,"encryptedNonces",0);
		char* xfad = dp->getJSArrayString(ctx,arrObj,"xfad",0);
		char* xerc = dp->getJSArrayString(ctx,arrObj,"xerc",0);
		char* clientNonce = dp->getJSArrayString(ctx,arrObj,"clientNonce",0);
		char* serverInitialVector = dp->getJSArrayString(ctx,arrObj,"serverInitialVector",0);
        
        dp->functionObjectMap[kDecrypt_Activation_Data_Success] = NULL;
        dp->functionObjectMap[kDecrypt_Activation_Data_Error] = NULL;
    	JSObjectRef onSuccess = dp->getJSArrayObject(ctx,arrObj,"onSuccess");
        dp->protectCallbackOnMainThread(onSuccess);
        dp->functionObjectMap[kDecrypt_Activation_Data_Success] = onSuccess;
    	JSObjectRef onError = dp->getJSArrayObject(ctx,arrObj,"onError");
        dp->protectCallbackOnMainThread(onError);
        dp->functionObjectMap[kDecrypt_Activation_Data_Error] = onError;
        

    	if (chsKey && clientPrivateKey && encryptedServerPublicKey && encryptedNonces && xfad && xerc && clientNonce && serverInitialVector && onSuccess)
    	{

    		dp->decryptActivationData(chsKey,clientPrivateKey,encryptedServerPublicKey,encryptedNonces,xfad,xerc,clientNonce,serverInitialVector,onSuccess,onError);
    		retval = JSValueMakeBoolean(ctx,true);
    	}
    	else
    	{
    		retval = JSValueMakeBoolean(ctx,false);
    	}
    	if (chsKey) delete[] chsKey;
    	if (clientPrivateKey) delete[] clientPrivateKey;
    	if (encryptedServerPublicKey) delete[] encryptedServerPublicKey;
    	if (encryptedNonces) delete[] encryptedNonces;
    	if (xfad) delete[] xfad;
    	if (xerc) delete[] xerc;
    	if (clientNonce) delete[] clientNonce;
    	if (serverInitialVector) delete[] serverInitialVector;
	}
	else
	{
		retval = JSValueMakeBoolean(ctx,false);
	}
	return retval;
}

JSValueRef js_validate_shared_data_checksum(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception)
{
    DPPlugin *dp = DPPlugin::getInstance();
	JSValueRef retval;
	if (argumentCount == 1 && JSValueIsObject(ctx,arguments[0]))
	{
		JSObjectRef arrObj = JSValueToObject(ctx,arguments[0],0);
		char* activationPassword = DPPlugin::getJSArrayString(ctx,arrObj,"activationPassword",0);
        
        dp->functionObjectMap[kValidate_Shared_Data_Success] = NULL;
        dp->functionObjectMap[kValidate_Shared_Data_Error] = NULL;
    	JSObjectRef onSuccess = DPPlugin::getJSArrayObject(ctx,arrObj,"onSuccess");
        dp->protectCallbackOnMainThread(onSuccess);
        dp->functionObjectMap[kValidate_Shared_Data_Success] = onSuccess;
    	JSObjectRef onError = DPPlugin::getJSArrayObject(ctx,arrObj,"onError");
        dp->protectCallbackOnMainThread(onError);
        dp->functionObjectMap[kValidate_Shared_Data_Error] = onError;

    	if ( activationPassword && onSuccess)
    	{

    		dp->validateSharedDataChecksum(activationPassword,onSuccess,onError);
    		retval = JSValueMakeBoolean(ctx,true);
    	}
    	else
    	{
    		retval = JSValueMakeBoolean(ctx,false);
    	}
    	if (activationPassword) delete[] activationPassword;
	}
	else
	{
		retval = JSValueMakeBoolean(ctx,false);
	}
	return retval;
}
