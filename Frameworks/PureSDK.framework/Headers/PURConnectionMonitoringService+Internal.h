//
//  PURConnectionMonitoringService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 1/9/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURConnectionMonitoringService.h>

@class PURConnectionEventDeduplicator;

NS_ASSUME_NONNULL_BEGIN

@interface PURConnectionMonitoringService (Internal)

@property (nonatomic) CLLocationManager *locationManager;
@property (nonatomic) PURConnectionEventDeduplicator *connectionProvider;

@end

NS_ASSUME_NONNULL_END
