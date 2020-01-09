//
//  PURSystemStateService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/20/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>
#import <PureSDK/PURDefaultsService.h>
#import <PureSDK/PURCommittableFlagWrapper.h>

@class PURObserver, PURSwitch;

NS_ASSUME_NONNULL_BEGIN

@interface PURSystemStateService : PURService

// Saves to disk. NSSNumber. Default = NO.
@property (nonatomic, class, readonly) PURDefaultsKey *applicationWasTerminated;

// True if the last session was terminated by iOS.
// Relies on `applicationWillTerminate` notifications being sent.
@property (nonatomic, readonly) PURSwitch *lastSessionWasTerminated;

@property (nonatomic, readonly) PURSwitch *isLowPowerModeActive;

// UIApplicationState == Inactive || Background
@property (nonatomic, readonly) PURSwitch *isInBackground;

// UIApplicationState == Active
@property (nonatomic, readonly) PURSwitch *isInForeground;

// True if the launch dictionary contained UIApplicationLaunchOptionsLocationKey.
@property (nonatomic, readonly) PURSwitch *wasStartedByLocationEvent;

// An observer that tracks whether or not the battery is above the threshold configured from the cloud config.
@property (nonatomic, readonly) PURObserver *isBatteryLevelAboveThresholdObserver;

// An observer that tracks whether or not we're in the background.
@property (nonatomic, readonly) PURObserver *isInBackgroundObserver;

// An observer that tracks whether or not we're in the foreground.
// App multitask, and notification center cause this to be triggered.
@property (nonatomic, readonly) PURObserver *isInForegroundObserver;

// An observer that tracks whether or not the phone is being charged.
@property (nonatomic, readonly) PURObserver *isChargingObserver;

@property (nonatomic, readonly) PURCommittableValueWrapper<NSNumber *> *latestBatteryLevel;
@property (nonatomic, readonly) PURCommittableValueWrapper<NSNumber *> *isLikelyDebugModeWrapper;

@end

NS_ASSUME_NONNULL_END
