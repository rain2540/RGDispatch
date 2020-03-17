//
//  RGDispatchOnce.m
//  RGGCD
//
//  Created by RAIN on 16/5/5.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import "RGDispatchOnce.h"

@implementation RGDispatchOnce

+ (void)perform:(dispatch_block_t)perform {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, perform);
}

@end
