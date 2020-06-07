
/*   
해당 heap_max.h는 heap의 max를 찾기 위한 기능으로,  
부모가 자식 노드보다 큰 heap 구조 key(부모 노드) >= key(자식 노드)를 말합니다.  

본 기능은 기존 기능과 같이 #include 을 사용하여 활용할 수 있습니다.  

*/   


#ifndef HEAP_MAX_H
#define HEAP_MAX_H

#include <iostream>

namespace algo {

    class Heap {
    private:
        int* heap;
        int capacity;
        int currentSize;


	void swap(int* a, int *b) {
		int t = *a;
		*a = *b;
		*b = t;
	}


    public :


	Heap(int Capacity)  : capacity(Capacity){
		heap = new int[Capacity];
		currentSize = 0;
	}

	~Heap() {
		delete[] heap;
	}

	void Insert(int val) {

		if (currentSize >= capacity) {
			//printf("Heap is full!");
			return;
		}

		int mPos = currentSize++;
		heap[mPos] = val;

		int parPos = (mPos - 1) / 2;
		while (heap[mPos]>heap[parPos]) {
			swap(&heap[mPos], &heap[parPos]);
			mPos = parPos;
			parPos = (mPos - 1) / 2;
		}
	}

	int pop() {
		if (currentSize <= 0) {
			//printf("Heap is Empty!!!\n");
			return NULL;
		}
		int returnVal = heap[0];

		swap(&heap[0],&heap[currentSize-1]);

		heap[currentSize - 1] = NULL;
		currentSize--;

		int root = 0;
		int leftChild;
		int rightChild;

		while (root<=currentSize-1) {
			leftChild = (root + 1) * 2 - 1;
			rightChild = (root + 1) * 2;

			if (leftChild >= currentSize) {

				break;
			}
			else if (rightChild >=currentSize) {

				if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else break;
			}
			else {

				if (heap[leftChild] > heap[root] && heap[rightChild] > heap[root]) {
					if (heap[leftChild]<heap[rightChild]) {
						swap(&heap[rightChild], &heap[root]);
						root = rightChild;
					}
					else {
						swap(&heap[leftChild], &heap[root]);
						root = leftChild;
					}
				}
				else if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else if (heap[rightChild] > heap[root]) {
					swap(&heap[rightChild], &heap[root]);
					root = rightChild;
				}
				else {
					break;
				}
			}

		}
		return returnVal;

	}
	int GetTop() {
		if(currentSize>=1)	return heap[0];
		else return -1;
	}

    };

}


#endif
