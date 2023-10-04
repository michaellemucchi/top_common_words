#include "validation.h"

void remove_symbols(std::string& input) {
/*
The complete list of special characters is: \,.:;"|!@#$%^&*()_+-=[]{}<>?/~`'
*/
    std::string unwanted_characters = "\\,.:;\"|!@#$%^&*()_+-=[]{}<>?/~`";
    for (int i = 0; i < unwanted_characters.size(); ++i) {
        input.erase(std::remove(input.begin(), input.end(), unwanted_characters[i]), input.end());
    }
    if (input.at(0) == '\'') {
        input.erase(0,1);
    }
    if (input.at(input.size()-1) == '\'') {
        input.erase(input.size()-1,1);
    }
}

void set_lowercase(std::string& input) {
    // NOTE: go through the word, setlower everything.
    for (int i = 0; i < input.size(); ++i) {
        input[i] = tolower(input.at(i));
    }
}