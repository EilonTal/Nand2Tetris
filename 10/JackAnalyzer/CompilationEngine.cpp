//
// Created by eilon on 06/01/2021.
//

#include "CompilationEngine.h"

CompilationEngine::CompilationEngine(ifstream &input, ofstream &output) :
    input(input), output(output), tokenizer(input)
{
    if (tokenizer.hasMoreTokens())
        compileClass();
}

void CompilationEngine::compileClass()
{
    token last_token;

    // get class token
    tokenizer.advance();
    last_token = tokenizer.getLastToken();
    if (last_token != "class")
        throw Exceptions::wrongTokenException();
    outputStartXmlComm(tokenizer.getLastTokenType());

    // get class name
    tokenizer.advance();
    if (tokenizer.getLastTokenType() != Identifier)
        throw Exceptions::wrongTokenTypeException();

    //
}

void CompilationEngine::compileClassVarDec()
{

}

void CompilationEngine::compileSubroutineDec()
{

}

void CompilationEngine::compileParameterList()
{

}

void CompilationEngine::compileSubroutineBody()
{

}

void CompilationEngine::compileVarDec()
{

}

void CompilationEngine::compileStatements()
{

}

void CompilationEngine::compileLet()
{

}

void CompilationEngine::compileIf()
{

}

void CompilationEngine::compileWhile()
{

}

void CompilationEngine::compileDo()
{

}

void CompilationEngine::compileReturn()
{

}

void CompilationEngine::outputStartXmlComm(xmlVarType xml_var_type)
{
    cout << "<";
    outputXmlCommAux(xml_var_type);
    cout << ">" << endl;
}

void CompilationEngine::outputEndXmlComm(xmlVarType xml_var_type)
{
    cout << "</";
    outputXmlCommAux(xml_var_type);
    cout << ">" << endl;
}

void CompilationEngine::outputXmlCommAux(xmlVarType xml_var_type)
{
    switch(xml_var_type)
    {
        case Keyword:
            cout << "keyword";
        case Symbol:
            cout << "symbol";
        case IntegerConstant:
            cout << "integerConstant";
        case StringConstant:
            cout << "stringConstant";
        case Identifier:
            cout << "identifier";
        case Class:
            cout << "class";
        case ClassVerDec:
            cout << "classVerDec";
        case SubroutineDec:
            cout << "subroutineDec";
        case ParameterList:
            cout << "parameterList";
        case SubroutineBody:
            cout << "subroutineBody";
        case VarDec:
            cout << "varDec";
        case LetStatement:
            cout << "letStatement";
        case IfStatement:
            cout << "ifStatement";
        case WhileStatement:
            cout << "whileStatement";
        case DoStatement:
            cout << "doStatement";
        case ReturnStatement:
            cout << "returnStatement";
        case Expression:
            cout << "expression";
        case Term:
            cout << "term";
        case ExpressionList:
            cout << "expressionList";
        case Op:
            cout << "op";
        case UnaryOp:
            cout << "unaryOp";
        case KeywordConstant:
            cout << "keywordConstant";
    }
}
