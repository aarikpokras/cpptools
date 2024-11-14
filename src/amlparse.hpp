#include <iostream>
using namespace std;

/*
* AML Parser
* Format:
* key=value
* key=value1,value2
*/

namespace cpptools{
    vector<string> aml_values(string key, string file) {
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
