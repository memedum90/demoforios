//
//  SecureStore.h
//  Smartface
//
//  Created by Faruk Toptas on 12.12.2013.
//  Copyright (c) 2013 Bivium. All rights reserved.
//


#import <SecureStorageSDK/SecureStorageSDK.h>

@interface SecureStore : NSObject{
    SecureStorageSDK* secureStorage;
}

@property (nonatomic, strong) SecureStorageSDK* secureStorage;

-(void)addItem:(NSString*)key value:(NSData*)value;
-(void)removeItem:(NSString*)key;
-(NSData*)getItem:(NSString*)forKey;

@end