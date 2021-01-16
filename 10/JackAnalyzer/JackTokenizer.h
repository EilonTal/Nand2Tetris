//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_JACKTOKENIZER_H
#define JACKANALYZER_JACKTOKENIZER_H
#include "Exceptions.h"
#include "Utils.h"
#include <iostream>
using namespace std;
using token = string;
using xmlVarType = Utils::xml_var_type;

/**
 * JackTokenizer class: used by CompilationEngine
 * its purpose is to:-
 * 1. check if there's another token
 * 2. advance to the next token
 * 3. return last token advanced to
 */
class JackTokenizer
{
    token last_token;
    ifstream & input_file;
public:


    JackTokenizer(ifstream& input_file);
    JackTokenizer(JackTokenizer& tokenizer) = default;
    JackTokenizer& operator=(JackTokenizer& tokenizer) = default;

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

    // returns last token type
    xmlVarType tokenType();

    // returns next token type without advancing
    xmlVarType nextTokenType();
};


#endif //JACKANALYZER_JACKTOKENIZER_H
