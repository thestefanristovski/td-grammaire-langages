//
// Stefan Ristovski & Aydin Akaydin
//

#ifndef GL_ETAT_H
#define GL_ETAT_H

#include <iostream>
#include <string>

#include "Symbole.h"

class Automate;
using namespace std;

class Etat {
    public:
        Etat(const string &name);
        virtual ~Etat();
        virtual void print() const;
        virtual bool transition(Automate *automate,Symbole * s) = 0;
        void printUnknown();

    protected:
            string name;
};


#endif //GL_ETAT_H
