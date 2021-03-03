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
  cout << endl;
  //save the associated symbol
  symbols.push_back(s);
  //add the new state to the stack
  states.push_back(e);
}

void Automate::reduction(int n, Symbole * s) {
  
  cout << endl;

  vector<Symbole *> poped;
  int val;

  //for the number of states to remove
  for(int i=0;i<n;i++) {

    //remove the last state in stack
    delete(states.back());
    states.pop_back();
    //remove last symbol from stack and store it
    if(n == 1){
      val = symbols.back()->eval();
    } else{
      poped.push_back(symbols.back());
    }
    symbols.pop_back();
  }
  
  //reverse poped symbols to get right order
  //calculate value of expression
  if( n != 1){
    if( *poped[1] == PLUS ) val = poped[0]->eval() + poped[2]->eval(); 
    else if( *poped[1] == MULT  ) val = poped[0]->eval() * poped[2]->eval(); 
    else val = poped[1]->eval();
  } 
  
  //transition from last state in stack to the new expression
  states.back()->transition(this, new Expr(val));
  lexer->putSymbol(s);
}

Automate::~Automate() {
  delete lexer;
}
