//
//  BCMessageInfo.h
//  BoomCore
//
//  Created by zhaozhidan on 2020/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BCMessageInfo : NSObject

/// 房间ID
@property(nonatomic, copy) NSString *roomId;

/// 消息发送者
@property(nonatomic, copy) NSString *userId;

/// 消息接收者。为 nullptr 时表示当前消息为房间广播
@property(nonatomic, copy) NSString *to;

/// 消息信息
@property(nonatomic, copy) NSString *msg;

/// 是否是发送给其他用户的私聊消息。只在获取消息列表的回调中被使用
@property(nonatomic, assign) BOOL privateMsg;

/// 消息序列号
@property(nonatomic, assign) NSInteger seq;

//- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
