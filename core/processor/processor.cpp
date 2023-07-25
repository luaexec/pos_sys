#include "processor.h"

NS Processor
{
    PaymentOutput Complete( PaymentInput input )
    {
        PaymentOutput out{ };
        switch( input.m_cMethod )
        {
            case PaymentMethod::PM_CASH: {
                out.m_cStat = ( input.m_flDue > input.m_flTendered ) ? PS_AWAIT : PS_SUCCESS;
                out.m_flChange = std::abs( input.m_flDue - input.m_flTendered );
            } break;

            case PaymentMethod::PM_EFT: {
                out.m_cStat = ( input.m_flTendered && input.m_flDue > input.m_flTendered ) ? PS_AWAIT : PS_SUCCESS;
                out.m_flChange = std::abs( input.m_flDue - input.m_flTendered );
            } break;

            default:
                break;
        }

        return out;
    }

    PaymentInput PromptInput( )
    {
        PaymentInput output{ };
        WRITE( output.m_cMethod, "Select your preferred form of payment method: " );
        WRITE( output.m_flTendered, "Enter the amount you wish to pay (-1 = all): " );

        return output;
    }
};