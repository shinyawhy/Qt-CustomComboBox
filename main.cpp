#include "mainwindow.h"
#include "comboboxtableview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    tableComboBox *tcb = new tableComboBox;

    w.setCentralWidget(tcb);

    tcb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    w.show();


    return a.exec();
}
