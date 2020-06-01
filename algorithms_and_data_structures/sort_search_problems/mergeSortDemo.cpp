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
//원소가 랜덤으로 10개가 들어있는 배열에 대한 간단한 병합정렬코드
#include <generic.h>
#include <mergeSort.h>

int main()
{
    const int MAX_ELEMENTS = 10;
    int arr[MAX_ELEMENTS];
    double arrD[MAX_ELEMENTS];

    //Filling up the array with random numbers;
    for (int i = 0; i < MAX_ELEMENTS; ++i)
    {   
        arr[i] = algo::random_range(1, 100);
        arrD[i] = algo::random_range(1.0, 99.99);
    }

    std::cout << "정렬되기 전:\n";
    algo::printList(arr, MAX_ELEMENTS);
    algo::mergeSort(arr, 0, MAX_ELEMENTS - 1);
    std::cout << "정렬된 후:\n";
    algo::printList(arr, MAX_ELEMENTS);


    std::cout << "\n\n정렬되기 전:\n";
    algo::printList(arrD, MAX_ELEMENTS);
    algo::mergeSort(arrD, 0, MAX_ELEMENTS - 1);
    std::cout << "정렬된 후:\n";
    algo::printList(arrD, MAX_ELEMENTS);
    return 0;
}

