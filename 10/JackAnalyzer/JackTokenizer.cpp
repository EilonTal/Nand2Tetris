#include "JackTokenizer.h"

void JackTokenizer::advance()
{
    if (!hasMoreTokens())
    {
        throw noTokensLeft();
    }

}
