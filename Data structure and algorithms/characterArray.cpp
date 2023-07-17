#include <iostream>
#include <vector>
using namespace std;

void printCharVector(vector<char>arr, int size){
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printIntArray(int arr[], int size){
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getLength(char ch[]){
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++){
        count++;
    }
    return count;
}

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        return ch - 'A' + 'a';
    }
}

void reverseString(char ch[], int size){
    int s = 0;
    int e = size-1;
    while(s<e){
        swap(ch[s++], ch[e--]);
    }
}

bool checkPalindrome(char ch[], int size){
    int s = 0;
    int e = size-1;
    while(s<=e){
        if(!((ch[s] >= 'a' && ch[s] <= 'z') || (ch[s] >= 'A' && ch[s] <= 'Z') || (ch[s] >= '0' && ch[s] <= '9'))){
            s++;
            continue;
        }
        if(!((ch[e] >= 'a' && ch[e] <= 'z') || (ch[e] >= 'A' && ch[e] <= 'Z') || (ch[e] >= '0' && ch[e] <= '9'))){
            e--;
            continue;
        }

        if(toLowerCase(ch[s]) != toLowerCase(ch[e])){
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
}

void reverseWord(vector<char>& ch){
    int initial = 0;
    for(int i = 0; i <= ch.size(); i++){
        if(ch[i] == ' ' || ch[i] == '\0'){
            int s = initial;
            int e = i - 1;
            while(s<e){
                swap(ch[s++], ch[e--]);
            }
            initial = i+1;
        }
    }
}

char getMaxOccCharacter(string s){
    int arr[26] = {0};
    for(int i = 0; i < s.length(); i++){
        int num;
        if(s[i] >= 'a' && s[i] <= 'z'){//lowercase
            num = s[i] - 'a';
        }else{//uppercase
            num = s[i] - 'A';
        }
        arr[num]++;
    }

    int maxi = -1, index = 0;
    for(int i = 0; i < 26; i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            index = i;
        }
    }
    char ans = 'a'+index;
    return ans;
}

void replaceSpaces(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            str.replace(i, 1, "@40");
        }
    }
}

void removeOccurances(string &s, string part){
    while (s.length() > 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    
}

//*****************************************************************************start
// revise it 
bool checkEqual(int a[26], int b[26]){
    for(int i = 0; i < 26; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

bool containPermutation(string s1, string s2){
    int count1[26] = {0};
    for(int i = 0; i < s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    while(i < windowSize && i < s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count1, count2)){
        return 1;
    }

    while(i < s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        
        i++;

        if(checkEqual(count1, count2)){
            return 1;
        }
    }

    return 0;
}
//*****************************************************************************end

// ***********************************************************start
//revise it again
string removeAdjDuplicate(string s){
    string temp = "";
    int i = 0;

    while(i < s.length()){
        if(temp.empty() || s[i] != temp.back()){
            temp.push_back(s[i]);
        }else{
            temp.pop_back();
        }
        i++;
    }
    return temp;
}
// ***********************************************************end

int compression(char ch[], int size){
    int i = 0;
    int n = size;
    int ansIndex = 0;

    while(i < n){
        int j = i + 1;
        while(j < n && ch[i] == ch[j]){
            j++;
        }
        ch[ansIndex++] = ch[i];
        int count = j - i;
        if(count > 1){
            string st = to_string(count);
            for(char s : st){
                ch[ansIndex++] = s;
            }   
        }
        
        i = j;
    }
    return ansIndex;
}



int main(){
    // char ch[30];
    // cout<<"Enter a string : ";
    // cin>>ch;
    // int size = getLength(ch);
    // cout<<ch<<endl;
    // cout<<getLength(ch)<<endl;
    // cout<<toLowerCase('a')<<endl;
    // cout<<toLowerCase('A')<<endl;
    

    // reverseString(ch, size);
    // cout<<ch<<endl;

    // cout<<"Palindrome or not : "<<checkPalindrome(ch, size)<<endl;

    // vector<char> ch2 = {'T','h','e',' ','m','a','n',' ','i','s',' ','a',' ','h','u','n','t','e','r'};
    // reverseWord(ch2);
    // printCharVector(ch2, ch2.size());

    // string s;
    // cout<<"Enter the string : "<<endl;
    // cin>>s;
    // cout<<getMaxOccCharacter(s)<<endl;


    // string s,part;
    // cout<<"Enter a string : ";
    // getline(cin, s);
    // cout<<"Enter the part : ";
    // getline(cin, part);
    // // replaceSpaces(s);
    // // removeOccurances(s, part);
    // cout<<containPermutation(s, part)<<endl;
    // cout<<s<<endl;


    string s;
    cout<<"Enter the string : ";
    getline(cin, s);
    cout<<removeAdjDuplicate(s)<<endl;

    // char ch[30];
    // cout<<"Enter a string : ";
    // cin>>ch;
    // int size = getLength(ch);
    // cout<<compression(ch, size)<<endl;

    // char ch[26] = {'A','B','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // for(int i = 0; i < 26; i++){
    //     cout<<ch[i]-'a'<<" ";
    // }
    // cout<<endl;
    return 0;
}