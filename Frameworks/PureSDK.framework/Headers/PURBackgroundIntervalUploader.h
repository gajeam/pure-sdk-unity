//
//  PURBackgroundIntervalUploader.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/26/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PUREventInterval.h>
#import <PureSDK/PURDefaultsKey.h>
#import <PureSDK/PURIntervalProtocol.h>

@class PURServiceLocator, PURQueue, PURBackgroundIntervalUploader, PURAsyncBlockOperation, PURRequestResponse;
@class PURBackgroundAPIClient;

NS_ASSUME_NONNULL_BEGIN

typedef void(^UploadFailureBlock)(PURIntervalObject *, BOOL canceled);

@interface PURBackgroundIntervalUploader<IntervalClass: PURIntervalObject *> : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                 frameworkQueue:(PURQueue *)queue
                concurrentQueue:(PURQueue *)concurrent
                  intervalClass:(Class)intervalClass
                      logPrefix:(NSString *)logPrefix
          uploadEndpointDefault:(PURDefaultsKey<NSString *> *)uploadEndpointDefault
              retryCountDefault:(PURDefaultsKey<NSNumber *> *)retryCountDefault;

@property (nonatomic, copy) void (^uploadDidSucceedBlock)(PURIntervalObject *);
@property (nonatomic, copy) UploadFailureBlock uploadDidFailBlock;

- (void)validateOngoingUploadTasks:(dispatch_group_t)dispatchGroup
             scheduleEligibleTasks:(BOOL)shouldScheduleTasks;

- (void)pur_commitEventIntervalsForUpload:(NSArray<IntervalClass> *)eventIntervals
                               completion:(void (^ _Nullable)(void))completion;

// Exposed for ForegroundUploader. We can use common logic whenever a request completes.
- (void)pur_didFinishRequest:(PURRequestResponse *)response forEventInterval:(PURIntervalObject *)eventInterval;

- (void)notifyWhenBackgroundTaskProcessingComplete:(void (^)(void))complete onQueue:(PURQueue *)queue;

@property (nonatomic, readonly, weak) PURBackgroundAPIClient *backgroundAPIClient;
@property (nonatomic, readonly) dispatch_group_t networkTaskResultProcessing;

@end

NS_ASSUME_NONNULL_END
