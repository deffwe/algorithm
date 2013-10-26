#include <string>
using namespace std;
string::size_type kmp(string s) {
    map<string, string::size_type> kc;
    //前缀
    for(auto it=s.size() - 1; it != 0; --it) {
        kc.insert(make_pair(s.substr(0, it), 1));
    }
    for(string::size_type it=1; it != s.size(); ++it) {
        auto ir = kc.insert(make_pair(s.substr(it, s.size() - 1), 1));
        if(!ir.second) {
            ++ir.first->second;
        }
    }
    string::size_type result = 0;
    for(auto it = kc.begin(); it != kc.end(); ++it) {
        if(it->second > 0) {
            if(it->first.size() > result) {
                result = it->first.size();
            }
        }
    }
    return result;
}
