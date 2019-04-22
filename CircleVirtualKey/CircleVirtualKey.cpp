#include "CircleVirtualKey.h"

CircleVirtualKey::CircleVirtualKey()
{
    //设置默认大小
    this->resize(160,160);
    //设置默认状态
    this->_IsClick=false;
    //设置默认文本
    this->_Text="";
    //设置默认的未按下的状态
    this->_Up=QColor(255,255,255);
     //设置默认的按下的状态
    this->_Down=QColor(150,150,150);
    //设置默认的字体属性
    this->_Font=QFont("Microsoft YaHei",12);
}


//设置按键为按下时的状态（颜色）
 void CircleVirtualKey::SetStateUpColor(const QColor& DownColor)
 {
    this->_Down=DownColor;
 }
//设置按键按下时的状态（颜色）
 void CircleVirtualKey::SetStateDownColor(const QColor& UpColor)
 {
    this->_Up=UpColor;
 }

//重写绘制事件
void CircleVirtualKey::paintEvent(QPaintEvent* Ev)
{
    QPainter p(this);

    if(this->_IsClick)
    {
        p.setBrush(QBrush(this->_Down));
        p.setPen(this->_Up);
    }
    else
    {
        p.setBrush(QBrush(this->_Up));
        p.setPen(this->_Down);
    }

    p.setFont(this->_Font);
    p.drawEllipse(this->rect());
    p.drawText(this->rect(),this->_Text,QTextOption(Qt::AlignCenter));

}

//重写鼠标按下事件
void CircleVirtualKey::mousePressEvent(QMouseEvent* Ev)
{
    this->_IsClick=true;
    this->update();

}

//重写鼠标释放事件
void CircleVirtualKey::mouseReleaseEvent(QMouseEvent* Ev)
{
    this->_IsClick=false;
    this->update();
    //在此范围内释放鼠标才会发射信号
    if(this->rect().contains(Ev->pos()))
    {
        emit this->Clicked();
    }

}


//获取活跃的键值
QString CircleVirtualKey::GetActiveKey()const
{
    return  this->_Text;
}
//设置键值
 void CircleVirtualKey::SetVirtualKeyValue(const QString& Text)
 {
    this->_Text=Text;
 }

 //设置字体
  void CircleVirtualKey::SetFont(const QFont& Font)
 {
    this->_Font=Font;
 }
