#include<iostream>
using namespace std;
int main()
{
    string inputText;
    int inputTextLength;int vowel=0;
    int consonent=0;
    int value=0;
    getline (cin, inputText);
    inputTextLength=inputText.size();
    for(int i=0; i<inputTextLength; i++)
    {
        value=inputText[i];
        if(value==65 || value==69|| value==73|| value==79|| value==85|| value==97|| value==101|| value==105|| value==111|| value==117) vowel++;
        else if((value>=66 && value<=90 && value !=69&& value !=73&& value !=79&& value !=85) || (value>=98 && value<=122 && value !=101&& value !=105&& value !=111&& value !=117)) consonent++;

    }

    cout<<"Number Of Vowels: "<<vowel<<endl;
    cout<<"Number Of Consonant: "<<consonent<<endl;

    return 0;
}
