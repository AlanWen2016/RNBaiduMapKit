//
//  BMK3DTraceOverlayOption.h
//  MapComponent
//
//  Created by Baidu on 2023/10/8.
//  Copyright © 2023 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
* 动画类型
*/
typedef NS_ENUM(NSInteger, BMK3DTraceOverlayAnimationEasingCurve) {
    BMK3DTraceOverlayAnimationEasingCurveLinear, /// 线性
    BMK3DTraceOverlayAnimationEasingCurveEaseIn, /// 淡入
    BMK3DTraceOverlayAnimationEasingCurveEaseOut, /// 淡出
    BMK3DTraceOverlayAnimationEasingCurveEaseInOut /// 淡入淡出
};

/*
 * 轨迹类型
 */
typedef NS_ENUM(NSInteger, BMK3DTraceOverlayType) {
    
    BMK3DTraceOverlayTypeSurface = 3,     /// 面类型3D轨迹线
    BMK3DTraceOverlayTypeDefault,         /// 3D轨迹线
};
NS_ASSUME_NONNULL_BEGIN

/// 3D动画轨迹线Option
@interface BMK3DTraceOverlayOption : NSObject

/// 轨迹类型
@property (nonatomic, assign) BMK3DTraceOverlayType traceType;
/// 动画时间 默认5s 单位s
@property (nonatomic, assign) NSTimeInterval duration;
/// 动画类型
@property (nonatomic, assign) BMK3DTraceOverlayAnimationEasingCurve easingCurve;
/// 调色板图片（3D轨迹线高度面的取色板）, 默认为mapapi.bundle/images/icon_traceColors.png
@property (nonatomic, strong) UIImage *paletteImage;
/// 投影调色板图片 （贴合底图的2D轨迹线的取色板），默认为mapapi.bundle/images/icon_traceColors.png
@property (nonatomic, strong) UIImage *projectionPaletteImage;
/// 轨迹绘制的透明度，取值范围[0.0, 1.0], 默认1.0
@property (nonatomic, assign) CGFloat opacity;
/// 轨迹投影面的透明度，取值范围[0.0, 1.0], 默认1.0
@property (nonatomic, assign) CGFloat paletteOpacity;

@end

NS_ASSUME_NONNULL_END
