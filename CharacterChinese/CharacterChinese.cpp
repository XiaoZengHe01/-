#include "CharacterChinese.h"

CharacterChinese::CharacterChinese()
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
 QString CharacterChinese::ActiveVirtualKey()const
 {
     return this->_Text;
 }

//显示键盘
 void CharacterChinese::VirtualKeyboardShow()
 {
    this->_VirtuakBoard.show();
 }

//隐藏键盘
 void CharacterChinese::VirtualKeyboardHide()
 {
    this->_VirtuakBoard.hide();
 }

//关闭键盘
 void CharacterChinese::VirtualKeyboardClose()
 {
    this->_VirtuakBoard.close();
 }

//设置按键为按下时的状态（颜色）
 void CharacterChinese::SetStateUpColor(const QColor& UpColor)
 {
    for(auto i:this->_VK)
    {
        i->SetStateUpColor(UpColor);
    }
 }

//设置按键按下时的状态（颜色）
 void CharacterChinese::SetStateDownColor(const QColor& UpColor)
 {
     for(auto i:this->_VK)
     {
         i->SetStateDownColor(UpColor);
     }
 }
//键值初始化、按键的布局
void CharacterChinese::Initialize()
{

    //添加所需要的键值
    this->_KeyValue.push_back("。");
    this->_KeyValue.push_back("？");
    this->_KeyValue.push_back("：");
    this->_KeyValue.push_back("、");
    this->_KeyValue.push_back("“”");

    this->_KeyValue.push_back("；");
    this->_KeyValue.push_back("（）");
    this->_KeyValue.push_back("《》");
    this->_KeyValue.push_back("～");
    this->_KeyValue.push_back("‘’");

    this->_KeyValue.push_back("〈〉");
    this->_KeyValue.push_back("——");
    this->_KeyValue.push_back("·");
    this->_KeyValue.push_back("ˉ");
    this->_KeyValue.push_back("ˇ");

    this->_KeyValue.push_back("¨");
    this->_KeyValue.push_back("《》");
    this->_KeyValue.push_back("々");
    this->_KeyValue.push_back("‖");
    this->_KeyValue.push_back("∶");

    this->_KeyValue.push_back("＂");
    this->_KeyValue.push_back("＇");
    this->_KeyValue.push_back("｀");
    this->_KeyValue.push_back("｜");
    this->_KeyValue.push_back("〔〕");

    this->_KeyValue.push_back("「」");
    this->_KeyValue.push_back("．");
    this->_KeyValue.push_back("〖〗");
    this->_KeyValue.push_back("【】");
    this->_KeyValue.push_back("［］");

    this->_KeyValue.push_back("｛｝");
    this->_KeyValue.push_back("，");
    this->_KeyValue.push_back("Back");
    this->_KeyValue.push_back("");
    this->_KeyValue.push_back("");


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



        QHBoxLayout* HL5(new QHBoxLayout);
        for(i=0;i<5;i++)
        {
            _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
           this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+20));
           HL5->addWidget(_VK.back(),1);

        }

        GL->addLayout(HL5,4,0,1,1);

        QHBoxLayout* HL6(new QHBoxLayout);
        for(i=0;i<5;i++)
        {
            _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
           this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+25));
           HL6->addWidget(_VK.back(),1);

        }

        GL->addLayout(HL6,5,0,1,1);




        QHBoxLayout* HL7(new QHBoxLayout);
        for(i=0;i<5;i++)
        {
            _VK.push_back(FactoryVirtualKey::CreateVirtualKey(FactoryVirtualKey::RECTVIRTUALKEY));
           this->_VK.back()->SetVirtualKeyValue(this->_KeyValue.at(i+30));
           HL7->addWidget(_VK.back(),1);

        }

        GL->addLayout(HL7,6,0,1,1);

        this->_VirtuakBoard.setLayout(GL);
}
