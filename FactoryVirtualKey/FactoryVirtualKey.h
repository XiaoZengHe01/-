#ifndef FACTORYVIRTUALKEY_H
#define FACTORYVIRTUALKEY_H

#include "RectVirtualKey/RectVirtualKey.h"
#include "CircleVirtualKey/CircleVirtualKey.h"
#include "CircularBeadVirtualKey/CircularBeadVirtualKey.h"

class FactoryVirtualKey
{
public:
    enum VIRTUALKEYTYPE
    {
        CIRCLEVIRTUALKEY,
        CIRCULARBEADVIRTUALKEY,
        RECTVIRTUALKEY
    };
    FactoryVirtualKey();
    //这个静态方法用来生产按键
    static AbstractVirtualKey* CreateVirtualKey(const VIRTUALKEYTYPE& VKType);
};

#endif // FACTORYVIRTUALKEY_H
