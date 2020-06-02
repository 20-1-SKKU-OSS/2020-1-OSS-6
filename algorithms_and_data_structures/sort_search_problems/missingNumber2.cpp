/**
 *
 * 다음에 나열된 수가 수학적으로 의미있기 위해서 추가해야 하는 수를 찾으시오.
 * 예시)
 * 입력: arr[]  = {2, 4, 8, 10, 12, 14}
 * 출력: 6
 *
 * 입력: arr[]  = {1, 6, 11, 16, 21, 31};
 * 출력: 26
 */

#include <iostream>
#include <vector>
#include <limits>

int findMissingUtil( std::vector<int> & vec, int diff) {
	size_t low = 0;
	size_t high = vec.size() - 1;
	while ( low < high ) {
		size_t mid = ( low + high ) / 2;
		//중간에 있는 값 바로 답음에 빠진 원소가 우리가 찾는 추가해야 하는 원소인지 확인하시오.
		if ( mid < vec.size() - 1 && vec[mid + 1] - vec[mid] != diff ) {
			return vec[mid] + diff;
		}
		// 중간 전의 원소가 추가해야 하는 값이면
		if ( mid > 0 && vec[mid-1] - vec[mid] != diff ) {
			return vec[mid - 1]  + diff;
		}
		//중간 이전의 하위 배열이 AP를 따른다.
		if ( vec[mid] == vec[0] + diff * mid ) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return std::numeric_limits<int>::max();
}

void printVec( std::vector<int> & vec ) {
	std::cout << "Vec: ";
	for ( auto v : vec ) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

int missingNumber( std::vector<int> & vec ) {
	int diff = (vec[vec.size() - 1] - vec[0])/(vec.size());
	return findMissingUtil( vec, diff );
}

int main() {
	std::vector<int> vec{ 2, 4, 8, 10, 12, 14 };
	printVec(vec);
	std::cout << "위의 수학적 나열 중에서 빠진 수는 : "
			  << missingNumber(vec) << std::endl;
	return 0;
}
