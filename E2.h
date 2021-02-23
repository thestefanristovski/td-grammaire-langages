//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E2_H
#define GL_E2_H


#include "Etat.h"

class Automate;

class E2 : public Etat {
  public :
    E2(string name);
    ~E2();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E2_H
