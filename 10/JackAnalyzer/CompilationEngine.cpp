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

// first token is already read only after entering compileX function
void CompilationEngine::compileClass()
{
    outputStartXmlComm(Utils::Class, end_line);

    // get class token
    tokenizer.advance();
    if (tokenizer.getToken() != "class")
        throw wrongTokenException();
    outputOneLiner();

    // get class name
    tokenizer.advance();
    if (tokenizer.getTokenType() != Identifier)
        throw wrongTokenTypeException();
    outputOneLiner();

    // get '{'
    tokenizer.advance();
    if (tokenizer.getToken() != "{")
        throw wrongTokenException();
    outputOneLiner();

    // get class variables declarations , dont advance until entering the functions
    while (tokenizer.getNextToken() == "static" || tokenizer.getNextToken() == "field")
    {
        compileClassVarDec();
    }

    // get class subroutines declarations
    while (tokenizer.getNextToken() == "constructor" || tokenizer.getNextToken() == "function"
    || tokenizer.getNextToken() == "method")
    {
        compileSubroutineDec();
    }

    // get '}'
    tokenizer.advance();
    if (tokenizer.getToken() != "}")
        throw wrongTokenException();
    outputOneLiner();

    outputEndXmlComm(Utils::Class, end_line);
}

void CompilationEngine::compileClassVarDec()
{
    // outputs the static\field keyword
    tokenizer.advance();
    if (tokenizer.getToken() != "static" && tokenizer.getToken() != "field")
        throw wrongTokenException();
    outputOneLiner();

    // outputs the type of variable (int\char\boolean\className)
    tokenizer.advance();
    if (tokenizer.getToken() != "int" && tokenizer.getToken() != "char"
    && tokenizer.getToken() != "boolean" && tokenizer.getTokenType() != Utils::Identifier)
    {
        throw wrongTokenException();
    }
    outputOneLiner(); // className identifier is a one-liner

    // outputs the varName (identifier)
    tokenizer.advance();
    if (tokenizer.getTokenType() != Utils::Identifier)
    {
        throw wrongTokenTypeException();
    }
    outputOneLiner(); // varName identifier is a one-liner
}

void CompilationEngine::compileSubroutineDec()
{
    // outputs the constructor\function\method keyword
    tokenizer.advance();
    if (tokenizer.getNextToken() != "constructor" && tokenizer.getNextToken() != "function"
        && tokenizer.getNextToken() != "method")
    {
        throw wrongTokenException();
    }
    outputOneLiner();

    // outputs the return type of the subroutine
    tokenizer.advance();

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

void CompilationEngine::outputStartXmlComm(xmlVarType xml_var_type, bool shouldEndLine)
{
    cout << "<";
    outputXmlCommAux(xml_var_type);
    cout << ">";
    if (shouldEndLine)
    {
        cout << endl;
    }
}

void CompilationEngine::outputEndXmlComm(xmlVarType xml_var_type, bool shouldEndLine)
{
    cout << "</";
    outputXmlCommAux(xml_var_type);
    cout << ">";
    if (shouldEndLine)
    {
        cout << endl;
    }
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

void CompilationEngine::outputOneLiner()
{
    outputStartXmlComm(tokenizer.getTokenType());
    cout << tokenizer.getToken();
    outputEndXmlComm(tokenizer.getTokenType(), end_line);
    cout << endl;
}
