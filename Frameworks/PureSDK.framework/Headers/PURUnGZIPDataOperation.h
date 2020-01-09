//
//  PURUnGZIPDataOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/6/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PUROperation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURUnGZIPDataOperation : PUROperation

- (instancetype)initWithName:(NSString *)name input:(NSData *)input queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
