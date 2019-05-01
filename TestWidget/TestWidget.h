#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

#include "DelegateVKB/DelegateVKB.h"


class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = nullptr);
    //键盘代理
 DelegateVKB* _VBK;
signals:

public slots:
};

#endif // TESTWIDGET_H
