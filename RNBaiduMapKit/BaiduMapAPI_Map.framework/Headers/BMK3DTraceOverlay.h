//
//  BMK3DTraceOverlay.h
//  MapComponent
//
//  Created by Baidu on 2023/10/8.
//  Copyright © 2023 Baidu. All rights reserved.
//

#import "BMKMultiPoint.h"
#import "BMKOverlay.h"
#import "BMK3DTraceOverlayOption.h"

@class BMK3DTraceOverlay;

NS_ASSUME_NONNULL_BEGIN


@protocol BMK3DTraceOverlayAnimationDelegate <NSObject>

@optional
/// 动画开始
- (void)traceOverlayAnimationDidStart:(BMK3DTraceOverlay *)traceOverlay;

/// 动画进度
/// @param traceOverlay BMK3DTraceOverlay
/// @param progress 进度 0.0 ~ 100.0
- (void)traceOverlay:(BMK3DTraceOverlay *)traceOverlay animationRunningProgress:(CGFloat)progress;

/// 追踪动画实时位置
/// @param traceOverlay BMK3DTraceOverlay
/// @param position 当前位置
- (void)traceOverlay:(BMK3DTraceOverlay *)traceOverlay animationTraceMovePosition:(CLLocationCoordinate2D)position;

/// 动画结束
/// @param traceOverlay BMKTraceOverlay
/// @param flag 动画是否完成
- (void)traceOverlay:(BMK3DTraceOverlay *)traceOverlay animationDidEnd:(BOOL)flag;

@end


/// 3D轨迹动画 since 6.6.0
/// 使用旧版逻辑绘制轨迹动画仅支持一条。
@interface BMK3DTraceOverlay : BMKMultiPoint <BMKOverlay>

/// 动画代理
@property (nonatomic, weak, nullable) id<BMK3DTraceOverlayAnimationDelegate> delegate;
/// option参数
@property (nonatomic, strong, readonly) BMK3DTraceOverlayOption *overlayOption;
/// 轨迹动画暂停状态
@property (nonatomic, assign, readonly) BOOL onPauseStatus;
/// 轨迹动画进度 0.0~1.0
@property (nonatomic, assign, readonly) CGFloat progress;

/// 暂停轨迹动画绘制
- (void)pause3DTraceOverlayDraw;
/// 继续轨迹动画绘制
- (void)resume3DTraceOverlayDraw;

/// 创建BMK3DTraceOverlay
/// @param coords 经纬度坐标数组
/// @param count 经纬度坐标数组大小
/// @param overlayOption 动画参数
+ (nullable instancetype)traceOverlay3DWithCoordinates:(CLLocationCoordinate2D *)coords
                                               count:(NSUInteger)count
                                              option:(BMK3DTraceOverlayOption *)overlayOption;

/// 创建BMK3DTraceOverlay
/// @param points 直角坐标数组
/// @param count 直角坐标数组大小
/// @param overlayOption 动画参数
+ (nullable instancetype)traceOverlay3DWithPoints:(BMKMapPoint *)points
                                          count:(NSUInteger)count
                                         option:(BMK3DTraceOverlayOption *)overlayOption;
@end

NS_ASSUME_NONNULL_END
