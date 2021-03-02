//
// Stefan Ristovski & Aydin Akaydin
//

#include "E3.h"
#include "Automate.h"
#include "Symbole.h"

E3::E3(const string name) : Etat(name) {

}

E3::~E3() {

}

void E3::print() const {
    Etat::print();
}

bool E3::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        cout<<"PLUS; reduction; 1";
        automate->reduction(1, new Symbole(2));
        break;
      case MULT:
        cout<<"MULT; reduction; 1";
        automate->reduction(1, new Symbole(3));
        break;
      case CLOSEPAR:
        cout<<"CLOSEPAR; reduction; 1";
        automate->reduction(1, new Symbole(1));
        break;
      case FIN:
        cout<<"FIN; reduction; 1";
        automate->reduction(1, new Symbole(5));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
