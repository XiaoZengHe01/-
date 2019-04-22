#include "FactoryVirtualKey.h"

FactoryVirtualKey::FactoryVirtualKey()
{

}

/*********************************************************************
 *如果新增加一种类型的按钮，那么就要在"CreateVirtualKey"的基础上修改源代
 * 码，正因如此简单工厂模式不符合开闭原则；
 *********************************************************************/
AbstractVirtualKey* FactoryVirtualKey::CreateVirtualKey(const VIRTUALKEYTYPE& VKType)
{
    //工厂在这里根据枚举值来生产不同类型的按键；
    switch (VKType)
    {
     case CIRCLEVIRTUALKEY:
        return  new CircleVirtualKey;
     case CIRCULARBEADVIRTUALKEY:
        return  new CircularBeadVirtualKey;
     case RECTVIRTUALKEY:
        return  new RectVirtualKey;
    }
   return  nullptr;
}
