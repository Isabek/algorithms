#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> v);

void merge(vector<int> &v, vector<int> &a, vector<int> &b)
{
	unsigned vi = 0, ai = 0, bi = 0;
	while(ai < a.size() && bi < b.size()){
		if(a[ai] == b[bi]){
			v[vi++] = a[ai++];
			v[vi++] = b[bi++];
		}
		else if(a[ai] < b[bi]){
			v[vi++] = a[ai++];
		}
		else{
			v[vi++] = b[bi++];
		}
	}

	while(ai < a.size()) v[vi++] = a[ai++];
	while(bi < b.size()) v[vi++] = b[bi++];
}

void mergeSort(vector<int> &v)
{
	if(v.size() <= 1) return;
	int k = v.size() / 2;

	vector<int> a = vector<int>(v.begin(), v.begin() + k);
	vector<int> b = vector<int>(v.begin() + k, v.end());
	mergeSort(a);
	mergeSort(b);
	merge(v, a, b);
}

void print(vector<int> v){
	for(int i = 0; i < (int) v.size(); i ++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main()
{
	int size = 20;

	vector<int> a(size, 0);
	for(int i = 0; i < size; i ++) 
		a[i] = rand() % size + 1;

	print(a);
	mergeSort(a);
	print(a);

	return 0;
}