//
//  NSOperation+PURConvenience.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/25/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSOperation (PURConvenience)

- (void)pur_addDependency:(nullable NSOperation *)operation;

@end

NS_ASSUME_NONNULL_END
