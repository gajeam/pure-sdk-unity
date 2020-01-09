//
//  PURMessageInterval.h
//  PureSDK
//
//  Created by Hakon Hanesand on 2/15/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>

#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURIntervalProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURMessageInterval : NSManagedObject <PURExportableEvent, PURIntervalProtocol>

@end

NS_ASSUME_NONNULL_END
