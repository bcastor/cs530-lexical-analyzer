/*
 * functions used to to compile a file
 * using BNF grammar
 *
 * Brandon Castor
 * SDSU cs503
 * 5/6/2020
 */
#include <iostream>
#include <vector>
#include <string>
#include "bnf.h"
#include <stack>
#include <algorithm>

using namespace std;

void bnf::invalid(string line){

    vector<string> vec;
    string he;
    char a;
    char op[] = {'*', '/', '+', '(', ')', '=','-',';'};
    size_t found = line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789()+-=;*/% :");
    //check if id has an invalid char
    if (found!=string::npos)
    {
       cout << "**** unknown character ****" << endl;
    }
    //removes opperators, semicolons and parentheses from the string
    for(char i : op){
        line.erase(remove(line.begin(),line.end(),i), line.end());
    }
    //tokenizes the id's and puts them in a vector
    tokenize(line,' ',vec);
    //checks if id begins with a valid char
    for(const auto & i : vec){
        he = i;
        if(!(isalpha(he.at(0)))){

            cout<<"**** Id does not have the right format, must begin with char ****"<<endl;
        }
    }
}
int bnf::countChar(string s, char x) {
    int count = 0, n = 0;
    //counts the number of specified chars in a string
    for (char i : s)
        if (i == x)
            count++;

    return count;
}

void bnf::ScolCheck(string line){

    size_t found = line.find(';');
    //if line is an assignment check that it contains a semi colon
    if (assignment(line)){

        //check for missing semicolon
        if (found == string::npos){
            cout <<"**** missing semicolon ****"<< endl;
        }
    }

}

bool bnf::assignment(string line){
    vector<string> vec;
    tokenize(line,' ',vec);
    //check that the line is a valid assignment by checking if it contains an operator
    if(!expression(line)) {
        if (vec[1] == "=") {

            if (countChar(line, '=') > 1) {

                cout << "*** more than one '=' operator ***" << endl;
            }

            return true;
        }
        //checks if the line has the correct assignment format: id = ...
        if (line.find('=') && !(vec[1] == "=")) {

            cout << "**** wrong assignment format ****" << endl;
            return true;
        }
    }
    return false;
}
//checks if the line is an expression
bool bnf::expression(string line){

    bool semi = line.find(';') != string::npos;
    bool eq = line.find('=') != string::npos;

    return !(semi || eq);

}

void bnf::op(string line){

    vector<string> vec;
    tokenize(line,' ',vec);
    bool test;
    bool test2;
    string l;
    string n;


    for(int i = 0; i < vec.size(); i++){

        l = vec[i+1];
        n = vec[i];
        test = (n == "+") || (n == "-") || (n =="*" )|| (n =="/")||(n =="=");
        test2 = (n.at(0) == '+') || (n.at(0) == '-') || (n.at(0) =='*' )|| (n.at(0) =='/')||(n.at(0) =='=');

        //checks that the operator is followed by an id, if not return an error message
        if(test && !(isalpha(l.at(0))) && l.at(0) != '('){

            cout<< vec[i] << endl;
            cout<< "****operator must be followed by a valid id****"<<endl;

        }
        //error if operator is followed  by another operator
        if ((n.size() > 1) && test2){

            cout<< vec[i] << endl;
            cout<< "****operator must be followed by a valid id****"<<endl;
        }
    }
}

void bnf::balancedParentheses(string line)
{
    stack<char> s;
    //checks that the  parentheses are closed by putting open parentheses in stack
    for (char i : line){

        if(i == '('){
            s.push(i);
        }
    //remove from stack if a pair is found
        if(i == ')'){

            s.pop();
        }
    }
    //if not empty then parentheses are not cloed
    if (!s.empty()){

        cout<< "**** bracket is not closed ****"<<endl;
    }

}

void bnf::tokenize(string const &str, const char elim, vector<string> &out){

    size_t start;
    size_t end = 0;
    //tokenizes a string by separating tokens by a char
    while ((start = str.find_first_not_of(elim, end)) != string::npos){

        end = str.find(elim, start);
        out.push_back(str.substr(start, end - start));
    }
}

