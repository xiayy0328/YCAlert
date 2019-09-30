//
//  SelectedListModel.h
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SelectedListModel : NSObject

@property (nonatomic , assign ) NSInteger sid;

@property (nonatomic , copy ) NSString *title;

@property (nonatomic , strong ) id context;

- (instancetype)initWithSid:(NSInteger)sid
                      Title:(NSString *)title;

- (instancetype)initWithSid:(NSInteger)sid
                      Title:(NSString *)title
                    Context:(id)context;
@end
