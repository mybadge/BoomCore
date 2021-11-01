//
//  BCConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/14.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"

@interface BCConfig : NSObject

/// （必传）业务类型
@property (nonatomic, assign) BCBusLocationType locationType;

/// （非必传）私有服务域
@property (nullable, nonatomic, copy) NSString *uri;

/// （必传）appkey
@property (nonnull, nonatomic, copy) NSString *appID;
@end

