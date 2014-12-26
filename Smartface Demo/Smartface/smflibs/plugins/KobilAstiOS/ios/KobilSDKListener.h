//
//  SDKListener.h
//  Smartface
//
//  Created by Ugur Kilic on 01.07.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AstSdkListener.h"
#import "KobilAstSDK.h"

@interface SDKListener : NSObject <AstSdkListener, NSXMLParserDelegate>

-(void)setMySDK:(KobilAstSDK *)sdk;

/**
 * Application Configuration Data
 */

@property(nonatomic, strong) NSString *webPortalUrl;
@property(nonatomic, strong) NSString *forgotActivationCodeUrl;
@property(nonatomic, strong) NSString *forgotPinUrl;
@property(nonatomic, strong) NSString *forgotPinUrlHardware;
@property(nonatomic, strong) NSString *requestActivationCodeUrl;
@property(nonatomic, strong) NSString *trustMessageSignUrl;
@property(nonatomic, strong) NSString *pinRegexp;
@property(nonatomic, strong) NSString *pukRegexp;
@property(nonatomic, strong) NSString *activationCodeRegexp;
@property(nonatomic, strong) NSString *certificatePolicy;
@property(nonatomic, strong) NSString *webViewPolicy;
@property(nonatomic, strong) NSString *connectionRetryCounter;
@property(nonatomic, strong) NSString *connectionRetryInterval;
@property(nonatomic, strong) NSString *serverBusyTimeout;
@property(nonatomic, strong) NSString *useDeviceNameSoftware;
@property(nonatomic, strong) NSString *useDeviceNameHardware;
@property(nonatomic, strong) NSString *useWebView;
@property(nonatomic, strong) NSString *useMessageSign;
@property(nonatomic, strong) NSString *useQrCode;
@property(nonatomic, strong) NSString *useInbox;
@property(nonatomic, strong) NSString *usePushNotification;
@property(nonatomic, strong) NSString *supportFamilyScenario;
@property(nonatomic, strong) NSString *showReActivate;
@property(nonatomic, strong) NSString *showLogoutButton;
@property(nonatomic, strong) NSString *showUnblockPinDialog;
@property(nonatomic, strong) NSString *useAutoLogin;
@property(nonatomic, strong) NSString *defaultLanguage;
@property(nonatomic, strong) NSString *allowedHostDevicesApple;
@property(nonatomic, strong) NSString *maintenanceURL;
@property(nonatomic, strong) NSArray *supportedLanguages;
@property(nonatomic, strong) NSString *openOnLogoutUrl;

@property(nonatomic, strong) NSString *useDeveloperMode;
@property(nonatomic, strong) NSString *showDeleteAllUsers;

@property(nonatomic, strong) NSString *appInactivityTimeout;
@property(nonatomic, strong) NSString *minimumPinLength;
@property(nonatomic, strong) NSString *tabToDisplayTransaction;

@property(nonatomic, strong) NSMutableArray *whitelist;
@property(nonatomic, strong) NSMutableString *currentElement;

@end
