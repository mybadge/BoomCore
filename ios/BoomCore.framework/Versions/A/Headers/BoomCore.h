//
//  BoomCore.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/14.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BoomCoreDelegate.h"
#import "Constants.h"

NS_ASSUME_NONNULL_BEGIN

@class BCConfig;
@class BCJoinConfig;
@class BCPublishConfig;
@class BCCanvas;
@class BCSubscribeConfig;
@class BCUser;
@class BCStream;
@class BCCanvasConfig;
@class BCSendVideoConfig;
@interface BoomCore : NSObject 


/// BoomCore入口，创建BoomCore实例
/// @param config  BC 入口配置
/// @param delegate BC监听回掉代理
/// @return bRtc BC的实例
+ (instancetype )create:(BCConfig *)config delegate:(id<BoomCoreDelegate> )delegate;


/// 销毁创建的BC实例`
/// @param bRtc 创建的bRtc实例
/// @return number（错误代码）
+ (NSNumber *)destroy:(BoomCore *)bRtc;


/// 加入房间
/// @param config 加入房间对应的配置
- (void)joinRoom:(BCJoinConfig *)config;


/// 离开房间
- (void)leaveRoom;


/// 设置SDK回掉事件
/// @param delegate 委托实体
/// @return 错误码number
- (NSNumber *)setEventDelegate:(id<BoomCoreDelegate> )delegate;


/// 创建BCCanvas
/// @param renderMode (非必需 ) view的渲染模式
/// @param mirrorMode (必需) view是否开启镜像
/// @return BCCanvas实例


/// 创建BCCanvas
/// @param config 创建Canvas所需要的配置参数
- (BCCanvas *)createCanvas:(BCCanvasConfig *)config;


/// 向服务端推流
/// @param streamID 定义的本地的streamid
/// @param config (非必需 )推流的配置
/// @param canvas (非必需 )用于回显本地流的抽象画布实例，内含画布实例
- (void)publish:(NSString *)streamID publishConfig:(BCPublishConfig *)config canvas:(BCCanvas *_Nullable)canvas;


/// 取消推流
/// @param streamID 流的唯一标识
- (void)unpublish:(NSString *)streamID;


/// 从服务端订阅流
/// @param streamID 定义的本地的streamid
/// @param config (非必需 )拉流的配置
/// @param canvas (非必需 )用于显示远流的抽象画布实例，内含画布实例
- (void)subscribe:(NSString *)streamID subscribeConfig:(BCSubscribeConfig *_Nullable)config canvas:(BCCanvas *_Nullable)canvas;


/// 取消订阅流
/// @param streamID 流的唯一标识
- (void)unsubscribe:(NSString *)streamID;


/// 为指定流添加显示画面
/// @param streamID  流的唯一标识
/// @param canvas 用于显示远流的抽象画布实例，内含画布实例
- (void)addStreamCanvas:(NSString *)streamID canvas:(BCCanvas *)canvas;


/// 为指定流删除显示画面
/// @param streamID  流的唯一标识
/// @param canvas (可选)用于显示远流的抽象画布实例，内含画布实例
- (void)removeStreamCanvas:(NSString *)streamID canvas:(BCCanvas *)canvas;


/// 禁止或恢复播放音频流
/// @param streamID  流的唯一标识
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)muteStreamAudio:(NSString *)streamID mute:(BOOL)mute;


/// 禁止或恢复播放视频流
/// @param streamID  流的唯一标识
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)muteStreamVideo:(NSString *)streamID mute:(BOOL)mute;

- (void)startReportStatus:(NSString *)streamID;
- (void)stopReportStatus:(NSString *)streamID;
- (void)toggleVideoStream:(NSString *)streamID index:(NSInteger)index;

- (void)switchCamera;

/// 通过 用户id 获取相应用户的信息
/// @param userID 用户ID
/// @return BCUser的实例
- (BCUser *)getUserInfo:(NSString *)userID;


/// 通过 用户ID 获取 流id 列表
/// @param userID 用户ID
/// @return BCStream实例的数组
- (NSArray *)getUserStreams:(NSString *)userID;


/// 通过 用户id 获取相应Stream的信息
/// @param streamID 用户ID
/// @return BCStream的实例
- (BCStream *)getStreamInfo:(NSString *)streamID;


/// token
/// @param token 用户token
- (void)renewToken:(NSString *)token;

- (void)reconnectForToken:(NSString *)token reconnectCount:(NSInteger)reconnectCount;

/// 结束会议,销毁房间
- (void)releaseRoom;

/// 修改主持人
/// @param userId        新主持人用户ID
- (void)changeMaster:(NSString *)userId;

/// 修改管理员
/// @param userId        用户ID
/// @param enable        是否拥有管理员权限 true:设置拥有管理员权限, false:撤销管理员权限
- (void)changeManager:(NSString *)userId enable:(BOOL)enable;

- (void)updateUserForUserId:(NSString *)userId user:(BCUser *)user;

/// 设置全员禁言
/// @param enable        全员禁言使能, true:开启全员禁言, false:关闭全员禁言
/// @param selfOpenAudio 是否允许用户自行开启MIC
- (void)setAudioOff:(BOOL)enable selfOpenAudio:(BOOL)selfOpenAudio;

/// 设置房间锁
/// @param enable        是否锁定房间(锁定后后续用户无法加入)
///                  true　 锁定
///                  false  释放锁定
- (void)setDoorOpen:(BOOL)enable;

- (void)setRoomLock:(BOOL)enable;


/// 设置扬声器状态
/// @param mute           true 开启 false 关闭
- (void)setSpeakerMute:(BOOL)mute;

/// 房间广播
/// @param message               广播消息
/// @param fromUserId        发送者用户ID
/// @param toUserId            接收者用户ID(没有为全员广播)
- (void)sendMessage:(NSString *)message toUserId:(NSString *)toUserId fromUserId:(NSString *)fromUserId;

/// 将 userId 用户踢出房间。当前用户为主持人时才可使用此方法，被踢出的用户无法再次进入当前房间。
/// @param userId 要踢出房间的用户的 userId
- (void)evictUser:(NSString *)userId;

/// 获取消息列表，将当前房间内的历史消息的 seq 为 [startSeq,endSeq) 区间内的消息返回
/// @param startSeq 起始 seq
/// @param endSeq 结束 seq
- (void)getMessageListForStartSeq:(NSInteger)startSeq endSeq:(NSInteger)endSeq;

/**
 * 启用音量大小提示
 *
 * 开启此功能后，SDK 会在 onUserVoiceVolume() 中反馈对每一路声音音量大小值的评估。
 * 如需打开此功能，请在 enableLocalAudio: 之前调用。
 *
 * @param interval interval 设置 onUserVoiceVolume, 回调的触发间隔，单位为ms，最小间隔为100ms，如果小于等于0则会关闭回调，建议设置为300ms；
 */
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval;


#pragma mark - 屏幕分享相关接口

// app内屏幕分享
- (void)startScreenCaptureInApp:(BCSendVideoConfig *)config;

// 系统级屏幕分享
- (void)startScreenCaptureByReplaykit:(BCPublishConfig *)config appGroup:(NSString *)appGroup;

// 停止屏幕采集
- (int)stopScreenCapture;

// 暂停屏幕分享
- (int)pauseScreenCapture;

// 恢复屏幕分享
- (int)resumeScreenCapture;

- (void)controlScreenAudioEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
