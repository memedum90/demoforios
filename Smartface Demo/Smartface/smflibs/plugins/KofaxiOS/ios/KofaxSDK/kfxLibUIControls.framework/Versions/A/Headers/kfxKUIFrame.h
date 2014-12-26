//  API Reference
//  kfxKUIFrame.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>

//! This class defines a frame that can be applied to a capture control.
/**
 This class is responsible for defining a frame that will be drawn in a capture control
 to indicate the desired size of the target image inside of a capture control.
 */
@interface kfxKUIFrame : NSObject

//! The size of the visible area of the frame
/** The size of the area inside the frame in points that represents the visible area. It will 
 be centered inside the area of the control that it is set on and the area outside this size will
 be colored using the borderColor and the outerColor;
 */
@property (nonatomic) CGSize size;

//! The width of the border
/** A line width in points that sets the width of the border that is drawn around the visible 
 area of the frame */
@property (nonatomic) int borderWidth;

//! The color of the border
/** A color that is used to draw the border around the visible
 area of the frame */
@property (nonatomic, strong) UIColor* borderColor;

//! The color of the frame
/** A color that is used to the area outside the visible area to the edges of the control */
@property (nonatomic, strong) UIColor* outerColor;

@end
