#ifndef ABSTRACTVIRTUALKEY_H
#define ABSTRACTVIRTUALKEY_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QString>
#include <QFont>

class AbstractVirtualKey : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractVirtualKey(QWidget *parent = nullptr);
    virtual ~AbstractVirtualKey()=0;
    //设置按键为按下时的状态（颜色）
    virtual void SetStateUpColor(const QColor& DownColor)=0;
    //设置按键按下时的状态（颜色）
    virtual void SetStateDownColor(const QColor& UpColor)=0;
    //获取活跃的键值
    virtual QString GetActiveKey()const=0;
    //设置键值
    virtual void SetVirtualKeyValue(const QString& Text)=0;
    //设置字体
    virtual void SetFont(const QFont& Font)=0;

protected:
    //重写绘制事件
   virtual void paintEvent(QPaintEvent* Ev)=0;
    //重写鼠标按下事件
   virtual void mousePressEvent(QMouseEvent* Ev)=0;
    //重写鼠标释放事件
   virtual void mouseReleaseEvent(QMouseEvent* Ev)=0;

protected:
        //按键的文本
       QString _Text;
       //按键是否被按下
       bool _IsClick;
       //按键为按下的颜色
       QColor _Up;
       //按键已按下的颜色
       QColor _Down;
       //按键文本的字体
       QFont _Font;
signals:
      //按键按下后的信号
    void Clicked();
public slots:
};

#endif // ABSTRACTVIRTUALKEY_H
