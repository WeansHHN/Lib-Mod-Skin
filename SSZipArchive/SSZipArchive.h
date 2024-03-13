//
//  SSZipArchive.h
//  SSZipArchive
//
//  Created by Sam Soffes on 7/21/10.
//  Copyright (c) Sam Soffes 2010-2013. All rights reserved.
//

#ifndef _SSZIPARCHIVE_H
#define _SSZIPARCHIVE_H

#import "minizip/unzip.h"
#import <Foundation/Foundation.h>

@protocol SSZipArchiveDelegate;

@interface SSZipArchive : NSObject

// Password check
+ (BOOL)isFilePasswordProtectedAtPath:(NSString * _Nonnull)path;

// Unzip
+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path toDestination:(NSString * _Nonnull)destination;
+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path toDestination:(NSString * _Nonnull)destination delegate:(nullable id<SSZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path toDestination:(NSString * _Nonnull)destination overwrite:(BOOL)overwrite password:(nullable NSString *)password error:(NSError * _Nullable * _Nullable)error;
+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path toDestination:(NSString * _Nonnull)destination overwrite:(BOOL)overwrite password:(nullable NSString *)password error:(NSError * _Nullable * _Nullable)error delegate:(nullable id<SSZipArchiveDelegate>)delegate NS_REFINED_FOR_SWIFT;

+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path
          toDestination:(NSString * _Nonnull)destination
     preserveAttributes:(BOOL)preserveAttributes
              overwrite:(BOOL)overwrite
               password:(nullable NSString *)password
                  error:(NSError * _Nullable * _Nullable)error
               delegate:(nullable id<SSZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path
          toDestination:(NSString * _Nonnull)destination
       progressHandler:(void (^ _Nonnull)(NSString * _Nonnull entry, unz_file_info zipInfo, long entryNumber, long total))progressHandler
     completionHandler:(void (^ _Nonnull)(NSString * _Nonnull path, BOOL succeeded, NSError * _Nullable error))completionHandler;

+ (BOOL)unzipFileAtPath:(NSString * _Nonnull)path
          toDestination:(NSString * _Nonnull)destination
              overwrite:(BOOL)overwrite
               password:(nullable NSString *)password
       progressHandler:(void (^ _Nonnull)(NSString * _Nonnull entry, unz_file_info zipInfo, long entryNumber, long total))progressHandler
     completionHandler:(void (^ _Nonnull)(NSString * _Nonnull path, BOOL succeeded, NSError * _Nullable error))completionHandler;

// Zip

// without password
+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withFilesAtPaths:(NSArray<NSString *> * _Nonnull)paths;
+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withContentsOfDirectory:(NSString * _Nonnull)directoryPath;

+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withContentsOfDirectory:(NSString * _Nonnull)directoryPath keepParentDirectory:(BOOL)keepParentDirectory;

// with password, password could be nil
+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withFilesAtPaths:(NSArray<NSString *> * _Nonnull)paths withPassword:(nullable NSString *)password;
+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withContentsOfDirectory:(NSString * _Nonnull)directoryPath withPassword:(nullable NSString *)password;
+ (BOOL)createZipFileAtPath:(NSString * _Nonnull)path withContentsOfDirectory:(NSString * _Nonnull)directoryPath keepParentDirectory:(BOOL)keepParentDirectory withPassword:(nullable NSString *)password;

// - (instancetype)initWithPath:(NSString * _Nonnull)path;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL open;
- (BOOL)writeFile:(NSString * _Nonnull)path withPassword:(nullable NSString *)password;
- (BOOL)writeFolderAtPath:(NSString * _Nonnull)path withFolderName:(NSString * _Nonnull)folderName withPassword:(nullable NSString *)password;
- (BOOL)writeFileAtPath:(NSString * _Nonnull)path withFileName:(nullable NSString *)fileName withPassword:(nullable NSString *)password;
- (BOOL)writeData:(NSData * _Nonnull)data filename:(nullable NSString *)filename withPassword:(nullable NSString *)password;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL close;

@end

@protocol SSZipArchiveDelegate <NSObject>

@optional

- (void)zipArchiveWillUnzipArchiveAtPath:(NSString * _Nonnull)path zipInfo:(unz_global_info)zipInfo;
- (void)zipArchiveDidUnzipArchiveAtPath:(NSString * _Nonnull)path zipInfo:(unz_global_info)zipInfo unzippedPath:(NSString * _Nonnull)unzippedPath;

- (BOOL)zipArchiveShouldUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString * _Nonnull)archivePath fileInfo:(unz_file_info)fileInfo;
- (void)zipArchiveWillUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString * _Nonnull)archivePath fileInfo:(unz_file_info)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString * _Nonnull)archivePath fileInfo:(unz_file_info)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString * _Nonnull)archivePath unzippedFilePath:(NSString * _Nonnull)unzippedFilePath;

- (void)zipArchiveProgressEvent:(unsigned long long)loaded total:(unsigned long long)total;
- (void)zipArchiveDidUnzipArchiveFile:(NSString * _Nonnull)zipFile entryPath:(NSString * _Nonnull)entryPath destPath:(NSString * _Nonnull)destPath;

@end

#endif /* _SSZIPARCHIVE_H */
