//
//  PURDeviceInformationService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/8/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>

@class PURDefaultsKey, PURDeviceInformation;

NS_ASSUME_NONNULL_BEGIN

// Device info is a part of every log event.
@interface PURDeviceInformationService : PURService

- (PURDeviceInformation *)currentDeviceInformation;
- (PURDeviceInformation *)currentAnonymizedDeviceInformation; // Does not include advertising information.

// The mobile connection type (if any). 2G, 3G, 4G or blank
- (NSString * _Nullable)cellTypeString;

@end

NS_ASSUME_NONNULL_END
