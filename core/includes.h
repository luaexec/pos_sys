#ifndef POS_INCLUDES_H
#define POS_INCLUDES_H

// macros.
#define NS namespace
#define IL inline
#define FIL __forceinline

// windows includes.
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

// essentials.
IL void Print( const std::string& input )
{
    std::cout << input.c_str( ) << std::endl;
}

#define WRITE( Var, Text )                 \
{                                          \
  Print( Text );                           \
  std::cin >> Var;                         \
}

#endif //POS_INCLUDES_H