#include <iostream>
#include "Lexer.h"
#include "Automate.h"
#include <string>

int main() {
    string chaine;
  
    std::cout << "Enter your query:" << std::endl;
    std::getline(std::cin,chaine);
    std::cout << "Calculating: "+chaine << std::endl;
    
    Automate automate(chaine);
    automate.eval();
    
    return 0;
}
