//
//  PURPureIdentifierService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 10/23/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

@class PURDefaultsKey;

#import <PureSDK/PURService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURPureIdentifierService : PURService

@property (nonatomic, readonly, class) PURDefaultsKey *pureIdentifierDefaultsKey;

@property (nonatomic, readonly) NSString *pureIdentifier;

@end

NS_ASSUME_NONNULL_END
