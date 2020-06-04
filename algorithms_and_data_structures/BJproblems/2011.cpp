#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int

int main(){
    char input[5005];
    ll output[5005];   memset(output, 0, 5005 * sizeof(ll));
    scanf("%s",input);
    
    int length = strlen(input);
    output[length] = 1;

    if(input[length -1] == '0') output[length - 1] = 0;
    else output[length -1 ] = 1;

    for(int i = length - 2; i >= 0; i--){
        int tmp_num = (input[i] - '0')*10 + input[i+1] - '0';
        //check impossible
        if( tmp_num == 0 ){ printf("0"); return 0;}
        else if( input[i] == '0'){
            output[i] = 0;
        }else{
            if (input[i+1] == '0' && tmp_num > 26){printf("0"); return 0;}
            if( tmp_num > 26 || tmp_num < 1) output[i] = output[i+1];
            else output[i] = (output[i+1] + output[i+2]) % 1000000;
        }            
    }
    printf("%lld",output[0] % 1000000);
}
