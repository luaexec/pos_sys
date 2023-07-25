#include "queue.h"

NS Queue
{
    void New( Order& order )
    {
        m_vecQueue.push_back( std::make_shared<Order>( order ) );
    }

    std::shared_ptr<Order> Get( int id )
    {
        return m_vecQueue[ id - 1 ];
    }

    std::shared_ptr<Order> LoadNext( )
    {
        auto i = 0;
        for ( auto member : m_vecQueue )
        {
            switch( member->m_cStat )
            {
                case OrderStat::OS_VOID:
                case OrderStat::OS_PAID:
                    break;

                default:
                case OrderStat::OS_UNPAID: {
                    i++;
                } break;
            }
        }

        return Get( i + 1 );
    }
};