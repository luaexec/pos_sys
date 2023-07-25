#include "order.h"

void Order::Void( )
{
    this->m_cStat = OrderStat::OS_VOID;
    this->m_vecItems.clear( );
    this->m_flTotal = 0.f;
}

bool Order::Pay( Processor::PaymentInput input )
{
    auto result = Processor::Complete( input );
    switch( result.m_cStat )
    {
        case Processor::PaymentStat::PS_SUCCESS: {
            return true;
        } break;

        case Processor::PaymentStat::PS_AWAIT: {
            Processor::PaymentInput nInput{ Processor::PromptInput( ) };
            nInput.m_flDue = result.m_flChange;

            return Pay( nInput );
        } break;

        case Processor::PaymentStat::PS_DECLINE: {
            return false;
        } break;

        default:
            break;
    }

    return false;
}