//
//  BCSubscribeConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/18.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCReceiveAudioConfig;
@class BCReceiveVideoConfig;
@interface BCSubscribeConfig : NSObject

/// (非必需) 拉取的音频流的配置，不设置时使用默认配置拉取
@property (nullable, nonatomic, strong) BCReceiveAudioConfig *audio;

/// (非必需) 拉取的视频流的配置，不设置时使用默认配置拉取
@property (nullable, nonatomic, strong) BCReceiveVideoConfig *video;

/// (非必需) 是否默认挂起音频流，不设置时默认不挂起
@property (nonatomic, assign) BOOL muteAudio;

/// (非必需) 是否默认挂起视频流，不设置时默认不挂起
@property (nonatomic, assign) BOOL muteVideo;
@end
