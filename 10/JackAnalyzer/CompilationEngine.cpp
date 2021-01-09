//
// Created by eilon on 06/01/2021.
//

#include "CompilationEngine.h"

CompilationEngine::CompilationEngine(ifstream &input, ofstream &output) :
    input(input), output(output)
{
    JackTokenizer tokenizer(input);
    if (tokenizer.hasMoreTokens())
        CompileClass();
}

void CompilationEngine::CompileClass()
{
    if
}

void CompilationEngine::CompileClassVarDec()
{

}

void CompilationEngine::CompileSubroutineDec()
{

}

void CompilationEngine::CompileParameterList()
{

}

void CompilationEngine::CompileSubroutineBody()
{

}

void CompilationEngine::CompileVarDec()
{

}

void CompilationEngine::CompileStatements()
{

}

void CompilationEngine::CompileLet()
{

}

void CompilationEngine::CompileIf()
{

}

void CompilationEngine::CompileWhile()
{

}

void CompilationEngine::CompileDo()
{

}

void CompilationEngine::CompileReturn()
{

}

void CompilationEngine::OutputStartXmlComm(CompilationEngine::xml_var_type &xmlVarType)
{

}

void CompilationEngine::OutputEndXmlComm(CompilationEngine::xml_var_type &xmlVarType)
{

}
