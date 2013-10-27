#include <iostream>
#include <map>
using namespace std;
int main() {
	string s1, s2;
	while(getline(cin, s1)) {
		getline(cin, s2);
		map<char, string::size_type> hmap;
		for(auto c:s1) {
			hmap.insert(make_pair(c, 1));
		}
		bool contain = true;
		for(auto c:s2){
			auto insert_result = hmap.insert(make_pair(c, 1));
			if(insert_result.second) {
				contain = false;
			}
		}

		if(contain) cout << "包含" << endl;
		else cout << "不包含" << endl;
	}

	return 0;
}