//
//  NSString+PURMD5.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/1/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (PURMD5)

- (NSString *)pur_md5String;

@end

@interface NSData (PURMD5)

// Better to use with large data files.
- (NSString * _Nullable)pur_md5String;

@end

NS_ASSUME_NONNULL_END
