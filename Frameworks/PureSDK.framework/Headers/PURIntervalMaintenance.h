//
//  PURIntervalMaintenance.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/7/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURServiceLocator, PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURIntervalMaintenance : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                  intervalClass:(Class)intervalClass
                  matchingClass:(Class)matchingClass
                    serialQueue:(PURQueue *)serialQueue
                      logPrefix:(NSString *)logPrefix;

- (void)deleteIntervalsAndEventsAccordingToPolicy:(dispatch_group_t)takeOffGroup;

@end

NS_ASSUME_NONNULL_END
