//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E6_H
#define GL_E6_H


#include "Etat.h"

class Automate;

class E6 : public Etat {
  public :
    E6(string name);
    ~E6();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E6_H
