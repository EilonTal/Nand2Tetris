//
// Created by eilon on 06/01/2021.
//

#ifndef JACKANALYZER_COMPILATIONENGINE_H
#define JACKANALYZER_COMPILATIONENGINE_H

#include <fstream>
#include "JackTokenizer.h"

class CompilationEngine
{
    ofstream & output;
    JackTokenizer tokenizer;
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
    void compileExpression();
    void compileTerm();
    void compileExpressionList();
};


#endif //JACKANALYZER_COMPILATIONENGINE_H
