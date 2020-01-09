//
//  PURLocationTrackingStateObserver.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/18/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@class PURServiceLocator, PURDefaultsTokenBag, PURQueue, PURSwitch, PURObserver;

typedef void(^PUREnabledCallback)(BOOL enabled);

@interface PURLocationTrackingStateCallbacks : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, copy) PUREnabledCallback updateLocationTrackingState;
@property (nonatomic, copy) PUREnabledCallback updatePeriodicTrackingState;
@property (nonatomic, copy) PUREnabledCallback updateSleepTrackingMode;
@property (nonatomic, copy) PUREnabledCallback updateVisitsTrackingState;

- (instancetype)initWithUpdateLocationTrackingState:(PUREnabledCallback)loc
                                updatePeriodicState:(PUREnabledCallback)periodic
                                   updateSleepState:(PUREnabledCallback)sig
                                  updateVisitsState:(PUREnabledCallback)visits;

@end

@interface PURLocationTrackingStateObserver : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) PURObserver *locationAuthorizationObserver;

- (instancetype)initWithQueue:(PURQueue *)queue
locationAuthorizationObserver:(PURObserver *)observer
         stateUpdateCallbacks:(PURLocationTrackingStateCallbacks *)callbacks;
    
- (void)beginObservingStateWithLocator:(PURServiceLocator *)locator
                              tokenBag:(PURDefaultsTokenBag *)tokenBag;

- (void)setSleepModeTrackingEnabled:(BOOL)enabled;
- (void)setIsInsideHighPriorityRegion:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
