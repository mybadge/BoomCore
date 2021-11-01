//
//  BCRoomInfo.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/15.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCRoomInfo : NSObject

/// 房间ID
@property(nonatomic, copy) NSString *roomId;
@property(nonatomic, copy) NSString *roomName;

/// 入会打开麦克风
@property(nonatomic, assign) BOOL openMic;
/// 入会打开摄像头
@property(nonatomic, assign) BOOL openCam;
/// 入会通知
@property(nonatomic, assign) BOOL leaveNotice;


/// 本地用户的 userId
@property(nonatomic, copy) NSString *localUserId;

/// 房间内的总人数
@property(nonatomic, assign) NSInteger total;

/// 是否上报统计信息
@property(nonatomic, assign) BOOL report;

/// 房间创建时间 单位秒
@property(nonatomic, assign) NSInteger startup;

/// 房间持续时间 单位秒
@property(nonatomic, assign) NSInteger duration;

/// 房间剩余时间 单位秒
@property(nonatomic, assign) NSInteger lastTime;

/// 房间内用户数量的最大值
@property(nonatomic, assign) NSInteger limit;

/// 加入房间时，最新的消息的 seq。可用于调用[VloudClient getMessageListForStartSeq:endSeq:]获取历史消息
@property(nonatomic, assign) NSInteger msgSeq;

/// 房间创建者的 userId
@property(nonatomic, copy) NSString *creatorId;


/// 房间主持人的 userId
@property(nonatomic, copy) NSString *masterId;

/// 当前房间是否已启动全员禁用麦克风
@property(nonatomic, assign) BOOL audioOff;

/// 当前房间是否已启动全员禁用摄像头
@property(nonatomic, assign) BOOL videoOff;

/// 当前房间是否已启动全员禁止发送消息
@property(nonatomic, assign) BOOL msgOff;

/// 当前房间是否有密码
@property(nonatomic, assign) BOOL secret;

/// 当前房间是否允许加入
@property(nonatomic, assign) BOOL doorOpen;

/// 当前房间是否锁定
@property(nonatomic, assign) BOOL lock;

/// 是否允许用户自行打开麦克风
@property(nonatomic, assign) BOOL selfOpenAudio;

@end

