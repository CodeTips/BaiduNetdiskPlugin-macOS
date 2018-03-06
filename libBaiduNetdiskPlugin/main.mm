//
//  main.c
//  libBaiduNetdiskPlugin
//
//  Copyright © 2018 CodeTips. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaiduNetdisk+Hook.h"
static void __attribute__((constructor)) initialize(void) {
    [NSObject hookBaiduNetdisk];
}
