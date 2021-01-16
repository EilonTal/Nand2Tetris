//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_COMPILATIONENGINE_H
#define JACKANALYZER_COMPILATIONENGINE_H

#include <fstream>
#include "JackTokenizer.h"

class CompilationEngine
{
    ifstream & input;
    ofstream & output;
    JackTokenizer tokenizer;
    token last_token;
    enum xml_var_type{
        Keyword, Symbol, IntegerConstant, StringConstant, Identifier,
        Class, ClassVerDec, SubroutineDec, ParameterList, SubroutineBody,
        VarDec, LetStatement, IfStatement, WhileStatement, DoStatement,
        ReturnStatement, Expression, Term, ExpressionList, Op,
        UnaryOp, KeywordConstant
    };
    const bool end_line = true;
    void outputStartXmlComm(xmlVarType xml_var_type, bool shouldEndLine = false);
    void outputEndXmlComm(xmlVarType xml_var_type, bool shouldEndLine = false);
    void outputXmlCommAux(xmlVarType xml_var_type);
    void outputOneLiner();
public:
    CompilationEngine(ifstream& input, ofstream & output);
    void compileClass();
    void compileClassVarDec();
    void compileSubroutineDec();
    void compileParameterList();
    void compileSubroutineBody();
    void compileVarDec();
    void compileStatements();
    void compileLet();
    void compileIf();
    void compileWhile();
    void compileDo();
    void compileReturn();
    friend void initTokenizer(ifstream &input);
};


#endif //JACKANALYZER_COMPILATIONENGINE_H
