#include "core/system/system.h"

int main( )
{
    while ( true )
    {
        if ( System::m_cAction == CurrentCommand::CC_NONE )
        {
            std::string in;
            WRITE( in, "Please select an action to continue:" );
            if ( in == "exit" or in == "0" )
                break;

            System::m_cAction = CurrentCommand( atoi( in.c_str( ) ) );
        } else
            System::Loop( );
    }
}
