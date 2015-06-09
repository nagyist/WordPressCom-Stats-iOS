#import <UIKit/UIKit.h>
#import "StatsTableViewController.h"

typedef NS_ENUM(NSInteger, StatsType)
{
    StatsTypeInsights,
    StatsTypeDays,
    StatsTypeWeeks,
    StatsTypeMonths,
    StatsTypeYears
};

@class WPStatsViewController;

@protocol WPStatsTypeSelectionDelegate <NSObject>

- (void)viewController:(UIViewController *)viewController changeStatsTypeSelection:(StatsType)statsType;

@end

@protocol WPStatsViewControllerDelegate <NSObject>

@optional

- (void)statsViewController:(WPStatsViewController *)controller didSelectViewWebStatsForSiteID:(NSNumber *)siteID;
- (void)statsViewController:(WPStatsViewController *)controller openURL:(NSURL *)url;

@end

@protocol StatsProgressViewDelegate <NSObject>

- (void)statsViewControllerDidBeginLoadingStats:(UIViewController *)controller;
- (void)statsViewController:(UIViewController *)controller loadingProgressPercentage:(CGFloat)percentage;
- (void)statsViewControllerDidEndLoadingStats:(UIViewController *)controller;

@end

@interface WPStatsViewController : UIViewController

@property (nonatomic, strong) NSNumber *siteID;
@property (nonatomic, copy)   NSString *oauth2Token;
@property (nonatomic, strong) NSTimeZone *siteTimeZone;
@property (nonatomic, weak) id<WPStatsViewControllerDelegate> statsDelegate;

- (IBAction)statsTypeControlDidChange:(UISegmentedControl *)control;

@end
