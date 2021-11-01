//
//  BCCanvas.h
//  BoomCore-i
//
//  Created by jia fei on 2020/8/17.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Constants.h"
@class BCCanvas;
@protocol BCCanvasDelegate <NSObject>

- (void)firstFrameRenderedOn:(BCCanvas *)canvas;

@end

@interface BCCanvas : NSObject
@property (nonatomic, weak) id<BCCanvasDelegate> delegate;
@property (nonatomic, assign) BCVideoRenderMode renderMode;
@property (nonatomic, assign) BCVideoMirrorMode mirrorMode;
@property (nonatomic, strong) UIView *view;

//- (void)addStreamId:(NSString *)streamId;
//- (void)removeStreamId:(NSString *)streamId;
//- (NSArray *)getAllStreamIds;
@end

