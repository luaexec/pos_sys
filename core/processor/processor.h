#ifndef POS_PROCESSOR_H
#define POS_PROCESSOR_H

#include "../includes.h"

NS Processor {
    enum PaymentStat : int {
        PS_AWAIT = 0,
        PS_DECLINE,
        PS_SUCCESS
    };

    enum PaymentMethod : int {
        PM_CASH = 0,
        PM_EFT
    };

    struct PaymentInput {
        PaymentMethod m_cMethod;
        float m_flDue, m_flTendered;
    };

    struct PaymentOutput {
        PaymentStat m_cStat;
        float m_flChange;
    };

    PaymentOutput Complete( PaymentInput input );
    PaymentInput PromptInput( );
};

#endif //POS_PROCESSOR_H
