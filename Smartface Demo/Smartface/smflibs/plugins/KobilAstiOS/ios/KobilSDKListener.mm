//
//  SDKListener.mm
//  Smartface
//
//  Created by Ugur Kilic on 01.07.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import "KobilSDKListener.h"

#include <vector>
#include <string>

@interface SDKListener () {
    KobilAstSDK *coreSdk;
    NSXMLParser *xmlParser;
    bool configParsed;
}
@end

@implementation SDKListener

- (id)init {
    if ((self = [super init]))
    {
        coreSdk = NULL;
        xmlParser = NULL;
        configParsed = false;
    }
    return self;
}

- (void)setMySDK:(KobilAstSDK *)sdk {
    coreSdk = sdk;
}

#pragma mark SDK INIT
- (void)onDeviceConnection:(AstDeviceType)device connectionState:(AstConnectionState)connectionState {
    switch (connectionState) {
        case AstConnectionState_CONNECTION_LOST:
            NSLog(@"conn lost");
            break;
        case AstConnectionState_DISCONNECTED:
            NSLog(@"disconnect");
            break;
            
        default:
            break;
    }
}

#pragma mark ACTIVATION

- (void)onActivationBegin:(AstDeviceType)device {
    if (coreSdk) {
        coreSdk->onActivationBegin((KAstDeviceType)device);
    }
}

- (NSDictionary *)getProxyParameter {
  return nil;
}


#pragma mark APP_CONFIG

- (NSArray *)getAppConfigParameter:(AstConfigParameter)type {
    if ((type != AstConfigParameter_CONFIG_BUNDLE) &&
        (type != AstConfigParameter_USER_CREDENTIALS_PATH) &&
        (type != AstConfigParameter_WEB_VIEW_BASIC_AUTH)) {
        
        if (!configParsed) {
            NSData *data = (NSData *)coreSdk->getAppConfigData();
            
            xmlParser = [[NSXMLParser alloc] initWithData:data];
            self.whitelist = [[NSMutableArray alloc] init];
            
            xmlParser.delegate = self;
            [xmlParser parse];
            
            configParsed = true;
        }
    }
    
    switch (type) {
        case AstConfigParameter_WHITELIST: {
            return self.whitelist;
        }
            
        case AstConfigParameter_CONFIG_BUNDLE:
            return [NSArray arrayWithObject:@""];
            break;
            
        case AstConfigParameter_USER_CREDENTIALS_PATH:
            return [NSArray arrayWithObject:[NSString stringWithUTF8String: getenv("HOME")]];
            
        case AstConfigParameter_CERTIFICATE_POLICY:
            return [NSArray arrayWithObject: self.certificatePolicy];
            
        case AstConfigParameter_SERVER_BUSY_TIMEOUT:
            return [NSArray arrayWithObject: self.serverBusyTimeout];
            
        case AstConfigParameter_CONNECTION_RETRY_COUNTER:
            return [NSArray arrayWithObject: self.connectionRetryCounter];
            
        case AstConfigParameter_CONNECTION_RETRY_INTERVAL:
            return [NSArray arrayWithObject: self.connectionRetryInterval];
            
        case AstConfigParameter_USE_DEVICE_NAME_SOFTWARE:
            return [NSArray arrayWithObject: self.useDeviceNameSoftware];
            
        case AstConfigParameter_USE_DEVICE_NAME_HARDWARE:
            return [NSArray arrayWithObject: self.useDeviceNameHardware];
            
        case AstConfigParameter_WEB_VIEW_BASIC_AUTH:
            return [NSArray arrayWithObject:@""];
            
        case AstConfigParameter_ALLOWED_HOST_DEVICES:
            return [NSArray arrayWithObject:self.allowedHostDevicesApple];
            
        default: return [NSArray arrayWithObject: nil];
    }
}


-(void)onActivationEnd:(AstDeviceType)deviceType status:(AstStatus)status{
    if (coreSdk) {
        coreSdk->onActivationEnd((KAstDeviceType)deviceType, (KAstStatus)status);
    }
}



-(void)onLoginBegin:(AstDeviceType)deviceType userIdList:(NSArray *)userIdList{
    if (coreSdk) {
        std::vector<std::string> userIDs;
        for (int i = 0; i < userIdList.count; ++i)
        {
            NSString *string = [userIdList objectAtIndex:i];
            userIDs.push_back(std::string([string UTF8String]));
        }
        coreSdk->onLoginBegin((KAstDeviceType)deviceType, userIDs);
    }
}

- (void)onLoginEnd:(AstDeviceType)device status:(AstStatus)status loginOtp:(NSString *)loginOtp userId:(NSString *)userId retryCounter:(int)retryCounter retryDelay:(int)retryDelay {
    if (coreSdk) {
        coreSdk->onLoginEnd((KAstDeviceType)device, (KAstStatus)status, [loginOtp UTF8String], [userId UTF8String], retryCounter, retryDelay);
    }
}

-(void)onReActivationEnd:(AstStatus)status {
    
}

-(void)onPinChangeBegin:(AstDeviceType)deviceType status:(AstStatus)status {
    if (coreSdk) {
        coreSdk->onPinChangeBegin((KAstDeviceType)deviceType, (KAstStatus)status);
    }
}

-(void)onPinChangeEnd:(AstDeviceType)deviceType status:(AstStatus)status retryCounter:(int)retryCounter {
    if (coreSdk) {
        coreSdk->onPinChangeEnd((KAstDeviceType)deviceType, (KAstStatus)status, retryCounter);
    }
}

-(void)onServerConnection:(AstDeviceType)deviceType connectionState:(AstConnectionState)connectionState {
    
}

- (void)onTransactionBegin:(AstDeviceType)device displayData:(NSString *)displayData confirmationType:(AstConfirmationType)confirmationType {
    if (coreSdk) {
        coreSdk->onTransactionBegin((KAstDeviceType)device, [displayData UTF8String], (KAstConfirmationType)confirmationType);
    }
}

-(void)onTransactionEnd:(AstDeviceType)deviceType status:(AstStatus)status {
    if (coreSdk) {
        coreSdk->onTransactionEnd((KAstDeviceType)deviceType, (KAstStatus)status);
    }
}

-(void)onDisplayMessage:(AstDeviceType)deviceType displayData:(NSString *)displayData messageType:(AstMessageType)messageType {
    
}

-(void)onInfoHardwareTransactionBegin {
    
}

-(void)onInfoHardwareTransactionEnd {
    
}

-(void)onPinRequiredBegin:(AstDeviceType)deviceType pinReason:(AstPinReason)pinReason {
    
}

-(void)onPinRequiredEnd:(AstDeviceType)deviceType status:(AstStatus)status retryCounter:(int)retryCounter {
    
}

-(void)onTransportPinBegin:(AstCheckPinReason)checkPinReason {
    
}

-(void)onTransportPinEnd:(AstStatus)status {
    
}

-(void)onPinUnblockBegin {
    
}

-(void)onPinUnblockEnd:(AstStatus)status retryCounter:(int)retryCounter {
    
}

-(void)onAlert:(AstDeviceType)device subSystem:(unsigned int)subSystem errorCode:(unsigned int)errorCode {
    if (coreSdk) {
        coreSdk->onAlert((KAstDeviceType)device, subSystem, errorCode);
    }
}

-(void)onUrlBlocked:(NSString *)url urlBlockedReason:(UrlBlockedReason)urlBlockedReason {
    
}

-(void)onCertificateDataAvailable:(AstDeviceType)deviceType certificate:(NSData *)certificate {
    
}

-(void)onSetPropertyBegin:(AstDeviceType)deviceType status:(AstStatus)status {
    if (coreSdk) {
        coreSdk->onSetPropertyBegin((KAstDeviceType)deviceType, (KAstStatus)status);
    }
}

-(void)onSetPropertyEnd:(AstDeviceType)deviceType status:(AstStatus)status subSystem:(uint32_t)subSystem errorCode:(uint32_t)errorCode {
    if (coreSdk) {
        coreSdk->onSetPropertyEnd((KAstDeviceType)deviceType, (KAstStatus)status, subSystem, errorCode);
    }
}

-(void)onGetPropertyBegin:(AstDeviceType)deviceType status:(AstStatus)status {
    
}

-(void)onGetPropertyEnd:(AstDeviceType)deviceType status:(AstStatus)status propertyData:(id)propertyData propertyType:(AstPropertyType)propertyType propertyTTL:(uint32_t)propertyTTL propertyFlags:(uint32_t)propertyFlags {
    
}

-(void)onDeactivateEnd:(AstStatus)status userIdList:(NSArray *)userIdlist {
    if (coreSdk) {
        std::vector<std::string> userIDs;
        for (int i = 0; i < userIdlist.count; ++i)
        {
            NSString *string = [userIdlist objectAtIndex:i];
            userIDs.push_back(std::string([string UTF8String]));
        }
        coreSdk->onDeactivateEnd((KAstStatus)status, userIDs);
    }
}

-(void)onDetectHwDevicesEnd:(AstStatus)status availableDevices:(NSArray *)availableDevices {
    
}

-(void)onConnectHwDeviceEnd:(AstStatus)status {
    
}

-(void)onDisconnectHwDeviceEnd:(AstStatus)status {
    
}

-(void)onLogMessage:(AstDeviceType)deviceType message:(NSString *)message {
    
}

-(void)onReport:(AstDeviceType)deviceType reportId:(int)reportId {
    
}

- (void)informNCToOpenConfirmationPage {

}

- (void)onInformationAvailable:(AstContextType)context informationKey:(AstInformationKey)informationKey informationValue:(id)informationValue {
    
}

- (void)onInfoHardwareDisplayMessageBegin {
}

- (void)onInfoHardwareDisplayMessageEnd {
}

- (void)onTransactionBlockBegin:(AstDeviceType)deviceType timeout:(uint32_t)timeout {
}

- (void)onTransactionBlockEnd:(AstDeviceType)deviceType {
}
- (void)onConnectHardwareDeviceEnd:(AstStatus)status {
}

- (void)onDisconnectHardwareDeviceEnd:(AstStatus)status {
}

- (void)onDetectHardwareDevicesEnd:(AstStatus)status availableDevices:(NSArray *)availableDevices {
}

#pragma mark - Application Configuration Data Parsing

- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict {
    
    if ([elementName isEqualToString:@"app"]) {
        //        NSLog(@"FOUND APP TAG IN APP CONFIG FILE");
    }
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName {
    
    if ([elementName isEqualToString:@"webPortalUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.webPortalUrl = self.currentElement;
    } else if ([elementName isEqualToString:@"forgotActivationCodeUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.forgotActivationCodeUrl = self.currentElement;
    } else if ([elementName isEqualToString:@"forgotPinUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.forgotPinUrl = self.currentElement;
    } else if ([elementName isEqualToString:@"forgotPinUrlHardware"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.forgotPinUrlHardware = self.currentElement;
    } else if ([elementName isEqualToString:@"requestActivationCodeUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.requestActivationCodeUrl = self.currentElement;
    } else if ([elementName isEqualToString:@"trustMessageSignUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.trustMessageSignUrl = self.currentElement;
    } else if ([elementName isEqualToString:@"PinRegexp"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.pinRegexp = self.currentElement;
    } else if ([elementName isEqualToString:@"PukRegexp"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.pukRegexp = self.currentElement;
    } else if ([elementName isEqualToString:@"string"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        [self.whitelist addObject:self.currentElement];
    } else if ([elementName isEqualToString:@"appInactivityTimeout"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.appInactivityTimeout = self.currentElement;
    } else if ([elementName isEqualToString:@"certificatePolicy"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.certificatePolicy = self.currentElement;
    } else if ([elementName isEqualToString:@"webViewPolicy"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.webViewPolicy = self.currentElement;
    } else if ([elementName isEqualToString:@"connectionRetryCounter"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.connectionRetryCounter = self.currentElement;
    } else if ([elementName isEqualToString:@"connectionRetryInterval"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.connectionRetryInterval = self.currentElement;
    } else if ([elementName isEqualToString:@"serverBusyTimeout"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.serverBusyTimeout = self.currentElement;
    } else if ([elementName isEqualToString:@"appInactivityTimeout"]) {
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.appInactivityTimeout = self.currentElement;
    } else if ([elementName isEqualToString:@"minimumPinLength"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.minimumPinLength = self.currentElement;
    } else if ([elementName isEqualToString:@"tabToDisplayTransaction"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.tabToDisplayTransaction = self.currentElement;
    } else if ([elementName isEqualToString:@"useDeviceNameSoftware"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useDeviceNameSoftware = self.currentElement;
    } else if ([elementName isEqualToString:@"useDeviceNameHardware"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useDeviceNameHardware = self.currentElement;
    } else if ([elementName isEqualToString:@"useWebView"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useWebView = self.currentElement;
    } else if ([elementName isEqualToString:@"useMessageSign"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useMessageSign = self.currentElement;
    } else if ([elementName isEqualToString:@"useQRCode"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useQrCode = self.currentElement;
    } else if ([elementName isEqualToString:@"usePushNotification"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.usePushNotification = self.currentElement;
    } else if ([elementName isEqualToString:@"showReActivate"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.showReActivate = self.currentElement;
    } else if ([elementName isEqualToString:@"showLogoutButton"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.showLogoutButton = self.currentElement;
    } else if ([elementName isEqualToString:@"showUnblockPinDialog"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.showUnblockPinDialog = self.currentElement;
    } else if ([elementName isEqualToString:@"supportFamilyScenario"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.supportFamilyScenario = self.currentElement;
    } else if ([elementName isEqualToString:@"useDeveloperMode"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useDeveloperMode = self.currentElement;
    } else if ([elementName isEqualToString:@"useAutoLogin"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useAutoLogin = self.currentElement;
    } else if ([elementName isEqualToString:@"showDeleteAllUsers"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.showDeleteAllUsers = self.currentElement;
    } else if ([elementName isEqualToString:@"defaultLanguage"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.defaultLanguage = self.currentElement;
    } else if ([elementName isEqualToString:@"supportedLanguages"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.supportedLanguages =
        [self.currentElement componentsSeparatedByString:@","];
    } else if ([elementName isEqualToString:@"allowedHostDevicesApple"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.allowedHostDevicesApple = self.currentElement;
    } else if ([elementName isEqualToString:@"maintenanceURL"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.maintenanceURL = self.currentElement;
    } else if ([elementName isEqualToString:@"useInbox"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.useInbox = self.currentElement;
    } else if ([elementName isEqualToString:@"ActivationCodeRegexp"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.activationCodeRegexp = self.currentElement;
    } else if ([elementName isEqualToString:@"openOnLogoutUrl"]) {
        
        self.currentElement = (NSMutableString *)[self.currentElement
                                                  stringByTrimmingCharactersInSet:
                                                  [NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.openOnLogoutUrl = self.currentElement;
    }
    
    self.currentElement = nil;
    if ([elementName isEqualToString:@"app"]) return;
}

- (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError {
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
    
    if (!self.currentElement)
        self.currentElement = [[NSMutableString alloc] initWithString:string];
    
    else
        [self.currentElement appendString:string];
}

@end
