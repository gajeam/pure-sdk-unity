//
//  NSProcessInfo+PURProcessInfo.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSProcessInfo (PURProcessInfo)

@property (nonatomic, readonly) BOOL pur_isTesting;

@end

NS_ASSUME_NONNULL_END
