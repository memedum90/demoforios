//
//  KobilAstSDK.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include "KobilAstSDK.h"
#include "SpJSKobilAstSDK.h"

JSObjectRef KobilAstSDK::GetKobilJSObjectRef(JSContextRef ctx) {
    if (!kobilAstObjectRef) {
        JSClassRef classDef = JSClassCreate(&spjskobilastsdk_def);
        kobilAstObjectRef = JSObjectMake(ctx, classDef, (void*)this);
        JSClassRelease(classDef);

        jsContextRef = ctx;
    }
    return kobilAstObjectRef;
}

void KobilAstSDK::SetListener(JSContextRef ctx, JSObjectRef listener) {
    if (kobilAstSdkListenerRef) {
        JSValueUnprotect(ctx, kobilAstSdkListenerRef);
    }
    kobilAstSdkListenerRef = listener;
    JSValueProtect(ctx, kobilAstSdkListenerRef);
}

/**
 * SDK Callbacks
 */
void KobilAstSDK::onActivationBegin(KAstDeviceType deviceType) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onActivationBegin");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d};})()", deviceType);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onActivationEnd(KAstDeviceType deviceType, KAstStatus status) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onActivationEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d};})()", deviceType, status);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onLoginBegin(KAstDeviceType deviceType, std::vector<std::string> userIdList) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onLoginBegin");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d};})()", deviceType);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                // Construct userIdList array
                int userIdCount = userIdList.size();
                JSValueRef userIdStringRefs[userIdCount];
                for (int i = 0; i < userIdCount; ++i) {
                    JSStringRef userIdRef = JSStringCreateWithUTF8CString(userIdList[i].c_str());
                    userIdStringRefs[i] = JSValueMakeString(jsContextRef, userIdRef);
                    JSStringRelease(userIdRef);
                }
                JSObjectRef userIdArrayObject = JSObjectMakeArray(jsContextRef, userIdCount, userIdStringRefs, NULL);

                JSStringRef userIdsStrRef = JSStringCreateWithUTF8CString("userIdList");
                JSObjectSetProperty(jsContextRef, (JSObjectRef)argumentValue, userIdsStrRef, userIdArrayObject, NULL, NULL);
                JSStringRelease(userIdsStrRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onLoginEnd(KAstDeviceType deviceType, KAstStatus status, const char *loginOtp, const char *userId, int retryCounter, int retryDelay) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onLoginEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[1024];
                memset(buf, 0, 1024);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d, \"loginOtp\" : \"%s\", \"userId\" : \"%s\", \"retryCounter\" : %d, \"retryDelay\" : %d};})()", deviceType, status, loginOtp, userId, retryCounter, retryDelay);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onPinChangeBegin(KAstDeviceType deviceType, KAstStatus status) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onPinChangeBegin");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d};})()", deviceType, status);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onPinChangeEnd(KAstDeviceType deviceType, KAstStatus status, int retryCounter) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onPinChangeEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[256];
                memset(buf, 0, 256);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d, \"retryCounter\" : %d};})()", deviceType, status, retryCounter);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onTransactionBegin(KAstDeviceType deviceType, const char *displayData, KAstConfirmationType confirmationType) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onTransactionBegin");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[1024];
                memset(buf, 0, 1024);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"displayData\" : \"%s\", \"confirmationType\" : %d};})()", deviceType, displayData, confirmationType);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onTransactionEnd(KAstDeviceType deviceType, KAstStatus status) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onTransactionEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d};})()", deviceType, status);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onAlert(KAstDeviceType deviceType, unsigned int subSystem, unsigned int errorCode) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onAlert");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[256];
                memset(buf, 0, 256);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"subSystem\" : %u, \"errorCode\" : %u};})()", deviceType, subSystem, errorCode);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onSetPropertyBegin(KAstDeviceType deviceType, KAstStatus status) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onSetPropertyBegin");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d};})()", deviceType, status);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onSetPropertyEnd(KAstDeviceType deviceType, KAstStatus status, uint32_t subSystem, uint32_t errorCode) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onSetPropertyEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[256];
                memset(buf, 0, 256);
                sprintf(buf, "(function(){return {\"deviceType\" : %d, \"status\" : %d, \"subSystem\" : %u, \"errorCode\" : %u};})()", deviceType, status, subSystem, errorCode);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

void KobilAstSDK::onDeactivateEnd(KAstStatus status, std::vector<std::string> userIdList) {
    if (kobilAstSdkListenerRef) {
        JSStringRef propertyStringRef = JSStringCreateWithUTF8CString("onDeactivateEnd");
        if (JSObjectHasProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef)) {
            JSValueRef functionRef = JSObjectGetProperty(jsContextRef, kobilAstSdkListenerRef, propertyStringRef, NULL);
            if (functionRef) {
                char buf[128];
                memset(buf, 0, 128);
                sprintf(buf, "(function(){return {\"status\" : %d};})()", status);
                JSStringRef bufStringRef = JSStringCreateWithUTF8CString(buf);
                JSValueRef argumentValue = JSEvaluateScript(jsContextRef, bufStringRef, NULL, NULL, 0, NULL);
                JSStringRelease(bufStringRef);
                
                // Construct userIdList array
                int userIdCount = userIdList.size();
                if(userIdCount > 0)
                {
					JSValueRef userIdStringRefs[userIdCount];
					for (int i = 0; i < userIdCount; ++i) {
						JSStringRef userIdRef = JSStringCreateWithUTF8CString(userIdList[i].c_str());
						userIdStringRefs[i] = JSValueMakeString(jsContextRef, userIdRef);
						JSStringRelease(userIdRef);
					}
					JSObjectRef userIdArrayObject = JSObjectMakeArray(jsContextRef, userIdCount, userIdStringRefs, NULL);

					JSStringRef userIdsStrRef = JSStringCreateWithUTF8CString("userIdList");
					JSObjectSetProperty(jsContextRef, (JSObjectRef)argumentValue, userIdsStrRef, userIdArrayObject, NULL, NULL);
					JSStringRelease(userIdsStrRef);
                }

                JSValueRef arguments[] = { argumentValue };
                RunJavaScriptSmartface(jsContextRef, (JSObjectRef)functionRef, kobilAstSdkListenerRef, 1, arguments);
            }
        }
        JSStringRelease(propertyStringRef);
    }
}

#ifdef __ANDROID__
#include "SpBrBase.h"
void KobilAstSDK::RunJavaScriptSmartface(JSContextRef ctx, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[]) {
    SpBrBase::JSObjectCallAsFunctionSafe(ctx, object, thisObject, argumentCount, arguments);
}

#endif
