#include <cstdio>
#include <algorithm>

void maxHeapify(int *heap, int index, int size){
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	if(left < size && heap[left] > heap[index]){
		largest = left;
	}
	if(right < size && heap[right] > heap[largest]){
		largest = right;
	}
	if(largest != index){
		std::swap(heap[index], heap[largest]);
		maxHeapify(heap, largest, size);
	}
}

void minHeapify(int *heap, int index, int size){
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int smallest = index;
	if(left < size && heap[left] < heap[index]){
		smallest = left;
	}
	if(right < size && heap[right] < heap[smallest]){
		smallest = right;
	}
	if(index != smallest){
		std::swap(heap[index], heap[smallest]);
		minHeapify(heap, smallest, size);
	}

}

void buildMaxHeap(int *heap, int size){
	for(int i = size / 2 - 1; i >= 0; i --){
		maxHeapify(heap, i, size);
	}
}

void buildMinHeap(int *heap, int size){
	for(int i = size / 2 - 1; i >= 0; i --){
		minHeapify(heap, i, size);
	}
}

void print(int * arr, int size){
	for(int i = 0; i < size; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void heapSortAsc(int *heap, int size){
	buildMaxHeap(heap, size);

	while(size > 0){
		std::swap(heap[0], heap[size - 1]);
		size --;
		maxHeapify(heap, 0, size);
	}
}

void heapSortDesc(int *heap, int size){
	buildMinHeap(heap, size);

	while(size > 0){
		std::swap(heap[0], heap[size - 1]);
		size --;
		minHeapify(heap, 0, size);
	}
}

int main(int argc, char const *argv[])
{
	int size = 10;
	int heap[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	print(heap, size);
	heapSortAsc(heap, size);
	print(heap, size);
	heapSortDesc(heap, size);
	print(heap, size);

	return 0;
}