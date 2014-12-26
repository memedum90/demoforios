//
//  API Reference
//  kfxKUIImageReviewAndEditNew.h
//  Framework: kfxLibUIControls
//
//  Created by Nathan Gopen on 8/13/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>

@class kfxKEDImage;
@class kfxKEDBoundingTetragon;

//! Displays an image for review, and an optional crop rectangle/tetragon, for user to manually adjust page boundaries.
/**
The Image Edit and Review Control object provides a means for the application to display an image (processed or unprocessed) to the user for review and/or edit purposes. The actual image processing operation that “edits” the image according to the user’s preferences is performed separately by the application using the ImageProcessing object.  The two main features supported in Mobile SDK 2.0 are zoom and set page boundaries.  Zoom allows the user, via platform specific gestures, to magnify the image in order to set more detail.  Set Page Boundaries provides a UI for setting the boundaries of a selection area (typically the page boundaries) for subsequent cropping and rectangularization by the application upon receiving the coordinates of the bounding rectangle or tetragon through an event.  The application is responsible for creating and displaying any screen overlays which offer user feedback, such as “image blurry”.
 */
@interface kfxKUIImageReviewAndEdit : UIControl
<UIGestureRecognizerDelegate>
{
    
    
}

+(void) initializeControl;

// ==========================================================
//                  P R O P E R T I E S
// ==========================================================


// ==========================================================
//! The crop tetragon specified during edit operations.
/**
 Developer can set the tetragon coordinates to initialize the control before displaying bounding tetragon (crop rectangle), or allow the control to set it to a default. The library returns this crop tetragon while edit is in progress.  After the user closes the view, this object contains the users final corner points after editing is complete. */
@property (nonatomic,strong) kfxKEDBoundingTetragon* cropTetragon;


// ==========================================================
//! Color of lines in cropping rectangle/tetragon.
@property (nonatomic, strong) UIColor * cropLineColor;

// ==========================================================
//! Color of corner handles (circles) in cropping rectangle/tetragon.
@property (nonatomic, strong) UIColor * cropCornerColor;



typedef enum LINE_STYLE_ENUM {
    LINE_STYLE_SOLID, LINE_STYLE_DOTTED
} kfxUILineStyle;

// ==========================================================
//! Whether crop rectangle lines should be solid or dashed.
@property (nonatomic, assign) kfxUILineStyle cropLineStyle;        

// ==========================================================
//                  M E T H O D S
// ==========================================================



/// Set image to review.
/** 
 This method call is used to load the image object to be reviewed.  It also calculates a default crop rectangle (tetragon) based on the size and layout of the imageObjectToReview.   If you want to override the default crop rectangle, change the cropTetragon property prior to calling showCropRectangle. This method will not succeed if a valid image processing license is not set.
 
 @param imageObjectToReview: This is the kfxKEDImage object to review
 
 @return Status - KMC_SUCCESS (success), KMC_IP_LICENSE_INVALID (no license found), KMC_IP_NO_REPRESENTATION (not bitmap or file based, or buffered image)
 
 @code
    int setImageStatus = [ImageReview setImage:myImage];
 @endcode
 */

- (int)setImage: (kfxKEDImage*) imageObjectToReview;


/// Show or hide crop rectangle (tetragon).
/**
 Displays cropping rectangle with draggable corner indicators.  Corners can be repositioned independently, creating a tetragon.  Individual sides can be dragged to resize the rectangle and maintain the rectangular shape.
 
 @param shouldShow: set TRUE to show it, or FALSE to hide.  
 
 @return void
 
 */

-(void) showCropRectangle:(BOOL) shouldShow;


@end

