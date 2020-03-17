//
//  RGDispatchOnce.h
//  RGGCD
//
//  Created by RAIN on 16/5/5.
//  Copyright © 2016年 Smartech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RGDispatchOnce : NSObject

+ (void)perform:(dispatch_block_t)perform;

@end
