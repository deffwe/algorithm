#include <iostream>
#include <random>
#include "define.h"
#define N 10
using namespace std;

int Min_k::quick_sort_partion(int *start, int *end) {
	int key = *end;
	int *j = start - 1;
	for(int *i = start; i != end; ++i) {
		if(*i < key) {
			++j;
			swap(*i, *j);
		}
	}
	swap(*(j+1), key);
	return j +1 - pnum;
}

void Min_k::quick_k(int start, int end) {
	if(start < end) {
		int mid = quick_sort_partion(pnum + start, pnum + end);
		if(mid > k) {
			quick_k(start, mid - 1);
		} else if(mid < k) {
			k = mid - k;
			quick_k(mid + 1, end);
		} else {
			return;
		}
	}
}


int main() {
	int A[N];
	uniform_int_distribution<unsigned> u(0, 20);
	default_random_engine e(20);
	for(size_t i = 0; i < N; ++i) {
		A[i] = u(e);
		cout << A[i] << " ";
	}
	cout << endl;

	Min_k quick_method(A, N, N/4);
	quick_method.quick_k(0, N - 1);

	for(size_t i = 0; i < N/4; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
