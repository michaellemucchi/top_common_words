#include <fstream>
#include "map.h"
#include "validation.h"

int main(int argc, char** argv) {
    std::ifstream inFile(argv[1]); // create an ifstream
    int num_words;
    if (argc == 3) {
        num_words = std::stoi(argv[2]);
    } else {
        num_words = 10;
    } // TAKE IN THE N THEY WANT. 10 IF UNSPECIFIED.

    std::map<std::string, int> word_map;
    std::string input;

    while (inFile >> input) {
        remove_symbols(input);
        set_lowercase(input);
        add_to_map(input, word_map);
    }
    filter_common_words(word_map);
    std::map<int, std::vector<std::string>> flipped_map = flip_map(word_map);
    inFile.close();
    print_map(flipped_map, num_words);

    return 0;
}