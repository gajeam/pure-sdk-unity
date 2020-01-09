//
//  PURConnectionDeduplicator.h
//  PureSDK
//
//  Created by Hakon Hanesand on 8/17/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURCurrentConnectionProvider.h>
#import <PureSDK/PURConnectionDefines.h>

@class PURQueue, PURDeviceInformationService;

NS_ASSUME_NONNULL_BEGIN

@interface PURConnectionEventDeduplicator : NSObject

- (instancetype)initWithQueue:(PURQueue *)queue;

@property (nonatomic, readonly) BOOL isMonitoring;
@property (nonatomic, readonly, weak) PURQueue *queue;

@property (nonatomic) id<PURCurrentConnectionProvider> currentConnectionProvider;

// The initial connection is used to determine whether to
// send an update immediately after monitoring is started.
- (void)startMonitoringWithInitialConnection:(PURDatedConnectionInformation *)initialConnection
                           deviceInformation:(PURDeviceInformationService *)deviceInformation
                 connectionDidChangeCallback:(void (^)(PURDatedConnectionInformation *))callback
    NS_SWIFT_NAME(startMonitoring(initialConnection:deviceInformation:callback:));

- (void)stopMonitoring;

// Returns information about the currently connected wifi network. The `lastChangedTimestamp`
// will remain PURClock.now unless monitoring is started.
@property (nonatomic, readonly) PURDatedConnectionInformation *currentConnectionInfo;

@property (nonatomic, readonly) PURConnectionType currentConnectionType;

@end

NS_ASSUME_NONNULL_END
