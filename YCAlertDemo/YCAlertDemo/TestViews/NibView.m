//
//  NibView.m
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import "NibView.h"

@implementation NibView

+ (instancetype)instance {
    return [[[NSBundle mainBundle] loadNibNamed:@"NibView"
                                          owner:nil options:nil]lastObject];
}

@end
