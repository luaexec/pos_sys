#include "system.h"
#include "../queue/queue.h"

NS System
{
    void Loop( )
    {
        switch( m_cAction )
        {
            case CurrentCommand::CC_LOAD: {
                m_cOrder = Queue::LoadNext( );
                m_cAction = CurrentCommand::CC_NONE;
            } break;

            case CurrentCommand::CC_NEW: {
                Order order{ };
                do
                {
                    std::string in;
                    WRITE( in, "Please enter the item ID you wish to add: " );
                    if ( in == "exit" ) {
                        if ( order.m_vecItems.empty( ) )
                            m_cAction = CurrentCommand::CC_NONE;
                        else break;
                    }

                    Item item{ };
                    item.m_iID = atoi( in.c_str( ) );
                    item.m_flPrice = 12.50f;

                    WRITE( in, "Please enter the quantity of the selected item: " );
                    if ( !atoi( in.c_str( ) ) )
                        continue;

                    item.m_iQuantity = atoi( in.c_str( ) );

                    Print( "Added! -=~=-=~=-=~=-=~=-=~=-=~=-=~=-=~=-=~=-" );
                } while ( true );

                Queue::New( order );
                m_cAction = CurrentCommand::CC_NONE;
                Print( "Added order to the queue! -=~=-=~=-=~=-=~=-" );
            } break;

            case CurrentCommand::CC_PAY: {
                if ( !m_cOrder.get( ) ) {
                    Print( "No order selected/available!" );
                    m_cAction = CurrentCommand::CC_NONE;
                }

                Processor::PaymentInput nInput{ Processor::PromptInput( ) };
                nInput.m_flDue = m_cOrder->CalculateTotal( );

                if ( m_cOrder->Pay( nInput ) ) {
                    Print( "Payment successful!" );
                    m_cAction = CurrentCommand::CC_NONE;
                }
                else
                    Print( "Payment declined, please try again." );
            } break;

            case CurrentCommand::CC_SELECT: {
                std::string in;
                WRITE( in, "Please enter the order ID you wish to load: ");
                if ( in != "exit" )
                    m_cOrder = Queue::Get( atoi( in.c_str( ) ) );

                m_cAction = CurrentCommand::CC_NONE;
            } break;

            case CurrentCommand::CC_VOID: {
                std::string in;
                WRITE( in, "Please enter the order ID you wish to void or write 'selected' for the current order: ");

                if ( in == "selected" )
                {
                    if ( !m_cOrder.get( ) )
                        Print( "No order selected/available!" );
                    else {
                        m_cOrder->Void( );
                        Print( "Order voided successfully!" );
                    }

                    m_cAction = CurrentCommand::CC_NONE;
                } else if ( in == "exit" )
                {
                    m_cAction = CurrentCommand::CC_NONE;
                    Print( "Exiting.." );
                } else
                {
                    Queue::Get( atoi( in.c_str( ) ) )->Void( );
                    m_cAction = CurrentCommand::CC_NONE;
                }
            } break;

            default:
                break;
            }
    }
};