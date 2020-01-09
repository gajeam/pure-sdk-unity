//
//  PURIntervalFuser.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/6/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDefaultProperty.h>
#import <PureSDK/PURIntervalProtocol.h>
#import <PureSDK/PURMulticastDispatcher.h>

@class PURServiceLocator, PUREventStore;

NS_ASSUME_NONNULL_BEGIN

@interface PURIntervalFuser : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                  intervalClass:(Class)intervalClass
              batchSizeProperty:(PURDefaultsKey *)batchSizeProperty
                      logPrefix:(NSString *)logPrefix
                    serialQueue:(PURQueue *)serialQueue
                concurrentQueue:(PURQueue *)concurrentQueue
        serializedAsEventsArray:(BOOL)serializedAsEventsArray;

// Only dispatches the intervals that were consumed to create the new interval
@property (nonatomic) PURMulticastDispatcher<NSArray<PURIntervalObject *> *> *fusedIntervalsDispatcher;

- (void)fuseOnDiskSerializedEvents:(dispatch_group_t)takeOffGroup;

@end

NS_ASSUME_NONNULL_END
