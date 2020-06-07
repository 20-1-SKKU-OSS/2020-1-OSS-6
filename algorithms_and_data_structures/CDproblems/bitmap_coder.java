/* 먼저 높이와 넓이를 입력한 후에 (해상도), 0과 1로 구성된 그림을 입력하면,  
이를 비트맵 코드로 변환하여 출력합니다. 즉, 라인당 0의 갯수와 1의 갯수를 번갈아  
코드로 출력합니다. 단, 항상 각 코드 라인의 첫번째 숫자는 0의 갯수이므로,
입력하는 그림에서 1로 시작하는 라인들은 0으로 시작하는 코드를 출력합니다.

#Input1
height & width: 6 5
0 1 1 1 0 
0 0 0 0 1 
0 1 1 1 1 
1 0 0 0 1 
1 0 0 0 1 
0 1 1 1 1 

#Output1
1 3 1
4 1
1 4
0 1 3 1
0 1 3 1
1 4

*/



package bitmap_coder2;
import java.util.Scanner;
public class BitmapCoder2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int i, j, num;

        /*입력받기*/
        System.out.print("height & width:");
        int height = in.nextInt();
        int width = in.nextInt();
        String[] input_raw = new String[height];
        String dummy = in.nextLine();
        for(i=0; i<height; i++)
            input_raw[i] = in.nextLine();

        boolean previous; //true:1, false:0
        for(i=0; i<height; i++) {
            num=0;
            previous=false;
            for(j=0; j<input_raw[i].length(); j++) {
                if(input_raw[i].charAt(j)=='0') {
                    if(previous==false)
                        num++;
                    else {
                        System.out.print(num+" ");
                        previous=false;
                        num=1;
                    }
                }
                else if(input_raw[i].charAt(j)=='1') {
                    if(previous==false) {
                        System.out.print(num+" ");
                        previous=true;
                        num=1;
                    }
                    else 
                        num++;
                }
            }
            System.out.println(num);
        }
    }
}
