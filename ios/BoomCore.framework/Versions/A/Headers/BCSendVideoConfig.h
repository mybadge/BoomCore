//
//  BCSendVideoConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/17.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"

@interface BCSendVideoConfig : NSObject

/// （必传）是否需要推送视频
@property (nonatomic, assign) BOOL has;

/// （非必传）  视频编码。不设置默，默认H264 
@property (nullable, nonatomic, copy) NSString *codec;

/// （非必传）视频码率，单位为 Kb。不设置默认值为，不设置默认为1000
@property (nonatomic, assign) int bandWidth;

/// （非必传）视频的宽。不设置默认值是720
@property (nonatomic, assign) int width;

/// （非必传）视频的宽。不设置默认值是1280
@property (nonatomic, assign) int height;

/// （非必传）视频的帧率。不设置默认值是25
@property (nonatomic, assign) int fps;

/// （非必传）视频宽高比模式。不设置默认值是竖屏模式
@property (nonatomic, assign) BCVideoResolutionMode resolutionMode;

/// （非必传）多流配置，如配置了此参数，则会覆盖 bandWidth、width、height 的设置
@property (nullable, nonatomic, strong) NSArray *videoInfos;

/// 处理分辨率
- (void)handleScreenSize:(BOOL)isLandscape;
@end
