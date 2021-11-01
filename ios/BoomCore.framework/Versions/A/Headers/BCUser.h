//
//  BCUser.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/15.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BCUserPermission;

@interface BCUser : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *userInfo;
@property (nonatomic, copy) NSString *extendInfo;
@property (nonatomic, copy) NSString *cver;
/// 入会的时候可以使用这个值, 其他地方暂不能使用
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, assign) BOOL raiseHands;
@property (nonatomic, strong) BCUserPermission *permission;

@end
