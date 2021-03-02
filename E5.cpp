//
// Stefan Ristovski & Aydin Akaydin
//

#include "E5.h"
#include "E3.h"
#include "E2.h"
#include "E8.h"
#include "Automate.h"

E5::E5(const string name) : Etat(name) {

}

E5::~E5() {

}

void E5::print() const {
    Etat::print();
}

bool E5::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case INT:
        cout<<"INT; decalage; state3";
        automate->decalage(s, new E3("state3"));
        break;
      case OPENPAR:
        cout<<"OPENPAR; decalage; state2";
        automate->decalage(s, new E2("state2"));
        break;
      case EXPR:
        cout<<"EXPR; decalage; state8";
        automate->decalage(s, new E8("state8"));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
