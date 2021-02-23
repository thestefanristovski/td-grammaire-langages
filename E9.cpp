//
// Stefan Ristovski & Aydin Akaydin
//

#include "E9.h"
#include "Expr.h"
#include "Automate.h"
#include "Symbole.h"

E9::E9(const string name) : Etat(name) {

}

E9::~E9() {

}

void E9::print() const {
    Etat::print();
}

bool E9::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        printTransition("PLUS","reduction","3");
        automate->reduction(3, new Symbole(2));
        break;
      case MULT:
        printTransition("MULT","reduction","3");
        automate->reduction(3, new Symbole(3));
        break;
      case CLOSEPAR:
        printTransition("CLOSEPAR","reduction","3");
        automate->reduction(3, new Symbole(1));
        break;
      case FIN:
        printTransition("FIN","reduction","3");
        automate->reduction(3, new Symbole(5));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
