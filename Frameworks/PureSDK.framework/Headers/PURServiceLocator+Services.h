//
//  PURServiceLocator+Services.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURServiceLocator.h>

#import <PureSDK/PUREventStore.h>
#import <PureSDK/PURLocationTrackingService.h>
#import <PureSDK/PURDefaultsService.h>
#import <PureSDK/PURSystemStateService.h>
#import <PureSDK/PURAPIClient.h>
#import <PureSDK/PURDeviceInformationService.h>
#import <PureSDK/PURConnectionMonitoringService.h>
#import <PureSDK/PUREventLinker.h>
#import <PureSDK/PURCloudConfigService.h>
#import <PureSDK/PURRuntimeConfigurationService.h>
#import <PureSDK/PURBackgroundAPIClient.h>
#import <PureSDK/PURDebugNotificationService.h>
#import <PureSDK/PURLiveEventService.h>
#import <PureSDK/PURErrorRetryService.h>
#import <PureSDK/PURAnalyticsService.h>
#import <PureSDK/PUREventUploadingService.h>
#import <PureSDK/PURPureIdentifierService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURServiceLocator (Services)

@property (nonatomic, readonly) PUREventStore *eventStore;
@property (nonatomic, readonly) PURLocationTrackingService *locationTracker;
@property (nonatomic, readonly) PURDefaultsService *defaultsService;
@property (nonatomic, readonly) PURSystemStateService *systemState;
@property (nonatomic, readonly) PURLoggingService *logger;
@property (nonatomic, readonly) PURDeviceInformationService *deviceInfo;
@property (nonatomic, readonly) PURConnectionMonitoringService *connectionMonitoring;
@property (nonatomic, readonly) PUREventLinker *eventLinker;
@property (nonatomic, readonly) PURCloudConfigService *cloudConfig;
@property (nonatomic, readonly) PURRuntimeConfigurationService *runtimeConfig;
@property (nonatomic, readonly) PURAPIClient *apiClient;
@property (nonatomic, readonly) PURLiveEventService *liveEvent;
@property (nonatomic, readonly) PURBackgroundAPIClient *backgroundApiClient;
@property (nonatomic, readonly) PURErrorRetryService *errorRetry;
@property (nonatomic, readonly) PURDebugNotificationService *notifications API_AVAILABLE(ios(10.0));
@property (nonatomic, readonly) PURAnalyticsService *analytics;
@property (nonatomic, readonly) PUREventUploadingService *eventUpload;
@property (nonatomic, readonly) PURPureIdentifierService *identifierService;

@end

NS_ASSUME_NONNULL_END
