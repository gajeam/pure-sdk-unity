//
//  NSDictionary+PURExtension.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/22/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (PURExtension)

// Returns a string : "(key:value)separator(key:value)..."
- (NSString *)pur_pairStringRepresentationWithSeperator:(NSString *)separator;

- (NSString *)pur_valueStortedRepresentation;

@end

NS_ASSUME_NONNULL_END
