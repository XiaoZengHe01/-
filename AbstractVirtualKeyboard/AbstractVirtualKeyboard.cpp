#include "AbstractVirtualKeyboard.h"

AbstractVirtualKeyboard::AbstractVirtualKeyboard()
{
    QDesktopWidget *p=QApplication::desktop();
    this->_VirtuakBoard.resize(p->width(),240);
    this->_VirtuakBoard.setPalette(QPalette(Qt::Drawer));
    this->_VirtuakBoard.setFocusPolicy(Qt::NoFocus);
}

AbstractVirtualKeyboard::~AbstractVirtualKeyboard()
{

}
void AbstractVirtualKeyboard::SetParent(QWidget* Parent)
{
    if(nullptr!=Parent)
    {
        this->_VirtuakBoard.setParent(Parent);
    }
}

QDialog* AbstractVirtualKeyboard::ReturnVBThis()
{
    return &this->_VirtuakBoard;
}
