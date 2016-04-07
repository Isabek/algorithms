#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

int partition(std::vector<int> &a, int p, int q){
	int x = a[p];
	int i = p;

	for(int j = p + 1; j <= q; j ++){
		if(a[j] <= x){
			i ++;
			std::swap(a[i], a[j]);
		}
	}

	std::swap(a[p], a[i]);

	return i;
}

void quick_sort(std::vector<int> &a, int p, int r){
	if(p < r){
		int q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

void print(std::vector<int> v){
	for(int i = 0; i < (int) v.size(); i ++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main()
{
	int size = 8;
	std::vector<int> a(size, 0);

	for(int i = 0; i < size; i ++){
		a[i] = std::rand() % size + 1; 
	}

	print(a);
	quick_sort(a, 0, size - 1);
	print(a);

	return 0;
}
