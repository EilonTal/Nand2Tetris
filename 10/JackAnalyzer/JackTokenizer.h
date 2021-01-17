//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_JACKTOKENIZER_H
#define JACKANALYZER_JACKTOKENIZER_H
#include "Utils.h"
#include <fstream>
#include <map>
using namespace std;
using token = string;
using xmlVarType = Utils::xml_var_type;

/**
 * JackTokenizer class: used by CompilationEngine
 * its purpose is to:-
 * 1. check if there's another token
 * 2. advance to the next token
 * 3. return last token advanced to and its type
 */
class JackTokenizer
{
    token last_token;
    token last_token_type;
    ifstream & input_file;
    enum keyWords
    {
        Class, Constructor, Function, Method, Field, Static,
        Var, Int, Char, Boolean, Void, True, False, Null, This,
        Let, Do, If, Else, While, Return
    };
    enum Symbols
    {
        OpenCurly, CloseCurly, OpenBrackets, CloseBrackets, OpenSquare, CloseSquare,
        Dot, Comma, SemiColon, Plus, Minus, Multiplication, Division, And, Or,
        SmallerThan, BiggerThan, Equals, Inverse
    };
    map <string, keyWords> keyWordsMatcher;
    map <string, Symbols> symbolsMatcher;
    bool isToken(string s);
    bool isKeyword(string s);
    bool isSymbol(string s);
    bool isIntegerConstant(string s);
    bool isStringConstant(string s);
    bool isIdentifier(string s);

public:
    JackTokenizer(ifstream& input_file);

    /**
     * advances to the next token
     * writes it to "last token" member
     */
    void advance();

    // returns true if there are any more tokens in file and false otherwise
    bool hasMoreTokens();

    // returns last token
    token getToken();

    // returns next token without advancing
    token nextToken();

    // return true if token is a binary operation and false otherwise
    bool isTokenBiOp(token t);

    // return true if token is an unary operation and false otherwise
    bool isTokenUnOp(token t);

    // returns last token type
    xmlVarType tokenType();

};


#endif //JACKANALYZER_JACKTOKENIZER_H
