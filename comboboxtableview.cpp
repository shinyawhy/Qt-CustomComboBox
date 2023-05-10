#include "comboboxtableview.h"
#include <QStandardItemModel>
#include <QPushButton>
#include <QHeaderView>
#include <QDebug>
#include <QButtonGroup>
#include <QLineEdit>
comboBoxTableView::comboBoxTableView(QComboBox *parent):QTableView(parent)
{
    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    auto model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setRowCount(3);
    this->setModel(model);

    QList<QPushButton*> list;
    QButtonGroup *btnGroup = new QButtonGroup(this);


    for(int i = 1; i < 10; i++)
    {
        QPushButton *btn = new QPushButton(this);
        btn->setCheckable(true);

        btn->setStyleSheet(QString("QPushButton{color:#ffffff;padding:6px 10px 6px 10px;background-color:#00beac;font-size:24px;border-radius:6px;}"
                                   "QPushButton:hover{background-color:#20c9b3;}"
                                   "QPushButton:pressed{background-color:#01968c;}"
                                   "QPushButton:checked{background-color:red;}"));

        btn->setText(QString("%1").arg(i));
        list << btn;
        btnGroup->addButton(btn);
        connect(btn, &QPushButton::toggled, [=]{
            parent->setCurrentText(btn->text());
        });

    }
    btnGroup->setExclusive(true);
    for(int i = 0;i < 3;++i)
    {
        for (int j = 0;j < 3;++j)
        {
            model->setItem(i, j, new QStandardItem());
            this->setIndexWidget(model->index(i,j),list[i * 3 + j]);
        }
    }
}

tableComboBox::tableComboBox(QWidget *parent)
{
    auto view = new comboBoxTableView(this);
    this->setModel(view->model());
    this->setView(view);
    setEditable(true);
    lineEdit()->setReadOnly(true);
    setStyleSheet("QComboBox{border-radius: 6px;border: 1px solid #00bcd4;padding:6px 10px 6px 10px;font-size:28px;color: #000000;selection-background-color: #00beac;}");
}
