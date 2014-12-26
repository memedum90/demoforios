//
//  SpJSKobilAstSDKFunctions.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "SpJSKobilAstSDKFunctions.h"
#include "KobilAstEnums.h"
#include "KobilAstSDK.h"

JSValueRef sdkInit(JSContextRef ctx,
                   JSObjectRef function,
                   JSObjectRef thisObject,
                   size_t argumentCount,
                   const JSValueRef arguments[],
                   JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *locale = kobilJSGetString(ctx, arrObject, "locale");
    char *version = kobilJSGetString(ctx, arrObject, "version");
    char *appName = kobilJSGetString(ctx, arrObject, "appName");
    KAstLogLevel logLevel = (KAstLogLevel)kobilJSGetInteger(ctx, arrObject, "logLevel");
    
    if (locale && version && appName)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        KAstStatus status = sdkObject->init(locale, version, appName, logLevel);
        return JSValueMakeNumber(ctx, status);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkExit(JSContextRef ctx,
                   JSObjectRef function,
                   JSObjectRef thisObject,
                   size_t argumentCount,
                   const JSValueRef arguments[],
                   JSValueRef* exception)
{
    KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
    return JSValueMakeNumber(ctx, sdkObject->exit(0));
}

JSValueRef sdkDoActivation(JSContextRef ctx,
                           JSObjectRef function,
                           JSObjectRef thisObject,
                           size_t argumentCount,
                           const JSValueRef arguments[],
                           JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *pin = kobilJSGetString(ctx, arrObject, "pin");
    char *userId = kobilJSGetString(ctx, arrObject, "userId");
    char *activationCode = kobilJSGetString(ctx, arrObject, "activationCode");
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");
    
    if (pin && userId && activationCode)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doActivation(deviceType, pin, userId, activationCode);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoLogin(JSContextRef ctx,
                      JSObjectRef function,
                      JSObjectRef thisObject,
                      size_t argumentCount,
                      const JSValueRef arguments[],
                      JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *pin = kobilJSGetString(ctx, arrObject, "pin");
    char *userId = kobilJSGetString(ctx, arrObject, "userId");
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");
    
    if (pin && userId)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doLogin(deviceType, pin, userId);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoPinChangeRequest(JSContextRef ctx,
                                 JSObjectRef function,
                                 JSObjectRef thisObject,
                                 size_t argumentCount,
                                 const JSValueRef arguments[],
                                 JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");

    KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
    sdkObject->doPinChangeRequest(deviceType);
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoPinChange(JSContextRef ctx,
                          JSObjectRef function,
                          JSObjectRef thisObject,
                          size_t argumentCount,
                          const JSValueRef arguments[],
                          JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *currentPin = kobilJSGetString(ctx, arrObject, "currentPin");
    char *newPin = kobilJSGetString(ctx, arrObject, "newPin");
    KAstConfirmation confirm = (KAstConfirmation)kobilJSGetInteger(ctx, arrObject, "confirm");
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");
    
    if (currentPin && newPin)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doPinChange(deviceType, confirm, currentPin, newPin);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoSetPropertyRequest(JSContextRef ctx,
                                   JSObjectRef function,
                                   JSObjectRef thisObject,
                                   size_t argumentCount,
                                   const JSValueRef arguments[],
                                   JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");
    
    KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
    sdkObject->doSetPropertyRequest(deviceType);
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoSetProperty(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *propertyKey = kobilJSGetString(ctx, arrObject, "propertyKey");
    char *propertyData = kobilJSGetString(ctx, arrObject, "propertyData");
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");
    KAstPropertyOwner propertyOwner = (KAstPropertyOwner)kobilJSGetInteger(ctx, arrObject, "propertyOwner");
    KAstPropertyFlag propertyFlags = (KAstPropertyFlag)kobilJSGetInteger(ctx, arrObject, "propertyFlags");
    KAstPropertyType propertyType = (KAstPropertyType)kobilJSGetInteger(ctx, arrObject, "propertyType");
    int propertyTTL = kobilJSGetInteger(ctx, arrObject, "propertyTTL");
    
    if (propertyKey && propertyData)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doSetProperty(deviceType, propertyKey, propertyData, propertyType, propertyOwner, propertyTTL, propertyFlags);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoTransaction(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *displayData = kobilJSGetString(ctx, arrObject, "displayData");
    KAstConfirmation confirm = (KAstConfirmation)kobilJSGetInteger(ctx, arrObject, "confirm");
    KAstDeviceType deviceType = (KAstDeviceType)kobilJSGetInteger(ctx, arrObject, "deviceType");

    if (displayData)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doTransaction(deviceType, confirm, displayData);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkDoDeactivate(JSContextRef ctx,
                            JSObjectRef function,
                            JSObjectRef thisObject,
                            size_t argumentCount,
                            const JSValueRef arguments[],
                            JSValueRef* exception)
{
    JSObjectRef arrObject = (JSObjectRef)arguments[0];
    char *userId = kobilJSGetString(ctx, arrObject, "userId");
    
    if (userId)
    {
        KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
        sdkObject->doDeactivate(userId);
    }
    
    return JSValueMakeNull(ctx);
}

JSValueRef sdkResume(JSContextRef ctx,
                  JSObjectRef function,
                  JSObjectRef thisObject,
                  size_t argumentCount,
                  const JSValueRef arguments[],
                  JSValueRef* exception) {
    KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
    if (sdkObject) {
        KAstStatus status = sdkObject->resume();
        return JSValueMakeNumber(ctx, status);
    }
    return JSValueMakeNull(ctx);
}

JSValueRef sdkSuspend(JSContextRef ctx,
                   JSObjectRef function,
                   JSObjectRef thisObject,
                   size_t argumentCount,
                   const JSValueRef arguments[],
                   JSValueRef* exception) {
    KobilAstSDK *sdkObject = (KobilAstSDK *)JSObjectGetPrivate(thisObject);
    if (sdkObject) {
        sdkObject->suspend();
    }
    return JSValueMakeNull(ctx);
}

char *kobilJSGetString(JSContextRef ctx, JSObjectRef arrayObject, const char *propertyName) {
    char* propertyBuffer = NULL;
    JSStringRef jspropertyName = JSStringCreateWithUTF8CString(propertyName);
    if (JSObjectHasProperty(ctx, arrayObject, jspropertyName)) {
        JSValueRef propertyValRef = JSObjectGetProperty(ctx, arrayObject, jspropertyName, NULL);
        JSStringRef propertyString = JSValueToStringCopy(ctx, propertyValRef, NULL);
        size_t stringLen = JSStringGetMaximumUTF8CStringSize(propertyString);
        propertyBuffer = (char*)malloc(stringLen);
        JSStringGetUTF8CString(propertyString, propertyBuffer, stringLen);
        JSStringRelease(propertyString);
    }
    JSStringRelease(jspropertyName);
    return propertyBuffer;
}

int kobilJSGetInteger(JSContextRef ctx, JSObjectRef arrayObject, const char *propertyName) {
    int propertyInteger = -1;
    JSStringRef jspropertyName = JSStringCreateWithUTF8CString(propertyName);
    if (JSObjectHasProperty(ctx, arrayObject, jspropertyName)) {
        JSValueRef propertyValRef = JSObjectGetProperty(ctx, arrayObject, jspropertyName, NULL);
        propertyInteger = JSValueToNumber(ctx, propertyValRef, NULL);
    }
    JSStringRelease(jspropertyName);
    return propertyInteger;
}
