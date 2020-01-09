//
//  PURFunctions.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/16/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

id _Nullable pur_NSNullUnwrap(id _Nullable value);
id _Nonnull pur_NSNullWrapped(id _Nullable unwrapped);

NSArray * _Nullable pur_singleArray(id _Nullable value);

extern NSString *pur_boolString(BOOL val);
extern NSString *pur_boolEmojiString(BOOL val);

NS_ASSUME_NONNULL_END
