//
//  SpBrAdViewDelegate.h
//  SpratIOS
//
//  Created by ugur on 8 Feb 2012.
//  Copyright 2011 Bivium. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#ifdef SPRAT_IOSPROJECT_DEBUG
#define SMF_ADMOB_ENABLED
#endif

#ifdef SMF_ADMOB_ENABLED

#import "GADBannerView.h"
#import "SpBrNuiAdView.h"

@interface SpBrAdViewDelegate : NSObject <GADBannerViewDelegate> {
    SpBrNuiAdView* smfObject;
}
@property SpBrNuiAdView* smfObject;
#else

@interface SpBrAdViewDelegate : NSObject {
    
}

#endif

@end
