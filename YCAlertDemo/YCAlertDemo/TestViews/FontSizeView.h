//
//  FontSizeView.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FontSizeView : UIView

@property (nonatomic , copy ) void (^changeBlock)(NSInteger);

@end

NS_ASSUME_NONNULL_END
