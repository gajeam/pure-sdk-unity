//
//  PURLocationTrackingService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURInterruptibleTimer;
@class PURDefaultsKey;
@class PURObserver;

#import <PureSDK/PURService.h>
#import <PureSDK/PURTrackingEnums.h>

#import <PureSDK/PURLocationTracker.h>

#import <PureSDK/PURMovementClassifier.h>

typedef struct PURLocationServiceState {
    PURTransportMethod transportMethod;
    PURTrackingAccuracy trackingAccuracy;
    PURTrackingState trackingState;
} PURLocationServiceState;

NS_ASSUME_NONNULL_BEGIN

// regular location tracking <-> significant location tracking + visit tracking
@interface PURLocationTrackingService : PURService

// YES if inside area where GDPR does not takes affect. When NO, tracking uses
// only significant tracking and no location data is collected.
// The default value of the backing default key is YES.
@property (nonatomic, readonly, getter=isInsideWhitelistedArea) BOOL insideWhitelistedArea;

// Indicates if we are in the request location event cycle.
// If YES, then we're either waiting to request another location,
// or waiting for an location from the operating system.
@property (nonatomic, readonly) PURSwitch *periodicLocationActive;

@property (nonatomic, readonly) PURObserver *locationAuthorizationObserver;

@end

@interface PURLocationTrackingService (Delegates)
<
PURLocationTrackerDelegate,
PURMovementClassifierDelegate
>
@end

NS_ASSUME_NONNULL_END
