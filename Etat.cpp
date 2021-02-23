//
// Created by Olivier VICENTE on 14/02/2017.
//

#include "Etat.h"

Etat::Etat(const string &name) : name(name) {}

void Etat::printTransition(string symbole, string action, string etat) {
  cout << "symbol:" << symbole << " detected, " << action << " to " << etat << endl;
}

Etat::~Etat() {

}

void Etat::print() const {
  cout << "Current state : " << this->name << endl;
}

void Etat::printUnknown() {
  cout << "Character not recognized" << endl;
}
