#include "imports.h"

void connectDialog(QMainWindow *window) {
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
}