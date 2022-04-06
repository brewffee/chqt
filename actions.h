#ifndef actions_h
#define actions_h
#endif

#include "imports.h"

void openDialog(std::string dialogType, QMainWindow *window) {
    if (dialogType == "connect") {
        QWidget *newWidget = new QWidget();
        newWidget -> setWindowFlags(Qt::Window);
        newWidget -> setWindowModality(Qt::ApplicationModal);
        newWidget -> setWindowTitle("Add connection");
        newWidget -> setFixedSize(300, 200);

        // ugly
        newWidget -> move( 
            window -> x() + (window -> width() / 2) - (newWidget -> width() / 2),
            window -> y() + (window -> height() / 2) - (newWidget -> height() / 2)
        );

        newWidget -> show();
    }
}