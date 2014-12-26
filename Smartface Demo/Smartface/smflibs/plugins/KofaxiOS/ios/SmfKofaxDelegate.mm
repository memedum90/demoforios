//
//  SmfKofaxDelegate.mm
//  Smartface
//
//  Created by ugur kilic on 20.04.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import "SmfKofaxDelegate.h"
#import "KofaxClass.h"

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#import <iOSPlayer/inc/ESpratIOSPlayer.h>
#else
#import "ESpratIOSPlayer.h"
#endif

#ifdef KOFAX_ENABLED

@interface SmfKofaxDelegate() {
    
}
@end


@implementation SmfKofaxDelegate

+ (id)sharedDelegate
{
    static SmfKofaxDelegate *sharedDelegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedDelegate = [[self alloc] init];
    });
    return sharedDelegate;
}

-(void) capturedKImage:(UIImage **)imageDataPtr
{
    KofaxClass *kofax = KofaxClass::getInstance();
    
    NSDate *date = [NSDate date];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"ddMMyyyyHHmmssSSS"];
    NSString *date_string = [formatter stringFromDate:date];
    [formatter release];
    
    NSMutableString *imageName = [[NSMutableString alloc] initWithString:@"temp_dwnMx_"];
    [imageName appendString:date_string];
    [imageName appendString:@".png"];
    
    NSString *basePath = [NSTemporaryDirectory() stringByAppendingPathComponent:@"kofax"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:basePath]) {
        [[NSFileManager defaultManager] createDirectoryAtPath:basePath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    NSString *imagePath = [basePath stringByAppendingPathComponent:imageName];
    
    // Save new image to file
    NSData *photoData = UIImagePNGRepresentation(*imageDataPtr);
    BOOL result = NO;
    if (photoData)
        result = [photoData writeToFile:imagePath atomically:YES];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        UINavigationController *vc = [[ESpratIOSPlayer SMFGetPlayer] SMFGetActiveNavigationController];
        [vc dismissViewControllerAnimated:YES completion:^() {
            
        }];
        
        char* buffer = strdup([imagePath UTF8String]);
        kofax->ImageCaptured(buffer);
        free(buffer);
    });
}

-(void) hideCaptureScreenKImg;
{
    UINavigationController *vc = [[ESpratIOSPlayer SMFGetPlayer] SMFGetActiveNavigationController];
    [vc dismissViewControllerAnimated:YES completion:^() {
        
    }];
    
    KofaxClass *kofax = KofaxClass::getInstance();
    kofax->ImageCaptureCancelled();
}

-(void) processedKImage:(kfxKEDImage *)IPPKImg withError:(NSString *)error
{
    KofaxClass *kofax = KofaxClass::getInstance();
    if (error) {
        char* buffer = strdup([error UTF8String]);
        kofax->ImageProcessError(buffer);
        free(buffer);
        return;
    }
    
    UIImage *image = [IPPKImg getImageBitmap];
    
    NSDate *date = [NSDate date];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"ddMMyyyyHHmmssSSS"];
    NSString *date_string = [formatter stringFromDate:date];
    [formatter release];
    
    NSMutableString *imageName = [[NSMutableString alloc] initWithString:@"temp_dwnMx_"];
    [imageName appendString:date_string];
    [imageName appendString:@".png"];
    
    NSString *basePath = [NSTemporaryDirectory() stringByAppendingPathComponent:@"kofax"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:basePath]) {
        [[NSFileManager defaultManager] createDirectoryAtPath:basePath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    NSString *imagePath = [basePath stringByAppendingPathComponent:imageName];
    
    // Save new image to file
    NSData *photoData = UIImagePNGRepresentation(image);
    BOOL result = NO;
    if (photoData)
        result = [photoData writeToFile:imagePath atomically:YES];
    
    dispatch_async(dispatch_get_main_queue(), ^() {
        char *buffer = strdup([imagePath UTF8String]);
        char *metaData = strdup([[IPPKImg imageMetaData] UTF8String]);
        kofax->ImageProcessed(buffer, metaData, image.size.width, image.size.height);
        free(buffer);
        free(metaData);
    });
}

@end

#endif
