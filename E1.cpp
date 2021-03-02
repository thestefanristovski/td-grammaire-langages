//
// Stefan Ristovski & Aydin Akaydin
//

#include "E1.h"
#include "E5.h"
#include "E4.h"
#include "Automate.h"


E1::E1(const string name) : Etat(name) {

}

E1::~E1() {

}

void E1::print() const {
    Etat::print();
}

bool E1::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        cout<<"PLUS; decalage; state4";
        automate->decalage(s, new E4("state4"));
        break;
      case MULT:
        cout<<"MULT; decalage; state5";
        automate->decalage(s, new E5("etat5"));
        break;
      case FIN:
        cout<<"FIN; accept; ";
        return false;
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
