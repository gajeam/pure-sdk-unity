//
//  PURCurrentConnectionProvider.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/9/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDatedConnectionInformation.h>

@class PURQueue, PURSwitch, PURDeviceInformationService;

NS_ASSUME_NONNULL_BEGIN

typedef void (^PURNetworkReachabilityStatusBlock)(PURRawConnectionInformation *connection);

@protocol PURCurrentConnectionProvider <NSObject>

- (instancetype)initWithQueue:(PURQueue *)queue;

@property (nonatomic, readonly) PURConnectionType currentConnectionType;
@property (nonatomic, readonly) PURRawConnectionInformation *currentConnection;

- (void)startMonitoring:(PURNetworkReachabilityStatusBlock)callback
      deviceInformation:(PURDeviceInformationService *)deviceInformation;

- (void)stopMonitoring;

@end

@interface PURCaptiveNetworkConnectionProvider : NSObject <PURCurrentConnectionProvider>

@end

NS_ASSUME_NONNULL_END
