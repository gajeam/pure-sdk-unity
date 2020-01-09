//
//  PURRuntimeConfigurationService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 4/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURService.h>

@class PURDefaultsKey;

NS_ASSUME_NONNULL_BEGIN

@interface PURRuntimeConfigurationService : PURService

+ (PURDefaultsKey *)showsBackgroundLocationIndicator;
+ (PURDefaultsKey *)dispatchesLocationNotifications;
+ (PURDefaultsKey *)dispatchesBeaconNotifications;
+ (PURDefaultsKey *)dispatchesPriorityNotifications;

@end

NS_ASSUME_NONNULL_END
