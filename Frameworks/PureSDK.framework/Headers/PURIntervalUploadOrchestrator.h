//
//  PURIntervalUploadOchestrator.h
//  PureSDK
//
//  Created by Hakon Hanesand on 4/1/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDefaultsKey.h>

@class PURServiceLocator, PURQueue, PURAPIClient;
@class PURDefaultsTokenBag, PURBackgroundAPIClient, PURSystemStateService;

NS_ASSUME_NONNULL_BEGIN

@interface PURIntervalUploadOrchestrator : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
              dataDirectoryName:(NSString *)dataDirectory
            backupDirectoryName:(NSString *)backupDirectory
            uploadingEventClass:(Class)matchingClass
                  intervalClass:(Class)intervalClass
             intervalMaxSizeKey:(PURDefaultsKey<NSNumber *> *)intervalMaxSizeKey
          maxTimeBetweenBatches:(PURDefaultsKey<NSNumber *> *)maxTimeBetweenBatches
        eventEndpointDefaultKey:(PURDefaultsKey<NSString *> *)eventEndpointDefaultKey
           retryCountDefaultKey:(PURDefaultsKey<NSNumber *> *)retryCountDefaultKey
               lastBatchTimeKey:(PURDefaultsKey<NSNumber *> *)lastBatchTimeKey
                      logPrefix:(NSString *)logPrefix
                       tokenBag:(PURDefaultsTokenBag *)tokenBag
       shouldExportAsDictionary:(BOOL)serializeAsEventsArray;

- (void)foregroundPushPendingIntervalsForceBatch:(BOOL)force
                                      completion:(void (^ _Nullable)(void))completion;

- (void)takeOffWithDispatchGroup:(dispatch_group_t)takeOffGroup
                  foregroundPush:(BOOL)foregroundPush
              forceCreateBatches:(BOOL)forceBatching;

@end

NS_ASSUME_NONNULL_END
