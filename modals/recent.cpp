#include "imports.h"

void recentDialog(QMainWindow *window) {
    QWidget *newWidget = new QWidget();
    newWidget -> setWindowFlags(Qt::Window);
    newWidget -> setWindowModality(Qt::ApplicationModal);
    newWidget -> setWindowTitle("Add connection");
    newWidget -> setFixedSize(512, 420);
    
    newWidget -> move( 
        window -> x() + (window -> width() / 2) - (newWidget -> width() / 2),
        window -> y() + (window -> height() / 2) - (newWidget -> height() / 2)
    );

    QLabel *listLabel = new QLabel("Recent connections");
    listLabel -> setContentsMargins(0, 12, 0, 0);

    // new treeview list
    QStandardItemModel *model = new QStandardItemModel();
    // append 15 items 
    for (int i = 0; i < 30; i++) {
        QStandardItem *item = new QStandardItem("Item " + QString::number(i));
        model -> appendRow(item);
    }

    QTreeView *list = new QTreeView();
    list -> setModel(model);
    list -> setHeaderHidden(true);
    list -> setFixedHeight(250);
    list -> setEditTriggers(QAbstractItemView::NoEditTriggers);

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

    layout -> addWidget(listLabel);
    layout -> addWidget(list);
    layout -> addWidget(usernameLabel);
    layout -> addWidget(usernameEntry);
    layout -> addLayout(buttonLayout);

    newWidget -> setLayout(layout);
    newWidget -> show();

    // newWidget -> connect(bookmarkButton, SIGNAL(clicked()), ...);
    newWidget -> connect(cancelButton, SIGNAL(clicked()), newWidget, SLOT(close()));
    // newWidget -> connect(connectButton, SIGNAL(clicked()), ...);
}