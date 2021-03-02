//
// Stefan Ristovski & Aydin Akaydin
//

#include "E8.h"
#include "Automate.h"
#include "Symbole.h"

E8::E8(const string name) : Etat(name) {

}

E8::~E8() {

}

void E8::print() const {
    Etat::print();
}

bool E8::transition(Automate *automate, Symbole *s) {
    
    this->print();
    
    switch(*s) {
      case PLUS:
        cout<<"PLUS; réduction; 3";
        automate->reduction(3, new Symbole(2));
        break;
      case MULT:
        cout<<"MULT; réduction; 3";
        automate->reduction(3, new Symbole(3));
        break;
      case CLOSEPAR:
        cout<<"CLOSEPAR; réduction; 3";
        automate->reduction(3, new Symbole(1));
        break;
      case FIN:
        cout<<"FIN; réduction; 3";
        automate->reduction(3, new Symbole(5));
        break;
      default:
        this->printUnknown();
        return false;
    }
    
    return true;
}
