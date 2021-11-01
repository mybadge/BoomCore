//
//  BCPublishConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/17.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCSendAudioConfig;
@class BCSendVideoConfig;
@interface BCPublishConfig : NSObject

/// （非必传）推送的音频流的配置，不设置时使用默认配置推送
@property (nullable, nonatomic, strong) BCSendAudioConfig *audio;

/// （非必传）推送的视频流的配置，不设置时使用默认配置推送
@property (nullable, nonatomic, strong) BCSendVideoConfig *video;

/// （非必传）是否默认挂起音频流，不设置时默认不挂起
@property (nonatomic, assign) BOOL muteAudio;

/// （非必传）是否默认挂起视频流，不设置时默认不挂起
@property (nonatomic, assign) BOOL muteVideo;
@end
