#include "JackTokenizer.h"


JackTokenizer::JackTokenizer(ifstream &input_file)
        : input_file(input_file), last_token()
{
    keyWordsMatcher = {
        {"class",Class}, {"constructor",Constructor}, {"function",Function}, {"method",Method},
        {"field",Field}, {"static",Static}, {"var",Var}, {"int",Int},
        {"char",Char}, {"boolean",Boolean}, {"void",Void}, {"true",True},
        {"false",False}, {"null",Null}, {"this",This}, {"let",Let},
        {"do",Do}, {"if",If}, {"else",Else}, {"while",While}, {"return",Return}
    };
    symbolsMatcher = {
        {"{",OpenCurly}, {"}",CloseCurly}, {"(",OpenBrackets},
        {")",CloseBrackets}, {"[",OpenSquare}, {"]",CloseSquare},
        {".",Dot}, {",",Comma},{";",SemiColon}, {"+",Plus},
        {"-",Minus}, {"*",Multiplication},{"/",Division},
        {"&",And}, {"|",Or}, {"<",SmallerThan},{">",BiggerThan},
        {"=",Equals}, {"~",Inverse}
    };
}

// todo
void JackTokenizer::advance()
{
    if (!hasMoreTokens())
    {
        return;
    }
    string token_accumulator;
    string accumulator_peek;
    accumulator_peek += std::to_string(input_file.peek());
    // keep reading if no token was found yet OR next char appended to accumulator is also token
    while (!isToken(token_accumulator) || isToken(accumulator_peek))
    {
        token_accumulator += std::to_string(input_file.get());
        accumulator_peek += std::to_string(input_file.peek());
    }
    last_token = token_accumulator;

    // deal with token type
}

bool JackTokenizer::hasMoreTokens()
{
    if (input_file.peek() == EOF)
    {
        return false;
    }
    return true;
}

token JackTokenizer::getToken()
{
    return last_token;
}

// todo
token JackTokenizer::nextToken()
{
    return token();
}

bool JackTokenizer::isToken(const string& s)
{
    if (isKeyword(s) || isSymbol(s) || isIntegerConstant(s) || isStringConstant(s) || isIdentifier(s))
    {
        return true;
    }
    return false;
}

bool JackTokenizer::isTokenBiOp(const token& t)
{
    switch (symbolsMatcher[t])
    {
        case Plus:
        case Minus:
        case Multiplication:
        case Division:
        case And:
        case Or:
        case SmallerThan:
        case BiggerThan:
        case Equals:
            return true;
        default:
            return false;
    }
}

bool JackTokenizer::isTokenUnOp(const token& t)
{
    switch (symbolsMatcher[t])
    {
        case Inverse:
        case Minus:
            return true;
        default:
            return false;
    }
}



bool JackTokenizer::isKeyword(const string& s)
{
    switch (keyWordsMatcher[s])
    {
        case Class:
        case Constructor:
        case Function:
        case Method:
        case Field:
        case Static:
        case Var:
        case Int:
        case Char:
        case Boolean:
        case Void:
        case True:
        case False:
        case Null:
        case This:
        case Let:
        case Do:
        case If:
        case Else:
        case While:
        case Return:
            return true;
        default:
            return false;
    }
}

bool JackTokenizer::isSymbol(const string& s)
{
    switch (symbolsMatcher[s])
    {
        case OpenCurly:
        case CloseCurly:
        case OpenBrackets:
        case CloseBrackets:
        case OpenSquare:
        case CloseSquare:
        case Dot:
        case Comma:
        case SemiColon:
        case Plus:
        case Minus:
        case Multiplication:
        case Division:
        case And:
        case Or:
        case SmallerThan:
        case BiggerThan:
        case Equals:
        case Inverse:
            return true;
        default:
            return false;
    }
}

bool JackTokenizer::isIntegerConstant(const string& s)
{
    try
    {
        int i = stoi(s);
        if (i >= 0 && i <= 32767)
        {
            return true;
        }
    }
    catch (...)
    {
        return false;
    }
    return false;
}

// todo (reminder string constant is output without "")
bool JackTokenizer::isStringConstant(string s)
{
    if (s[0] != '"' || s[s.length() - 1] != '"')
    {
        return false;
    }
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '\n' || s[i] == '"')
        {
            return false;
        }
    }
    return true;
}

bool JackTokenizer::isIdentifier(const string& s)
{
    if (isdigit(s[0]))
    {
        return false;
    }
    for (char i : s)
    {
        if (!isalnum(i) && i != '_')
        {
            return false;
        }
    }
    return true;
}


xmlVarType JackTokenizer::tokenType()
{
    return last_token_type;
}

