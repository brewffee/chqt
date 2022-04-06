#include "imports.h"
#include "menu.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();
    QWidget content;

    window -> setCentralWidget(&content);
    content.setWindowTitle("chqt");
    content.setMinimumSize(680, 360);
    content.resize(1280, 720); 
    window -> resize(1280, 720);

    QMenuBar *menuBar = new QMenuBar(window);
    window -> setMenuBar(menuBar);
    menuBar -> setNativeMenuBar(false);

    populate(menuBar, window);

    QWidget sidebarL, main, sidebarR;
    QHBoxLayout layout;

    // LEFT SIDEBAR
    QTreeView *treeView = new QTreeView();
    QStandardItemModel *model = new QStandardItemModel();

    // typically the tree would be populated from a database
    QStandardItem *server = new QStandardItem("Default Server");
    QStandardItem *channel = new QStandardItem("Default Channel");
    server -> appendRow(channel);
    model -> appendRow(server);

    treeView -> setModel(model);
    treeView -> setHeaderHidden(true);
    treeView -> expandAll();
    treeView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    treeView -> setCurrentIndex(model -> indexFromItem(channel));

    sidebarL.setFixedWidth(content.width() / 6);

    QVBoxLayout *sidebarL_layout = new QVBoxLayout();
    QLabel *headerL = new QLabel("Connections");
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
    QList<QStandardItem *> items;

    // types of possible members
    QStandardItem *op = new QStandardItem("@Operator");
    QStandardItem *moderator = new QStandardItem("+Moderator");
    QStandardItem *member = new QStandardItem("Member");
    QStandardItem *buddy = new QStandardItem("Buddy");
    QStandardItem *muted = new QStandardItem("Muted");
    QStandardItem *blocked = new QStandardItem("Blocked");
    QStandardItem *self = new QStandardItem("You");

    // give each member type a font style
    buddy -> setForeground(QBrush(QColor(2, 200, 0)));
    muted -> setForeground(QBrush(QColor(200, 200, 200)));
    blocked -> setForeground(QBrush(QColor(255, 0, 0)));

    // my system's default font is Product Sans, need to
    // find out how to use default font properties later
    self -> setFont(QFont("Product Sans", 12, QFont::Bold));

    std::array <QStandardItem *, 7> member_types = {op, moderator, member, buddy, muted, blocked, self};

    for (auto &item : member_types) {
        items.append(item);
    }

    QStandardItemModel *member_model = new QStandardItemModel();
    member_model -> appendColumn(items);

    // create a tree view from the model
    QTreeView *member_tree = new QTreeView();
    member_tree -> setModel(member_model);
    member_tree -> setHeaderHidden(true);
    member_tree -> expandAll();
    member_tree -> setEditTriggers(QAbstractItemView::NoEditTriggers);
 
    sidebarR.setFixedWidth(content.width() / 6);

    QVBoxLayout *sidebarR_layout = new QVBoxLayout();
    QLabel *headerR = new QLabel("Members");
    headerR -> setAlignment(Qt::AlignCenter);
    sidebarR_layout -> addWidget(headerR);
    sidebarR_layout -> addWidget(member_tree);
    sidebarR.setLayout(sidebarR_layout);
    
    layout.addWidget(&sidebarR);

    // finishing up
    content.setLayout(&layout);

    content.layout() -> setContentsMargins(0, 0, 0, 0);
    window -> layout() -> setContentsMargins(0, 0, 0, 0);

    window -> show();
    return app.exec();
}
