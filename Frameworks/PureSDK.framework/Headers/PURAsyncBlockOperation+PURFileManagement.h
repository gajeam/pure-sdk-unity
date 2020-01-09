//
//  PURAsyncBlockOperation+PURFileManagement.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/26/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURAsyncBlockOperation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAsyncBlockOperation (PURFileManagement)

+ (instancetype)readDataAtURL:(NSURL *)targetFileURL queue:(PURQueue *)queue;

+ (instancetype)writeToTargetFileOperation:(NSURL *)targetFileURL queue:(PURQueue *)queue;

/// Ignores NSFileNoSuchFileError.
+ (instancetype)deleteFileAtTargetURLOperation:(NSURL *)targetFileURL
                                         queue:(PURQueue *)queue;

+ (instancetype)copyItemFrom:(NSURL *)from
                          to:(NSURL *)to
                 overwriting:(BOOL)overwriting
           ignoringErrorCode:(NSInteger)ignoring
                       queue:(PURQueue *)queue;

+ (instancetype)moveItemFrom:(NSURL *)from
                          to:(NSURL *)to
                 overwriting:(BOOL)overwriting
           ignoringErrorCode:(NSInteger)ignoring
                       queue:(PURQueue *)queue;

+ (instancetype)setFileAttributes:(NSDictionary<NSFileAttributeKey, id> *)attrs
                            atURL:(NSURL *)url
                ignoringErrorCode:(NSInteger)acceptibleErrorCode
                            queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
