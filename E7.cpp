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
        cout<<"PLUS; reduction; 3";
        automate->reduction(3,new Symbole(2));
        break;
      case MULT:
        cout<<"MULT; decalage; state5";
        automate->decalage(s, new E5("state5"));
        break;
      case CLOSEPAR:
        cout<<"CLOSEPAR; reduction; 3";
        automate->reduction(3, new Symbole(1));
        break;
      case FIN:
        cout<<"FIN; reduction; 3";
        automate->reduction(3, new Symbole(5));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
