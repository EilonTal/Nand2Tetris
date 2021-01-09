//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_COMPILATIONENGINE_H
#define JACKANALYZER_COMPILATIONENGINE_H

#include <fstream>
#include "JackTokenizer.h"
using namespace std;

class CompilationEngine
{
    ifstream & input;
    ofstream & output;
    enum xml_var_type{
        Keyword, Symbol, IntegerConstant, StringConstant, Identifier,
        Class, ClassVerDec, Type, SubroutineDec, ParameterList,
        SubroutineBody, VarDec, ClassName, SubroutineName, VarName,
        Statement, LetStatement, IfStatement, WhileStatement, DoStatement,
        ReturnStatement, Expression, Term, SubroutineCall, ExpressionList,
        Op, UnaryOp, KeywordConstant
    };
    void OutputStartXmlComm(enum xml_var_type& xmlVarType);
    void OutputEndXmlComm(enum xml_var_type& xmlVarType);
public:
    CompilationEngine(ifstream& input, ofstream & output);
    void CompileClass();
    void CompileClassVarDec();
    void CompileSubroutineDec();
    void CompileParameterList();
    void CompileSubroutineBody();
    void CompileVarDec();
    void CompileStatements();
    void CompileLet();
    void CompileIf();
    void CompileWhile();
    void CompileDo();
    void CompileReturn();
};


#endif //JACKANALYZER_COMPILATIONENGINE_H
