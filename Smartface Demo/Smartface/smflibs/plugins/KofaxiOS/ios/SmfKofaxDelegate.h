//
//  SmfKofaxDelegate.h
//  Smartface
//
//  Created by ugur kilic on 20.04.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KofaxCaptureProcessManager.h"

#ifdef KOFAX_ENABLED

@interface SmfKofaxDelegate : NSObject <KofaxCaptureProcessDelegate> {
    
}

+ (id)sharedDelegate;

-(void) capturedKImage:(UIImage **)imageDataPtr;
-(void) processedKImage:(kfxKEDImage *)IPPKImg withError:(NSString *)error;
-(void) hideCaptureScreenKImg;

@end

#endif