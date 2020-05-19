#include <iostream>
#include <string>
#ifndef UNTITLED1_BNF_H
#define UNTITLED1_BNF_H

using namespace std;


class bnf{

public:

    int countChar(string,char);
    ///counts the number of given characters in a string
    ///returns the number of characters.
    ////  takes a string and a char as parameters.

    void ScolCheck(string line);
    ///analyses the string and checks that it contains a semicolon at the end
    ///if the string is an assignment.
    /// takes a string as a parameter.

    bool assignment(string);
    ///check whether the line is an assignment
    ///returns true / false
    ///takes a string as a parameter.

    void balancedParentheses(string expr);
    ///checks whether the there are parentheses in the line anc
    ///checks that they are balanced.
    ///takes a string as a parameter

    void invalid(string line);
    ///checks if the id is valid or invalid
    ///takes a string as a parameter.

    void tokenize(string const &str, const char elim, vector<string> &out);
    ///tokenizes a string and stores the tokens in a vector

    bool expression(string line);
    ///takes a string, char and vector as parameters.
    ///checks if the line is an expression
    ///returns true / false
    ///takes a string as a parameter

    void op(string line);
    ///checks if the operators are valid if they are followed by an identifier
    ///takes a string as a parameter.
};

#endif //UNTITLED1_BNF_H
