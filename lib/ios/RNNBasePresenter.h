#import "RNNNavigationOptions.h"
#import "RNNReactComponentRegistry.h"

typedef void (^RNNReactViewReadyCompletionBlock)(void);

@interface RNNBasePresenter : NSObject

@property(nonatomic, weak, setter=bindViewController:) UIViewController *boundViewController;

@property(nonatomic, strong) NSString *boundComponentId;

@property(nonatomic, strong) RNNNavigationOptions *defaultOptions;

@property(nonatomic, strong) RNNReactComponentRegistry *componentRegistry;

- (instancetype)initWithDefaultOptions:(RNNNavigationOptions *)defaultOptions;

- (instancetype)initWithComponentRegistry:(RNNReactComponentRegistry *)componentRegistry
                           defaultOptions:(RNNNavigationOptions *)defaultOptions;

- (void)applyOptionsOnInit:(RNNNavigationOptions *)initialOptions;

- (void)applyOptionsOnViewDidLayoutSubviews:(RNNNavigationOptions *)options;

- (void)applyOptions:(RNNNavigationOptions *)options;

- (void)mergeOptions:(RNNNavigationOptions *)options
     resolvedOptions:(RNNNavigationOptions *)resolvedOptions;

- (void)renderComponents:(RNNNavigationOptions *)options
                 perform:(RNNReactViewReadyCompletionBlock)readyBlock;

- (void)viewDidLayoutSubviews;

- (void)componentWillAppear;

- (void)componentDidAppear;

- (void)componentWillDisappear;

- (void)componentDidDisappear;

- (UINavigationItem *)currentNavigationItem;

- (UIStatusBarStyle)getStatusBarStyle;

- (UIInterfaceOrientationMask)getOrientation;

- (BOOL)getStatusBarVisibility;

- (BOOL)hidesBottomBarWhenPushed;

- (BOOL)prefersHomeIndicatorAutoHidden;

@end
