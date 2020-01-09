//
//  PUREventDescription.h
//  FluxloopPureSDK
//
//  Created by Hakon Hanesand on 11/15/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURLogEvent.h>

@class PUREventLinkerState, PURMutableEventLinkerState;
@class PURSystemStateService, PURQueue, PURDeviceInformationService;

NS_ASSUME_NONNULL_BEGIN

@interface PUREventDescription : NSObject <NSCoding>

@property (nonatomic, readonly) NSTimeInterval eventTimestamp;
@property (nonatomic, readonly) BOOL isInBackground;
@property (nonatomic, readonly) BOOL lowPowerModeActive;

@property (nonatomic, readonly) BOOL isCharging;
@property (nonatomic, readonly) float batteryLevel;

@property (nonatomic, readonly) PURLogEventType eventType;
@property (nonatomic, readonly) PUREventLinkerState *linkerState;
@property (nonatomic, readonly) NSDictionary *deviceInformation;

- (instancetype)initWithEventType:(PURLogEventType)eventType
                      linkerState:(PUREventLinkerState *)linkerState
                      systemState:(PURSystemStateService *)systemState
         deviceInformationService:(PURDeviceInformationService *)deviceInformationService;

- (instancetype)initWithEventType:(PURLogEventType)eventType
                      linkerState:(PUREventLinkerState *)linkerState
                        timestamp:(NSTimeInterval)timestamp
                   isInBackground:(BOOL)background
               lowPowerModeActive:(BOOL)lowPowerModeActive
                       isCharging:(BOOL)isCharging
                     batteryLevel:(float)batteryLevel
                deviceInformation:(NSDictionary *)deviceInformation;

- (void)updateLinkerState:(void (^)(PURMutableEventLinkerState *))update onQueue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
