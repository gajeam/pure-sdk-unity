//
//  NSData+PURHexString.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/17/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (PURHexString)

- (NSString *)pur_hexRepresentation;

- (NSString * _Nullable)pur_prettyJSONString;

@end

@interface NSDictionary (PURJSON)

- (NSString * _Nullable)pur_prettyJSONString;

@end

NS_ASSUME_NONNULL_END
