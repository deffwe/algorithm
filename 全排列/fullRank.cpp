#include "iostream"
using namespace std;
void fullRank(string);
void swap(char &, char &);

void fullRank(string s, int k, int m) {
	if(k == m) {
		cout << s << endl;
	} else {
		for(string::size_type i = k; i!= m+1; ++i) {
			swap(s[k], s[i]);
			fullRank(s, k+1, m);
			swap(s[k], s[i]);
		}
	}	
}

void swap(char &i, char &j) {
	char k = i;
	i = j;
	j = k;
}

int main() {
	string s;
	getline(cin, s);
	fullRank(s, 0, s.size() - 1);

	return 0;
}
