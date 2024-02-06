//
//  BMK3DTraceOverlayView.h
//  MapComponent
//
//  Created by Baidu on 2023/10/8.
//  Copyright © 2023 Baidu. All rights reserved.
//

#import "BMKGeometryView.h"
#import "BMK3DTraceOverlay.h"

NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一个3D轨迹View since 6.6.0
@interface BMK3DTraceOverlayView : BMKGeometryView

/// 根据指定的轨迹生成一个轨迹View
/// @param traceOverlay 指定的轨迹数据对象
/// @return 新生成的轨迹View
- (nullable instancetype)initWithTraceOverlay:(BMK3DTraceOverlay *)traceOverlay;

/// 该View对应的折线数据对象
@property (nonatomic, readonly) BMK3DTraceOverlay *traceOverlay;

/// 使用BMK3DTraceOverlay绘制时，必须设置
/// 注意：strokeHeights 长度与轨迹点的个数必须保持一致
@property (nonatomic, copy) NSArray<NSNumber *> *strokeHeights;
@end

NS_ASSUME_NONNULL_END
