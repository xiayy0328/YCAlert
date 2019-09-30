//
//  YCAlert.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YCAlertHelper.h"

/*
*************************简要说明************************

Alert 使用方法

[YCAlert alert].cofing.XXXXX.XXXXX.YcShow();

ActionSheet 使用方法

[YCAlert actionSheet].cofing.XXXXX.XXXXX.YcShow();

特性:
- 支持alert类型与actionsheet类型
- 默认样式为Apple风格 可自定义其样式
- 支持自定义标题与内容 可动态调整其样式
- 支持自定义视图添加 同时可设置位置类型等 自定义视图size改变时会自动适应.
- 支持输入框添加 自动处理键盘相关的细节
- 支持屏幕旋转适应 同时可自定义横竖屏最大宽度和高度
- 支持自定义action添加 可动态调整其样式
- 支持内部添加的功能项的间距范围设置等
- 支持圆角设置 支持阴影效果设置
- 支持队列和优先级 多个同时显示时根据优先级顺序排队弹出 添加到队列的如被高优先级覆盖 以后还会继续显示.
- 支持两种背景样式 1.半透明 (支持自定义透明度比例和颜色) 2.毛玻璃 (支持效果类型)
- 支持自定义UIView动画方法
- 支持自定义打开关闭动画样式(动画方向 渐变过渡 缩放过渡等)
- 更多特性未来版本中将不断更新.

设置方法结束后在最后请不要忘记使用.YcShow()方法来显示.

最低支持iOS8及以上

*****************************************************
*/


NS_ASSUME_NONNULL_BEGIN

@interface YCAlert : NSObject

/** 初始化 */

+ (nonnull YCAlertConfig *)alert;

+ (nonnull YCAlertConfig *)actionsheet;

/** 获取Alert窗口 */
+ (nonnull YCAlertWindow *)getAlertWindow;

/** 设置主窗口 */
+ (void)configMainWindow:(UIWindow *)window;

/** 继续队列显示 */
+ (void)continueQueueDisplay;

/** 清空队列 */
+ (void)clearQueue;

/**
 关闭指定标识

 @param identifier 标识
 @param completionBlock 关闭完成回调
 */
+ (void)closeWithIdentifier:(NSString *)identifier completionBlock:(void (^ _Nullable)(void))completionBlock;

/**
 关闭指定标识

 @param identifier 标识
 @param force 是否强制关闭
 @param completionBlock 关闭完成回调
 */
+ (void)closeWithIdentifier:(NSString *)identifier force:(BOOL)force completionBlock:(void (^ _Nullable)(void))completionBlock;

/**
 关闭当前

 @param completionBlock 关闭完成回调
 */
+ (void)closeWithCompletionBlock:(void (^ _Nullable)(void))completionBlock;

@end

@interface YCAlertConfigModel : NSObject

/** ✨通用设置 */

/** 设置 标题 -> 格式: .YcTitle(@@"") */
@property (nonatomic , copy , readonly ) YCConfigToString YcTitle;

/** 设置 内容 -> 格式: .YcContent(@@"") */
@property (nonatomic , copy , readonly ) YCConfigToString YcContent;

/** 设置 自定义视图 -> 格式: .YcCustomView(UIView) */
@property (nonatomic , copy , readonly ) YCConfigToView YcCustomView;

/** 设置 动作 -> 格式: .YcAction(@"name" , ^{ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToStringAndBlock YcAction;

/** 设置 取消动作 -> 格式: .YcCancelAction(@"name" , ^{ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToStringAndBlock YcCancelAction;

/** 设置 取消动作 -> 格式: .YcDestructiveAction(@"name" , ^{ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToStringAndBlock YcDestructiveAction;

/** 设置 添加标题 -> 格式: .YcConfigTitle(^(UILabel *label){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToConfigLabel YcAddTitle;

/** 设置 添加内容 -> 格式: .YcConfigContent(^(UILabel *label){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToConfigLabel YcAddContent;

/** 设置 添加自定义视图 -> 格式: .YcAddCustomView(^(YCCustomView *){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToCustomView YcAddCustomView;

/** 设置 添加一项 -> 格式: .YcAddItem(^(YCItem *){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToItem YcAddItem;

/** 设置 添加动作 -> 格式: .YcAddAction(^(YCAction *){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToAction YcAddAction;

/** 设置 头部内的间距 -> 格式: .YcHeaderInsets(UIEdgeInsetsMake(20, 20, 20, 20)) */
@property (nonatomic , copy , readonly ) YCConfigToEdgeInsets YcHeaderInsets;

/** 设置 上一项的间距 (在它之前添加的项的间距) -> 格式: .YcItemInsets(UIEdgeInsetsMake(5, 0, 5, 0)) */
@property (nonatomic , copy , readonly ) YCConfigToEdgeInsets YcItemInsets;

/** 设置 最大宽度 -> 格式: .YcMaxWidth(280.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcMaxWidth;

/** 设置 最大高度 -> 格式: .YcMaxHeight(400.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcMaxHeight;

/** 设置 设置最大宽度 -> 格式: .YcConfigMaxWidth(CGFloat(^)(^CGFloat(YCScreenOrientationType type) { return 280.0f; }) */
@property (nonatomic , copy , readonly ) YCConfigToFloatBlock YcConfigMaxWidth;

/** 设置 设置最大高度 -> 格式: .YcConfigMaxHeight(CGFloat(^)(^CGFloat(YCScreenOrientationType type) { return 600.0f; }) */
@property (nonatomic , copy , readonly ) YCConfigToFloatBlock YcConfigMaxHeight;

/** 设置 圆角半径 -> 格式: .YcCornerRadius(13.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcCornerRadius;

/** 设置 圆角半径 -> 格式: .YcCornerRadii(CornerRadiiMake(13.0f, 13.0f, 13.0f, 13.0f))  注意: 该方法优先级高于YCCornerRadius  */
@property (nonatomic , copy , readonly ) YCConfigToCornerRadii YcCornerRadii;

/** 设置 开启动画时长 -> 格式: .YcOpenAnimationDuration(0.3f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcOpenAnimationDuration;

/** 设置 关闭动画时长 -> 格式: .YcCloseAnimationDuration(0.2f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcCloseAnimationDuration;

/** 设置 颜色 -> 格式: .YcHeaderColor(UIColor) */
@property (nonatomic , copy , readonly ) YCConfigToColor YcHeaderColor;

/** 设置 背景颜色 -> 格式: .YcBackGroundColor(UIColor) */
@property (nonatomic , copy , readonly ) YCConfigToColor YcBackGroundColor;

/** 设置 半透明背景样式及透明度 [默认] -> 格式: .YcBackgroundStyleTranslucent(0.45f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcBackgroundStyleTranslucent;

/** 设置 模糊背景样式及类型 -> 格式: .YcBackgroundStyleBlur(UIBlurEffectStyleDark) */
@property (nonatomic , copy , readonly ) YCConfigToBlurEffectStyle YcBackgroundStyleBlur;

/** 设置 点击头部关闭 -> 格式: .YcClickHeaderClose(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcClickHeaderClose;

/** 设置 点击背景关闭 -> 格式: .YcClickBackgroundClose(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcClickBackgroundClose;

/** 设置 是否可滑动 -> 格式: .YcIsScrollEnabled(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcIsScrollEnabled;

/** 设置 阴影偏移 -> 格式: .YcShadowOffset(CGSizeMake(0.0f, 2.0f)) */
@property (nonatomic , copy , readonly ) YCConfigToSize YcShadowOffset;

/** 设置 阴影不透明度 -> 格式: .YcShadowOpacity(0.3f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcShadowOpacity;

/** 设置 阴影半径 -> 格式: .YcShadowRadius(5.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcShadowRadius;

/** 设置 阴影颜色 -> 格式: .YcShadowOpacity(UIColor) */
@property (nonatomic , copy , readonly ) YCConfigToColor YcShadowColor;

/** 设置 标识 -> 格式: .YcIdentifier(@@"ident") */
@property (nonatomic , copy , readonly ) YCConfigToString YcIdentifier;

/** 设置 是否加入到队列 -> 格式: .YcQueue(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcQueue;

/** 设置 优先级 -> 格式: .YcPriority(1000) */
@property (nonatomic , copy , readonly ) YCConfigToInteger YcPriority;

/** 设置 是否继续队列显示 -> 格式: .YcContinueQueue(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcContinueQueueDisplay;

/** 设置 window等级 -> 格式: .YcWindowLevel(UIWindowLevel) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcWindowLevel;

/** 设置 是否支持自动旋转 -> 格式: .YcShouldAutorotate(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcShouldAutorotate;

/** 设置 是否支持显示方向 -> 格式: .YcShouldAutorotate(UIInterfaceOrientationMaskAll) */
@property (nonatomic , copy , readonly ) YCConfigToInterfaceOrientationMask YcSupportedInterfaceOrientations;

/** 设置 打开动画配置 -> 格式: .YcOpenAnimationConfig(^(void (^animatingBlock)(void), void (^animatedBlock)(void)) { //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToBlockAndBlock YcOpenAnimationConfig;

/** 设置 关闭动画配置 -> 格式: .YcCloseAnimationConfig(^(void (^animatingBlock)(void), void (^animatedBlock)(void)) { //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToBlockAndBlock YcCloseAnimationConfig;

/** 设置 打开动画样式 -> 格式: .YcOpenAnimationStyle() */
@property (nonatomic , copy , readonly ) YCConfigToAnimationStyle YcOpenAnimationStyle;

/** 设置 关闭动画样式 -> 格式: .YcCloseAnimationStyle() */
@property (nonatomic , copy , readonly ) YCConfigToAnimationStyle YcCloseAnimationStyle;

/** 设置 状态栏样式 -> 格式: .YcStatusBarStyle(UIStatusBarStyleDefault) */
@property (nonatomic , copy , readonly ) YCConfigToStatusBarStyle YcStatusBarStyle;


/** 显示  -> 格式: .YcShow() */
@property (nonatomic , copy , readonly ) YCConfig YcShow;

/** ✨alert 专用设置 */

/** 设置 添加输入框 -> 格式: .YcAddTextField(^(UITextField *){ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToConfigTextField YcAddTextField;

/** 设置 中心点偏移 -> 格式: .YcCenterOffset(CGPointMake(0, 0)) */
@property (nonatomic , copy , readonly ) YCConfigToPoint YcAlertCenterOffset;
    
/** 设置 是否闪避键盘 -> 格式: .YcAvoidKeyboard(YES) */
@property (nonatomic , copy , readonly ) YCConfigToBool YcAvoidKeyboard;

/** ✨actionSheet 专用设置 */

/** 设置 ActionSheet的背景视图颜色 -> 格式: .YcActionSheetBackgroundColor(UIColor) */
@property (nonatomic , copy , readonly ) YCConfigToColor YcActionSheetBackgroundColor;

/** 设置 取消动作的间隔宽度 -> 格式: .YcActionSheetCancelActionSpaceWidth(10.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcActionSheetCancelActionSpaceWidth;

/** 设置 取消动作的间隔颜色 -> 格式: .YcActionSheetCancelActionSpaceColor(UIColor) */
@property (nonatomic , copy , readonly ) YCConfigToColor YcActionSheetCancelActionSpaceColor;

/** 设置 ActionSheet距离屏幕底部的间距 -> 格式: .YcActionSheetBottomMargin(10.0f) */
@property (nonatomic , copy , readonly ) YCConfigToFloat YcActionSheetBottomMargin;

/** 设置 是否可以关闭 -> 格式: .YcShouldClose(^{ return YES; }) */
@property (nonatomic, copy, readonly ) YCConfigToBlockReturnBool YcShouldClose;

/** 设置 是否可以关闭(Action 点击) -> 格式: .YcShouldActionClickClose(^(NSInteger index){ return YES; }) */
@property (nonatomic, copy, readonly ) YCConfigToBlockIntegerReturnBool YcShouldActionClickClose;

/** 设置 当前关闭回调 -> 格式: .YcCloseComplete(^{ //code.. }) */
@property (nonatomic , copy , readonly ) YCConfigToBlock YcCloseComplete;

@end


@interface YCItem : NSObject

/** item类型 */
@property (nonatomic , assign ) YCItemType type;

/** item间距范围 */
@property (nonatomic , assign ) UIEdgeInsets insets;

/** item设置视图Block */
@property (nonatomic , copy ) void (^block)(id view);

- (void)update;

@end

@interface YCAction : NSObject

/** action类型 */
@property (nonatomic , assign ) YCActionType type;

/** action标题 */
@property (nonatomic , strong ) NSString *title;

/** action高亮标题 */
@property (nonatomic , strong ) NSString *highlight;

/** action标题(attributed) */
@property (nonatomic , strong ) NSAttributedString *attributedTitle;

/** action高亮标题(attributed) */
@property (nonatomic , strong ) NSAttributedString *attributedHighlight;

/** action字体 */
@property (nonatomic , strong ) UIFont *font;

/** action标题颜色 */
@property (nonatomic , strong ) UIColor *titleColor;

/** action高亮标题颜色 */
@property (nonatomic , strong ) UIColor *highlightColor;

/** action背景颜色 (与 backgroundImage 相同) */
@property (nonatomic , strong ) UIColor *backgroundColor;

/** action高亮背景颜色 */
@property (nonatomic , strong ) UIColor *backgroundHighlightColor;

/** action背景图片 (与 backgroundColor 相同) */
@property (nonatomic , strong ) UIImage *backgroundImage;

/** action高亮背景图片 */
@property (nonatomic , strong ) UIImage *backgroundHighlightImage;

/** action图片 */
@property (nonatomic , strong ) UIImage *image;

/** action高亮图片 */
@property (nonatomic , strong ) UIImage *highlightImage;

/** action间距范围 */
@property (nonatomic , assign ) UIEdgeInsets insets;

/** action图片的间距范围 */
@property (nonatomic , assign ) UIEdgeInsets imageEdgeInsets;

/** action标题的间距范围 */
@property (nonatomic , assign ) UIEdgeInsets titleEdgeInsets;

/** action圆角曲率 */
@property (nonatomic , assign ) CGFloat cornerRadius;

/** action高度 */
@property (nonatomic , assign ) CGFloat height;

/** action边框宽度 */
@property (nonatomic , assign ) CGFloat borderWidth;

/** action边框颜色 */
@property (nonatomic , strong ) UIColor *borderColor;

/** action边框位置 */
@property (nonatomic , assign ) YCActionBorderPosition borderPosition;

/** action点击不关闭 (仅适用于默认类型) */
@property (nonatomic , assign ) BOOL isClickNotClose;

/** action点击事件回调Block */
@property (nonatomic , copy ) void (^ _Nullable clickBlock)(void);

- (void)update;

@end

@interface YCCustomView : NSObject

/** 自定义视图对象 */
@property (nonatomic , strong, nullable ) UIView *view;

/** 自定义视图位置类型 (默认为居中) */
@property (nonatomic , assign ) YCCustomViewPositionType positionType;

/** 是否自动适应宽度 (不支持 AutoLayout 布局的视图)*/
@property (nonatomic , assign ) BOOL isAutoWidth;

@end

@interface YCAlertConfig : NSObject

@property (nonatomic , strong, nonnull ) YCAlertConfigModel *config;

@property (nonatomic , assign ) YCAlertType type;

@end


@interface YCAlertWindow : UIWindow @end

@interface YCBaseViewController : UIViewController @end

@interface YCAlertViewController : YCBaseViewController @end

@interface YCActionSheetViewController : YCBaseViewController @end


@interface UIView (CornerRadii)

CornerRadii CornerRadiiMake(CGFloat topLeft, CGFloat topRight, CGFloat bottomLeft, CGFloat bottomRight);

CornerRadii CornerRadiiZero(void);

CornerRadii CornerRadiiNull(void);

@end

NS_ASSUME_NONNULL_END
