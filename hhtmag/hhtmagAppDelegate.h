//
//  hhtmagAppDelegate.h
//  hhtmag
//
//  Created by Truong Manh Quan on 2/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

@class hhtmagViewController;

@interface hhtmagAppDelegate : NSObject <UIApplicationDelegate> {
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet hhtmagViewController *viewController;

@end
