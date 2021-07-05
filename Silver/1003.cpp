
// 1003. 피보나치 함수
// 출력 값의 규칙을 찾으면 간단한 문제
// 문제에서는 피보나치 함수를 재귀로 표현을 해놨으나, 사실은 DP로 바꿔서 풀어야 하는 문제

#include <iostream>
using namespace std;

int fiboArray[50] = {0, 1, };

int fibonacci(int n){
    if(n <= 1){
        return fiboArray[n];
    }else if(fiboArray[n] == 0){
        fiboArray[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return fiboArray[n];
}

int main(){
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++){
        int input;
        cin >> input;
        if(input == 0){
            cout << "1 0" << endl;
        }else{
            cout << fibonacci(input - 1) << ' ' << fibonacci(input) << endl;
        }
    }
}
