/*** 
 *     _  __                ___      _                                   
 *     | |/ /___ ___ _ __   / __|__ _| |_ __                              
 *     | ' </ -_) -_) '_ \ | (__/ _` | | '  \
 *     |_|\_\___\___| .__/  \___\__,_|_|_|_|_|                            
 *                  |_|                                                   
 *                   _                                                    
 *      __ _ _ _  __| |                                                   
 *     / _` | ' \/ _` |                                                   
 *     \__,_|_||_\__,_|                                                   
 *                                                                        
 *      _                          _   _              _ _   _             
 *     | |   ___ __ _ _ _ _ _     /_\ | |__ _ ___ _ _(_) |_| |_  _ __  ___
 *     | |__/ -_) _` | '_| ' \   / _ \| / _` / _ \ '_| |  _| ' \| '  \(_-<
 *     |____\___\__,_|_| |_||_| /_/ \_\_\__, \___/_| |_|\__|_||_|_|_|_/__/
 *                                      |___/                             
 *     Yeah! Ravi let's do it! 
 */


#include <bubbleSort.h>	//do not assume people will have their path set
#include <generic.h>
#include <stdlib.h>
#include <time.h>

//bubble sort는 배우 비효율 적이니 배열 내 원소의 수가 매우 적을 때만 사용하시오.
int main()
{
    const int MAX_ELEMENTS = 10;
    int arr[MAX_ELEMENTS];
    double arrD[MAX_ELEMENTS];
	srand(time(0));
	
    //배열에 랜덤 숫자들로 채워 넣는다.
    for (int i = 0; i < MAX_ELEMENTS; ++i)
    {   
        // arr[i] = algo::random_range(1, 100);	//does not generate random number everytime  
        //arrD[i] = algo::random_range(1.0, 99.99);	//does not generate random
		arr[i] = rand() % 100 + 1;		//1부터 100까지의 수로 arr을 채워 넣는다.
		double f = (double)rand() / RAND_MAX;	
		arrD[i] = 1.0 + f * (99.99 - 1.0);	// 1.0부터 99.99까지의 수로 랜덤수를 arrD에 채워 넣는다. 
    }

    std::cout << "Before Sorting:\n";	//정렬하기 전의 배열의 상태를 보여준다.
    algo::printList(arr, MAX_ELEMENTS);
    algo::bubbleSort(arr, 0, MAX_ELEMENTS - 1);	//정렬 후의 배열 상태를 보여준다.
    std::cout << "After Sorting:\n";
    algo::printList(arr, MAX_ELEMENTS);


    std::cout << "\n\nBefore Sorting:\n";	// 실수 범위에 대해서 위과 같은 과정을 반복한다.
    algo::printList(arrD, MAX_ELEMENTS);
    algo::bubbleSort(arrD, 0, MAX_ELEMENTS - 1);
    std::cout << "After Sorting:\n";
    algo::printList(arrD, MAX_ELEMENTS);
    return 0;
}

