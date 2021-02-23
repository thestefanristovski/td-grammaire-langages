#include <Automate.h>

Automate::Automate(string s){
    this->lexer = new Lexer(s);
}

void Automate::decalage(Symbole* s, Etat* etat){
    pileEtats.push(etat);
    pileSymbols.push(s);
}

void Automate::reduction( int n, Etat* etat){

    for( int i=0; i<n; i++){
        pileEtats.pop();
    }

}