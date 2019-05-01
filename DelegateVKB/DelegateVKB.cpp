#include "DelegateVKB.h"


DelegateVKB::DelegateVKB()
{

    //默认是小写字母键盘
    this->_NowVTK=true;
    //创建数字键盘对象，并且插入"QMap"容器中
    this->_MapVKB.insert(FactoryVirtualKeyboard::ARABICNUMERALS,
                         FactoryVirtualKeyboard::CreateVirtualKeyboard(FactoryVirtualKeyboard::ARABICNUMERALS));

    //创建中文字符键盘对象，并且插入"QMap"容器中
    this->_MapVKB.insert(FactoryVirtualKeyboard::CHARACTERCHINESE,\
                         FactoryVirtualKeyboard::CreateVirtualKeyboard(FactoryVirtualKeyboard::CHARACTERCHINESE));


    //创建英文字符键盘对象，并且插入"QMap"容器中
    this->_MapVKB.insert(FactoryVirtualKeyboard::CHARACTERENGLISH,
                         FactoryVirtualKeyboard::CreateVirtualKeyboard(FactoryVirtualKeyboard::CHARACTERENGLISH));

    //创建大写字母键盘对象，并且插入"QMap"容器中
    this->_MapVKB.insert(FactoryVirtualKeyboard::LETTERCAPITAL,
                         FactoryVirtualKeyboard::CreateVirtualKeyboard(FactoryVirtualKeyboard::LETTERCAPITAL));
    //创建小写字母键盘对象，并且插入"QMap"容器中
    this->_MapVKB.insert(FactoryVirtualKeyboard::LETTERLOWER,
                         FactoryVirtualKeyboard::CreateVirtualKeyboard(FactoryVirtualKeyboard::LETTERLOWER));

    //遍历容器中的每个对象
    for(auto i:this->_MapVKB)
    {

        //为每个对象的信号关联一个槽，我这里为了偷懒所以用"Lambda"。
        QObject::connect(i,
                         &AbstractVirtualKeyboard::ActiveKey,
                         [=](){

            //“Shift” 按下表示要切换大小写
            if("Shift"==i->ActiveVirtualKey())
            {
                //“this->_NowVTK”判读当前是大写字母键盘还是小写字母键盘
                if(this->_NowVTK)
                {
                    //由小写字母键盘切换到大写字母键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERLOWER,
                              FactoryVirtualKeyboard::LETTERCAPITAL);
                    this->_NowVTK=false;
                }
                else
                {
                    //由大写字母键盘切换到小写字母键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERCAPITAL,
                              FactoryVirtualKeyboard::LETTERLOWER);
                    this->_NowVTK=true;
                }
            }   //“123”按下表示要切换数字键
            else if("123"==i->ActiveVirtualKey())
            {
                //“this->_NowVTK”判读当前是大写字母键盘还是小写字母键盘
                if(this->_NowVTK)
                {
                    //由小写字母键盘切换到数字键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERLOWER,
                              FactoryVirtualKeyboard::ARABICNUMERALS);

                }
                else
                {
                    //由大写字母键盘切换到数字键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERCAPITAL,
                              FactoryVirtualKeyboard::ARABICNUMERALS);
                }

            } //返回上一次的键盘
            else if("Back"==i->ActiveVirtualKey())
            {
                //“this->_NowVTK”判读当前是大写字母键盘还是小写字母键盘
                if(this->_NowVTK)
                {
                    //判读i是否指向数字键盘对象
                    if(i==this->_MapVKB.find(FactoryVirtualKeyboard::ARABICNUMERALS).value())
                    {
                        //由数字键盘对象切换到小写字母键盘
                        ChangeVTK(FactoryVirtualKeyboard::ARABICNUMERALS,
                                  FactoryVirtualKeyboard::LETTERLOWER);
                    }
                    else if(i==this->_MapVKB.find(FactoryVirtualKeyboard::CHARACTERENGLISH).value())
                    {
                        //由大写字母键盘切换到小写字母键盘
                        ChangeVTK(FactoryVirtualKeyboard::CHARACTERENGLISH,
                                  FactoryVirtualKeyboard::LETTERLOWER);
                    }
                }
                else
                {
                    //判断 i 是否指向数字键盘对象
                    if(i==this->_MapVKB.find(FactoryVirtualKeyboard::ARABICNUMERALS).value())
                    {
                        //由数字键盘切换到大写字母键盘
                        ChangeVTK(FactoryVirtualKeyboard::ARABICNUMERALS,
                                  FactoryVirtualKeyboard::LETTERCAPITAL);
                    }
                    else if(i==this->_MapVKB.find(FactoryVirtualKeyboard::CHARACTERENGLISH).value())
                    {
                        //由大写字母键盘切换到小写字母键盘
                        ChangeVTK(FactoryVirtualKeyboard::CHARACTERENGLISH,
                                  FactoryVirtualKeyboard::LETTERCAPITAL);
                    }
                }

            } //“Character” 键按下表示要切换到字符键盘
            else if("Character"==i->ActiveVirtualKey())
            {
                //“this->_NowVTK”判读当前是大写字母键盘还是小写字母键盘
                if(this->_NowVTK)
                {
                    //由小写字母键盘切换到字符键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERLOWER,
                              FactoryVirtualKeyboard::CHARACTERENGLISH);

                }
                else
                {
                    //由小写字母键盘切换到大写字母键盘
                    ChangeVTK(FactoryVirtualKeyboard::LETTERCAPITAL,
                              FactoryVirtualKeyboard::CHARACTERENGLISH);
                }
            }

            //"Space" 按下就发射一个携带" " 的信号
            if("Space"==i->ActiveVirtualKey())
            {
                emit this->HasActiveKey(" ");
            } //"Enter" 按下就发射一个携带"\r" 的信号
            else if(("Enter"==i->ActiveVirtualKey()))
            {
                emit this->HasActiveKey("\r");
            }   //"Backspace" 按下就发射一个携带xxx信号，不晓得写什么=_=|||
            else if(("Backspace"==i->ActiveVirtualKey()))
            {

            }
            else
            {
                //把一些辅助过滤到
                if("Shift"!=i->ActiveVirtualKey()&&
                        "123"!=i->ActiveVirtualKey()&&
                        "Character"!=i->ActiveVirtualKey()&&
                        "Back"!=i->ActiveVirtualKey()&&
                        "Backspace"!=i->ActiveVirtualKey()&&
                        "Enter"!=i->ActiveVirtualKey())
                {
                    //发射一个携带键值的信号
                    emit this->HasActiveKey(i->ActiveVirtualKey());
                }


            }

        });

        this->_Keyboards.append(i);

    }

}

void DelegateVKB::Start(FactoryVirtualKeyboard::VKType VK)
{
    //根据枚举值来启动对应的键盘
    this->_Keyboards.at(VK)->VirtualKeyboardShow();

}

void DelegateVKB::ChangeVTK(FactoryVirtualKeyboard::VKType OldVTK,
                            FactoryVirtualKeyboard::VKType NewVTK)
{
    //隐藏之前的键盘
    this->_Keyboards.at(OldVTK)->VirtualKeyboardHide();
    //显示现在需要的键盘
    this->_Keyboards.at(NewVTK)->VirtualKeyboardShow();
}
