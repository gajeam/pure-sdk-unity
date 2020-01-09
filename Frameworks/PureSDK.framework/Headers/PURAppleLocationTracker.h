//
//  PURLocationTracker.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURLocationTracker.h>
#import <PureSDK/PURDefaultsService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAppleLocationTracker : NSObject <PURLocationTracker>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<PURLocationTrackerDelegate>)delegate queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
