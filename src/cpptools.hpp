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

    vector<string> get_aml_values(string key, string file) {
        regex key_r("^" + key + "=");
        regex sp(" ");
        string ln;
        vector<string> ret_vec;
        ifstream fileTP(file);
        if (!fileTP.is_open()) {
            return vector<string>{"err"};
        }
        while(getline(fileTP, ln)) {
            if (regex_search(ln, key_r)) {
                string ret_vp__ = regex_replace(ln, key_r, "");

                int ret_find = ret_vp__.find(",");
                ret_vec.push_back(ret_vp__.substr(0, ret_find));
                ret_vp__.erase(0, ret_find+1);

                ret_vec.push_back(ret_vp__);
            }
        }
        fileTP.close();
        return ret_vec;
    }
}
