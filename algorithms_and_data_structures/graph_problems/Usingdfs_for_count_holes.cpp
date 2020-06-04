#include<iostream>
/*The size of the wall is given first input r c(row, col) 0 means you can get through holes at least ad big as 2*2
 이 코드는 사람이 통과할 수 있는 구멍이 몇개인지를 찾는 코드 입니다. 첫 줄에 입력 받은 두 수는 벽의 row와 col을 나타냅니다. 다음에 입력 받은 0과 1의 배열을 통해 통과할 수 있는 구멍이 몇개인지를 찾는 것입니다. DFS를 사용해 구현했습니다. */
using namespace std;

void dfs(int **arr, int row, int col, int num){
	arr[row][col] = num;

	if (arr[row - 1][col] == 0){
		dfs(arr, row - 1, col, num);
	}
	if (arr[row + 1][col] == 0){
		dfs(arr, row + 1, col, num);
	}
	if (arr[row][col + 1] == 0){
		dfs(arr, row, col + 1, num);
	}
	if (arr[row][col - 1] == 0){
		dfs(arr, row, col - 1, num);
	}
}

int main(){
	int check = 0;
	int a, b;
	cin >> a >> b;
	int num = 2;

	int **array;
		array= new int*[a];

	for (int i = 0; i < a; i++){
		array[i] = new int[b];
	}

	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			cin >> array[i][j];


		}

	}

	int **realarray = new int*[a + 2];

	for (int i = 0; i < a + 2; i++){
		realarray[i] = new int[b + 2];
	}
	for (int i = 0; i < a + 2; i++){
		for (int j = 0; j < b + 2; j++){
			realarray[i][j] = 1;
		}
	}


	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			realarray[i + 1][j + 1] = array[i][j];
		}
	}

	for (int i = 0; i < a + 2; i++){
		for (int j = 0; j < b + 2; j++){
			if (realarray[i][j] == 0){
				dfs(realarray, i, j, num);

				num++;
			}
		}
	}



	for (int i = 0; i < a + 2; i++){
		for (int j = 0; j < b + 2; j++){
			if (realarray[i][j] != 1){
				int checking = realarray[i][j];

				if (realarray[i][j] == checking && realarray[i + 1][j] == checking && realarray[i][j + 1] == checking && realarray[i + 1][j + 1] == checking){
					check++;


					for (int c = 0; c < a + 2; c++){

						for (int d = 0; d < b + 2; d++){
							if (realarray[c][d] == checking){

								realarray[c][d] = 1;
							}
						}
					}
				}
			}

		}

	}



	cout << check;


	for (int i = 0; i < a + 2; i++){
		delete[] realarray[i];
	}
	 delete[]realarray;



	for (int i = 0; i < a; i++){
		 delete[] array[i];
	}
	 delete[]array;
	return 0;
}
