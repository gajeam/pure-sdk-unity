//
//  PURGZIPDataOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/16/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PUROperation.h>

NS_ASSUME_NONNULL_BEGIN

// Accepts NSData, or any valid Foundation JSON type.
// If input not provided, must have parent task which produces valid input.
// Returns GZIPed data and MD5 hash in an array.
@interface PURGZIPDataOperation : PUROperation

- (instancetype)initWithName:(NSString *)name input:(id)input queue:(PURQueue *)queue;

@end

@interface PURExtractIndexOperation : PUROperation

- (instancetype)initWithName:(NSString *)name
             extractingIndex:(NSUInteger)index
                       queue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
