//
//  YCAlertHelper.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#ifndef YCAlertHelper_h
#define YCAlertHelper_h

@class YCAlert,
YCBaseConfig,
YCAlertConfig,
YCActionSheetConfig,
YCBaseConfigModel,
YCAlertWindow,
YCAction,
YCItem,
YCCustomView;

typedef NS_ENUM(NSInteger, YCScreenOrientationType) {
    /** 屏幕方向类型 横屏 */
    YCScreenOrientationTypeHorizontal,
    /** 屏幕方向类型 竖屏 */
    YCScreenOrientationTypeVertical
};

typedef NS_ENUM(NSInteger, YCActionType) {
    /** 默认 */
    YCActionTypeDefault,
    /** 取消 */
    YCActionTypeCancel,
    /** 销毁 */
    YCActionTypeDestructive
};


typedef NS_OPTIONS(NSInteger, YCActionBorderPosition) {
    /** Action边框位置 上 */
    YCActionBorderPositionTop      = 1 << 0,
    /** Action边框位置 下 */
    YCActionBorderPositionBottom   = 1 << 1,
    /** Action边框位置 左 */
    YCActionBorderPositionLeft     = 1 << 2,
    /** Action边框位置 右 */
    YCActionBorderPositionRight    = 1 << 3
};


typedef NS_ENUM(NSInteger, YCItemType) {
    /** 标题 */
    YCItemTypeTitle,
    /** 内容 */
    YCItemTypeContent,
    /** 输入框 */
    YCItemTypeTextField,
    /** 自定义视图 */
    YCItemTypeCustomView,
};


typedef NS_ENUM(NSInteger, YCCustomViewPositionType) {
    /** 居中 */
    YCCustomViewPositionTypeCenter,
    /** 靠左 */
    YCCustomViewPositionTypeLeft,
    /** 靠右 */
    YCCustomViewPositionTypeRight
};

typedef NS_OPTIONS(NSInteger, YCAnimationStyle) {
    /** 动画样式方向 默认 */
    YCAnimationStyleOrientationNone    = 1 << 0,
    /** 动画样式方向 上 */
    YCAnimationStyleOrientationTop     = 1 << 1,
    /** 动画样式方向 下 */
    YCAnimationStyleOrientationBottom  = 1 << 2,
    /** 动画样式方向 左 */
    YCAnimationStyleOrientationLeft    = 1 << 3,
    /** 动画样式方向 右 */
    YCAnimationStyleOrientationRight   = 1 << 4,
    
    /** 动画样式 淡入淡出 */
    YCAnimationStyleFade               = 1 << 12,
    
    /** 动画样式 缩放 放大 */
    YCAnimationStyleZoomEnlarge        = 1 << 24,
    /** 动画样式 缩放 缩小 */
    YCAnimationStyleZoomShrink         = 2 << 24,
};

typedef struct {
    CGFloat topLeft;
    CGFloat topRight;
    CGFloat bottomLeft;
    CGFloat bottomRight;
} CornerRadii;

NS_ASSUME_NONNULL_BEGIN

typedef YCBaseConfigModel * _Nonnull (^YCConfig)(void);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBool)(BOOL is);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToInteger)(NSInteger number);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToFloat)(CGFloat number);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToString)(NSString *str);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToView)(UIView *view);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToColor)(UIColor *color);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToSize)(CGSize size);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToPoint)(CGPoint point);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToEdgeInsets)(UIEdgeInsets insets);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToAnimationStyle)(YCAnimationStyle style);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBlurEffectStyle)(UIBlurEffectStyle style);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToInterfaceOrientationMask)(UIInterfaceOrientationMask);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToFloatBlock)(CGFloat(^)(YCScreenOrientationType type));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToAction)(void(^)(YCAction *action));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToCustomView)(void(^)(YCCustomView *custom));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToCornerRadii)(CornerRadii);
typedef YCBaseConfigModel * _Nonnull (^YCConfigToStringAndBlock)(NSString *str, void (^ _Nullable)(void));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToConfigLabel)(void(^ _Nullable)(UILabel *label));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToConfigTextField)(void(^ _Nullable)(UITextField *textField));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToItem)(void(^)(YCItem *item));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBlock)(void(^block)(void));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBlockReturnBool)(BOOL(^block)(void));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBlockIntegerReturnBool)(BOOL(^block)(NSInteger index));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToBlockAndBlock)(void(^)(void (^animatingBlock)(void) , void (^animatedBlock)(void)));
typedef YCBaseConfigModel * _Nonnull (^YCConfigToStatusBarStyle)(UIStatusBarStyle style);

API_AVAILABLE(ios(13.0))
typedef YCBaseConfigModel * _Nonnull (^YCConfigToUserInterfaceStyle)(UIUserInterfaceStyle style);

NS_ASSUME_NONNULL_END

#endif /* YCAlertHelper_h */
