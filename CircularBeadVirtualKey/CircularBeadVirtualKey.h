#ifndef CIRCULARBEADVIRTUALKEY_H
#define CIRCULARBEADVIRTUALKEY_H

#include "AbstractVirtualKey/AbstractVirtualKey.h"

class CircularBeadVirtualKey : public AbstractVirtualKey
{
public:
    CircularBeadVirtualKey();
    //设置按键为按下时的状态（颜色）
    virtual void SetStateUpColor(const QColor& DownColor);
    //设置按键按下时的状态（颜色）
    virtual void SetStateDownColor(const QColor& UpColor);
    //获取活跃的键值
    virtual QString GetActiveKey()const;
    //设置键值
    virtual void SetVirtualKeyValue(const QString& Text);
    //设置字体
    virtual void SetFont(const QFont& Font);
private:
    //重写绘制事件
   virtual void paintEvent(QPaintEvent* Ev);
    //重写鼠标按下事件
   virtual void mousePressEvent(QMouseEvent* Ev);
    //重写鼠标释放事件
   virtual void mouseReleaseEvent(QMouseEvent* Ev);

};

#endif // CIRCULARBEADVIRTUALKEY_H
