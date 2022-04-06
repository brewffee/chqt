#ifndef menu_h
#define menu_h 
#endif

#include "actions.h"
#include "imports.h"

void populate(QMenuBar *menuBar, QMainWindow *window) {
    // FILE MENU
    QMenu *fileMenu = menuBar -> addMenu("File");

    QAction *connectAction = fileMenu -> addAction("Connect");
    connectAction -> setShortcut(QKeySequence("Ctrl+Shift+C"));

    QAction *disconnectAction = fileMenu -> addAction("Disconnect");
    disconnectAction -> setShortcut(QKeySequence("Ctrl+Shift+D"));

    QAction *recentAction = fileMenu -> addAction("Recent servers");

    fileMenu -> addSeparator();

    QAction *joinChannelAction = fileMenu -> addAction("Join channel");
    joinChannelAction -> setShortcut(QKeySequence("Ctrl+Shift+J"));

    QAction *leaveChannelAction = fileMenu -> addAction("Leave channel");
    leaveChannelAction -> setShortcut(QKeySequence("Ctrl+Shift+L"));

    fileMenu -> addSeparator();

    QAction *optionAction = fileMenu -> addAction("Options");
    optionAction -> setShortcut(QKeySequence("Ctrl+O"));

    fileMenu -> addSeparator();

    QAction *quitAction = fileMenu -> addAction("Quit");
    quitAction -> setShortcut(QKeySequence("Ctrl+Q"));

    // EDIT MENU
    QMenu *editMenu = menuBar -> addMenu("Edit");

    QAction *undoAction = editMenu -> addAction("Undo");
    undoAction -> setShortcut(QKeySequence("Ctrl+Z"));

    QAction *redoAction = editMenu -> addAction("Redo");
    redoAction -> setShortcut(QKeySequence("Ctrl+Y"));

    editMenu -> addSeparator();

    QAction *cutAction = editMenu -> addAction("Cut");
    cutAction -> setShortcut(QKeySequence("Ctrl+X"));

    QAction *copyAction = editMenu -> addAction("Copy");
    copyAction -> setShortcut(QKeySequence("Ctrl+C"));

    QAction *pasteAction = editMenu -> addAction("Paste");
    pasteAction -> setShortcut(QKeySequence("Ctrl+V"));

    QAction *pasteLastMessageAction = editMenu -> addAction("Paste last message");
    pasteLastMessageAction -> setShortcut(QKeySequence("Ctrl+Shift+V"));

    editMenu -> addSeparator();

    QAction *selectAllAction = editMenu -> addAction("Select all");
    selectAllAction -> setShortcut(QKeySequence("Ctrl+A"));

    // VIEW MENU
    QMenu *viewMenu = menuBar -> addMenu("View");

    QAction *showServerListAction = viewMenu -> addAction("Show server list");
    showServerListAction -> setShortcut(QKeySequence("Ctrl+Shift+S"));

    QAction *showMemberListAction = viewMenu -> addAction("Show member list");
    showMemberListAction -> setShortcut(QKeySequence("Ctrl+Shift+M"));

    viewMenu -> addSeparator();

    QAction *appearanceAction = viewMenu -> addAction("Appearance");

    viewMenu -> addSeparator();

    QAction *showTopicAction = viewMenu -> addAction("Show topic");
    showTopicAction -> setShortcut(QKeySequence("Ctrl+Shift+T"));

    QAction *showHideBlockedUsersAction = viewMenu -> addAction("Show/hide blocked users");
    showHideBlockedUsersAction -> setShortcut(QKeySequence("Ctrl+B"));

    // BOOKMARKS MENU
    QMenu *bookmarksMenu = menuBar -> addMenu("Bookmarks");

    QAction *addCurServerAction = bookmarksMenu -> addAction("Add current server");

    QAction *manageBookmarksAction = bookmarksMenu -> addAction("Manage bookmarks");

    bookmarksMenu -> addSeparator();
    // get from a data file later
    QAction *defaultBookmarkAction = bookmarksMenu -> addAction("Default bookmark");
    defaultBookmarkAction -> setShortcut(QKeySequence("Ctrl+Alt+1"));

    // TOOLS MENU
    QMenu *toolMenu = menuBar -> addMenu("Tools");

    QAction *updateNicknameAction = toolMenu -> addAction("Update nickname");

    QAction *setAvatarAction = toolMenu -> addAction("Set avatar");

    toolMenu -> addSeparator();

    QAction *blockUserAction = toolMenu -> addAction("Block user");

    QAction *friendUserAction = toolMenu -> addAction("Friend user");

    toolMenu -> addSeparator();

    QAction *clearChatAction = toolMenu -> addAction("Clear chat");
    
    toolMenu -> addSeparator();

    // MOD MENU
    QMenu *modMenu = menuBar -> addMenu("Mod");

    QAction *kickAction = modMenu -> addAction("Kick");

    QAction *banAction = modMenu -> addAction("Ban");

    QAction *unbanAction = modMenu -> addAction("Unban");

    modMenu -> addSeparator();

    QAction *muteAction = modMenu -> addAction("Mute");

    QAction *unmuteAction = modMenu -> addAction("Unmute");

    modMenu -> addSeparator();

    QAction *manageChannelAction = modMenu -> addAction("Manage channel");

    // HELP MENU
    QMenu *helpMenu = menuBar -> addMenu("Help");

    QAction *updateAction = helpMenu -> addAction("Check for updates");

    QAction *aboutAction = helpMenu -> addAction("About chqt");

    window -> connect(connectAction, &QAction::triggered, [=]() {
       openDialog("connect", window);
    });
}