//
//  PURConnectionMonitoringService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/8/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>
#import <PureSDK/PURConnectionDefines.h>
#import <PureSDK/PURDatedConnectionInformation.h>

@class PURSwitch, PURDefaultsKey, PURObserver;

NS_ASSUME_NONNULL_BEGIN

// Goal of this class is to output connection events whenever the connection changes.
// We try to make sure the connection change timestamp in the event matches doesn't
// get reset across SDK launches.
@interface PURConnectionMonitoringService : PURService

// These properties are available for reading at any point in the service lifecycle.
@property (nonatomic, readonly) PURConnectionType currentConnectionType;
@property (nonatomic, readonly) PURDatedConnectionInformation *currentConnectionInfo;

// An observer that tracks the current connection.
@property (nonatomic, readonly) PURObserver *currentConnectionObserver;

// If YES, indicates that all the requirements for this service have been fulfilled.
@property (nonatomic, readonly) PURSwitch *canMonitorConnection;

@end

NS_ASSUME_NONNULL_END
