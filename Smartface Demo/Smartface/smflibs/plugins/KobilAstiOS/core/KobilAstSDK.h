//
//  KobilAstSDK.h
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#ifndef __KobilAstSDK__
#define __KobilAstSDK__

#include <vector>
#include <string>

#if defined (__APPLE__) && !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#include "inc/JavaScriptCore.h"
#endif

#include <map>

#ifdef ANDROID_NDK
#include <jni.h>
#endif

#include "KobilAstEnums.h"

class KobilAstSDK {
public:
	KobilAstSDK();
	virtual ~KobilAstSDK();
    
    JSObjectRef GetKobilJSObjectRef(JSContextRef ctx);
    void SetListener(JSContextRef ctx, JSObjectRef listener);
    static void FactoryFreeAst();
    
#ifdef ANDROID_NDK
	static std::map<pthread_t,JNIEnv*> *envMap;
	static jobject pluginImpObject;
	static JNIEnv* GetJNIEnv();
	void SetContextRef(JSContextRef ctx);
	jobject objRef;
	void LoadAstSDK();
#endif

    /**
     * SDK Functions
     */
    KAstStatus init(const char *locale, const char *version, const char *appName, KAstLogLevel logLevel);
    void doActivation(KAstDeviceType deviceType, const char *pin, const char *userId, const char *activationCode);
    void doLogin(KAstDeviceType deviceType, const char *pin, const char *userId);
    void doPinChangeRequest(KAstDeviceType deviceType);
    void doPinChange(KAstDeviceType deviceType, KAstConfirmation confirm, const char *currentPin, const char *newPin);
    void doSetPropertyRequest(KAstDeviceType deviceType);
    void doSetProperty(KAstDeviceType deviceType, const char *propertyKey, const char *propertyData, KAstPropertyType propertyType, KAstPropertyOwner propertyOwner, int propertyTTL, KAstPropertyFlag propertyFlag);
    void doTransaction(KAstDeviceType deviceType, KAstConfirmation confirmation, const char *displayData);
    void doDeactivate(const char *userId);
    KAstStatus resume();
    void suspend();
    int exit(int errorCode);
    
    /**
     * SDK Callbacks
     */
    void onActivationBegin(KAstDeviceType deviceType);
    void onActivationEnd(KAstDeviceType deviceType, KAstStatus status);
    void onLoginBegin(KAstDeviceType deviceType, std::vector<std::string> userIdList);
    void onLoginEnd(KAstDeviceType deviceType, KAstStatus status, const char *loginOtp, const char *userId, int retryCounter, int retryDelay);
    void onPinChangeBegin(KAstDeviceType deviceType, KAstStatus status);
    void onPinChangeEnd(KAstDeviceType deviceType, KAstStatus status, int retryCounter);
    void onTransactionBegin(KAstDeviceType deviceType, const char *displayData, KAstConfirmationType confirmationType);
    void onTransactionEnd(KAstDeviceType deviceType, KAstStatus status);
    void onAlert(KAstDeviceType deviceType, unsigned int subSystem, unsigned int errorCode);
    void onSetPropertyBegin(KAstDeviceType deviceType, KAstStatus status);
    void onSetPropertyEnd(KAstDeviceType deviceType, KAstStatus status, uint32_t subSystem, uint32_t errorCode);
    void onDeactivateEnd(KAstStatus status, std::vector<std::string> userIdList);
    
    void *getAppConfigData();

    
    /**
     * JavaScriptCore Calls
     */
    void RunJavaScriptSmartface(JSContextRef ctx, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[]);

private:
    JSContextRef jsContextRef;
	JSObjectRef kobilAstObjectRef;
    JSObjectRef kobilAstSdkListenerRef;
    
    void *mySDK;
    void *sdkListener;
};

#endif /* __KobilAstSDK__ */
