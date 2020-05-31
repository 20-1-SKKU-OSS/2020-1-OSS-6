/**
 * 원소의 값이 증가하다가 감소하는 배열 내에 가장 큰 수를 찾습니다.
 * 예시)
 * Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
 * Output: 500
 *
 * 다음과 같은 상황도 고려합니다.
 * 
 * Input: arr[] = {10, 20, 30, 40, 50}
 * Output: 50
 *
 * Input: arr[] = {120, 100, 80, 20, 0}
 * Output: 120
 */

#include <iostream>
#include <vector>

int findMaximum(std::vector<int> & arr, int low, int high) {
	// 하부 배열의 원소가 하나만 있을 때
	if ( high == low ) {
		return arr[low]; // 바로 그 값을 반환합니다.
	}

	//하부 배열의 원소가 2개일 때
	if ( high - low == 1 ) {
		return arr[high] > arr[low] ? arr[high] : arr[low]; // 높은 쪽에 있는 것과 낮은 쪽에 있는 것 중 높은 값을 반환합니다.
	}

	//그 외의 경우, 원소가 3개 이상 있을 때는 findMaximum함수를 재귀적으로 호출합니다. 단, 배열을 이분해서 호출합니다.
	int mid = ( high + low )/2;
	if ( arr[mid-1] > arr[mid] ) {
		return findMaximum(arr, low, mid-1);
	} else {
		return findMaximum(arr, mid+1, high);
	}

}

//원소를 처음부터 끝까지 출력합니다.
void printVec( std::vector<int> & arr ) {
	std::cout << "Arr:";
	for ( auto & a : arr ) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
}



int main() {
	std::vector<int> arr1{ 8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 };
	printVec(arr1);
	std::cout << "Max in above arr:" << findMaximum( arr1, 0, arr1.size()-1 ) << std::endl;

	std::vector<int> arr2{1, 3, 50, 10, 9, 7, 6};
	printVec(arr2);
	std::cout << "Max in above arr:" << findMaximum( arr2, 0, arr2.size()-1 ) << std::endl;


	std::vector<int> arr3{10, 20, 30, 40, 50};
	printVec(arr3);
	std::cout << "Max in above arr:" << findMaximum( arr3, 0, arr3.size()-1 ) << std::endl;

	std::vector<int> arr4{120, 100, 80, 20, 0};
	printVec(arr4);
	std::cout << "Max in above arr:" << findMaximum( arr4, 0, arr4.size()-1 ) << std::endl;

	return 0;
}
