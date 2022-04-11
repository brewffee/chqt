#include "imports.h"

void joinDialog(QMainWindow *window) {
    QWidget *newWidget = new QWidget();
    newWidget -> setWindowFlags(Qt::Window);
    newWidget -> setWindowModality(Qt::ApplicationModal);
    newWidget -> setWindowTitle("Join a channel");
    newWidget -> setFixedSize(512, 200);

    newWidget -> move( 
        window -> x() + (window -> width() / 2) - (newWidget -> width() / 2),
        window -> y() + (window -> height() / 2) - (newWidget -> height() / 2)
    );

    // build the form 
    QLabel *channelLabel = new QLabel("Channel:");
    QLineEdit *channelEntry = new QLineEdit();
    channelLabel -> setContentsMargins(0, 12, 0, 0);

    // fill username with current username later
    QLabel *usernameLabel = new QLabel("Username:");
    QLineEdit *usernameEntry = new QLineEdit();

    // for fixing entry height with added margins
    usernameLabel -> setFixedHeight(20);
    usernameEntry -> setFixedHeight(50);

    usernameLabel -> setContentsMargins(0, 36, 0, 0);
    usernameEntry -> setContentsMargins(0, 0, 0, 24);

    QVBoxLayout *layout = new QVBoxLayout();

    // add buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *cancelButton = new QPushButton("Cancel");
    QPushButton *joinButton = new QPushButton("Join");

    cancelButton -> setFixedWidth(80);
    joinButton -> setFixedWidth(100);

    buttonLayout -> addWidget(cancelButton);
    buttonLayout -> addWidget(joinButton);

    buttonLayout -> setAlignment(Qt::AlignRight);

    layout -> addWidget(channelLabel);
    layout -> addWidget(channelEntry);
    layout -> addWidget(usernameLabel);
    layout -> addWidget(usernameEntry);
    layout -> addLayout(buttonLayout);

    newWidget -> setLayout(layout);
    newWidget -> show();

    newWidget -> connect(cancelButton, SIGNAL(clicked()), newWidget, SLOT(close()));
    // newWidget -> connect(joinButton, SIGNAL(clicked()), ...);
}