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
    vector<Symbole *> symbols;
    vector<Etat *> states;
    Lexer *lexer;
  
  public:
    Automate(string chaine);
    ~Automate();
    void run();
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    int calculate(vector<Symbole *> tab);
};

