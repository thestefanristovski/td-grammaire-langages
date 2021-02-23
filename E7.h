//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E7_H
#define GL_E7_H


#include "Etat.h"

class Automate;

class E7 : public Etat {
  public :
    E7(string name);
    ~E7();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E7_H
