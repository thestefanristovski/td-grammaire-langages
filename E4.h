//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_E4_H
#define GL_E4_H


#include "Etat.h"

class Automate;

class E4 : public Etat {
  public:
    E4(string name);
    ~E4();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};


#endif //GL_E4_H
