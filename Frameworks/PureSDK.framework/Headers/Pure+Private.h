//
//  Pure+Private.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/18/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/Pure.h>

static NSString * const PURPublisherIdDidChange = @"PURPublisherIdDidChange";

@interface Pure (Private)

@property (class, nonatomic) BOOL lightweightAnalyticsEnabled;
@property (class, nonatomic) BOOL hasMigratedDefaultsStore;

@end
