#ifndef CHARACTERENGLISH_H
#define CHARACTERENGLISH_H

#include <QHBoxLayout>
#include <QGridLayout>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QListView>
#include "AbstractVirtualKeyboard/AbstractVirtualKeyboard.h"
#include "AbstractVirtualKey/AbstractVirtualKey.h"
#include "FactoryVirtualKey/FactoryVirtualKey.h"

class CharacterEnglish : public AbstractVirtualKeyboard
{
public:
    CharacterEnglish();


    //活跃键——返回按下的键的键值
    virtual QString ActiveVirtualKey()const;
    //显示键盘
    virtual void VirtualKeyboardShow();
    //隐藏键盘
    virtual void VirtualKeyboardHide();
    //关闭键盘
    virtual void VirtualKeyboardClose();
    //设置按键为按下时的状态（颜色）
    virtual void SetStateUpColor(const QColor& UpColor);
    //设置按键按下时的状态（颜色）
    virtual void SetStateDownColor(const QColor& UpColor);

private:
    //键值初始化、按键的布局
    void Initialize();
private:
    //保存所有的虚拟按键
    QVector<AbstractVirtualKey*> _VK;
    //保存按键的所有键值
    QVector<QString> _KeyValue;

};

#endif // CHARACTERENGLISH_H
