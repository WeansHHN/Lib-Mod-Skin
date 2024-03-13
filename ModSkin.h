#ifndef ModSkinDSGaming_h
#define ModSkinDSGaming_h

#import "SSZipArchive/SSZipArchive.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define timer(sec) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, sec * NSEC_PER_SEC), dispatch_get_main_queue(), ^

@interface ModSkinDSGM : NSObject

+ (void)ActiveModDSGM; // mod skin ở đây

+ (void)RemoveModDSGM; // xoá mod ở đây

+ (void)ActiveModBackgroud;

@end

#endif