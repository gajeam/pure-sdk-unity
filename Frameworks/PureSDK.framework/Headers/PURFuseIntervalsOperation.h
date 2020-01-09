//
//  PURFuseIntervalsOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/6/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURIntervalProtocol.h>
#import <PureSDK/PURAsyncBlockOperation.h>
#import <PureSDK/PUREventStore.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURFuseIntervalsOperation : PURAsyncBlockOperation

- (instancetype)initWithEventStore:(PUREventStore *)eventStore
                         intervals:(NSArray<PURIntervalObject *> *)intervals
                              name:(NSString *)name
                       serialQueue:(PURQueue *)serialQueue
                   concurrentQueue:(PURQueue *)concurrentQueue
           serializedAsEventsArray:(BOOL)serializedAsEventsArray;

@end

NS_ASSUME_NONNULL_END
