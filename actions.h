#ifndef actions_h
#define actions_h
#endif

#include "imports.h"

// TODO: Organize this code by splitting it into separate files
//
// chqt-master/modals/{actionType}.cpp
// chqt-master/modals.h

void openDialog(std::string dialogType, QMainWindow *window) {
    if (dialogType == "connect") {
        QWidget *newWidget = new QWidget();
        newWidget -> setWindowFlags(Qt::Window);
        newWidget -> setWindowModality(Qt::ApplicationModal);
        newWidget -> setWindowTitle("Add connection");
        newWidget -> setFixedSize(512, 200);

        // ugly
        newWidget -> move( 
            window -> x() + (window -> width() / 2) - (newWidget -> width() / 2),
            window -> y() + (window -> height() / 2) - (newWidget -> height() / 2)
        );

        // build the form
        QLabel *serverAddressLabel = new QLabel("Server IP:");
        QLineEdit *serverAddressEntry = new QLineEdit();
        serverAddressLabel -> setContentsMargins(0, 12, 0, 0);

        QLabel *serverPortLabel = new QLabel("Port:");
        QLineEdit *serverPortEntry = new QLineEdit();

        serverPortEntry -> setFixedWidth(150);
        serverPortLabel -> setFixedWidth(150);

        serverPortLabel -> setContentsMargins(0,12, 0, 0);

        QLabel *usernameLabel = new QLabel("Username:");
        QLineEdit *usernameEntry = new QLineEdit();

        // for fixing entry height with added margins
        usernameLabel -> setFixedHeight(20);
        usernameEntry -> setFixedHeight(50);

        usernameLabel -> setContentsMargins(0, 36, 0, 0);
        usernameEntry -> setContentsMargins(0, 0, 0, 24);
 
        QVBoxLayout *layout = new QVBoxLayout();

        QHBoxLayout *serverInfoLabels = new QHBoxLayout();
        serverInfoLabels -> addWidget(serverAddressLabel);
        serverInfoLabels -> addWidget(serverPortLabel);

        QHBoxLayout *serverInfoEntries = new QHBoxLayout();
        serverInfoEntries -> addWidget(serverAddressEntry);
        serverInfoEntries -> addWidget(serverPortEntry);

        QHBoxLayout *usernameLabelBox = new QHBoxLayout();
        usernameLabelBox -> addWidget(usernameLabel);

        QHBoxLayout *usernameEntryBox = new QHBoxLayout();
        usernameEntryBox -> addWidget(usernameEntry);

        // add buttons
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        QPushButton *bookmarkButton = new QPushButton("Add to bookmarks");
        QPushButton *cancelButton = new QPushButton("Cancel");
        QPushButton *connectButton = new QPushButton("Connect");

        bookmarkButton -> setFixedWidth(150);
        cancelButton -> setFixedWidth(80);
        connectButton -> setFixedWidth(100);

        buttonLayout -> addWidget(bookmarkButton);
        buttonLayout -> addWidget(cancelButton);
        buttonLayout -> addWidget(connectButton);

        buttonLayout -> setAlignment(Qt::AlignRight);

        layout -> addLayout(serverInfoLabels);
        layout -> addLayout(serverInfoEntries);
        layout -> addLayout(usernameLabelBox);
        layout -> addLayout(usernameEntryBox);
        layout -> addLayout(buttonLayout);

        newWidget -> setLayout(layout);
        newWidget -> show();

        // newWidget -> connect(bookmarkButton, SIGNAL(clicked()), ...);
        newWidget -> connect(cancelButton, SIGNAL(clicked()), newWidget, SLOT(close()));
        // newWidget -> connect(connectButton, SIGNAL(clicked()), ...);
    } else if (dialogType == "about") {
        QWidget *newWidget = new QWidget();
        newWidget -> setWindowFlags(Qt::Window);
        newWidget -> setWindowModality(Qt::ApplicationModal);
        newWidget -> setWindowTitle("chqt {version}");
        newWidget -> setFixedSize(512, 256);        

        // ugly
        newWidget -> move( 
            window -> x() + (window -> width() / 2) - (newWidget -> width() / 2),
            window -> y() + (window -> height() / 2) - (newWidget -> height() / 2)
        );

        // start displaying information
        QLabel *picture = new QLabel();
        picture -> setPixmap(QPixmap("./res/logo.png"));
        picture -> setFixedSize(128, 128);
        picture -> setScaledContents(true);      
        picture -> setContentsMargins(12, 12, 12, 12);

        // add label next to picture

        QHBoxLayout *appDetails = new QHBoxLayout();

        QLabel *appName = new QLabel("chqt");

        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        appName -> setFont(font);

        QLabel *version = new QLabel("version {version}");

        // align the version label to the left, directly after the app name
        appName -> setAlignment(Qt::AlignLeft);
        version -> setAlignment(Qt::AlignBottom);
        version -> setContentsMargins(0, 0, 0, 12);

        appDetails -> addWidget(appName);
        appDetails -> addWidget(version);
        appDetails -> setAlignment(Qt::AlignLeft);

        QLabel *author = new QLabel("by <b>mxchakitty</b>");
        author -> setAlignment(Qt::AlignCenter);

        // draft this later when the MD is done lol
        QLabel *description = new QLabel("Lorem ipsum sit dolor amet consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ");
        description -> setWordWrap(true);

        QLabel *ghOffer = new QLabel("Want to contribute? Check out the <a href=\"https://github.com/mxchakitty/chqt\">GitHub repository</a>.");
        ghOffer -> setOpenExternalLinks(true);
        ghOffer -> setWordWrap(true);

        QLabel *sponsorOffer = new QLabel("Alternatively, you can support the development of this project by <a href=\"about:blank\">sponsoring</a>. <a href=\"about:blank\">Learn more</a>.");
        sponsorOffer -> setOpenExternalLinks(true);
        sponsorOffer -> setWordWrap(true);

        QHBoxLayout *aboutLayout = new QHBoxLayout();
        QVBoxLayout *aboutInformation = new QVBoxLayout();

        aboutLayout -> addWidget(picture);
        aboutLayout -> addLayout(aboutInformation);

        aboutInformation -> addLayout(appDetails);
        aboutInformation -> addWidget(description);
        aboutInformation -> addWidget(ghOffer);
        aboutInformation -> addWidget(sponsorOffer);
  
        aboutLayout -> setAlignment(Qt::AlignLeft);
        aboutInformation -> setAlignment(Qt::AlignLeft);

        // configure tab setup
        QTabWidget *tabs = new QTabWidget();
        QWidget *aboutTab = new QWidget();
        QWidget *contributorTab = new QWidget();
        QWidget *sponsorTab = new QWidget();

        aboutTab -> setLayout(aboutLayout);

        tabs -> addTab(aboutTab, "About");
        tabs -> addTab(contributorTab, "Contributors");
        tabs -> addTab(sponsorTab, "Sponsors");

        QVBoxLayout *layout = new QVBoxLayout();
        layout -> addWidget(tabs);

        newWidget -> setLayout(layout);
        newWidget -> show();
    }
}