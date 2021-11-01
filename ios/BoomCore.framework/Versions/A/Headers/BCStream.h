//
//  BCStream.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/18.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCStream : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *streamID;
/// 是否开启音频，更改该属性会设置音频状态
@property(nonatomic, assign) BOOL enableAudio;

/// 是否开启视频，更改该属性会设置视频状态
@property(nonatomic, assign) BOOL enableVideo;

/// 是否是本地流
@property(nonatomic, assign) BOOL isLocal;

/// 当前流是否含有音频
@property(nonatomic, assign) BOOL hasAudio;

/// 当前流是否含有视频
@property(nonatomic, assign) BOOL hasVideo;

@property(nonatomic, assign) NSInteger videoStreamCount;


@end
