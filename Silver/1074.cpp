
// 1074. Z

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, r, c;
    cin >> n >> r >> c;
    
    int* sumValue = new int[(int)pow(2, n)];
    int lastValue = 1;
    int lastCheck = 1;
    int lastPow = 1;
    sumValue[1] = 1;
    for(int i = 2; i < pow(2, n); i++){
        if(i == pow(2, lastPow)){
            sumValue[i] = lastValue * 4 - 1;
            lastValue = sumValue[i];
            lastCheck = 1;
            lastPow++;
        }else{
            sumValue[i] = sumValue[lastCheck];
            lastCheck++;
        }
    }
    
    int result = 0;
    
    for(int i = 0; i <= r; i++){
        result += sumValue[i] * 2;
    }
    for(int i = 0; i <= c; i++){
        result += sumValue[i];
    }
    cout << result << endl;
    delete[] sumValue;
}
