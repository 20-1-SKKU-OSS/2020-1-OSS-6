/**
 * 문제 설명
 * Problem Statement
 *
 * 그 아티스트인 민수씨는'가'와 '나'라는  두 리스트를 가지고 있다. '나'는 '가'의 순열이다.
 * 민수씨는 그 리스트에 대해서 자부심을 가지고 있었다. 불행히도 전시장에서 다른 전시장으로 옮기던 중 몇 가지 수가 '가'에서 빠졌다.
 * 당신은 그 수를 찾을 수 있겠는가?
 * 
 * 주의사항
 *
 * 만약 그 리스트 안에서 어떤 한 수가 여러 개 있다면, 당신은 반드시 양쪽의 리스트에 두 수가 같은 횟수 만큼 등장한다는 사실을 알아야 한다.
 * 만약 그 경우가 아니라면 그 수는 반드시 빠진 수다.
 * 당신은 오름차순으로 빠진 수들을 출력해야 한다.
 * '나'리스트에서 가장 큰 수와 가장 작은 수의 차이는 100이하다.
 * 
 * 입력 형식
 * 네 줄이 입력된다.
 *
 * n- 첫 번째 리스트의 크기
 * 첫 번째 리스트를 이루는 n 개의 정수 배열이 입력된다.
 * m- 두 번째 리스트의 크기
 * 두 번째 리스트를 이루는 m 개의 정수 배열이 입력된다.
 *
 * 출력 형식
 * 오름차순으로 빠진 숫자를 출력해라.
 *
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    long n,m;
    cin >> n;
    long *list1 = new long[n];
    for (long i = 0; i < n; ++i) {
        cin >> list1[i];
    }
    cin >> m;
    long *list2 = new long[m];
    for (long i = 0; i < m; ++i) {
        cin >> list2[i];
    }
    unordered_map<long,long> hash;
    for (long i = 0; i < m; ++i) {
        hash[list2[i]]++;
    }
    for (long i = 0; i < n; ++i) {
        hash[list1[i]]--;
    }
    unordered_map<long,long>::iterator it;
    vector<long> results;
    for (it = hash.begin(); it != hash.end(); ++it){
        if ( it->second > 0) {
            results.push_back(it->first);
        }
    }
    sort(results.begin(), results.end());
    vector<long>::iterator i;
    for (i = results.begin(); i != results.end(); ++i){
        cout << *i << " ";
    }
    return 0;
}

