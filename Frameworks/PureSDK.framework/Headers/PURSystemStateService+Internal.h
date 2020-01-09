//
//  PURSystemStateService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 6/10/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURSystemStateService.h>

@interface PURSystemStateService (Internal)

@property (nonatomic) PURSwitch *lastSessionWasTerminated;
@property (nonatomic) PURSwitch *isLowPowerModeActive;
@property (nonatomic) PURSwitch *wasStartedByLocationEvent;

@property (nonatomic) PURSwitch *isInBackground;
@property (nonatomic) PURSwitch *isMonitoringLifecycleEvents;

@property (nonatomic, readonly) PURObserver *isBatteryLevelAboveThresholdObserver;
@property (nonatomic, readonly) PURObserver *isInBackgroundObserver;
@property (nonatomic, readonly) PURObserver *isChargingObserver;

- (void)setBatteryLevel:(double)battery;

@end
