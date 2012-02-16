//
//  hhtmagViewController.m
//  hhtmag
//
//  Created by Truong Manh Quan on 2/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import "hhtmagViewController.h"

@implementation hhtmagViewController

@synthesize pageControl;
@synthesize thumbnailControl;

- (void)dealloc {
  [pageControl release];
  [thumbnailControl release];
  
  [super dealloc];
}

- (void)viewDidLoad {
  [super viewDidLoad];
  
  [thumbnailControl setBackgroundColor:[UIColor scrollViewTexturedBackgroundColor]];
  [thumbnailControl setHidden:YES];
 
  if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
    [thumbnailControl setPageSeparation:5];
    [thumbnailControl setPortraitSize:CGSizeMake(60,80)];
    [thumbnailControl setLandscapeSize:CGSizeMake(80,60)];
    [pageControl setScale:0.4166667];
  }
  else {
    [thumbnailControl setPageSeparation:10];
    [thumbnailControl setPortraitSize:CGSizeMake(135,180)];
    [thumbnailControl setLandscapeSize:CGSizeMake(180,135)];
    [pageControl setScale:1.0];
  }
  
  [pageControl setNavigator:thumbnailControl];
  // TODO: uncomment the line below when you're ready to go live
  // [pageControl setImageStore:[[[KGDiskImageStore alloc] init] autorelease]];
  [pageControl setDataSource:[[[KGLocalFileDataSource alloc] initWithPath:@"Data"] autorelease]];
  [pageControl setPageNumber:0];

  UITapGestureRecognizer *doubleTap = [[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(toggleNavigator)] autorelease];
  doubleTap.delegate = self;
  doubleTap.numberOfTapsRequired = 2;
  doubleTap.cancelsTouchesInView = NO;
  [pageControl addGestureRecognizer:doubleTap];
}

- (void)viewDidUnload {
  self.pageControl = nil;
  self.thumbnailControl = nil;
  [super viewDidUnload];
}

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  [pageControl.imageStore releaseMemory];
  [thumbnailControl.imageStore releaseMemory];  
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
  return YES;
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
  [super willRotateToInterfaceOrientation:toInterfaceOrientation duration:duration];
  
  if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
    if (UIInterfaceOrientationIsLandscape(toInterfaceOrientation))
      [pageControl setBounds:CGRectMake(0, 0, 426, 320)];
    else
      [pageControl setBounds:CGRectMake(0, 0, 320, 426)];
  }
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)recognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
  return YES;
}

- (void)toggleNavigator {
  [thumbnailControl setHidden:![thumbnailControl isHidden] animationStyle:KGAnimationSlideDown|KGAnimationFade duration:0.5];
}

@end
