#include "map.h"

void add_to_map(const std::string& input, std::map<std::string, int>& map) {
    int counter = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->first == input) {
            it->second += 1;
            counter++;
            break;
        }
    }
    if (counter == 0) {
        map.insert(std::pair<std::string, int>(input, 1));
    }
}

void filter_common_words(std::map<std::string, int>& map){
    // a, an, and, in, is, it the
    map.erase("a");
    map.erase("an");
    map.erase("and");
    map.erase("in");
    map.erase("is");
    map.erase("it");
    map.erase("the");
}

// TAKEN FROM PROF BUTNER
std::map<int, std::vector<std::string>> flip_map(const std::map<std::string, int>& orig_map) {
    std::map<int, std::vector<std::string>> flipped_map;
    for(const auto& key_value : orig_map){ //  each key value pair in the original map
        const auto& word = key_value.first;
        const auto& frequency = key_value.second;
        if (flipped_map.count(frequency) == 0) { // frequency is not in flipped_map
            flipped_map.insert(std::make_pair(frequency, std::vector<std::string>{word}));
        } else { // frequency is in flipped_book
            flipped_map.at(frequency).push_back(word);
        }
    }
    return flipped_map;
}

void print_map(std::map<int, std::vector<std::string>>& map, int num_words) {
    int count = 0;
    int rank = 1;

    for(auto it = map.rbegin(); it != map.rend(); it++) {
        if (count == num_words) {
            break;
        }
        std::cout << rank << ".) These words appeared " << it->first <<  " times: {";
        std::vector<std::string> new_vec(it->second);
        for (int a = 0; a < new_vec.size(); a++) {
            if (a == new_vec.size()-1) {
                std::cout << new_vec[a];
                break;
            }
            std::cout << new_vec[a] << ", ";
        }
        std::cout << "}" << std::endl;
        rank++;
        count++;
    }
}

//1.) These words appeared 78 times: {shake}