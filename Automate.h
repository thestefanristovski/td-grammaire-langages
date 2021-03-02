//
// Stefan Ristovski & Aydin Akaydin
//

#include <vector>
#include "Symbole.h"
#include "Lexer.h"
#include <string>

class Etat;
class E0;
using namespace std;

class Automate {
  protected :
    vector<Symbole *> symbolstack;
    vector<Etat *> statestack;
    Lexer *lexer;
    Symbole *reserve;
  
  public:
    Automate(string chaine);
    ~Automate();
    void run();
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    int calcul(vector<Symbole *> tab);
};

