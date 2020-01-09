//
//  PURLogMessage+PURExport.h
//  PureSDK
//
//  Created by Hakon Hanesand on 8/29/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURCocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLogMessage (PURExport)

- (NSDictionary *)pur_serialized;

@end

NS_ASSUME_NONNULL_END
