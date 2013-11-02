#include <iostream>
#include <string>
using namespace std;
void convert(string&, size_t, size_t);
inline void swap(char* const a, char* const b);
int main() {
	string str;
	size_t k;
	while(cin >> str) {
		cin >> k;

		convert(str, 0, k - 1);
		convert(str, k, str.size() - 1);
		convert(str, 0, str.size() - 1);

		cout << str << endl;
		
	}
	return 0;
}

void convert(string &str, size_t s, size_t e) {
	for(size_t i = s; i <= (s + e) / 2; ++i) {
		swap(str[i], str[s + e -i]);
	}
}

inline void swap(char* const a, char* const b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
