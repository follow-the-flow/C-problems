#include<iostream>
#include"myqueriable.h"

using namespace std;

int main(){
    int arr[] = {1, 4, 6, 2, 10};
    auto out = from(arr)
        .where([](int x){return x > 2 && x < 10;})
        .apply([](int x){return x * 2;})
        .sum();
    cout << out << endl;
}
