//
// Created by eilon on 06/01/2021.
//

#include "CompilationEngine.h"

CompilationEngine::CompilationEngine(ifstream &input, ostream &output) :
    output(output), tokenizer(input)
{
    if (tokenizer.hasMoreTokens())
        compileClass();
}

// first token is already read only after entering compileX function
void CompilationEngine::compileClass()
{
    outputStartXmlComm(Utils::Class, end_line);
    //outputIdentation
    // get class token
    tokenizer.advance();
    outputOneLiner();

    // get class name
    tokenizer.advance();
    outputOneLiner();

    // get '{'
    tokenizer.advance();
    outputOneLiner();

    // get class variables declarations , dont advance until entering the functions
    if (tokenizer.nextToken() == "static" || tokenizer.nextToken() == "field")
    {
        compileClassVarDec();
    }

    // get class subroutines declarations
    if (tokenizer.nextToken() == "constructor" || tokenizer.nextToken() == "function"
        || tokenizer.nextToken() == "method")
    {
        compileSubroutineDec();
    }

    // get '}'
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::Class, end_line);
}

void CompilationEngine::compileClassVarDec()
{
    outputStartXmlComm(Utils::ClassVarDec, end_line);

    while (tokenizer.nextToken() == "static" || tokenizer.nextToken() == "field")
    {
        // outputs the static\field keyword
        tokenizer.advance();
        outputOneLiner();

        // outputs the type of variable (int\char\boolean\className)
        tokenizer.advance();
        outputOneLiner(); // className identifier is a one-liner

        // outputs the varName (identifier)
        tokenizer.advance();
        outputOneLiner(); // varName identifier is a one-liner
    }

    outputEndXmlComm(Utils::ClassVarDec, end_line);
}

void CompilationEngine::compileSubroutineDec()
{
    outputStartXmlComm(Utils::SubroutineDec, end_line);

    while (tokenizer.nextToken() == "constructor" || tokenizer.nextToken() == "function"
           || tokenizer.nextToken() == "method")
    {
        // outputs the constructor\function\method keyword
        tokenizer.advance();
        outputOneLiner();

        // outputs the return type of the subroutine
        tokenizer.advance();
        outputOneLiner();

        // outputs the subroutine name
        tokenizer.advance();
        outputOneLiner();

        // outputs '('
        tokenizer.advance();
        outputOneLiner();

        compileParameterList();

        // outputs ')'
        tokenizer.advance();
        outputOneLiner();

        compileSubroutineBody();
    }

    outputEndXmlComm(Utils::SubroutineDec, end_line);
}

void CompilationEngine::compileParameterList()
{
    outputStartXmlComm(Utils::ParameterList, end_line);
    while (tokenizer.nextToken() != ")")
    {
        // outputs varType
        tokenizer.advance();
        outputOneLiner();

        // outputs varName
        tokenizer.advance();
        outputOneLiner();

        // outputs ',' if exists
        if (tokenizer.nextToken() == ",")
        {
            tokenizer.advance();
            outputOneLiner();
        }
    }
    outputEndXmlComm(Utils::ParameterList, end_line);

}

void CompilationEngine::compileSubroutineBody()
{
    outputStartXmlComm(Utils::SubroutineBody, end_line);

    // outputs {
    tokenizer.advance();
    outputOneLiner();

    compileVarDec();

    compileStatements();

    // outputs }
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::SubroutineBody, end_line);

}

void CompilationEngine::compileVarDec()
{

    while (tokenizer.nextToken() == "var")
    {
        outputStartXmlComm(Utils::VarDec, end_line);

        // output 'var'
        tokenizer.advance();
        outputOneLiner();

        //output type
        tokenizer.advance();
        outputOneLiner();

        // output first varName
        tokenizer.advance();
        outputOneLiner();
        //output next varNames (if exist)
        while (tokenizer.nextToken() == ",")
        {
            // output ','
            tokenizer.advance();
            outputOneLiner();

            //output varName
            tokenizer.advance();
            outputOneLiner();
        }

        // output ';'
        tokenizer.advance();
        outputOneLiner();

        outputEndXmlComm(Utils::VarDec, end_line);
    }

}

void CompilationEngine::compileStatements()
{
    outputStartXmlComm(Utils::Statements, end_line);

    while (true)
    {
        if (tokenizer.nextToken() == "let")
        {
            compileLet();
        }
        else if (tokenizer.nextToken() == "if")
        {
            compileIf();
        }
        else if (tokenizer.nextToken() == "while")
        {
            compileWhile();
        }
        else if (tokenizer.nextToken() == "do")
        {
            compileDo();
        }
        else if (tokenizer.nextToken() == "return")
        {
            compileReturn();
        }
        else break;
    }

    outputEndXmlComm(Utils::Statements, end_line);
}

void CompilationEngine::compileLet()
{
    outputStartXmlComm(Utils::LetStatement, end_line);

    // output 'let'
    tokenizer.advance();
    outputOneLiner();

    // output varName
    tokenizer.advance();
    outputOneLiner();

    // if its an array
    if (tokenizer.nextToken() == "[")
    {
        // output '['
        tokenizer.advance();
        outputOneLiner();

        // output expression index of array
        compileExpression();

        // output ']'
        tokenizer.advance();
        outputOneLiner();
    }

    // output '='
    tokenizer.advance();
    outputOneLiner();

    compileExpression();

    // output ';'
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::LetStatement, end_line);
}

void CompilationEngine::compileIf()
{
    outputStartXmlComm(Utils::IfStatement, end_line);

    // output 'if'
    tokenizer.advance();
    outputOneLiner();

    // output '('
    tokenizer.advance();
    outputOneLiner();

    compileExpression();

    // output ')'
    tokenizer.advance();
    outputOneLiner();

    // output '{'
    tokenizer.advance();
    outputOneLiner();

    compileStatements();

    // output '}'
    tokenizer.advance();
    outputOneLiner();

    if (tokenizer.nextToken() == "else")
    {
        // output 'else'
        tokenizer.advance();
        outputOneLiner();

        // output '{'
        tokenizer.advance();
        outputOneLiner();

        compileStatements();

        // output '}'
        tokenizer.advance();
        outputOneLiner();
    }

    outputEndXmlComm(Utils::IfStatement, end_line);
}

void CompilationEngine::compileWhile()
{
    outputStartXmlComm(Utils::WhileStatement, end_line);

    // output 'while'
    tokenizer.advance();
    outputOneLiner();

    // output '('
    tokenizer.advance();
    outputOneLiner();

    compileExpression();

    // output ')'
    tokenizer.advance();
    outputOneLiner();

    // output '{'
    tokenizer.advance();
    outputOneLiner();

    compileStatements();

    // output '}'
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::WhileStatement, end_line);
}

void CompilationEngine::compileDo()
{
    outputStartXmlComm(Utils::DoStatement, end_line);

    // output 'do'
    tokenizer.advance();
    outputOneLiner();

    // output subroutine call
    compileTerm();

    // output ';'
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::DoStatement, end_line);

}

void CompilationEngine::compileReturn()
{
    outputStartXmlComm(Utils::ReturnStatement, end_line);

    // output 'return'
    tokenizer.advance();
    outputOneLiner();

    // theres an expression (not a void func)
    if (tokenizer.nextToken() != ";")
    {
        compileExpression();
    }

    // output ';'
    tokenizer.advance();
    outputOneLiner();

    outputEndXmlComm(Utils::ReturnStatement, end_line);

}

void CompilationEngine::compileExpression()
{
    outputStartXmlComm(Utils::Expression, end_line);

    //output first term
    compileTerm();

    while (tokenizer.isTokenBiOp(tokenizer.nextToken()))
    {
        // output op
        tokenizer.advance();
        outputOneLiner();

        // output next term
        compileTerm();
    }

    outputEndXmlComm(Utils::Expression, end_line);
}

// handles subroutine call as well
void CompilationEngine::compileTerm()
{
    outputStartXmlComm(Utils::Term, end_line);

    // outputs first token in term
    tokenizer.advance();
    outputOneLiner();

    // case of (expression)
    if (tokenizer.getToken() == "(")
    {
        // output expression
        compileExpression();

        // output ')'
        tokenizer.advance();
        outputOneLiner();
    }

    // case of -term\~term
    else if (tokenizer.isTokenUnOp(tokenizer.getToken()))
    {
        compileTerm();
    }

     // case of varName[expression]
    else if (tokenizer.nextToken() == "[")
    {
        // output '['
        tokenizer.advance();
        outputOneLiner();

        compileExpression();

        // output ']'
        tokenizer.advance();
        outputOneLiner();
    }

    // case of subroutineName(expressionList)
    else if (tokenizer.nextToken() == "(")
    {
        // output '('
        tokenizer.advance();
        outputOneLiner();

        compileExpressionList();

        // output ')'
        tokenizer.advance();
        outputOneLiner();
    }

    // case of (className\varName).subroutineName(expressionList)
    // first brackets are just for understanding - not real
    // ex.   obj.func(1)
    else if (tokenizer.nextToken() == ".")
    {
        // output '.'
        tokenizer.advance();
        outputOneLiner();

        // output subroutineName
        tokenizer.advance();
        outputOneLiner();

        // output '('
        tokenizer.advance();
        outputOneLiner();

        compileExpressionList();

        // output ')'
        tokenizer.advance();
        outputOneLiner();
    }

    // in any other case only one advance is enough


    outputEndXmlComm(Utils::Term, end_line);
}

void CompilationEngine::compileExpressionList()
{
    outputStartXmlComm(Utils::ExpressionList, end_line);

    while (tokenizer.nextToken() != ")")
    {
        compileExpression();

        if (tokenizer.nextToken() == ",")
        {
            // output ','
            tokenizer.advance();
            outputOneLiner();
        }
    }
    outputEndXmlComm(Utils::ExpressionList, end_line);
}

void CompilationEngine::outputStartXmlComm(xmlVarType xml_var_type, bool shouldEndLine)
{
    output << "<";
    outputXmlCommAux(xml_var_type);
    output << "> ";
    if (shouldEndLine)
    {
        output << endl;
    }
}

void CompilationEngine::outputEndXmlComm(xmlVarType xml_var_type, bool shouldEndLine)
{
    output << "</";
    outputXmlCommAux(xml_var_type);
    output << ">";
    if (shouldEndLine)
    {
        output << endl;
    }
}

void CompilationEngine::outputXmlCommAux(xmlVarType xml_var_type)
{
    switch(xml_var_type)
    {
        case Utils::Keyword:
            output << "keyword";
            break;
        case Utils::Symbol:
            output << "symbol";
            break;
        case Utils::IntegerConstant:
            output << "integerConstant";
            break;
        case Utils::StringConstant:
            output << "stringConstant";
            break;
        case Utils::Identifier:
            output << "identifier";
            break;
        case Utils::Class:
            output << "class";
            break;
        case Utils::ClassVarDec:
            output << "classVarDec";
            break;
        case Utils::SubroutineDec:
            output << "subroutineDec";
            break;
        case Utils::ParameterList:
            output << "parameterList";
            break;
        case Utils::SubroutineBody:
            output << "subroutineBody";
            break;
        case Utils::VarDec:
            output << "varDec";
            break;
        case Utils::LetStatement:
            output << "letStatement";
            break;
        case Utils::IfStatement:
            output << "ifStatement";
            break;
        case Utils::WhileStatement:
            output << "whileStatement";
            break;
        case Utils::DoStatement:
            output << "doStatement";
            break;
        case Utils::ReturnStatement:
            output << "returnStatement";
            break;
        case Utils::Expression:
            output << "expression";
            break;
        case Utils::Term:
            output << "term";
            break;
        case Utils::ExpressionList:
            output << "expressionList";
            break;
        case Utils::Op:
            output << "op";
            break;
        case Utils::UnaryOp:
            output << "unaryOp";
            break;
        case Utils::KeywordConstant:
            output << "keywordConstant";
            break;
        case Utils::Statements:
            output << "statements";
            break;
    }
}

void CompilationEngine::outputOneLiner()
{
    outputStartXmlComm(tokenizer.tokenType());
    output << tokenizer.getToken() << " ";
    outputEndXmlComm(tokenizer.tokenType(), end_line);
}



