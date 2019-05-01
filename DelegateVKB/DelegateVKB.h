#ifndef DELEGATEVKB_H
#define DELEGATEVKB_H


#include <QMap>
#include <QVector>
#include <QString>

#include "FactoryVirtualKeyboard/FactoryVirtualKeyboard.h"
#include "AbstractVirtualKeyboard/AbstractVirtualKeyboard.h"


//虚拟键盘的代理
class DelegateVKB:public QObject
{
    Q_OBJECT
public:
    DelegateVKB();
    //启动键盘
    void Start(FactoryVirtualKeyboard::VKType VK=FactoryVirtualKeyboard::LETTERLOWER);

private:
    //根据枚举变量来切换键盘
    void ChangeVTK(FactoryVirtualKeyboard::VKType OldVTK,
                   FactoryVirtualKeyboard::VKType NewVTK);
signals:
    //这个信号携带一个参数，这个参数就是被按下的那个键值
    void HasActiveKey(QString ActiveKey);
private:
    //保存每一块键盘对象的地址
    QVector<AbstractVirtualKeyboard* >_Keyboards;
    //保存每一个键盘对象，并且用枚举值关联起来
    QMap<FactoryVirtualKeyboard::VKType,AbstractVirtualKeyboard*>_MapVKB;
    //如果当前为大写字母键盘，_NowVTK==false
    bool _NowVTK;
};

#endif // DELEGATEVKB_H
