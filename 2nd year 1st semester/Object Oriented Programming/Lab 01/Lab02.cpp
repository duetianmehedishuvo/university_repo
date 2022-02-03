#include <iostream>
using namespace std;

int main(){

    int number;
    int orginalNumber=0;
    int reverseNumber=0;
    int modulas;
    cin>>number;
    orginalNumber=number;
    while(number !=0){
        modulas=number%10;
        reverseNumber=reverseNumber*10+modulas;
        number=number/10;
    }
    cout<<"Original integer: "<<orginalNumber<<endl;
    cout<<"Reverse integer : "<<reverseNumber<<endl;
    return 0;
}
