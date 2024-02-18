#include<stdio.h>

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        return ch - 'A' + 'a';
    }
}

int main(){
    char c;
    printf("Enter any character : ");
    scanf("%c", &c);

    char ch = toLowerCase(c);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        printf("%c is vowel\n", c);
    }else{
        printf("%c is consonant\n", c);
    }

    return 0;

}