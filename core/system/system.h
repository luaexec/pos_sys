#ifndef POS_SYSTEM_H
#define POS_SYSTEM_H

#include "../order/order.h"

enum CurrentCommand : int {
    CC_NONE = 0,
    CC_SELECT,
    CC_LOAD,
    CC_PAY,
    CC_NEW,
    CC_VOID
};

NS System {
    std::shared_ptr<Order> m_cOrder;
    CurrentCommand m_cAction;

    void Loop( );
};

#endif //POS_SYSTEM_H
