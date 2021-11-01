//
//  BCJoinConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/14.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCUser;
@interface BCJoinConfig : NSObject

/// （必传）用户token
@property (nonnull, nonatomic, copy) NSString *token;
/// 用户鉴权token
@property (nonnull, nonatomic, copy) NSString *customToken;

/// （必传）房间号
@property (nonnull, nonatomic, copy) NSString *roomID;

/// （必传）用户数据
@property (nonnull, nonatomic, strong) BCUser *user;

/// （非必传）房间名
@property (nullable, nonatomic, copy) NSString *roomName;
/// 房间密码
@property (nullable, nonatomic, copy) NSString *roomPassword;

/// （非必传）是否直接创建房间
@property (nonatomic, assign) BOOL create;

@end

