//
//  PURDeviceInformation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/9/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Corresponds to "DeviceInfo" in the API spec
@interface PURDeviceInformation : NSObject <NSCopying>

@property (nonatomic, nullable) NSString *adid; // The AdvertisingId for Android or iOS
@property (nonatomic)           BOOL     adidLimited; // If AdvertisingId is limited on the device

@property (nonatomic, nullable) NSString *os; // The main operating system. android or ios
@property (nonatomic, nullable) NSString *osVersion; // The OS version

// device
@property (nonatomic, nullable) NSString *manufacturer; // The manufacturer of the device
@property (nonatomic, nullable) NSString *model; // The model of the device
@property (nonatomic, nullable) NSString *deviceName;

@property (nonatomic, nullable) NSString *clientId;
@property (nonatomic, nullable) NSString *appId; // The applicationId of the app
@property (nonatomic, nullable) NSString *publisherId;

@property (nonatomic, nullable) NSString *appVersion; // The version of the application
@property (nonatomic, nullable) NSString *sdkVersion; // The current PureSDK version

@property (nonatomic, nullable) NSString *locale;

// permissions
@property (nonatomic, nullable) NSString *location; // The type of location authentication authorized. always, foreground, none
@property (nonatomic)           BOOL     activity; // If activity tracking is available

// cloud config
@property (nonatomic, nullable) NSString *configUrl; // The config endpoint used by the app installation
@property (nonatomic)           BOOL     trackingEnabled; // If tracking is enabled
@property (nonatomic)           BOOL     locationServicesEnabled; // If device has location services enabled.
@property (nonatomic)           BOOL     significantLocationEnabled; // If device allows use of significant location change service.
@property (nonatomic)           BOOL     beaconMonitoringEnabled; // If device device allows monitoring of CLBeaconRegions.
@property (nonatomic)           BOOL     regionMonitoringEnabled; // If device device allows monitoring of CLCircularRegions.
@property (nonatomic)           BOOL     sessionAnalyticsEnabled; // Pure.lightweightAnalyticsEnabled

// connection info
@property (nonatomic, nullable) NSString *mcc; // The Mobile Country Code of the SIM
@property (nonatomic, nullable) NSString *mnc; // The Mobile Network Code of the SIM
@property (nonatomic, nullable) NSString *timestamp; // ISO8601 timestamp for when connection info was last updated

@property (nonatomic, nullable) NSString *generatedAt;
@property (nonatomic, nullable) NSString *scheduledFor;

+ (NSArray<NSString *> *)allFields;

- (NSDictionary<NSString *, id> *)dictionaryRepresentation;
- (id)copyWithZone:(nullable NSZone *)zone;

@end

NS_ASSUME_NONNULL_END
