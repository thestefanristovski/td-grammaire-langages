//
// Stefan Ristovski & Aydin Akaydin
//

#include "E0.h"
#include "E1.h"
#include "Automate.h"

E0::E0(const string name) : Etat(name) {

}

E0::~E0() {

}

void E0::print() const {
    Etat::print();
}

bool E0::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case EXPR:
        printTransition("EXPR","decalage","etat1");
        automate->decalage(s, new E1("etat1"));
        break;
      case OPENPAR:
        printTransition("OPENPAR","decalage","etat2");
        automate->decalage(s, new E2("etat2"));
        break;
      case INT:
        printTransition("INT","decalage","etat3");
        automate->decalage(s, new E3("etat3"));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
