//
//  PURSessionConfigurator.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/9/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PURSession;

NS_ASSUME_NONNULL_BEGIN

@interface PURSessionConfigurator : NSObject

+ (PURSession *)createSessionWithDefaultConfigurationExportingTimings:(NSDictionary * _Nonnull __autoreleasing * _Nonnull)timingInformationp;

+ (PURSession *)createBarebonesSession;

@end

NS_ASSUME_NONNULL_END
