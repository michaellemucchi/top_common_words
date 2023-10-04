#ifndef INC_TOPCOMMONWORDS_MAP_H
#define INC_TOPCOMMONWORDS_MAP_H
    #include <string>
    #include <map>
    #include <iostream>
    #include <vector>

    void add_to_map(const std::string& input, std::map<std::string, int>& map);
    void filter_common_words(std::map<std::string, int>& map);
    void print_map(std::map<int, std::vector<std::string>>& map, int num_words);
    std::map<int, std::vector<std::string>> flip_map(const std::map<std::string, int>& orig_map);

#endif //INC_TOPCOMMONWORDS_MAP_H
