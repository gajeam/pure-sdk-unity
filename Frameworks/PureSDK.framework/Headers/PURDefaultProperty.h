//
//  PURDefaultProperty.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/11/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDefaultsService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURDefaultProperty<DefaultValue> : NSObject

@property (nonatomic, nullable) DefaultValue value;

- (instancetype)initWithDefaultStore:(PURDefaultsService *)defaultsService
                         serialQueue:(PURQueue *)queue
                          defaultKey:(PURDefaultsKey *)defaultsKey
                            observer:(void (^ _Nullable)(DefaultValue value))observer;

@end

NS_ASSUME_NONNULL_END
