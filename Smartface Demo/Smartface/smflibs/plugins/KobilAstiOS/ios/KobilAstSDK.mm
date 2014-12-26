//
//  KobilAstSDK.mm
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import "AstSdkFactory.h"
#import "KobilSDKListener.h"

#include "KobilAstSDK.h"
#include "SpJSKobilDefs.h"
#include "SpJSKobilAstSDK.h"
#include "KobilAstSDKObject.h"

#if defined (__APPLE__)
#if !defined(SPRAT_IOSPROJECT_DEBUG)
#include <iOSPlayer.framework/Headers/inc/ESpratIOSPlayer.h>
#else
#include "ESpratIOSPlayer.h"
#endif
#endif


KobilAstSDK::KobilAstSDK() {
    jsContextRef = NULL;
    kobilAstObjectRef = NULL;
    kobilAstSdkListenerRef = NULL;
    sdkListener = [[SDKListener alloc] init];
    [AstSdkFactory FreeAst];
    mySDK = [AstSdkFactory CreateAst:(SDKListener *)sdkListener];
    [(SDKListener *)sdkListener setMySDK:this];
}

KobilAstSDK::~KobilAstSDK() {
    if (kobilAstSdkListenerRef) {
        JSValueUnprotect(jsContextRef, kobilAstSdkListenerRef);
    }
}

void KobilAstSDK::FactoryFreeAst() {
    [AstSdkFactory FreeAst];
}

KAstStatus KobilAstSDK::init(const char *locale, const char *version, const char *appName, KAstLogLevel logLevel) {
    KAstStatus returnCode = (KAstStatus)[(KobilAstSDKIOS *)mySDK init:[NSString stringWithCString:locale encoding:NSUTF8StringEncoding]
                                           version:[NSString stringWithCString:version encoding:NSUTF8StringEncoding]
                                           appName:[NSString stringWithCString:appName encoding:NSUTF8StringEncoding]
                                          logLevel:(AstLogLevel)logLevel];
    return returnCode;
}

void KobilAstSDK::doActivation(KAstDeviceType deviceType, const char *pin, const char *userId, const char *activationCode) {
    [(KobilAstSDKIOS *)mySDK doActivation:(AstDeviceType)deviceType
                                      pin:[NSString stringWithCString:pin encoding:NSUTF8StringEncoding]
                                   userId:[NSString stringWithCString:userId encoding:NSUTF8StringEncoding]
                           activationCode:[NSString stringWithCString:activationCode encoding:NSUTF8StringEncoding]];
}

void KobilAstSDK::doLogin(KAstDeviceType deviceType, const char *pin, const char *userId) {
    [(KobilAstSDKIOS *)mySDK doLogin:(AstDeviceType)deviceType
                                 pin:[NSString stringWithCString:pin encoding:NSUTF8StringEncoding]
                              userId:[NSString stringWithCString:userId encoding:NSUTF8StringEncoding]];
}

void KobilAstSDK::doPinChangeRequest(KAstDeviceType deviceType) {
    [(KobilAstSDKIOS *)mySDK doPinChangeRequest:(AstDeviceType)deviceType];
}

void KobilAstSDK::doPinChange(KAstDeviceType deviceType, KAstConfirmation confirm, const char *currentPin, const char *newPin) {
    [(KobilAstSDKIOS *)mySDK doPinChange:(AstDeviceType)deviceType
                                 confirm:(AstConfirmation)confirm
                              currentPin:[NSString stringWithCString:currentPin encoding:NSUTF8StringEncoding]
                                  newPin:[NSString stringWithCString:newPin encoding:NSUTF8StringEncoding]];
}

void KobilAstSDK::doSetPropertyRequest(KAstDeviceType deviceType) {
    [(KobilAstSDKIOS *)mySDK doSetPropertyRequest:(AstDeviceType)deviceType];
}

void KobilAstSDK::doSetProperty(KAstDeviceType deviceType, const char *propertyKey, const char *propertyData, KAstPropertyType propertyType, KAstPropertyOwner propertyOwner, int propertyTTL, KAstPropertyFlag propertyFlag) {
    NSData *dataProperty = [[NSString stringWithUTF8String:propertyKey] dataUsingEncoding:NSUTF8StringEncoding];
    [(KobilAstSDKIOS *)mySDK doSetProperty:(AstDeviceType)deviceType propertyKey:[NSString stringWithCString:propertyKey encoding:NSUTF8StringEncoding] propertyData:dataProperty propertyType:(AstPropertyType)propertyType propertyOwner:(AstPropertyOwner)propertyOwner propertyTTL:propertyTTL propertyFlags:propertyFlag];
}

void KobilAstSDK::doTransaction(KAstDeviceType deviceType, KAstConfirmation confirmation, const char *displayData) {
    [(KobilAstSDKIOS *)mySDK doTransaction:(AstDeviceType)deviceType
                                   confirm:(AstConfirmation)confirmation
                               displayData:[NSString stringWithCString:displayData encoding:NSUTF8StringEncoding]];
}

void KobilAstSDK::doDeactivate(const char *userId) {
    [(KobilAstSDKIOS *)mySDK doDeactivate:[NSString stringWithCString:userId encoding:NSUTF8StringEncoding]];
}

KAstStatus KobilAstSDK::resume() {
    KAstStatus returnCode = (KAstStatus)[(KobilAstSDKIOS *)mySDK resume];
    return returnCode;
}

void KobilAstSDK::suspend() {
    [(KobilAstSDKIOS *)mySDK suspend];
}

int KobilAstSDK::exit(int errorCode) {
    int returnCode = [(KobilAstSDKIOS *)mySDK exit:errorCode];
    return returnCode;
}

void* KobilAstSDK::getAppConfigData() {
    NSData *data = [[(KobilAstSDKIOS *)mySDK getAppConfigParameterData] dataUsingEncoding:NSUTF8StringEncoding];
    return data;
}

void KobilAstSDK::RunJavaScriptSmartface(JSContextRef ctx, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[]) {
    [[ESpratIOSPlayer SMFGetPlayer] SMFRunJavaScriptSmartface:ctx :object :thisObject :argumentCount :arguments];
}