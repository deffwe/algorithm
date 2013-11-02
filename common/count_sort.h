/*************************************************************************
	> File Name: count_sort.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2013年10月25日 星期五 12:55:21
 ************************************************************************/
using namespace std;
void count_sort(string);

void count_sort(string s, string &rs) {
    map<char, int> mc;
    for(auto c:s) {
        auto insert_result = mc.insert(make_pair(c, 1));
        if(!insert_result.second) {
            ++insert_result.first->second;
        }
    }
    //for(auto it=mc.begin();it!=mc.end();++it) cout << it->first << it->second << endl;
    auto pre = mc.begin();
    auto post = ++pre;
    --pre;
    while(post != mc.end()) {
        post->second += pre->second;
        ++post;
        ++pre;
    }
    //for(auto it=mc.begin();it!=mc.end();++it) cout << it->first << it->second << endl;
    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        rs[mc.at(*it) - 1] = *it;
        --(mc.at(*it));
    }
    /**
    for(; ; --it) {
        rs[mc.at(s[it])] = s[it];
        --(mc.at(s[it]));
		if(it == 0) break;
    }
    */
}
