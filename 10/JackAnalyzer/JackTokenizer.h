//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_JACKTOKENIZER_H
#define JACKANALYZER_JACKTOKENIZER_H
#include "Utils.h"
#include <fstream>
#include <map>
#include <string>
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

    token last_token;
    xmlVarType last_token_type;
    ifstream & input_file;
    map <string, keyWords> keyWordsMatcher;
    map <string, Symbols> symbolsMatcher;
    bool isToken(const string& s);
    bool isKeyword(const string& s);
    bool isSymbol(const string& s);
    static bool isIntegerConstant(const string& s);
    static bool isStringConstant(string s);
    static bool isIdentifier(const string& s);
    void determineTokenType(const token& t);
    void handleStringConstant();
    bool isSameToken(const token& t1, const token& t2);
    static int i;
public:
    explicit JackTokenizer(ifstream& input_file);

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
    bool isTokenBiOp(const token& t);

    // return true if token is an unary operation and false otherwise
    bool isTokenUnOp(const token& t);

    // returns last token type
    xmlVarType tokenType();

};

#endif //JACKANALYZER_JACKTOKENIZER_H
