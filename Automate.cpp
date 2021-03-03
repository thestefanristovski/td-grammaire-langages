//
// Stefan Ristovski & Aydin Akaydin
//

#include <algorithm>
#include "Automate.h"
#include "Etat.h"
#include "E0.h"

Automate::Automate(string query) {
  //start up lexer
  lexer = new Lexer(query);
  //initialize 0 state and push in the stack
  Etat *state0 = new E0("state0");
  states.push_back(state0);
}

void Automate::run() 
{
  bool returnTransition = true;
  //while not done with transitions
  while(returnTransition)
  {
    //read next symbol (lexer)
    Symbole *symbol = lexer->Consulter();
    //move lexer to next symbol
    lexer->Avancer();
    //execute transition for last state
    returnTransition = states.back()->transition(this, symbol);
  }
  
  cout << "End of parsing" << endl;
  for(int i=0;i<symbols.size();++i)
    cout << symbols[i]->eval() << endl;
}

void Automate::decalage(Symbole * s, Etat * e) {
  //save the associated symbol
  symbols.push_back(s);
  //add the new state to the stack
  states.push_back(e);
}

void Automate::reduction(int n, Symbole * s) {
  
  vector<Symbole *> poped;
  
  //for the number of states to remove
  for(int i=0;i<n;i++) {
    //remove the last state in stack
    delete(states.back());
    states.pop_back();
    //remove last symbol from stack and store it
    poped.push_back(symbols.back());
    symbols.pop_back();
  }
  
  //reverse poped symbols to get right order
  reverse(poped.begin(), poped.end());
  //calculate value of expression
  int val = calculate(poped);
  
  //transition from last state in stack to the new expression
  states.back()->transition(this, new Expr(val));
  lexer->putSymbol(s);
}

int Automate::calculate(vector<Symbole *> tab) {
  
  switch(tab.size()) {
      //single number
    case 1:
      return tab[0]->eval();
      break;
      //operation or parentheses: a+b, a*b, (a)
    case 3:
      if(*tab[0] == OPENPAR) {
        return tab[1]->eval();
      }
      else if(*tab[1] == PLUS) 
      {
        return tab[0]->eval() + tab[2]->eval();
      }
      else if(*tab[1] == MULT) 
      {
        return tab[0]->eval() * tab[2]->eval();
      }
      break;
  }
  
  return 0;
  
}

Automate::~Automate() {
  delete lexer;
}
