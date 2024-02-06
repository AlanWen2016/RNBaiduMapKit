//
//  BMK3DModelOverlayView.h
//  MapComponent
//
//  Created by zhaoxiangru on 2021/4/28.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKOverlayGLBasicView.h"
#import "BMK3DModelOverlay.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMK3DModelOverlayView : BMKOverlayGLBasicView
// 模型是否可点击，默认NO
@property (nonatomic, assign) BOOL isClickable;
- (nullable instancetype)initWith3DModelOverlay:(BMK3DModelOverlay *)modelOverlay;

/// 该View对应的3DModel数据对象
@property (nonatomic, readonly) BMK3DModelOverlay *modelOverlay;
@end

NS_ASSUME_NONNULL_END
