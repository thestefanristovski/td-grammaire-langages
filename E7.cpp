//
// Stefan Ristovski & Aydin Akaydin
//

#include "E7.h"
#include "E5.h"
#include "Automate.h"
#include "Symbole.h"

E7::E7(const string name) : Etat(name) {

}

E7::~E7() {

}

void E7::print() const {
    Etat::print();
}

bool E7::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        printTransition("PLUS","reduction","3");
        automate->reduction(3,new Symbole(2));
        break;
      case MULT:
        printTransition("MULT","decalage","etat5");
        automate->decalage(s, new E5("etat5"));
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
