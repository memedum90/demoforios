//  API Reference
//
//  kfxKEDBoundingRectangle.h
//
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
//! Bounding Rectangle of four coordinates.
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 An instance of this class contains the bounding rectangle (in pixels) for an item in an image.
 These rectangle coordinates should always be less than or equal to the image width and height.
 See also: kfxKEDBoundingTetragon
 */
@interface kfxKEDBoundingRectangle : NSObject

// ===================================================
//! Represents the left side of a rectangle
/**
 This left side of the rectangle references the least X coordinate.
 */
@property (assign, atomic) int rectLeft;


// ===================================================
//! Represents the top edge of a rectangle
/**
 This top side of the rectangle references the least Y coordinate.
 */
@property (assign, atomic) int rectTop;


// ===================================================
//! Represents the right side of a rectangle
/**
 This right side of the rectangle references the largest X coordinate.
 */
@property (assign, atomic) int rectRight;


// ===================================================
//! Represents the bottom edge of a rectangle
/**
 This bottom side of the rectangle references the largest Y coordinate.
 */
@property (assign, atomic) int rectBottom;

- (id)init;

@end
