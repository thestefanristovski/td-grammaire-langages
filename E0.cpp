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
        cout<<"EXPR; decalage; state1";
        automate->decalage(s, new E1("state1"));
        break;
      case OPENPAR:
        cout<<"OPENPAR; decalage; state2";
        automate->decalage(s, new E2("state2"));
        break;
      case INT:
        cout<<"INT; decalage; state3";
        automate->decalage(s, new E3("state3"));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
