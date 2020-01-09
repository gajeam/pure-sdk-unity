//
//  PUREventInterval.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/26/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

#import <PureSDK/PURExportableEvent.h>
#import <PureSDK/PURIntervalProtocol.h>

@class PURAPIRequestTemplate;

NS_ASSUME_NONNULL_BEGIN

@interface PUREventInterval : NSManagedObject <PURExportableEvent, PURIntervalProtocol>

@end

NS_ASSUME_NONNULL_END
