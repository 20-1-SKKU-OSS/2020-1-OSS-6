#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include "../include/queue.h"
#include "../include/generic.h"


int main() {
    const int QUEUE_SIZE = 10;
    priority_queue<int, vector<int>, greater<int>> Q;
    
	std::cout << "Pushing following values to queue:\n";
    for ( int i = 0; i < QUEUE_SIZE; ++i )
    {
        int rand_value = algo::random_range( 5, 50 );
		std::cout << rand_value << " ";
        Q.push(rand_value);
    }
    std::cout << std::endl;
    std::cout << "Size of Queue is :" << Q.size() << std::endl;
    std::cout << "\nPopping queue values :\n";
    while ( !Q.empty() ) {
        std::cout << Q.top() << " ";
        Q.pop();
    }
    std::cout << std::endl;
    return 0;
}