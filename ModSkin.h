#ifndef ModSkin_h
#define ModSkin_h

#import "SSZipArchive/SSZipArchive.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define timer(sec) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, sec * NSEC_PER_SEC), dispatch_get_main_queue(), ^

@interface ModSkin : NSObject

+ (void)ActiveModFile; // mod skin ở đây

+ (void)ActiveMod; // mod skin ở đây

+ (void)ActiveModFull;

+ (void)Backup;
@end

#endif