/*
 * Brandon Castor
 * This program simmulates a compiler using BNF grammar
 * takes a file and compiles the file, prints errors if found in the grammar
 * and if no errors are found nothing is printed.
 * SDSU cs530
 * 5/6/2020
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bnf.h"


using namespace std;

int main(int argc, char** argv) {

    string str;
    bnf grammar;

    vector<string> vecOfString;
    vector<string> vec;

   ifstream file(argv[1]);
   if (!file){
       cout<<"Cannot open file\n";
       return 0;
   }

    while(getline(file,str)){
        if(str.size() > 0)
            vecOfString.push_back(str);
    }


    for(const auto& string : vecOfString){

        cout<<string<<endl;

        grammar.ScolCheck(string);
        grammar.balancedParentheses(string);
        grammar.invalid(string);
        grammar.op(string);


    }


    file.close(); //closes file

    return 0;
}
