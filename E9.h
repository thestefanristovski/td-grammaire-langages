//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E9_H
#define GL_E9_H


#include "Etat.h"

class Automate;

class E9 : public Etat {
  public:
    E9(string name);
    ~E9();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E9_H
