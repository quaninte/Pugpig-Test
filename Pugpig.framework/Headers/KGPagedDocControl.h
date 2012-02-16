//
//  KGPagedDocControl.h
//  Pugpig
//
//  Copyright (c) 2011, Kaldor Holdings Ltd.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this list of
//  conditions and the following disclaimer. Redistributions in binary form must reproduce
//  the above copyright notice, this list of conditions and the following disclaimer in
//  the documentation and/or other materials provided with the distribution.
//  Neither the name of pugpig nor the names of its contributors may be
//  used to endorse or promote products derived from this software without specific prior
//  written permission.
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//  SUCH DAMAGE.
//

#import <UIKit/UIKit.h>
#import "KGPagedDocControlDelegate.h"
#import "KGPagedDocControlNavigator.h"
#import "KGDocumentImageStore.h"
#import "KGDocumentDataSource.h"
#import "KGAnimationStyle.h"
#import "KGDocumentPaneManagement.h"

@interface KGPagedDocControl : UIControl {    
}

@property (nonatomic, assign) id<KGPagedDocControlDelegate> delegate;
@property (nonatomic, retain) id<KGDocumentPaneManagement> paneManager;
@property (nonatomic, retain) id<KGDocumentImageStore> imageStore;
@property (nonatomic, retain) id<KGDocumentDataSource> dataSource;
@property (nonatomic, retain) UIControl<KGPagedDocControlNavigator> *navigator;
@property (nonatomic, readonly) NSUInteger numberOfPanes;
@property (nonatomic, readonly) NSUInteger numberOfPages;
@property (nonatomic, assign) NSUInteger paneNumber;
@property (nonatomic, assign) NSUInteger pageNumber;
@property (nonatomic, readonly) CGFloat fractionalPaneNumber;
@property (nonatomic, readonly) CGFloat fractionalPageNumber;
@property (nonatomic, readonly) UIView *currentPageView;
@property (nonatomic, assign) CGFloat scale;
@property (nonatomic, assign, getter = isScrollEnabled) BOOL scrollEnabled;
@property (nonatomic, assign) BOOL mediaPlaybackRequiresUserAction;
@property (nonatomic, assign) BOOL linksOpenInExternalBrowser;
@property (nonatomic, assign) BOOL bounces;

- (void)hideUntilInitialised;
- (void)hideUntilInitialised:(NSUInteger)requiredPages;
- (void)setPaneNumber:(NSUInteger)newPaneNumber animated:(BOOL)animated;
- (void)setPageNumber:(NSUInteger)newPageNumber animated:(BOOL)animated;
- (BOOL)moveToPageURL:(NSURL*)url animated:(BOOL)animated;
- (id)savePosition;
- (void)restorePosition:(id)position;
- (void)refreshCurrentPage;
- (void)refreshContentSize;
- (void)startSnapshotting;
- (void)stopSnapshotting;
- (NSString*)stringByEvaluatingScript:(NSString*)script;
- (KGOrientation)orientationForSize:(CGSize)size;

@end
