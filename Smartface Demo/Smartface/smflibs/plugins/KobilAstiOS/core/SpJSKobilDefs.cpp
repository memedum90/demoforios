//
//  SpJSKobilDefs.cpp
//  Smartface
//
//  Created by Ugur Kilic on 30.06.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "KobilAstEnums.h"
#include "SpJSKobilDefs.h"
#include "SpJSKobilAstFactory.h"
#include "SpJSKobilAstListener.h"
#include "KobilAstContextHolder.h"

void spjskobil_init_cb(JSContextRef ctx, JSObjectRef object)
{
    // AST object
    JSStringRef str = JSStringCreateWithUTF8CString("AST");
    JSClassRef classDef = JSClassCreate(&spjskobilast_def);
    JSObjectRef astObject = JSObjectMake(ctx, classDef, NULL);
    JSObjectSetProperty(ctx, object, str, astObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    JSClassRelease(classDef);
}

void spjskobilast_init_cb(JSContextRef ctx, JSObjectRef object)
{
    KobilAstContextHolder *contextHolder = KobilAstContextHolder::getInstance();
    contextHolder->ctx = ctx;
    
    // AST.SDKFactory object
    JSStringRef str = JSStringCreateWithUTF8CString("SDKFactory");
    JSClassRef classDef = JSClassCreate(&spjskobilastfactory_def);
    JSObjectRef sdkFactoryObject = JSObjectMake(ctx, classDef, &contextHolder);
    JSObjectSetProperty(ctx, object, str, sdkFactoryObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    JSClassRelease(classDef);
    
    // AST.SDKListener
    str = JSStringCreateWithUTF8CString("SDKListener");
	classDef = JSClassCreate(&spjskobilastlistener_def);
	JSObjectRef astListenerConstructor = JSObjectMakeConstructor(ctx, classDef, spjskobilastlistener_construct_cb);
	JSObjectSetProperty(ctx, object, str, astListenerConstructor, kJSPropertyAttributeNone, NULL);
	JSStringRelease(str);
    
    // SET ENUMS OF KOBIL.AST //
    
    // Confirmation Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    JSObjectRef enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    JSStringRef enumStringRef = JSStringCreateWithUTF8CString("ok");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmation_OK), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("cancel");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmation_Cancel), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("timeout");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmation_TimeOut), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("Confirmation");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // ConfirmationType Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("noConfirmation");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmationType_NoConfirmation), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("confirmationRequired");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmationType_ConfirmationRequired), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("splitConfirmation");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstConfirmationType_SplitConfirmation), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("ConfirmationType");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // DeviceType Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("mIdentity");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstDeviceType_MIdentity), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("virtualDevice");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstDeviceType_VirtualDevice), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("DeviceType");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // LogLevel Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("trace");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Trace), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("debug");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Debug), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("info");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Info), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("warn");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Warn), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("error");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Error), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("fatal");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstLogLevel_Fatal), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("LogLevel");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // PropertyFlag Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("nonPersistance");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyFlag_NonPersistance), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("valueEncrypted");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyFlag_ValueEncrypted), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("confidental");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyFlag_Confidental), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("uniqueToUser");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyFlag_UniqueToUser), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("immediate");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyFlag_Immediate), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("PropertyFlag");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // PropertyOwner Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("device");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyOwner_Device), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("user");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyOwner_User), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("group");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyOwner_Group), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("PropertyOwner");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // PropertyType Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("octetString");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyType_OctetString), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("integer");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyType_Integer), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("boolean");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyType_Boolean), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("utf8string");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyType_Utf8string), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("date");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstPropertyType_Date), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("PropertyType");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // Status Enums
    classDef = JSClassCreate(&spjskobilenum_def);
    enumObject = JSObjectMake(ctx, classDef, NULL);
    JSClassRelease(classDef);
    
    enumStringRef = JSStringCreateWithUTF8CString("ok");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_OK), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("updateAvailable");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_UPDATE_AVAILABLE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("activateCertificate");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_ACTIVATE_CERTIFICATE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("appRegistered");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_APP_REGISTERED), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("userCancel");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_USER_CANCEL), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("userConfirmationTimeout");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_USER_CONFIRMATION_TIMEOUT), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidPin");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_PIN), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidNewPinFormat");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_NEW_PIN_FORMAT), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidActivationCode");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_ACTIVATION_CODE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("unknownVersion");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_UNKNOWN_VERSION), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("unknownClientType");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_UNKNOWN_CLIENT_TYPE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("updateNecessary");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_UPDATE_NECESSARY), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("wrongCredentials");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_WRONG_CREDENTIALS), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("unknownCertificate");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_UNKNOWN_CERTIFICATE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("internalError");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INTERNAL_ERROR), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("activationCodeExpired");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_ACTIVATION_CODE_EXPIRED), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("lockedCertificate");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_LOCKED_CERTIFICATE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("lockedUser");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_LOCKED_USER), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidPuk");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_PUK), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("propertyNotExists");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_PROPERTY_NOT_EXISTS), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidKeyLength");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_KEY_LENGTH), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("notUnique");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_NOT_UNIQUE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("textTooLong");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_TEXT_TOO_LONG), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidState");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_STATE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidDevice");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_DEVICE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidParameter");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_PARAMETER), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("invalidUserId");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_INVALID_USER_ID), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("userIdAlreadyExists");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_USER_ID_ALREADY_EXISTS), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("deviceNotFound");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_DEVICE_NOT_FOUND), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("registerApp");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_REGISTER_APP), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("mismatchedUser");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_MISMATCHED_USER), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("negative");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_NEGATIVE), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("readOnly");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_READ_ONLY), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("temporaryLocked");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_TEMPORARY_LOCKED), NULL, NULL);
    JSStringRelease(enumStringRef);
    enumStringRef = JSStringCreateWithUTF8CString("notSuspended");
    JSObjectSetProperty(ctx, enumObject, enumStringRef, JSValueMakeNumber(ctx, KAstStatus_NOT_SUSPENDED), NULL, NULL);
    JSStringRelease(enumStringRef);
    
    str = JSStringCreateWithUTF8CString("Status");
    JSObjectSetProperty(ctx, object, str, enumObject, kJSPropertyAttributeNone, NULL);
    JSStringRelease(str);
    
    // SET ENUMS OF KOBIL.AST //
}