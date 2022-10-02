#include<iostream>
using namespace std;


int main(){

int a;
int count=0;
cout<<"Enter the number ";
cin>>a;
for(int i=2;i<=a;i++){
    if(a%i==0){
        count++;
    }
}
if(count==1){
    cout<<"Number is primt ";
}
else{
    cout<<"Not prime";
}
    return 0;

}