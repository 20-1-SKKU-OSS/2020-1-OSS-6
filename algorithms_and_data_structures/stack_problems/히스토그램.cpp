/*
히스토그램에서 가장 큰 직사각형

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다.
각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다.
예를 들어, 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이 있을 수 있다.
히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력

입력은 테스트 케이스 여러 개로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다.(1 ≤ n ≤ 100,000)
그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다.
이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다.
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력

각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.
*/

#include <iostream>
#include <stack>
 
int h[100000];
 
int main(void)
{
    int n; std::cin >> n;
    while (n) {
        std::stack<int> s;
        for (int i = 0; i < n; i++) std::cin >> h[i];
        long long area = 0;
 
        for (int i = 0; i < n; i++) {
            // 스택이 비어있지 않고 i번째 직사각형의 높이보다 스택에 들어있는 인덱스의 높이가 큰 경우
            while (!s.empty() && h[s.top()] > h[i]) {
                // 스택에서 pop시키기 전에 높이 저장
                long long height = h[s.top()];
                s.pop();
                // pop했을 때 스택이 비게 되면 그 너비는 i번째 직사각형을 제외한 스택에 들어있던 직사각형의 개수가 너비가 된다.
                long long width = i;
                // pop했을 때 스택에 아직도 있다면 i~s.top()의 길이가 너비가 된다.
                if (!s.empty()) width = i - s.top() - 1;
                // 더 큰 넓이가 오면 갱신
                if (width*height > area) area = width * height;
            }
            // 항상 스택에 인덱스를 넣는다.
            s.push(i);
        }
 
 
        // 스택이 비어있지 않은 경우, 오른쪽 끝까지 왔을 때!
        while (!s.empty()) {
            long long height = h[s.top()];
            s.pop();
            long long width = n;
            if (!s.empty()) width = n - s.top() - 1;
            if (width*height > area) area = width * height;
        }
        std::cout << area << '\n';
        std::cin >> n;
    }
    return 0;
}
