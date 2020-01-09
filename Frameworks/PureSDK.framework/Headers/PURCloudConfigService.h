//
//  PURCloudConfigService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/13/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>

#import <PureSDK/PURDefaultsService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURCloudConfigService : PURService

- (void)fetchCloudConfig;

@end

NS_ASSUME_NONNULL_END
