/*
 * 배열이 주어졌을 때, 정점에 있는 원소를 찾아라. 정점 원소란 이웃보다 큰 원소다
 * 예를 들어서)
 * 입력 : [8, 9, 10, 2, 5, 6]
 * 출력 : 정점 원소는 10이다.
 * 입력 : [8, 9, 10, 12, 15]
 * 출력: 정점원소는 15다.
 * 입력 : [10, 8, 6, 5, 3, 2]
 * 정점 원소는 10이다.
 */

#include <iostream>

int findPeak(int arr[], int n, int low, int high)
{
    // 중간점
    //
    int mid = (low + high) / 2;
    
    // 중간 원소가 정점인지 확인해라
    //
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
        (mid == n-1 || arr[mid+1] <= arr[mid]))
    {
        return mid;
    }

    // 만약 왼쪽의 이웃이 중간원소보다 더 크다면
    // 그 때는 왼쪽 배열에 정점이 있다.
    if (mid - 1 >= 0 && arr[mid-1] > arr[mid])
    {
        return findPeak(arr, n, low, mid-1);
    }

    // 그렇지 않다면 오른쪽에서 찾아라.
    //
    return findPeak(arr, n, mid+1, high);
}

int main()
{
    int arr[] = {10, 20, 30, 25, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeak(arr, n, 0, n-1);
    std::cout << "배열에서 정점 원소는:" << arr[peakIndex]
        << std::endl;
    return 0;
}
