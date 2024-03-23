#include<iostream>

double myPower(int x, long long n){
    if(n==0){return 1.0;}
    if(n<0){
        x = 1/x;
        n = -n;
    }

    if(n % 2 == 0){
        double temp = myPower(x, n/2);
        return temp * temp;
    }
    else{
        return x * myPower(x, n-1);
    }
}

int main(){
    double x1 = 2;
    int n = -4;
    std::cout<< myPower(x1, n);
    return 0;
}