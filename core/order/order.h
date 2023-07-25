#ifndef POS_ORDER_H
#define POS_ORDER_H

#include "../processor/processor.h"

struct Item {
    int m_iID, m_iQuantity;
    float m_flPrice;

    FIL auto Total( ) { return m_flPrice * m_iQuantity; }
};

enum OrderStat : int {
    OS_UNPAID = 0,
    OS_PAID,
    OS_VOID
};

class Order {
public:
    std::vector<Item> m_vecItems;
    OrderStat m_cStat;

    float m_flTotal;
    auto CalculateTotal( )
    {
        for ( auto& i : m_vecItems )
            m_flTotal += i.Total( );

        return m_flTotal;
    }

    void Void( );
    bool Pay( Processor::PaymentInput input );
};

#endif //POS_ORDER_H
