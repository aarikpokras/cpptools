#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace cpptools {
    vector<string> split(string str, string delim, size_t amount) {
        vector<string> ret_vec;
        string b_str = str;
        for (int i = 0; i < amount; i++) {
            size_t f_index = str.find(delim);
            ret_vec.push_back(str.substr(0, f_index));
            str.erase(0, f_index+1);
        }
        return ret_vec;
    }
}
