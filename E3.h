//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E3_H
#define GL_E3_H


#include "Etat.h"

class Automate;

class E3 : public Etat {
  public :
    E3(string name);
    ~E3();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E3_H
