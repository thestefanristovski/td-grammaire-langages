//
// Stefan Ristovski & Aydin Akaydin
//

#include "E2.h"
#include "E3.h"
#include "E6.h"
#include "Automate.h"

E2::E2(const string name) : Etat(name) {

}

E2::~E2() {

}

void E2::print() const {
    Etat::print();
}

bool E2::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case INT:
        cout<<"INT; décalage; state3";
        automate->decalage(s, new E3("state3"));
        break;
      case OPENPAR:
        cout<<"OPENPAR; décalage; state2";
        automate->decalage(s, new E2("state2"));
        break;
      case EXPR:
        cout<<"EXPR; décalage; state6";
        automate->decalage(s, new E6("state6"));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
