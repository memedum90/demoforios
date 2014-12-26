//
//  SecureStore.m
//  Smartface
//
//  Created by Faruk Toptas on 12.12.2013.
//  Copyright (c) 2013 Bivium. All rights reserved.
//

#import "SecureStore.h"
#import <SecureStorageSDK/SecureStorageSDK.h>
#import <SecureStorageSDK/SecureStorageSDKException.h>
#import "../core/DP4Capi.h"


#define STORAGE_NAME @"file"
#define FINGERPRINT @"fingerprint"


@implementation SecureStore

@synthesize secureStorage;

-(id)init{
    if (self == [super init]){

    }
    @try{
        self.secureStorage = [[SecureStorageSDK alloc] initWithFileName:STORAGE_NAME useFingerPrint:FINGERPRINT andIterationNumber:10];
    }@catch (SecureStorageSDKException *ex){
        //NSLog(@"SecureStorageSDK error: %d", ex.errorCode);
    }
    return self;
}

-(void)addItem:(NSString*)key value:(NSData*)value{
    @try {
        [self.secureStorage putBytes:value forKey:key];
        [self.secureStorage writeWithFingerPrint:FINGERPRINT andIterationNumber:10];
    }
    @catch (SecureStorageSDKException *exception) {
        //NSLog(@"SecureStorageSDK error: %d", exception.errorCode);
    }
}

-(void)removeItem:(NSString*)key{
    @try {
        [self.secureStorage removeForKey:key];
        [self.secureStorage writeWithFingerPrint:FINGERPRINT andIterationNumber:10];
    }
    @catch (SecureStorageSDKException *exception) {
        //NSLog(@"SecureStorageSDK error: %d", exception.errorCode);
    }
}

-(NSData*)getItem:(NSString*)forKey{
    NSData *retval;
    NSDictionary *dictionary = [self.secureStorage getAll];
    retval = [dictionary objectForKey:forKey];
    return retval;
}

@end
