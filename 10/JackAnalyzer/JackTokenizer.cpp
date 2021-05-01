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

void JackTokenizer::advance()
{
    if (!hasMoreTokens())
    {
        return;
    }
    // skip over spaces in beginning
    while (input_file.peek() == ' ')
    {
        input_file.get();
    }
    string token_accumulator;
    string accumulator_peek;
    accumulator_peek += std::string(1,input_file.peek());
    // stop reading if current is token and including next character it is not token
    while (!isSameToken(token_accumulator,accumulator_peek) &&
            (!isToken(token_accumulator) || isToken(accumulator_peek)
    || accumulator_peek == "//" || accumulator_peek == "/*"))
    {
        token_accumulator += std::string(1,input_file.get());
        accumulator_peek += std::string(1,input_file.peek());
        if (token_accumulator == "//")
        {
            string temp;
            getline(input_file,temp);
            token_accumulator.clear();
            accumulator_peek = std::string(1,input_file.peek());
        }
        if (token_accumulator == "\t" || token_accumulator == "\n" || token_accumulator == "\v"
        || token_accumulator == "\f" || token_accumulator == "\r")
        {
            token_accumulator.clear();
            accumulator_peek = std::string(1,input_file.peek());
        }
        if (token_accumulator == "/**")
        {
            string temp;
            getline(input_file,temp);
            while (temp.find("*/") == string::npos)
            {
                getline(input_file,temp);
            }
            token_accumulator.clear();
            accumulator_peek = std::string(1,input_file.peek());
        }
    }
    last_token = Utils::trim(token_accumulator);
    determineTokenType(last_token);
    handleStringConstant();
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

token JackTokenizer::nextToken()
{
    token last_token_copy = last_token;
    xmlVarType last_token_type_copy = last_token_type;
    advance();
    // retreat backwards
    for (int i = 0; i < last_token.length(); i++)
    {
        input_file.unget();
    }
    last_token_type = last_token_type_copy;
    last_token_copy.swap(last_token);
    return last_token_copy;
}

bool JackTokenizer::isToken(const string& s)
{
    string temp = Utils::trim(s);
    if (isKeyword(temp) || isSymbol(temp) || isIntegerConstant(temp) || isStringConstant(temp) || isIdentifier(temp))
    {
        return true;
    }
    return false;
}

bool JackTokenizer::isTokenBiOp(const token& t)
{
   if (symbolsMatcher.contains(t))
   {
       return true;
   }
   return false;
}

bool JackTokenizer::isTokenUnOp(const token& t)
{
    if (symbolsMatcher.contains(t))
    {
        return true;
    }
    return false;
}



bool JackTokenizer::isKeyword(const string& s)
{
    if (keyWordsMatcher.contains(s))
    {
        return true;
    }
    return false;
}

bool JackTokenizer::isSymbol(const string& s) {
    if (symbolsMatcher.contains(s))
    {
        return true;
    }
    return false;
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
    if (isdigit(s[0]) || s.empty())
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

// token type can be one of the following:
// keyword, symbol, integerConstant, stringConstant, Identifier.
void JackTokenizer::determineTokenType(const token& t)
{
    if (isKeyword(t))
    {
        last_token_type = Utils::Keyword;
    }
    else if (isSymbol(t))
    {
        last_token_type = Utils::Symbol;
    }
    else if (isIntegerConstant(t))
    {
        last_token_type = Utils::IntegerConstant;
    }
    else if (isStringConstant(t))
    {
        last_token_type = Utils::StringConstant;
    }
    else if (isIdentifier(t))
    {
        last_token_type = Utils::Identifier;
    }
}

void JackTokenizer::handleStringConstant()
{
    // if its a string constant, then the original is "String Constant", but it needs to be without ""
    if (last_token_type == Utils::StringConstant)
    {
        last_token = last_token.substr(1, last_token.length() - 2);
    }
}

bool JackTokenizer::isSameToken(const token& t1, const token& t2)
{
    string temp1 = Utils::trim(t1);
    string temp2 = Utils::trim(t2);
    return isToken(t1) && isToken(t2) && temp1 == temp2;
}

