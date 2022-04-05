#include <QStandardItemModel>
#include <QStandardItem>
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeView>
#include <QToolBar>
#include <QMenuBar>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();
    QWidget content;

    window -> setCentralWidget(&content);
    content.setWindowTitle("chqt");
    content.resize(1280, 720); 
    content.setMinimumSize(680, 360);

    QMenuBar *menuBar = new QMenuBar(window);
    window -> setMenuBar(menuBar);
    menuBar -> setNativeMenuBar(false);

    QMenu *menu = menuBar -> addMenu("Test");
    QAction *action = menu -> addAction("Test");

    QWidget sidebarL, main, sidebarR;
    QHBoxLayout layout;

    // LEFT SIDEBAR
    QTreeView *treeView = new QTreeView();
    QStandardItemModel *model = new QStandardItemModel();

    // typically the tree would be populated from a database
    QStandardItem *parent = new QStandardItem("parent");
    QStandardItem *child = new QStandardItem("child");
    parent -> appendRow(child);
    model -> appendRow(parent);

    treeView -> setModel(model);
    treeView -> setHeaderHidden(true);
    treeView -> expandAll();
    treeView -> setEditTriggers(QAbstractItemView::NoEditTriggers);

    sidebarL.setFixedWidth(content.width() / 6);

    QVBoxLayout *sidebarL_layout = new QVBoxLayout();
    QLabel *headerL = new QLabel("Sidebar Left");
    headerL -> setAlignment(Qt::AlignCenter);
    sidebarL_layout -> addWidget(headerL);
    sidebarL_layout -> addWidget(treeView);
    sidebarL.setLayout(sidebarL_layout);

    layout.addWidget(&sidebarL);

    // MAIN
    QLabel *headerM = new QLabel("Main", &main);
    headerM -> setAlignment(Qt::AlignCenter);

    main.setStyleSheet("background: #fdfdfd; border-left: 1px solid #e0e0e0; border-right: 1px solid #e0e0e0; padding: 2px;");
    content.setStyleSheet("background: #f2f2f2;");

    layout.addWidget(&main);

    // RIGHT SIDEBAR
    sidebarR.setFixedWidth(content.width() / 6);

    QVBoxLayout *sidebarR_layout = new QVBoxLayout();
    QLabel *headerR = new QLabel("Sidebar Right");
    headerR -> setAlignment(Qt::AlignCenter);
    sidebarR_layout -> addWidget(headerR);
    sidebarR.setLayout(sidebarR_layout);

    layout.addWidget(&sidebarR);

    // finishing up
    content.setLayout(&layout);

    content.layout() -> setContentsMargins(0, 0, 0, 0);
    window -> layout() -> setContentsMargins(0, 0, 0, 0);

    window -> show();
    return app.exec();
}

