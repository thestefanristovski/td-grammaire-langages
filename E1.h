//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E1_H
#define GL_E1_H


#include "Etat.h"

class Automate;

class E1 : public Etat {
  public :
    E1(string name);
    ~E1();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E1_H
