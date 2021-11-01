//
//  BCCanvasConfig.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/20.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"

@interface BCCanvasConfig : NSObject

/// （必传）渲染模式
@property (nonatomic, assign) BCVideoRenderMode renderMode;

/// （必传）是否打开镜像
@property (nonatomic, assign) BCVideoMirrorMode mirrorMode;

@end
