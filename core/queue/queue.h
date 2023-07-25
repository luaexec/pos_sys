#ifndef POS_QUEUE_H
#define POS_QUEUE_H

#include "../includes.h"

NS Queue {
    IL std::vector< std::shared_ptr< Order > > m_vecQueue;

    void New( Order& order );

    std::shared_ptr<Order> Get( int id );
    std::shared_ptr<Order> LoadNext( );
};

#endif //POS_QUEUE_H
