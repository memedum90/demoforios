//
//  DPPlugin.mm
//  Smartface
//
//  Created by Faruk Toptas on 30.11.2013.
//  Copyright (c) 2013 Mobinex. All rights reserved.
//


#include "../core/DPPlugin.h"
#include "SecureStore.h"
#include "DSAPP_Client.framework/Headers/DSAPPClient.h"

SecureStore* mSecureStore; // SecureStore instance

// save data to a file in documents folder
bool DPPlugin::saveFileToDocuments(const char* filename, char* data, int len){
    NSData *dataToWrite = [NSData dataWithBytes:data length:len];
    [[NSUserDefaults standardUserDefaults] setObject:dataToWrite forKey:[NSString stringWithCString:filename encoding:NSUTF8StringEncoding]];
    return [[NSUserDefaults standardUserDefaults] synchronize];
    
    /*
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:[NSString stringWithUTF8String:filename]];
    NSData *dataToWrite = [NSData dataWithBytes:data length:len];
    BOOL result = [dataToWrite writeToFile:filePath atomically:YES];
    return result;*/
}

// read file from documents folder
char* DPPlugin::readFileFromDocuments(const char *filename){
    NSData *dataRead = [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithCString:filename encoding:NSUTF8StringEncoding]];
    if (dataRead) {
        int len = [dataRead length] + 1;
        char *dataBuffer = (char *)calloc(len, sizeof(char));
        memcpy(dataBuffer, [dataRead bytes], [dataRead length]);
        return dataBuffer;
    }
    return NULL;
    /*
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *fName = [NSString stringWithFormat:@"%@/%s", documentsDirectory,filename];
    BOOL fileExists = [[NSFileManager defaultManager] fileExistsAtPath:fName];
    char* retval = NULL;
    if (fileExists){
        NSData *dataToRead =[NSData dataWithContentsOfFile:fName];
        retval = (char*)[dataToRead bytes];
    }
    return retval;*/
}

// save data with Secure Storage SDK
void DPPlugin::secureSave(const char* key, vds_byte* data, int len){
    if (mSecureStore == NULL){
        mSecureStore = [[SecureStore alloc]init];
    }
    NSData *dataToStore = [NSData dataWithBytes:data length:len];
    [mSecureStore addItem:[NSString stringWithUTF8String:key] value:dataToStore];
}
// read data with Secure Storage SDK
char* DPPlugin::secureRead(const char* key){
    if (mSecureStore == NULL){
        mSecureStore = [[SecureStore alloc]init];
    }
    NSData *data = [mSecureStore getItem:[NSString stringWithUTF8String:key]];
    return (char*)[data bytes];
}

void DPPlugin::initializeRegistrationDataV2(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError) {
    DPPlugin* dp = DPPlugin::getInstance();
	JSContextRef ctx = dp->jsContext;
    
    InitializeRegistrationDataResponse response;
    
    try {
        DSAPPClient::initializeRegistrationDataV2(activationPassword, response);
        
        NSMutableDictionary *resultDict = [NSMutableDictionary dictionaryWithCapacity:5];
        [resultDict setObject:[NSString stringWithUTF8String:response.chsKey.c_str()] forKey:@"chsKey"];
        [resultDict setObject:[NSString stringWithUTF8String:response.encryptedClientPublicKeyAndNonce.c_str()] forKey:@"encryptedClientPublicKeyAndNonce"];
        [resultDict setObject:[NSString stringWithUTF8String:response.clientPrivateKey.c_str()] forKey:@"clientPrivateKey"];
        [resultDict setObject:[NSString stringWithUTF8String:response.clientInitialVector.c_str()] forKey:@"clientInitialVector"];
        [resultDict setObject:[NSString stringWithUTF8String:response.clientNonce.c_str()] forKey:@"clientNonce"];
        
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:resultDict options:0 error:&error];
        NSString *dataString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        NSString *string = [NSString stringWithFormat:@"(function(){return %@})()", dataString];
        [dataString release];
        
        JSValueRef arguments[] = {JSValueMakeNull(ctx)};
        JSStringRef scriptJS = JSStringCreateWithUTF8CString([string UTF8String]);;
        arguments[0] = JSEvaluateScript(ctx,scriptJS,0, 0, 0, NULL);
        JSStringRelease(scriptJS);
        
        JSObjectCallAsFunction(ctx,onSuccess,0,1,arguments,0);
    }
    catch (std::exception &e) {
        if (onError) {
            NSString *string = [NSString stringWithFormat:@"(function(){return {\"message\" : \"%s\"}})()", e.what()];
            
            JSValueRef arguments[] = {JSValueMakeNull(ctx)};
            JSStringRef scriptJS = JSStringCreateWithUTF8CString([string UTF8String]);;
            arguments[0] = JSEvaluateScript(ctx, scriptJS, 0, 0, 0, NULL);
            JSStringRelease(scriptJS);
            
            JSObjectCallAsFunction(ctx, onError, 0, 1, arguments, 0);
        }
    }
}

void DPPlugin::decryptActivationData(const char* chsKey,const char* clientPrivateKey,const char* encryptedServerPublicKey,const char* encryptedNonces,const char* xfad,const char* xerc,const char* clientNonce,const char* serverInitialVector,JSObjectRef onSuccess,JSObjectRef onError) {
    DPPlugin* dp = DPPlugin::getInstance();
    JSContextRef ctx = dp->jsContext;
    
    DecryptActivationDataResponse response;
    try {
        DSAPPClient::decryptActivationData(chsKey, clientPrivateKey, encryptedServerPublicKey, encryptedNonces, xfad, xerc, clientNonce, serverInitialVector, response);
        
        NSMutableDictionary *resultDict = [NSMutableDictionary dictionaryWithCapacity:4];
        [resultDict setObject:[NSString stringWithUTF8String:response.fad.c_str()] forKey:@"fad"];
        [resultDict setObject:[NSString stringWithUTF8String:response.erc.c_str()] forKey:@"erc"];
        [resultDict setObject:[NSString stringWithUTF8String:response.encryptedServerNonce.c_str()] forKey:@"encryptedServerNonce"];
        [resultDict setObject:[NSString stringWithUTF8String:response.clientInitialVector.c_str()] forKey:@"clientInitialVector"];
        
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:resultDict options:0 error:&error];
        NSString *dataString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        NSString *string = [NSString stringWithFormat:@"(function(){return %@})()", dataString];
        [dataString release];
        
        JSValueRef arguments[] = {JSValueMakeNull(ctx)};
        JSStringRef scriptJS = JSStringCreateWithUTF8CString([string UTF8String]);;
        arguments[0] = JSEvaluateScript(ctx, scriptJS, 0, 0, 0, NULL);
        JSStringRelease(scriptJS);
        
        JSObjectCallAsFunction(ctx, onSuccess, 0, 1, arguments, 0);
    }
    catch (std::exception &e) {
        if (onError) {
            NSString *string = [NSString stringWithFormat:@"(function(){return {\"message\" : \"%s\"}})()", e.what()];
            
            JSValueRef arguments[] = {JSValueMakeNull(ctx)};
            JSStringRef scriptJS = JSStringCreateWithUTF8CString([string UTF8String]);;
            arguments[0] = JSEvaluateScript(ctx, scriptJS, 0, 0, 0, NULL);
            JSStringRelease(scriptJS);
            
            JSObjectCallAsFunction(ctx, onError, 0, 1, arguments, 0);
        }
    }
}

void DPPlugin::validateSharedDataChecksum(const char* activationPassword,JSObjectRef onSuccess,JSObjectRef onError) {
    DPPlugin* dp = DPPlugin::getInstance();
    JSContextRef ctx = dp->jsContext;

    try {
        DSAPPClient::validateSharedDataChecksum(activationPassword);
        
        JSObjectCallAsFunction(ctx, onSuccess, 0, 0, 0, 0);
    }
    catch (std::exception &e) {
        if (onError) {
            NSString *string = [NSString stringWithFormat:@"(function(){return {\"message\" : \"%s\"}})()", e.what()];
            
            JSValueRef arguments[] = {JSValueMakeNull(ctx)};
            JSStringRef scriptJS = JSStringCreateWithUTF8CString([string UTF8String]);;
            arguments[0] = JSEvaluateScript(ctx, scriptJS, 0, 0, 0, NULL);
            JSStringRelease(scriptJS);
            
            JSObjectCallAsFunction(ctx, onError, 0, 1, arguments, 0);
        }
    }
}

void DPPlugin::protectCallbackOnMainThread(JSObjectRef objectRef) {
    if ([NSThread isMainThread]) {
        JSValueProtect(jsContext, objectRef);
        return;
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        JSValueProtect(jsContext, objectRef);
    });
}

void DPPlugin::unProtectCallbackOnMainThread(JSObjectRef objectRef) {
    if ([NSThread isMainThread]) {
        JSValueUnprotect(jsContext, objectRef);
        return;
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        JSValueUnprotect(jsContext, objectRef);
    });
}
