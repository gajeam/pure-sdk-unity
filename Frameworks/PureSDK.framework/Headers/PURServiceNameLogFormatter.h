//
//  PURServiceNameLogFormatter.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/26/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURLog.h>

@class PURServiceLocator;

NS_ASSUME_NONNULL_BEGIN

@interface PURServiceNameLogFormatter : NSObject <PURLogFormatter>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithServiceLocator:(PURServiceLocator *)locator;

@end

NS_ASSUME_NONNULL_END
