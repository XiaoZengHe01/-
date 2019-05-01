#include "LetterCapital.h"



LetterCapital::LetterCapital()
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
 QString LetterCapital::ActiveVirtualKey()const
 {

    return this->_Text;
 }

//显示键盘
 void LetterCapital::VirtualKeyboardShow()
 {
    this->_VirtuakBoard.show();
 }

//隐藏键盘
 void LetterCapital::VirtualKeyboardHide()
 {
    this->_VirtuakBoard.hide();
 }

//关闭键盘
 void LetterCapital::VirtualKeyboardClose()
 {
  this->_VirtuakBoard.close();
 }

//设置按键为按下时的状态（颜色）
 void LetterCapital::SetStateUpColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateUpColor(UpColor);
     }
 }

//设置按键按下时的状态（颜色）
 void LetterCapital::SetStateDownColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateDownColor(UpColor);
     }
 }



//键值初始化、按键的布局
void LetterCapital::Initialize()
{

    //添加所需要的键值
    this->_KeyValue.push_back("Q");
    this->_KeyValue.push_back("W");
    this->_KeyValue.push_back("E");
    this->_KeyValue.push_back("R");
    this->_KeyValue.push_back("T");
    this->_KeyValue.push_back("Y");
    this->_KeyValue.push_back("U");
    this->_KeyValue.push_back("I");
    this->_KeyValue.push_back("O");
    this->_KeyValue.push_back("P");

    this->_KeyValue.push_back("A");
    this->_KeyValue.push_back("S");
    this->_KeyValue.push_back("D");
    this->_KeyValue.push_back("F");
    this->_KeyValue.push_back("G");
    this->_KeyValue.push_back("H");
    this->_KeyValue.push_back("J");
    this->_KeyValue.push_back("K");
    this->_KeyValue.push_back("L");

    this->_KeyValue.push_back("Shift");
    this->_KeyValue.push_back("Z");
    this->_KeyValue.push_back("X");
    this->_KeyValue.push_back("C");
    this->_KeyValue.push_back("V");
    this->_KeyValue.push_back("B");
    this->_KeyValue.push_back("N");
    this->_KeyValue.push_back("M");
    this->_KeyValue.push_back("Backspace");

    this->_KeyValue.push_back("Back");
    this->_KeyValue.push_back("123");
    this->_KeyValue.push_back("Character");
    this->_KeyValue.push_back("Space");
    this->_KeyValue.push_back("Enter");



//网格布局
  QGridLayout* GL(new QGridLayout);
//网格布局嵌套横向布局
//QWERTYUIOP
    QHBoxLayout* HL1(new QHBoxLayout);
    int i(0);
    for(;i<10;i++)
    {
      this->_VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
      this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i));
      HL1->addWidget(_VK.back());
    }
//嵌套到网格布局中
    GL->addLayout(HL1,0,0,1,1);
    QHBoxLayout* HL2(new QHBoxLayout);
    HL2->addSpacing(_VK.back()->width()/3);

    for(i=0;i<9;i++)
    {
      this->_VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
      this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+10));
       HL2->addWidget(_VK.back());
    }
    //添加间距
    HL2->addSpacing(_VK.back()->width()/3);

    //嵌套到网格布局中
    GL->addLayout(HL2,1,0,1,1);
    //创建横向布局
    QHBoxLayout* HL3(new QHBoxLayout);
    for(i=0;i<9;i++)
    {
        _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));

        this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+19));
        HL3->addWidget(_VK.back());
    }
    GL->addLayout(HL3,2,0,1,1);

    QHBoxLayout* HL4(new QHBoxLayout);
    for(i=0;i<3;i++)
    {
        _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
       this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+28));
       HL4->addWidget(_VK.back(),1);

    }

    _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
     this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+28));
     HL4->addWidget(_VK.back(),5);
    i++;

    this->_VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
    this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+28));
    HL4->addWidget(_VK.back(),2);

    GL->addLayout(HL4,3,0,1,1);

   this->_VirtuakBoard.setLayout(GL);

}
