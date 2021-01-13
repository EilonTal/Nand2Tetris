//
// Created by eilon on 13/01/2021.
//

#ifndef JACKANALYZER_UTILS_H
#define JACKANALYZER_UTILS_H


class Utils
{
public:
    enum xml_var_type{
        Keyword, Symbol, IntegerConstant, StringConstant, Identifier,
        Class, ClassVerDec, SubroutineDec, ParameterList, SubroutineBody,
        VarDec, LetStatement, IfStatement, WhileStatement, DoStatement,
        ReturnStatement, Expression, Term, ExpressionList, Op,
        UnaryOp, KeywordConstant
    };
};


#endif //JACKANALYZER_UTILS_H
