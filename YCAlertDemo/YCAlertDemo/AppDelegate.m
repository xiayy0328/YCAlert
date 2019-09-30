//
//  AppDelegate.m
//  YCAlertDemo
//
//  Created by Codyy.YY on 2019/9/30.
//  Copyright © 2019 Codyy.XYY. All rights reserved.
//

#import "AppDelegate.h"

#import "YCAlert.h"
#import "AlertTableViewController.h"
#import "ActionSheetTableViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    NSArray *classArray = @[@"AlertTableViewController" , @"ActionSheetTableViewController"];
    
    NSArray *titleArray = @[@"Alert" , @"ActionSheet"];
    
    NSMutableArray *ncArray = [NSMutableArray array];
    
    [classArray enumerateObjectsUsingBlock:^(id  _Nonnull class, NSUInteger idx, BOOL * _Nonnull stop) {
       
        UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:[[NSClassFromString(class) alloc] init]];
        
        [ncArray addObject:nc];
        
        nc.tabBarItem.title = titleArray[idx];
    }];
    
    UITabBarController *tbc = [[UITabBarController alloc] init];
    
    tbc.viewControllers = ncArray;
    
    self.window.rootViewController = tbc;
    
    // 设置主window
    
    [YCAlert configMainWindow:self.window];
    
    UIUserNotificationSettings *notificationSettings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
    
    [[UIApplication sharedApplication] registerUserNotificationSettings:notificationSettings];
    return YES;
}

@end
