//
// Created by eilon on 13/01/2021.
//

#ifndef JACKANALYZER_EXCEPTIONS_H
#define JACKANALYZER_EXCEPTIONS_H

using namespace std;

class Exceptions
{
public:
    virtual string getException() = 0;
};

class wrongTokenException: public Exceptions
{
    string getException()
    {
        return "wrongTokenException";
    }
};

class wrongTokenTypeException: public Exceptions
{
    string getException()
    {
        return "wrongTokenTypeException";
    }
};

class noTokensLeft: public Exceptions
{
    string getException()
    {
        return "noTokensLeft";
    }
};

#endif //JACKANALYZER_EXCEPTIONS_H
