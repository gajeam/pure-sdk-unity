//
//  PURPathProvider.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/25/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURService.h>

@class PURDefaultsService;

NS_ASSUME_NONNULL_BEGIN

@interface PURPathProvider : PURService

+ (void)migrateToNoneFileProtectionWithCompletion:(void (^)(void))completion;

+ (NSURL *)storageURLWithPath:(NSString *)path;

+ (NSString *)relativePathFromStorageURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
