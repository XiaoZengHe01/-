#include "MyDialog.h"

MyDialog::MyDialog(QWidget* Parent):QDialog (Parent)
{

    this->resize(900,300);

   //创建圆形的虚拟按键
    AbstractVirtualKey* Vk1(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::CIRCLEVIRTUALKEY));
    Vk1->SetVirtualKeyValue("XiaoZengHe");
    Vk1->SetStateDownColor(QColor(255,0,0));
    Vk1->SetStateUpColor(QColor(255,255,0));
    QObject::connect(Vk1,&AbstractVirtualKey::Clicked,[](){
        QMessageBox::warning(nullptr,"VirtualKey","CIRCLEVIRTUALKEY");
    });

  //创建圆角矩形的虚拟按键
    AbstractVirtualKey* Vk2(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::CIRCULARBEADVIRTUALKEY));
    Vk2->SetVirtualKeyValue("XiaoZengHe");
    Vk2->SetStateDownColor(QColor(255,0,0));
    Vk2->SetStateUpColor(QColor(255,255,0));
    QObject::connect(Vk2,&AbstractVirtualKey::Clicked,[](){
        QMessageBox::warning(nullptr,"VirtualKey","CIRCULARBEADVIRTUALKEY");
    });

  //创建矩形的虚拟按键
    AbstractVirtualKey* Vk3(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
    Vk3->SetVirtualKeyValue("XiaoZengHe");
    Vk3->SetStateDownColor(QColor(255,0,0));
    Vk3->SetStateUpColor(QColor(255,255,0));
    QObject::connect(Vk3,&AbstractVirtualKey::Clicked,[](){
        QMessageBox::warning(nullptr,"VirtualKey","RECTVIRTUALKEY");
    });

    //横向布局
    QHBoxLayout* HL(new QHBoxLayout);
    HL->addWidget(Vk1);
    HL->addWidget(Vk2);
    HL->addWidget(Vk3);

    //设置布局
    this->setLayout(HL);
}
