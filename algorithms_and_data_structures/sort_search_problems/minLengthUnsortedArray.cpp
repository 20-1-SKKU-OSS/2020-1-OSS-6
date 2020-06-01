/**
 * 크기가 n인 정렬되지 않은 배열이 주어졌을 때, 배열의 모든 부분이 정렬되어 있는 가장 작은 길이의 하위 배열을 찾는다. 
 * 예시:
 * 1) 만약 입력 배열이 [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]일 때, 당신의 프로그램은 반드시 3과 8사이의 하위 배열을 찾을 수 있어야 한다.
 * 2) 만약 입력 배열이 [0, 1, 15, 25, 6, 7, 30, 40, 50]일 때, 당신의 프로그램은반드시 2부터 5사이의 하위 배열을 찾을 수 있어야 한다.
 */


#include <iostream>
#include <vector>
#include <utility>

std::pair<size_t, size_t> minLengthSubarray( std::vector<int> arr ) {
	
	//1단계: 왼쪽부터 오른쪽까지 훑는다. 다음 원소보다 더 큰 첫 번째 원소를 찾는다.
	size_t start = 0;
	for ( start = 0; start < arr.size() - 1; ++start ) {
		if ( arr[start] > arr[start+1] ) {
			break;
		}
	}
	if ( start == arr.size() - 1 ) {
		return std::make_pair(0,0);
	}
	
	//2단께: 오른쪽부터 왼쪽으로 탐색한다. 그리고 이전보다 더 작은 원소를 찾는다.
	size_t end;
	for ( end = arr.size() - 1; end > 0; --end ) {
		if ( arr[end] < arr[end-1] ) {
			break;
		}
	}

	// 최소값과 최대값을 찾는다.
	int min = arr[start], max = arr[start];
	for ( size_t i = start + 1; i <= end; ++i ) {
		if ( arr[i] > max ) {
			max = arr[i];
		}
		if ( arr[i] < min ) {
			min = arr[i];
		}
	}

	// 하부 배열에서 최소값보다 더 큰 원소를 찾는다.
	// 그리고 그 원소의 참조값으로 시작 참조값을 바꾼다.
	for ( size_t i = 0; i < start; ++i ) {
		if ( arr[i] > min ) {
			start = i;
			break;
		}
	}

	// 이와같이, 최대값보다 작은 값을 오른쪽으로부터 찾는다. 그리고 그에 대한 참조값을 바꾼다.
	// change the end index to that element index
	for ( size_t i = arr.size() - 1; i >= end+1 ; --i ) {
		if ( arr[i] < max ) {
			end = i;
			break;
		}
	}
	return std::make_pair( start, end );

}


void printVec( std::vector<int> & vec, size_t begin, size_t end ) {
	for ( size_t i = begin; i <= end; ++i ) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec1{10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	std::pair<size_t, size_t> subArrayIndices = minLengthSubarray(vec1);
	std::cout << "Array:";
	printVec( vec1, 0, vec1.size() - 1 );
	size_t start = subArrayIndices.first;
	size_t end = subArrayIndices.second;
	if ( start == 0 && end == 0 ) {
		std::cout << "Above array is already sorted\n";
	} else {
		std::cout << "위의 배열을 완정하게 배열하기 위해서 배열되어야 하는 위 배열에서 가장 작은 배열의 길이는: ";
		printVec(vec1, start, end);
	}

	std::vector<int> vec2 { 0, 1, 15, 25, 6, 7, 30, 40, 50 };
	subArrayIndices = minLengthSubarray(vec2);
	std::cout << "배열:";
	printVec( vec2, 0, vec2.size() - 1 );
	start = subArrayIndices.first;
	end = subArrayIndices.second;
	if ( start == 0 && end == 0 ) {
		std::cout << "위의 배열은 이미 정렬되었다.\n";
	} else {
		std::cout << "위의 배열을 완전히 정렬하기 위해서 정렬되어야 하는 위의 배열의 최소 길이는: ";
		printVec(vec2, start, end);
	}

	return 0;
}
