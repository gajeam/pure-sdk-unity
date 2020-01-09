//
//  PURGZIPRequestSerializer.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/13/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURURLRequestSerialization.h>

#import <PureSDK/PURAPIRequestTemplate.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURGZIPRequestSerializer : PURJSONRequestSerializer

- (NSMutableURLRequest *)requestFromTemplate:(PURAPIRequestTemplate *)requestTemplate
                                       error:(NSError * __autoreleasing *)errorp;

@end

NS_ASSUME_NONNULL_END
