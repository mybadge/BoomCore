/***********************
auth: cszdlt@qq.com
date: 2020-03-26 20:52:36
name: VloudJoinConfigBuilder.h
************************/

#import <Foundation/Foundation.h>
#import "RTCMacros.h"

@class VloudJoinConfig;

NS_ASSUME_NONNULL_BEGIN

RTC_OBJC_EXPORT
@interface VloudJoinConfigBuilder : NSObject

+ (VloudJoinConfigBuilder *)builder;

- (instancetype)init;

- (VloudJoinConfig *)createVloudJoinConfig;

- (void)setRoomId:(NSString *)roomId;
- (void)setUserId:(NSString *)userId;
- (void)setRoomPassword:(NSString *)roomPassword;
- (void)setCreate:(BOOL)create;
- (void)setNickName:(NSString *)nickName;
- (void)setDevice:(NSString *)device;
- (void)setVersion:(NSString *)version;
- (void)setCustomToken:(NSString *)customToken;
- (void)setExtendInfo:(NSString *)extendInfo;
- (void)setCustomInfo:(NSString *)customInfo;

@end

NS_ASSUME_NONNULL_END
