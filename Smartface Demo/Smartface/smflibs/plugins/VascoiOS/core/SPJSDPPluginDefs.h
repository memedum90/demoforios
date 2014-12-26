//
//  SPJSDPPluginDefs.h
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//

#ifndef __Smartface__SPJSDPPluginDefs__
#define __Smartface__SPJSDPPluginDefs__

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif



#define kDPPluginIdentifier     "DPPLugin"
#define kDataIdentifier     "Data"

#define kMethodActivateOnline "activateOnlineWithFingerprint"
#define kMethodGenerateOTP "generateOTP"
#define kMethodValidatePassword "validatePassword"
#define kMethodChangePassword "changePassword"
#define kMethodGenerateDerivationCode "generateDerivationCode"
#define kMethodComputeTimeShift "computeTimeShift"
#define kMethodInitializeRegistrationDataV2 "initializeRegistrationDataV2"
#define kMethodDecryptActivationData "decryptActivationData"
#define kMethodValidateSharedDataChecksum "validateSharedDataChecksum"
#define kMethodGetInfo "getInfo"

#define kParamOnSuccess "onSuccess"
#define kParamOnErrror "onError"
#define kParamPassword "password"
#define kParamOldPassword "oldPassword"
#define kParamNewPassword "newPassword"
#define kParamServerTime "serverTime"
#define kParamActivationPassword "activationPassword"

#define kParamOTP "otp"
#define kParamCode "code"
#define kParamMessage "message"
#define kParamData "data"

#define kParamXfad "xfad"
#define kParamXerc "xerc"
#define kParamActivationPassword "activationPassword"
#define kParamNonce "nonce"
#define kParamPlatformFingerPrint "platformFingerprint"
#define kParamTimeShift "timeShift"
#define kParamChallenge "challenge"


extern const int kActivateOnline_Success;
extern const int kActivateOnline_Error;
extern const int kValidatePassword_Success;
extern const int kValidatePassword_Error;
extern const int kGenerateOTP_Success;
extern const int kGenerateOTP_Error;
extern const int kGenerateDerivationCode_Success;
extern const int kGenerateDerivationCode_Error;
extern const int kGeneratePassword_Success;
extern const int kGeneratePassword_Error;
extern const int kGetInfo_Success;
extern const int kGetInfo_Error;
extern const int kInitialize_Registration_Data_Success;
extern const int kInitialize_Registration_Data_Error;
extern const int kDecrypt_Activation_Data_Success;
extern const int kDecrypt_Activation_Data_Error;
extern const int kValidate_Shared_Data_Success;
extern const int kValidate_Shared_Data_Error;
extern const int kChange_Password_Success;
extern const int kChange_Password_Error;

JSValueRef js_validate_password(JSContextRef ctx,
                           JSObjectRef function,
                           JSObjectRef thisObject,
                           size_t argumentCount,
                           const JSValueRef arguments[],
                           JSValueRef* exception);


JSValueRef js_activate_online(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_generate_otp(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_generate_derivation_code(JSContextRef ctx,
                           JSObjectRef function,
                           JSObjectRef thisObject,
                           size_t argumentCount,
                           const JSValueRef arguments[],
                           JSValueRef* exception);

JSValueRef js_change_password(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_get_info(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_compute_timeshift(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_initialize_registration_dataV2(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_decrypt_activation_data(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

JSValueRef js_validate_shared_data_checksum(JSContextRef ctx,
                              JSObjectRef function,
                              JSObjectRef thisObject,
                              size_t argumentCount,
                              const JSValueRef arguments[],
                              JSValueRef* exception);

#endif /* defined(__Smartface__SPJSDPPluginDefs__) */
