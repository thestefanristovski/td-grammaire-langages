#include <iostream>
#include "Lexer.h"
#include "Automate.h"
#include <string>

using namespace std;

int main() {
    string query;
  
    cout << "Enter your query:" << endl;
    getline(std::cin,query);
    cout << "Calculating: "+query << endl;
    
    Automate automate(query);
    automate.run();
    
    return 0;
}
