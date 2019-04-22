#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QHBoxLayout>
#include "FactoryVirtualKey/FactoryVirtualKey.h"


class MyDialog : public QDialog
{
public:
    MyDialog(QWidget* Parent=nullptr);
};

#endif // MYDIALOG_H
