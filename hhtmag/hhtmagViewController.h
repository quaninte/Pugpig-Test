//
//  hhtmagViewController.h
//  hhtmag
//
//  Created by Truong Manh Quan on 2/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Pugpig/Pugpig.h>

@interface hhtmagViewController : UIViewController<UIGestureRecognizerDelegate> {
}

@property (nonatomic, retain) IBOutlet KGPagedDocControl *pageControl;
@property (nonatomic, retain) IBOutlet KGPagedDocThumbnailControl *thumbnailControl;

@end
