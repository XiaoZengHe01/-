#ifndef ABSTRACTVIRTUALKEYBOARD_H
#define ABSTRACTVIRTUALKEYBOARD_H

#include <QString>
#include <QColor>
#include <QDialog>
#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>
#include <QObject>


//这是一个抽象的虚拟键盘（虚基类），它的子类有：
//  1.LetterCapital——大写的英文字母
//  2.LetterLowercase——小写的英文字母
//  3.CharacterEn——英文字符
//  4.CharacterCH——中文字符
//  5.Arabicnumerals——阿拉伯数字

class AbstractVirtualKeyboard:public QObject
{
 Q_OBJECT
public:
    AbstractVirtualKeyboard();
    virtual ~AbstractVirtualKeyboard();
    //活跃键——返回按下的键的键值
    virtual QString ActiveVirtualKey()const=0;
    //显示键盘
    virtual void VirtualKeyboardShow()=0;
    //隐藏键盘
    virtual void VirtualKeyboardHide()=0;
    //关闭键盘
    virtual void VirtualKeyboardClose()=0;
    //设置按键为按下时的状态（颜色）
    virtual void SetStateUpColor(const QColor& UpColor)=0;
    //设置按键按下时的状态（颜色）
    virtual void SetStateDownColor(const QColor& UpColor)=0;
    void SetParent(QWidget* Parent=nullptr);
    QDialog* ReturnVBThis();
signals:
      //按键按下后的信号
    void ActiveKey();


protected:
    //虚拟盘——所有的虚拟按键将在这里显示
    QDialog _VirtuakBoard;
    QString _Text;
};

#endif // ABSTRACTVIRTUALKEYBOARD_H
