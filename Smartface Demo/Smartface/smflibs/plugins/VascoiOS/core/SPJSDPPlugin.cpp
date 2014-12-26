//
//  SPJSDPPlugin.cpp
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//

#include "SPJSDPPlugin.h"
#include "SPJSDPPluginDefs.h"
#include "DPPlugin.h"


void spjsdpplugin_init_cb(JSContextRef ctx, JSObjectRef object)
{
    
}

// has property for each method. new methods should be added here

bool spjsdpplugin_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName)
{
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char *)malloc(propertySize * sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
 	if(strcmp(kMethodActivateOnline,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodValidatePassword,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodGenerateOTP,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodGenerateDerivationCode,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodChangePassword,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodGetInfo,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodComputeTimeShift,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodInitializeRegistrationDataV2,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodDecryptActivationData,property) == 0)
    {
        ret = true;
    }
    else if(strcmp(kMethodValidateSharedDataChecksum,property) == 0)
    {
        ret = true;
    }
    free(property);
    return ret;
}

// get property for each methods, new methods should be added here
JSValueRef spjsdpplugin_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    bool ret = false;
    JSValueRef retval;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    if(strcmp(kMethodActivateOnline,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodActivateOnline);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_activate_online);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodValidatePassword,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodValidatePassword);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_validate_password);
        JSStringRelease(str);
        ret = true;
    }
    
    else if(strcmp(kMethodGenerateOTP,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodGenerateOTP);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_generate_otp);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodGenerateDerivationCode,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodGenerateDerivationCode);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_generate_derivation_code);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodChangePassword,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodChangePassword);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_change_password);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodGetInfo, property) == 0){
        JSStringRef str = JSStringCreateWithUTF8CString(kMethodGetInfo);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_get_info);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodComputeTimeShift,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodComputeTimeShift);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_compute_timeshift);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodInitializeRegistrationDataV2,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodInitializeRegistrationDataV2);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_initialize_registration_dataV2);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodDecryptActivationData,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodDecryptActivationData);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_decrypt_activation_data);
        JSStringRelease(str);
        ret = true;
    }
    else if(strcmp(kMethodValidateSharedDataChecksum,property) == 0)
    {
		JSStringRef str = JSStringCreateWithUTF8CString(kMethodValidateSharedDataChecksum);
        retval = (JSValueRef)JSObjectMakeFunctionWithCallback(ctx, str, js_validate_shared_data_checksum);
        JSStringRelease(str);
        ret = true;
    }
    free(property);
    return retval;
}

bool spjsdpplugin_set_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception)
{
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
	if(strcmp("customProperty",property) == 0)
    {
		ret = true;
    }
    
    free(property);
    return ret;
}

/* spjsdata_ methods */

void spjsdata_init_cb(JSContextRef ctx, JSObjectRef object)
{
    
}

// has property methods for callbacks. method parameter definitions( e.message, e.otp, e.data)
bool spjsdata_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName)
{
    bool ret = false;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char *)malloc(propertySize * sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
 	if(strcmp(kParamOTP,property) == 0)
    {
        ret = true;
    }
    if(strcmp(kParamCode,property) == 0)
    {
        ret = true;
    }
    if(strcmp(kParamMessage,property) == 0)
    {
        ret = true;
    }
    if(strcmp(kParamData,property) == 0)
    {
        ret = true;
    }
    
    free(property);
    return ret;
}

// has property method for callback parameters
JSValueRef spjsdata_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    bool ret = false;
    JSValueRef retval;
    int propertySize = JSStringGetMaximumUTF8CStringSize(propertyName);
    char* property = (char*)malloc(propertySize*sizeof(char));
    JSStringGetUTF8CString(propertyName, property, propertySize);
    char* data = (char*)JSObjectGetPrivate(object);
    if(strcmp(kParamOTP,property) == 0)
    {

        JSStringRef sref = JSStringCreateWithUTF8CString(data);
		JSValueRef ref = JSValueMakeString(ctx, sref);
        retval = ref;
        ret = true;
    }
    if(strcmp(kParamCode,property) == 0)
    {
        JSStringRef sref = JSStringCreateWithUTF8CString(data);
		JSValueRef ref = JSValueMakeString(ctx, sref);
        retval = ref;
        ret = true;
    }
    if(strcmp(kParamMessage,property) == 0)
    {
        JSStringRef sref = JSStringCreateWithUTF8CString(data);
		JSValueRef ref = JSValueMakeString(ctx, sref);
        retval = ref;
        ret = true;
    }
    if(strcmp(kParamData,property) == 0)
    {
        //JSStringRef sref = JSStringCreateWithUTF8CString(data);
  //JSValueRef ref = JSValueMakeString(ctx, sref);
        
        // json object is passed to e.data
        DPInfo* info = (DPInfo*)JSObjectGetPrivate(object);
//        std::string json = "{\"status\":\"" + (char)info->status + "\",\"version\":\"" + info->version + "\",\"serial\":\"" + info->serial + "\"}";

        char *jsonBuffer = new char[256];
        memset(jsonBuffer, 0, 256);
        sprintf(jsonBuffer, "{\"status\":\"%u\",\"version\":\"%u\",\"serial\":\"%s\",\"passwordFatalCounter\":\"%u\",\"appEventCounter\":\"%lu\"}", info->status, info->version, info->serial.c_str(), info->fatalCounter, info->appEventCounter);
        JSStringRef sref = JSStringCreateWithUTF8CString(jsonBuffer);
        delete []jsonBuffer;

        JSValueRef ref = JSValueMakeFromJSONString(ctx, sref);
        retval = ref;
        ret = true;
    }

    free(property);
    return retval;
}
