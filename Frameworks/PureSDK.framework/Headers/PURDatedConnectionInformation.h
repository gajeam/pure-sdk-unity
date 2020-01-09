//
//  PURDatedConnectionInformation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 7/27/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURConnectionDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class PURDatedConnectionInformation;

@interface PURRawConnectionInformation : NSObject <NSCoding>

@property (nonatomic, copy, nullable, readonly) NSString *SSID;
@property (nonatomic, copy, nullable, readonly) NSString *BSSID;
@property (nonatomic, copy, nullable) NSString *cellType;

@property (nonatomic, readonly) PURConnectionType connectionType;

- (instancetype)initWithSSID:(NSString *)SSID
                       BSSID:(NSString *)BSSID
                    cellType:(NSString *)cellType
              connectionType:(PURConnectionType)connectionType;

- (PURDatedConnectionInformation *)connectionInformationWithTimestamp:(NSTimeInterval)timestamp;

@end

@interface PURDatedConnectionInformation : NSObject <NSCoding>

@property (nonatomic, copy, nullable, readonly) NSString *SSID;
@property (nonatomic, copy, nullable, readonly) NSString *BSSID;
@property (nonatomic, copy, nullable, readonly) NSString *cellType;

@property (nonatomic, readonly) PURConnectionType connectionType;
@property (nonatomic, readonly) NSTimeInterval lastChangedTimestamp;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (instancetype)initWithSSID:(NSString * _Nullable)SSID
                       BSSID:(NSString * _Nullable)BSSID
                    cellType:(NSString *)cellType
              connectionType:(PURConnectionType)connectionType
        lastChangedTimestamp:(NSTimeInterval)lastChangedTimestamp;

- (BOOL)isEqualToRawConnection:(PURRawConnectionInformation *)rawConnection;
- (NSDictionary *)serialized;

@end

NS_ASSUME_NONNULL_END
