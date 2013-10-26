#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "count_sort.h"
#include "kmp.h"
using namespace std;
extern string::size_type kmp(string);
extern string count_sort(string);
int main() {
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
		s1 = count_sort(s1);
        s2 = count_sort(s2);
		map<char, string::size_type> kmpv;
		for(string::size_type i = 0; i != s2.size(); ++i) {
			string cs = s2.substr(0, i);
			kmpv.insert(make_pair(s2[i], kmp(cs)));
		}	
		string::size_type i = 0, j = 0, k = 0;
		bool contain = false;
		while(i < s1.size()) {
			if(s1[i] == s2[j]) {
				++i;
				++j;
				++k;
				if(k == s2.size()) {
					contain = true;
					break;
				}
			} else {
				if(k == 0) {
					++i; 
					j = 0;
				}
				else {
					i += k - kmpv[s2[j-1]];
					k = j = 0;		
				}
			}
		}
		if(contain) cout << "包含" << endl;
		else cout << "不包含" << endl;
    }
}
