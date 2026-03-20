#include <iostream>
using namespace std;

void helper(int n){
    if (n==0) return;
    cout<<"Hola!"<<endl;

    helper(n-1);
}

int main(){
    int n;
    cin>>n;
    helper(n);
    return 0;
}