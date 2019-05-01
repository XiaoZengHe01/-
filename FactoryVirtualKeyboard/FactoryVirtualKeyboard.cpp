#include "FactoryVirtualKeyboard.h"

FactoryVirtualKeyboard::FactoryVirtualKeyboard()
{

}


 //这是一个静态方法，该方法通过枚举常量来创建对应的键盘
AbstractVirtualKeyboard* FactoryVirtualKeyboard::CreateVirtualKeyboard(const VKType& VKT)
{

    switch (VKT)
    {
        //数字键盘
    case ARABICNUMERALS:
        return new ArabicNumerals;
        //英文字符
    case CHARACTERENGLISH:
        return new CharacterEnglish;
        //中文字符
    case CHARACTERCHINESE:
        return new CharacterChinese;
        //小写字母
    case LETTERLOWER:
        return new LetterLower;
        //大写字母
    case LETTERCAPITAL:
        return new LetterCapital;
    }
    return nullptr;
}
