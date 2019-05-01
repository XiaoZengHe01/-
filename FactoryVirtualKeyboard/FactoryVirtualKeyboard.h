#ifndef FACTORYVIRTUALKEYBOARD_H
#define FACTORYVIRTUALKEYBOARD_H


#include "AbstractVirtualKeyboard/AbstractVirtualKeyboard.h"
#include "LetterCapital/LetterCapital.h"
#include "LetterLower/LetterLower.h"
#include "ArabicNumerals/ArabicNumerals.h"
#include "CharacterEnglish/CharacterEnglish.h"
#include "CharacterChinese/CharacterChinese.h"



//这是一个用于创建键盘的简单工厂
class FactoryVirtualKeyboard
{
public:
    FactoryVirtualKeyboard();
    enum VKType
    {
        //数字键盘
        ARABICNUMERALS,
        //英文字符
        CHARACTERENGLISH,
        //中文字符
        CHARACTERCHINESE,
        //小写字母
        LETTERLOWER,
        //大写字母
        LETTERCAPITAL,
    };

    //这是一个静态方法，该方法通过枚举常量来创建对应的键盘
    static AbstractVirtualKeyboard* CreateVirtualKeyboard(const VKType& VKT);
};

#endif // FACTORYVIRTUALKEYBOARD_H
