//
//  BCVideoInfo.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/17.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCVideoInfo : NSObject
/// （非必传）视频码率，单位为 Kb。不设置默认值为，不设置默认为1000
@property (nonatomic, assign) int bandWidth;

/// （非必传）视频的宽。不设置默认值是720
@property (nonatomic, assign) int width;

/// （非必传）视频的宽。不设置默认值是1280
@property (nonatomic, assign) int height;
@end
