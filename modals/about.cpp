#include "imports.h"

void aboutDialog(QMainWindow *window) {
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