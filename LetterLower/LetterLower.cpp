#include "LetterLower.h"

LetterLower::LetterLower()
{
    //键值初始化、按键的布局
    this->Initialize();

    for(auto i:this->_VK)
    {
        //为每个按键连接信号和曹
        i->setFocusPolicy(Qt::NoFocus);
        QObject::connect(i,&AbstractVirtualKey::Clicked,[=](){
            this->_Text=i->_Text;
            emit this->ActiveKey();
        });

    }
}


//活跃键——返回按下的键的键值
 QString LetterLower::ActiveVirtualKey()const
 {
    return this->_Text;
 }

//显示键盘
 void LetterLower::VirtualKeyboardShow()
 {
    this->_VirtuakBoard.show();
 }

//隐藏键盘
 void LetterLower::VirtualKeyboardHide()
 {
    this->_VirtuakBoard.hide();
 }

//关闭键盘
 void LetterLower::VirtualKeyboardClose()
 {
  this->_VirtuakBoard.close();
 }

//设置按键为按下时的状态（颜色）
 void LetterLower::SetStateUpColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateUpColor(UpColor);
     }
 }

//设置按键按下时的状态（颜色）
 void LetterLower::SetStateDownColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
        i->SetStateDownColor(UpColor);
     }
 }



//键值初始化、按键的布局
void LetterLower::Initialize()
{

    //添加所需要的键值
    this->_KeyValue.push_back("q");
    this->_KeyValue.push_back("w");
    this->_KeyValue.push_back("e");
    this->_KeyValue.push_back("r");
    this->_KeyValue.push_back("t");
    this->_KeyValue.push_back("y");
    this->_KeyValue.push_back("u");
    this->_KeyValue.push_back("i");
    this->_KeyValue.push_back("o");
    this->_KeyValue.push_back("p");

    this->_KeyValue.push_back("a");
    this->_KeyValue.push_back("s");
    this->_KeyValue.push_back("d");
    this->_KeyValue.push_back("f");
    this->_KeyValue.push_back("g");
    this->_KeyValue.push_back("h");
    this->_KeyValue.push_back("j");
    this->_KeyValue.push_back("k");
    this->_KeyValue.push_back("l");

    this->_KeyValue.push_back("Shift");
    this->_KeyValue.push_back("z");
    this->_KeyValue.push_back("x");
    this->_KeyValue.push_back("c");
    this->_KeyValue.push_back("v");
    this->_KeyValue.push_back("b");
    this->_KeyValue.push_back("n");
    this->_KeyValue.push_back("m");
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
