/*
 *  BMKHexagonHeatMap.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import <CoreLocation/CLLocation.h>

#import "BMKGradient.h"
#import "BMKAnimation.h"
typedef enum {
    BMKHexagonTypeVertexUp = 0,      /// 六边形顶点向上
    BMKHexagonTypeEdgeUP             /// 六边形定边向上
} BMKHexagonType;

///蜂窝热力图节点信息
@interface BMKHexagonHeatMapNode : NSObject

/// 点的强度权值,默认值1，范围[> 0]
@property (nonatomic, assign) double intensity;
/// 点的位置坐标
@property (nonatomic, assign) CLLocationCoordinate2D pt;

@end

/// 蜂窝热力图的绘制数据和显示样式类
@interface BMKHexagonHeatMap : NSObject
/// 设置蜂窝热力图点半径 (米)，默认为200米
@property (nonatomic, assign) int mRadius;
/// 设置蜂窝热力图最大显示等级，默认为22，范围[4~22]
@property (nonatomic, assign) int mMaxShowLevel;
/// 设置蜂窝热力图最小显示等级，默认为4，范围[4~22]
@property (nonatomic, assign) int mMinShowLevel;
/// 设置蜂窝热力图最大权重值，默认为1.0
@property (nonatomic, assign) double mMaxIntensity;
/// 设置蜂窝热力图最小权重值，默认为0.0
@property (nonatomic, assign) double mMinIntensity;
/// 设置蜂窝热力图渐变，有默认值 DEFAULT_GRADIENT
@property (nonatomic, strong) BMKGradient *mGradient;
/// 设置蜂窝热力图层透明度，默认 0.6，范围[0~1]
@property (nonatomic, assign) double mOpacity;
/// 设置蜂窝热力图层六边形间隙，默认5.0
@property (nonatomic, assign) float mGap;
/// 设置蜂窝热力图层六边形样式，默认 BMKHexagonStyleVertexUp ：六边形顶点向上
@property (nonatomic, assign) BMKHexagonType mHexagonType;

/// 用户传入的蜂窝热力图数据，数组，成员类型为BMKHexagonHeatMapNode
@property (nonatomic, copy) NSArray <BMKHexagonHeatMapNode *> *mData;
@end
