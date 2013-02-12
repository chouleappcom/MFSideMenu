//
//  MFSideMenu.h
//
//  Created by Michael Frederick on 3/17/12.
//

#import "UINavigationController+MFSideMenu.h"

static const CGFloat kMFSideMenuSidebarWidth = 270.0f;
static const CGFloat kMFSideMenuShadowWidth = 10.0f;
static const CGFloat kMFSideMenuAnimationDuration = 0.2f;
static const CGFloat kMFSideMenuAnimationMaxDuration = 0.4f;

typedef enum {
    MFSideMenuOptionShadowEnabled = 1 << 0, // enable the shadow between the navigation controller & side menu
} MFSideMenuOptions;

typedef enum {
    MFSideMenuPanModeNavigationBar = 1 << 0, // enable panning on the navigation bar
    MFSideMenuPanModeNavigationController = 1 << 1 // enable panning on the body of the navigation controller
} MFSideMenuPanMode;

typedef enum {
    MFSideMenuStateClosed,
    MFSideMenuStateLeftMenuOpen,
    MFSideMenuStateRightMenuOpen
} MFSideMenuState;

typedef enum {
    MFSideMenuStateEventMenuWillOpen, // the menu is going to open
    MFSideMenuStateEventMenuDidOpen, // the menu finished opening
    MFSideMenuStateEventMenuWillClose, // the menu is going to close
    MFSideMenuStateEventMenuDidClose // the menu finished closing
} MFSideMenuStateEvent;

typedef void (^MFSideMenuStateEventBlock)(MFSideMenuStateEvent);

@interface MFSideMenu : NSObject<UIGestureRecognizerDelegate>

@property (nonatomic, readonly) UINavigationController *navigationController;

@property (nonatomic, assign) MFSideMenuState menuState;
@property (nonatomic, assign) MFSideMenuPanMode panMode;

// this can be used to observe all MFSideMenuStateEvents
@property (copy) MFSideMenuStateEventBlock menuStateEventBlock;

+ (MFSideMenu *) menuWithNavigationController:(UINavigationController *)controller
                        sideMenuController:(id)menuController;

+ (MFSideMenu *) menuWithNavigationController:(UINavigationController *)controller
                        sideMenuController:(id)menuController
                                   options:(MFSideMenuOptions)options;

+ (MFSideMenu *) menuWithNavigationController:(UINavigationController *)controller
                   sideMenuController:(id)menuController
                              options:(MFSideMenuOptions)options
                              panMode:(MFSideMenuPanMode)panMode;

+ (MFSideMenu *) menuWithNavigationController:(UINavigationController *)controller
                       leftSideMenuController:(id)leftMenuController
                      rightSideMenuController:(id)rightMenuController
                                      options:(MFSideMenuOptions)options
                                      panMode:(MFSideMenuPanMode)panMode;

@end