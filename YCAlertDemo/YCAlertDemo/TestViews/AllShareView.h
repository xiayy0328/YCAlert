//
//  AllShareView.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ShareButton.h"

typedef enum {
    
    MoreTypeToTheme = 0, //更改按钮类型主题
    
    MoreTypeToReport, //更多按钮类型举报

    MoreTypeToFontSize, //更多按钮类型字体大小
    
    MoreTypeToCopyLink, //更改按钮类型复制链接
    
} MoreType;

@interface AllShareView : UIView

- (instancetype)initWithFrame:(CGRect)frame ShowMore:(BOOL)showMore;

- (instancetype)initWithFrame:(CGRect)frame ShowMore:(BOOL)showMore ShowReport:(BOOL)showReport;

@property (nonatomic , copy ) void (^openShareBlock)(ShareType type);

@property (nonatomic , copy ) void (^openMoreBlock)(MoreType type);

/** 显示 */

- (void)show;

@end
