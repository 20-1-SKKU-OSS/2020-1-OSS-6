//이것은 c++에서 잠자기 정렬 중 가장 간단한 방법입니다.
#include<iostream>
#include<thread>
#include<vector>
#include <chrono>
using namespace std;

void sleepSort(int*, int);
void sleep(int);

int main()
{
	//정렬을 하기 위해서 정수 배열을 초기화합니다.
	//음수에 대해서는 반응하지 마세요.
	int arr[] = { 3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	//배열에서 가장 큰 값을 찾아
	//왜 최대값을 찾는지는 아래를 보세요.	
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	max++;

	//SLEEPSORT()라는 함수를 호출합니다.
	sleepSort(arr, n);

	//주요 스레드를 1초이상 잠자도록 합니다.
	//리스트에서 가장 큰 수를 
	//이것은 메인 함수가 끝나기 전에 모든 쓰레드가 끝나도록 보장합니다.
	std::this_thread::sleep_for(std::chrono::seconds(max));


	return(0);
}

void sleep( int i) {
	//I초 종안 스레드가 잠자도록 합니다
	std::this_thread::sleep_for(std::chrono::seconds(i));
	cout << i << " ";
}

void sleepSort(int* arr, int n) {
	thread* threads;
	threads = new thread[n];
	for (int i = 0; i < n; i++) {
		//새로은 쓰레드는 배열의 각각의 원소들을 위해서  만들어집니다. 그 배열은 arr[i] 초 동안 잠에 듭니다.
		threads[i] = (thread(sleep, arr[i]));
	}
}
