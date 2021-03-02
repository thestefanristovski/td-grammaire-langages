//
// Stefan Ristovski & Aydin Akaydin
//

#include "E6.h"
#include "E4.h"
#include "E5.h"
#include "E9.h"
#include "Automate.h"

E6::E6(const string name) : Etat(name) {

}

E6::~E6() {

}

void E6::print() const {
    Etat::print();
}

bool E6::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        cout<<"PLUS; decalage; state4";
        automate->decalage(s, new E4("state4"));
        break;
      case MULT:
        cout<<"MULT; decalage; state5";
        automate->decalage(s, new E5("state5"));
        break;
      case CLOSEPAR:
        cout<<"CLOSEPAR; decalage state9";
        automate->decalage(s, new E9("state9"));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
