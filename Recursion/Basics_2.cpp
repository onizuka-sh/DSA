//print 1 to N numbers

#include <iostream>
using namespace std;

void helper(int n,int curr){
    if (curr>n)return;

    cout<<curr<<endl;

    helper(n,++curr);
}

int main(){
    int n;
    cin>>n;

    helper(n,1);

    return 0;
}