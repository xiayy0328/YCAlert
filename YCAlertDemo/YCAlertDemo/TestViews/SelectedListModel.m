//
//  SelectedListModel.m
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import "SelectedListModel.h"

@implementation SelectedListModel

- (instancetype)initWithSid:(NSInteger)sid
                      Title:(NSString *)title{
    
    return [[SelectedListModel alloc] initWithSid:sid Title:title Context:nil];
}

- (instancetype)initWithSid:(NSInteger)sid
                      Title:(NSString *)title
                    Context:(id)context{
    
    self = [super init];
    
    if (self) {
        
        _sid = sid;
        
        _title = title;
        
        _context = context;
    }
    
    return self;
}

@end
