//
//  OpenPushView.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OpenPushView : UIView

/**
 *  关闭Block
 */
@property (nonatomic , copy ) void (^closeBlock)(void);

@end

NS_ASSUME_NONNULL_END
