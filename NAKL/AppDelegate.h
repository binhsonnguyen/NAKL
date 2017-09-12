/*******************************************************************************
 * Copyright (c) 2012 Huy Phan <dachuy@gmail.com>
 * This file is part of NAKL project.
 * 
 * NAKL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NAKL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NAKL.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/


#import <Cocoa/Cocoa.h>
#import "ShortcutRecorder/SRRecorderControl.h"
#import "PreferencesController.h"
#import "KeyboardHandler.h"
#import "PTHotKey.h"
#import "AppData.h"
#import "keymap.h"

#define NAKL_MAGIC_NUMBER 536870912L // 1<<29

typedef enum {
    VKM_OFF, VKM_VNID, VKM_TELEX, VKM_VNI
} NAKL_METHOD;

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    PreferencesController *preferencesController; 
    NSWindow *_window;
    IBOutlet NSMenu *statusMenu;
    NSStatusItem * statusItem;    
    NSImage *viStatusImage;
    NSImage *enStatusImage;    
    NSImage *statusHighlightImage;   
    CFMachPortRef      eventTap;    
}

+ (void)initialize;
- (IBAction) methodSelected:(id)sender;
- (IBAction) quit:(id)sender;
- (IBAction) showPreferences:(id)sender;
- (void) updateStatusItem;
- (void) updateCheckedItem;

@property (assign) IBOutlet NSWindow *window;
@property (assign) CFMachPortRef eventTap;    
@property (retain) PreferencesController *preferencesController;

@end
