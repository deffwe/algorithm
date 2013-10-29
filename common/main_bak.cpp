#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include "count_sort.h"
#include "kmp.h"
using namespace std;
extern string::size_type kmp(string);
extern void count_sort(string, string &);
int main() {
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        string cs1(s1), cs2(s2);
		count_sort(s1, cs1);
        count_sort(s2, cs2);

		map<string, string::size_type> kmpv;
		for(string::size_type i = 0; i != cs2.size(); ++i) {
			string cs = cs2.substr(0, i + 1);
			kmpv.insert(make_pair(cs, kmp(cs)));
		}	
		cout <<"cs1:"<<cs1<<endl;cout <<"cs2:"<<cs2<<endl;
		for(auto it=kmpv.begin();it!=kmpv.end();++it) cout << it->first << it->second << endl;
		exit;
		string::size_type i = 0, j = 0, k = 0;
		bool contain = false;
		while(i < cs1.size()) {
			if(s1[i] == cs2[j]) {
				++i;
				++j;
				++k;
				if(k == cs2.size()) {
					contain = true;
					break;
				}
			} else {
				if(k == 0) {
					++i; 
					j = 0;
				}
				else {
					i += k - kmpv.at(cs2.substr(0, k));
					k = j = 0;		
				}
			}
		}
		if(contain) cout << "包含" << endl;
		else cout << "不包含" << endl;
    }

    return 0;
}
