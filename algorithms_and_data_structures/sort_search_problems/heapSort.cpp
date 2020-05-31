#include<iostream>
using namespace std;


void maxHeapify(int*, int, int);
void buildHeap(int*, int);
void heapsort(int*, int);

int main() {

	int arr[] = { 4,2,3,1,5,6,8,};

	heapsort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

//배열을 max heap 형태로 재배열한다.
void maxHeapify(int* arr, int n, int i) {
	if (i > n / 2 - 1) {
		//만약 자신의 index를 i라고 하고 n을 정체 배열의 개수라고 할 때, i > n/2 -1이면 더 이상 내려갈 곳이 없다. 더 이상 maxHeapify를 호출하지 않아도 된다.
		return;
	}
	if (arr[i] > arr[2 * i] && arr[i] > arr[(2 * i) + 1]) {
		// i 번째 값이 2*i 번째 값보다 크고 i 번째 값이 2*i + 1 번째 값보다 크면 규칙을 만족하니 함수를 종료한다.
		//heap property already satisfied.
		return;
	}


	//maxInt에 i를 할당해 두고
	int maxInx = i, temp;

	while (i <= (n / 2 - 1)) {
		//자식들 중 가장 큰 값을 가지고 있는 녀석을 찾는다.
		if (arr[2 * i + 1] > arr[i] && (2 * i + 1) < n) {
			maxInx = 2 * i + 1;
		}
		if (arr[(2 * i) + 2] > arr[maxInx] && (2 * i + 2) < n) {
			maxInx = (2 * i) + 2;
		}
		//만약 이미 규칙을 만족해서 바꿀 필요가 없으면 함수를 종료한다.
		if (i == maxInx) { return; }

		//만약 규칙을 만족하기 위해서 자리 바꾸기를 해야할 필요가 있다면 
		//바꿔준다.
		temp = arr[maxInx];
		arr[maxInx] = arr[i];
		arr[i] = temp;
		i = maxInx;
	}

}

void buildHeap(int* arr, int n) {
	//
	//start calling from the last parent in the heap(n/2) and go upto the root node.
	//start from the last parent instead of root because here the loop invacriant is that heap condition is 
	//satisfied for all nodes other than the one for which it is called. which would not be true when it is 
	//called for the root node of the array when the array is compeletely random.
	//refer to CORMEN for more details.
	for (int i = (n / 2 - 1); i >= 0; i--) {
		maxHeapify(arr, n, i);
	}
}

void heapsort(int* arr, int n) {
	buildHeap(arr, n);
	
	int temp;
	while (n > 0) {
	//after the heap is built take the element a[0], swap it with the last element, discard it and call maxheapify 
	//for the root element

		temp = arr[n - 1];
		arr[n - 1] = arr[0];
		arr[0] = temp;
		n--;
		maxHeapify(arr, n, 0);
	}
}
