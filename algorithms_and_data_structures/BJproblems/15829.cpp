#include <iostream>
#include <cmath>

#define ll long long int

ll get_pow(ll _i){
    ll pow = 1;
    for(ll i = 0; i < _i; i++){
        pow = (pow * 31) % 1234567891;
    }
    return pow;
}

int main(){
    ll length;
    scanf("%d", &length);
    char input[50];
    scanf("%s",input);
    
    ll sum = 0;
    for(ll i = 0; i < length; i++){
        sum = ( sum + (input[i] - 'a' + 1) * get_pow(i) ) % 1234567891;
    }
    printf("%lld", sum);
}
