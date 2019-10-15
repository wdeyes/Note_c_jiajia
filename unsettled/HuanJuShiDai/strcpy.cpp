#include <iostream>
using namespace std;

char* mystrcpy(char* src, char* dst){
    if(src!=nullptr){
        int i=0;
       char* temp=dst;
        while(src[i]!='\0'){
            *temp=src[i];
            ++temp;
            ++i;
        }
        *temp='\0';
        return dst;
    }
    return nullptr;
}

int main() {
    char str[]="hello";
    for(int i=0; str[i]!='\0'; ++i)
        cout << str[i];
    cout << endl;

    for(char* temp=str; *temp!='\0'; ++temp)
        cout << *temp;
    cout << endl;

    char dst[]="";
    
    mystrcpy(str, dst);

    cout << dst << endl;
}