//
//  PURBackgroundCloudConfigScheduler.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/11/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURServiceLocator, PURQueue, PURDefaultsKey, PURDefaultsTokenBag;
@class PUROperation, PUROngoingBackgroundCloudConfigFetches;

NS_ASSUME_NONNULL_BEGIN

typedef PUROperation * _Nonnull(^PURScheduleRequestBlock)(NSDate *beginDate, void (^didSchedule)(NSURLSessionTask *task));

@interface PURBackgroundCloudConfigScheduler : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                    serialQueue:(PURQueue *)serialQueue
                concurrentQueue:(PURQueue *)concurrentQueue
    lastConfigFetchTimestampKey:(PURDefaultsKey *)lastConfigFetchTimestampKey
           scheduleRequestBlock:(PURScheduleRequestBlock)scheduleRequestWithBeginDate API_AVAILABLE(ios(11.0));

- (void)takeOff API_AVAILABLE(ios(11.0));

// Returns YES if this scheduler knows about the finished task.
- (BOOL)didFinishScheduledTaskWithIdentifier:(NSUInteger)taskIdentifier;

@end

NS_ASSUME_NONNULL_END
