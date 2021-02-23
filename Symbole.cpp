#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::eval()
{
	return 0;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::eval() {
	Symbole::Affiche();
	return this->valeur;
}

int Expr::eval() {
	return this->valeur;
}
