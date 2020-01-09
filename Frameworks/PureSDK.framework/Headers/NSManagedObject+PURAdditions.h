//
//  NSManagedObject+PURAdditions.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSManagedObject (PURAdditions)

@property (nonatomic, class, readonly) NSString *pur_entityName;

@end

NS_ASSUME_NONNULL_END
