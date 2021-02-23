//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E8_H
#define GL_E8_H


#include "Etat.h"

class Automate;

class E8 : public Etat {
  public :
    E8(string name);
    ~E8();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E8_H
