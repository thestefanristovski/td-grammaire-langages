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
        //constructor: name of state (for display and print)
        Etat(const string &name);
        virtual ~Etat();
        //print name of state
        virtual void print() const;
        //transition (decalage/reduction): returns false if reached the end
        virtual bool transition(Automate *automate,Symbole * s) = 0;
        void printUnknown();

    protected:
            string name;
};


#endif //GL_ETAT_H
