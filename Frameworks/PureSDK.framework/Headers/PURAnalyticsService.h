//
//  PURAnalyticsService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/17/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>

#import <PureSDK/PURAnalyticsEvent.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAnalyticsService : PURService

- (void)generateEventOfType:(PURAnalyticsEventType)type atTimestamp:(NSNumber *)timestamp;

@end

NS_ASSUME_NONNULL_END
