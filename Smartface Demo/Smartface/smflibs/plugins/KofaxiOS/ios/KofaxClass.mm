//
//  KofaxClass.mm
//  Smartface
//
//  Created by ugur kilic on 20.04.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import "KofaxClass.h"
#import "KofaxCaptureProcessManager.h"
#import "SmfKofaxDelegate.h"

void KofaxClass::SetSDKLicense(char* licenseStr)
{
#ifdef KOFAX_ENABLED
    NSString *license = [NSString stringWithFormat:@"%s",licenseStr];
    kfxKUTLicensing *licenseConfig = [[kfxKUTLicensing alloc] init];
    if([licenseConfig setMobileSDKLicense:license] == KMC_SUCCESS)
    {
        
    }
    [licenseConfig release];
#endif
}

void KofaxClass::OpenCaptureScreen(OptionParameter* temp){
#ifdef KOFAX_ENABLED
    KofaxCaptureProcessManager *captureProcessInstanceI = [KofaxCaptureProcessManager sharedClassInstance];
    captureProcessInstanceI.delegate = [SmfKofaxDelegate sharedDelegate];
    [captureProcessInstanceI presentCaptureScreenKImgWithOptions:temp];
#endif
}

void KofaxClass::ProcessImg(char *imgUrl,char *profile){
#ifdef KOFAX_ENABLED
    KofaxCaptureProcessManager *captureProcessInstanceI = [KofaxCaptureProcessManager sharedClassInstance];
    captureProcessInstanceI.delegate = [SmfKofaxDelegate sharedDelegate];
    
    NSString *filePath = [NSString stringWithUTF8String:imgUrl];
    UIImage *imageFile = [UIImage imageWithContentsOfFile:filePath];
    if (imageFile) {
        kfxKEDImage *kofaxImage = [[kfxKEDImage alloc] initWithImage:imageFile];
        KofaxCaptureProcessManager *captureProcessInstanceI = [KofaxCaptureProcessManager sharedClassInstance];
        captureProcessInstanceI.delegate = [SmfKofaxDelegate sharedDelegate];
        
        kfxKEDImagePerfectionProfile * kPerfectionProf = [[kfxKEDImagePerfectionProfile alloc]initWithName:@"ipp_Check" andOperations:[NSString stringWithUTF8String:profile]];
        [captureProcessInstanceI processCapturedKImg:kofaxImage WithIPP:kPerfectionProf];
        [kPerfectionProf release];
        kPerfectionProf = nil;
    } else {
        ImageProcessError("No image.");
    }
#endif
}
