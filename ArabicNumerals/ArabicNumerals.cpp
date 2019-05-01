#include "ArabicNumerals.h"

ArabicNumerals::ArabicNumerals()
{
    this->Initialize();
    for(auto i:this->_VK)
    {
          QObject::connect(i,&AbstractVirtualKey::Clicked,[=](){
            this->_Text=i->_Text;
            emit this->ActiveKey();
        });

    }
}

//活跃键——返回按下的键的键值
 QString ArabicNumerals::ActiveVirtualKey()const
 {
    return this->_Text;
 }

//显示键盘
 void ArabicNumerals::VirtualKeyboardShow()
 {
    this->_VirtuakBoard.show();
 }

//隐藏键盘
 void ArabicNumerals::VirtualKeyboardHide()
 {
    this->_VirtuakBoard.hide();
 }

//关闭键盘
 void ArabicNumerals::VirtualKeyboardClose()
 {
  this->_VirtuakBoard.close();
 }

//设置按键为按下时的状态（颜色）
 void ArabicNumerals::SetStateUpColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateUpColor(UpColor);
     }
 }

//设置按键按下时的状态（颜色）
 void ArabicNumerals::SetStateDownColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateDownColor(UpColor);
     }
 }


//键值初始化、按键的布局
void ArabicNumerals::Initialize()
{

    //添加所需要的键值
    this->_KeyValue.push_back("+");
    this->_KeyValue.push_back("1");
    this->_KeyValue.push_back("2");
    this->_KeyValue.push_back("3");
    this->_KeyValue.push_back("Backspace");

    this->_KeyValue.push_back("-");
    this->_KeyValue.push_back("4");
    this->_KeyValue.push_back("5");
    this->_KeyValue.push_back("6");
    this->_KeyValue.push_back("Back");

    this->_KeyValue.push_back("*");
    this->_KeyValue.push_back("7");
    this->_KeyValue.push_back("8");
    this->_KeyValue.push_back("9");
    this->_KeyValue.push_back("%");

    this->_KeyValue.push_back("/");
    this->_KeyValue.push_back("Space");
    this->_KeyValue.push_back("0");
    this->_KeyValue.push_back(".");
    this->_KeyValue.push_back("Enter");




//网格布局
  QGridLayout* GL(new QGridLayout);
//网格布局嵌套横向布局
//QWERTYUIOP
    QHBoxLayout* HL1(new QHBoxLayout);
    int i(0);
    for(;i<5;i++)
    {
      this->_VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
      this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i));
      HL1->addWidget(_VK.back());
    }
//嵌套到网格布局中
    GL->addLayout(HL1,0,0,1,1);
    QHBoxLayout* HL2(new QHBoxLayout);

    for(i=0;i<5;i++)
    {
      this->_VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
      this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+5));
       HL2->addWidget(_VK.back());
    }

    //嵌套到网格布局中
    GL->addLayout(HL2,1,0,1,1);

    //创建横向布局
    QHBoxLayout* HL3(new QHBoxLayout);
    for(i=0;i<5;i++)
    {
        _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));

        this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+10));
        HL3->addWidget(_VK.back());
    }
    GL->addLayout(HL3,2,0,1,1);

    QHBoxLayout* HL4(new QHBoxLayout);
    for(i=0;i<5;i++)
    {
        _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
       this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+15));
       HL4->addWidget(_VK.back(),1);

    }

    GL->addLayout(HL4,3,0,1,1);

   this->_VirtuakBoard.setLayout(GL);

}
