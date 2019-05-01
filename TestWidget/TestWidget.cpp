#include "TestWidget.h"
#include <QTextEdit>

TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{



    this->_VBK=new DelegateVKB;
    //启动键盘
    this->_VBK->Start();

    QTextEdit* textEdit;
    QVBoxLayout* VL(new QVBoxLayout);
    VL->addWidget(textEdit=new QTextEdit);


    connect(this->_VBK,
            &DelegateVKB::HasActiveKey,
            [=](QString ActiveKey){
        textEdit->insertPlainText(ActiveKey);

    });
    this->setLayout(VL);


}
