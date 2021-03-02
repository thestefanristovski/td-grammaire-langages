//
// Stefan Ristovski & Aydin Akaydin
//

#include "Etat.h"

Etat::Etat(const string &name) : name(name) {}

Etat::~Etat() {

}

void Etat::print() const {
  cout << "Current state : " << this->name << endl;
}

void Etat::printUnknown() {
  cout << "Character not recognized" << endl;
}
