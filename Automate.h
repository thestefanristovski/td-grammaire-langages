#pragma once 

#include <symbole.h>
#include <lexer.h>
#include <string>
#include <stack>



using namespace std;

class Etat;

class Automate{

    public:
        Automate( string s){};
        void decalage(Symbole* s, Etat* etat);
        void reduction(int n, Etat* etat);
    private:
        Lexer* lexer;
        stack<Etat*> pileEtats;
        stack<Symbole*> pileSymbols;


};