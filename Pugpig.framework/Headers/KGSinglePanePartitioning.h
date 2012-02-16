//
//  KGSinglePanePartitioning.h
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

#import "KGDocumentPaneManagement.h"

@interface KGSinglePanePartitioning : NSObject<KGDocumentPaneManagement> {
}

@property (nonatomic, retain) id<KGDocumentImageStore> imageStore;
@property (nonatomic, retain) id<KGDocumentDataSource> dataSource;

- (NSUInteger)numberOfPanesInOrientation:(KGOrientation)orientation;
- (NSInteger)pageForPaneNumber:(NSUInteger)pane orientation:(KGOrientation)orientation;
- (NSInteger)paneForPageNumber:(NSUInteger)page orientation:(KGOrientation)orientation;
- (CGRect)frameForPageNumber:(NSUInteger)page pageSize:(CGSize)size orientation:(KGOrientation)orientation;
- (BOOL)layoutWebView:(UIWebView*)webView pageSize:(CGSize)size orientation:(KGOrientation)orientation;
- (void)takeSnapshotsForWebView:(UIWebView*)webView pageSize:(CGSize)size orientation:(KGOrientation)orientation progressHandler:(void(^)(NSUInteger,BOOL))progress completionHandler:(void(^)(UIWebView*))completion;
- (BOOL)hasSnapshotsForPageNumber:(NSUInteger)page orientation:(KGOrientation)orientation;
- (UIImage*)snapshotForPaneNumber:(NSUInteger)pane orientation:(KGOrientation)orientation withOptions:(KGImageStoreOptions)options;
- (void)resetPageNumber:(NSUInteger)page;
- (void)resetAllPages;
- (NSInteger)paneFromFragment:(NSString*)fragment inWebView:(UIWebView*)webView pageSize:(CGSize)size orientation:(KGOrientation)orientation;
- (CGFloat)fractionalPageFromPane:(CGFloat)pane orientation:(KGOrientation)orientation;
- (id)persistentStateForPaneNumber:(NSUInteger)pane orientation:(KGOrientation)orientation;
- (NSUInteger)paneFromPersistentState:(id)state orientation:(KGOrientation)orientation;

@end
