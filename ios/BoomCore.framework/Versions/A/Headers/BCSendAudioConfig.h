//
//  BCSendAudioConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/17.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCSendAudioConfig : NSObject

/// （必传）是否需要推送音频
@property (nonatomic, assign) BOOL has;

/// （非必传）音频编码。不设置默认使用OPUS
@property (nullable, nonatomic, copy) NSString *codec;

/// （非必传）音频码率，单位为 Kb。不设置默认值为 32
@property (nonatomic, assign) int bandWidth;

/// （非必传）音频模块高级配置
@property (nullable, nonatomic, strong) NSDictionary *processConfig;
@end
