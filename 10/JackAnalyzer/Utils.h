//
// Created by eilon on 13/01/2021.
//

#ifndef JACKANALYZER_UTILS_H
#define JACKANALYZER_UTILS_H
#include <string>
const std::string WHITESPACE = " ";


class Utils
{
public:
    enum xml_var_type
    {
        Keyword, Symbol, IntegerConstant, StringConstant, Identifier,
        Class, ClassVarDec, SubroutineDec, ParameterList, SubroutineBody,
        VarDec, LetStatement, IfStatement, WhileStatement, DoStatement,
        ReturnStatement, Expression, Term, ExpressionList, Op,
        UnaryOp, KeywordConstant, Statements
    };
    static std::string ltrim(const std::string& s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    static std::string rtrim(const std::string& s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    static std::string trim(const std::string& s)
    {
        return rtrim(ltrim(s));
    }
};


#endif //JACKANALYZER_UTILS_H
