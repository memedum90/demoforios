//
// API Reference File
//  kfxKUICommon.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

//! An enumeration to set the flash mode of a capture control
/**
 Use one of the values of this enumeration to set the flash mode of a 
 capture control.
 */
typedef enum
{
    kfxKUIFlashOn = 0,
    kfxKUIFlashOff = 1,
    kfxKUIFlashAuto = 2
} kfxKUIFlashSetting;

//! An enumeration to set the guiding line mode of a barcode capture control
/**
 Use one of the values of this enumeration to set the guiding line display
 mode of a barcode capture contorl.
 */
typedef enum
{
    kfxKUIGuidingLineOff = 0,
    kfxKUIGuidingLineLandscape = 1,
    kfxKUIGuidingLinePortrait = 2
} kfxKUIGuidingLine;

//! An enumeration containing the different barcode symbologies that can be detected
/**
 One or more of these values can be passed to a barcode capture control to restrict
 search to those symbologies.
 */
typedef enum
{
    kfxKUISymbologyCode39 = 0,
    kfxKUISymbologyPdf417 = 1,
    kfxKUISymbologyQR = 2,
    kfxKUISymbologyDataMatrix = 3,
    kfxKUISymbologyCode128 = 4,
    kfxKUISymbologyCode25 = 5,
    kfxKUISymbologyEAN = 6,
    kfxKUISymbologyUPC = 7,
    kfxKUISymbologyCodabar = 8,
    kfxKUISymbologyAztec = 9,
    kfxKUISymbologyCode93 = 10
} kfxKUISymbology;

//! An enumeration containing the different possible barcode search directions
/**
 One or more of these values can be passed to a barcode capture control to restrict
 the directions that are searched for barcodes.
 */
typedef enum
{
    kfxKUIDirectionHorizontal = 1 | 2,
    kfxKUIDirectionVertical = 4 | 8,
    kfxKUIDirectionAll = 1 | 2 | 4 | 8,
} kfxKUISearchDirection;