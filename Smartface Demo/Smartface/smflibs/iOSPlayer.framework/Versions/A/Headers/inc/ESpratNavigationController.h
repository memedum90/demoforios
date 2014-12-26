#import <UIKit/UIKit.h>

__attribute__ ((visibility ("default"))) @protocol ESpratNavigationControllerInterface <NSObject>

-(void)setStatusBarNotified:(BOOL)value;

@end

__attribute__ ((visibility ("default"))) @interface ESpratNavigationController : NSObject {
    
}

+(id<ESpratNavigationControllerInterface>) SMFGetNavigationController;

@end
