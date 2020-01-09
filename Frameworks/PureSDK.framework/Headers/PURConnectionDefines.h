//
//  PURConnectionDefines.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/9/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SCNetworkReachability.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PURConnectionType) {
    PURConnectionTypeNone,
    PURConnectionTypeWifi,
    PURConnectionTypeCell
};

extern PURConnectionType pur_connectionTypeForFlags(SCNetworkReachabilityFlags flags);

NS_ASSUME_NONNULL_END
