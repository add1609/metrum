#include <iostream>
#include "Tokenizer.hpp"

int main() {
    std::string eingabe = "Fremd bin ich eingezogen,\n Fremd zieh ich wieder aus.\n Der Mai war mir gewogen mit manchem Blumenstrauss.";
    std::cout << "\nEingabe:\n" << eingabe << "\n\nAusgabe:\n";
    metrum::Tokenizer::parse(eingabe).debugPrint();
    return 0;
}
