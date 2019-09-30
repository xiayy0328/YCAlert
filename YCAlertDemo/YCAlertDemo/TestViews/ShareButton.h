//
//  ShareButton.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum {
    
    ShareTypeToQQFriend = 0,//QQ好友
    
    ShareTypeToQZone,//QQ空间
    
    ShareTypeToWechat,//微信好友
    
    ShareTypeToWechatTimeline,//微信朋友圈
    
    ShareTypeToSina,//新浪微博
    
} ShareType;

@interface ShareButton : UIButton
/**
 *  上下间距
 */
@property (nonatomic , assign ) CGFloat range;


/**
 *  设置标题图标
 *
 *  @param title 标题
 *  @param image 图标
 */
- (void)configTitle:(NSString *)title Image:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
