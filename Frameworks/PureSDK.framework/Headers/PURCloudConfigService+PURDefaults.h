//
//  PURCloudConfigService+PURDefaults.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURCloudConfigService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURCloudConfigService (PURDefaults)

@property (nonatomic, readonly, class) PURDefaultsKey *logsEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *eventsEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *configEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *customEventEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *liveEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *associateMetadataEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *analyticsEndpoint;
@property (nonatomic, readonly, class) PURDefaultsKey *locationAggregationMappingEndpoint;

@property (nonatomic, readonly, class) PURDefaultsKey *configFetchInterval;

@property (nonatomic, readonly, class) PURDefaultsKey *enableLocationTracking;
@property (nonatomic, readonly, class) PURDefaultsKey *enableWhenInUseLocationTracking;
@property (nonatomic, readonly, class) PURDefaultsKey *enableVisitsTracking;
@property (nonatomic, readonly, class) PURDefaultsKey *enableLogMessageReports;
@property (nonatomic, readonly, class) PURDefaultsKey *enableLocationAggregationMode;

@property (nonatomic, readonly, class) PURDefaultsKey *enableDebugMode;

// Used to blacklist Europe for GDPR compliance.
@property (nonatomic, readonly, class) PURDefaultsKey *locationBlacklist;
@property (nonatomic, readonly, class) PURDefaultsKey *locationWhitelist;

@property (nonatomic, readonly, class) PURDefaultsKey *trackingAccuracy;
@property (nonatomic, readonly, class) PURDefaultsKey *minIntervalBetweenLocationEvents;
@property (nonatomic, readonly, class) PURDefaultsKey *whenInUseLocationWaitBetweenScans;

@property (nonatomic, readonly, class) PURDefaultsKey *onlySendWhenCharging;
@property (nonatomic, readonly, class) PURDefaultsKey *onlySendOnWifi;

@property (nonatomic, readonly, class) PURDefaultsKey *minBatteryLevel;

@property (nonatomic, readonly, class) PURDefaultsKey *liveEventFields;
@property (nonatomic, readonly, class) PURDefaultsKey *locationTrySendLive;
@property (nonatomic, readonly, class) PURDefaultsKey *visitTrySendLive;
@property (nonatomic, readonly, class) PURDefaultsKey *connectionTrySendLive;

@property (nonatomic, readonly, class) PURDefaultsKey *logIntervalUploadRetryCount;
@property (nonatomic, readonly, class) PURDefaultsKey *eventIntervalUploadRetryCount;

@property (nonatomic, readonly, class) PURDefaultsKey *eventsMaxBatchSize;
@property (nonatomic, readonly, class) PURDefaultsKey *logsMaxBatchSize;
@property (nonatomic, readonly, class) PURDefaultsKey *maxIntervalBetweenEventBatches;

@property (nonatomic, readonly, class) PURDefaultsKey *logMessageReportLevel;

@property (nonatomic, readonly, class) PURDefaultsKey *analyticsMaxBatchSizeKey;
@property (nonatomic, readonly, class) PURDefaultsKey *analyticsMaxTimeBetweenBatches;

@property (nonatomic, readonly, class) NSDictionary<NSString *, PURDefaultsKey *> *defaultKeyByName;

@end

NS_ASSUME_NONNULL_END
