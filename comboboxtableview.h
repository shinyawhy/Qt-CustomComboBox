#ifndef COMBOBOXTABLEVIEW_H
#define COMBOBOXTABLEVIEW_H

#include <QComboBox>
#include <QTableView>

class comboBoxTableView : public QTableView
{
public:
    comboBoxTableView(QComboBox *parent);
};

class tableComboBox : public QComboBox
{
public:
    tableComboBox(QWidget *parent = nullptr);
};

#endif // COMBOBOXTABLEVIEW_H
