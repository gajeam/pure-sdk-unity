//
//  NSArray+PURMultilineDescription.h
//  PureSDK
//
//  Created by Hakon Hanesand on 3/26/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (PrefixedDescription)

- (NSString *)pur_descriptionWithPrefix:(NSString *)prefix;

@end

@interface NSArray (PURMultilineDescription)

- (NSString *)pur_multilineDescription;

- (NSString *)pur_multilineDescriptionWithPrefix:(NSString *)prefix;

@end

NS_ASSUME_NONNULL_END
