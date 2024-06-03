#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> &arr) {
  cout<<endl<<endl;
  int n = arr.size();
  if(n == 0){
    cout<<"Vector is empty"<<endl;
    return;
  }
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
} 

bool isRotated(string str1, string str2){
  int size = str1.size();
  if(size <= 1)
    return str1 == str2;
  
  string cmp = "";
  string pre = str1.substr(0, 2);
  for(int i = 2; i < size; i++)
    cmp += str1[i];

  cmp += pre;
  if(cmp == str2)
    return true;
  
  cmp = str1.substr(size-2, 2);
  for(int i = 0; i < size-2; i++)
    cmp += str1[i];

  if(cmp == str2)
    return true;

  return false;
}

bool checkIfPangram(string sentence) {
  vector<bool> arr(26, false);
  int size = sentence.size();
  for(int i = 0; i < size; i++){
    arr[sentence[i]-97] = true;
  }
  for(int i = 0; i < 26; i++)
    if(arr[i])
      return false;

  return true;
}

int longestPalindrome(string s) {
  vector<int> lower(26, 0), upper(26, 0);
  int n = s.size(), ans = 0;
  bool hasOdd = false;

  for(int i = 0; i < n; i++){
    if(s[i] >= 'a')
      lower[s[i]-'a']++;
    else
      upper[s[i]-'A']++;
  }

  for(int i = 0; i < 26; i++){
    if(upper[i] % 2 == 0)
      ans += upper[i];
    else{
      ans += upper[i] - 1;
      hasOdd = true;
    }

    if(lower[i] % 2 == 0)
      ans += lower[i];
    else{
      ans += lower[i] - 1;
      hasOdd = true;
    }     
  }

  ans = hasOdd ? ans+1 : ans;
  return ans;
}

string sortSentence(string s) {
  vector<string> vs(10, "-1");
  string temp = "";
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] == ' ' || i == n-1){
      int pos;
      if(i == n-1){
        pos = s[i] - '0';
      }else{
        pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
      }
      vs[pos] = temp;
      temp = "";
    }
    else{
      temp += s[i];
    }
  }

  s = "";
  for(int i = 1; i < 10; i++){
    if(vs[i] != "-1")
      s.append(vs[i] + " ");
  }
  s.pop_back();
  return s;
}

string sortVowels(string s) {
  vector<int> lower(26, 0);
  vector<int> upper(26, 0);
  int n = s.size();
  string vowels = "";

  for(int i = 0; i < n; i++){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      lower[s[i] - 'a']++;
      s[i] = '#';
    }
    else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
      upper[s[i] - 'A']++;
      s[i] = '#';
    }
  }

  for(int i = 0; i < 26; i++){
    char ch = i+'A';
    while(upper[i]){
      vowels += ch;
      upper[i]--;
    }
  }

  for(int i = 0; i < 26; i++){
    char ch = i+'a';
    while(lower[i]){
      vowels += ch;
      lower[i]--;
    }
  }

  int idx = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '#'){
      s[i] = vowels[idx];
      idx++;
    }
  }

  return s;
}

string addStrings(string num1, string num2) {
  string ans = "";
  int i = num1.size()-1, j = num2.size()-1;
  int carry = 0;
  while(i >= 0 || j >= 0){
    int sum = carry;
    if(i >= 0)
      sum = sum + (num1[i] - '0');

    if(j >= 0)
      sum = sum  +(num2[j] - '0');
        
    ans.push_back('0'+(sum%10));
    carry = sum/10;
    i--, j--;
  }
  if(carry)
    ans.push_back('0'+carry);
  
  reverse(ans.begin(), ans.end());
  return ans;
}

string caseSort(string s, int n){
  vector<int> lower(26, 0);
  vector<int> upper(26, 0);
  string l = "", u = "";

  for(int i = 0; i < n; i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      lower[s[i] - 'a']++;
      s[i] = '*';
    }
    else if(s[i] >= 'A' && s[i] <= 'Z'){
      upper[s[i] - 'A']++;
      s[i] = '#';
    }
  }

  for(int i = 0; i < 26; i++){
    char ch = i+'A';
    while(upper[i]){
      u += ch;
      upper[i]--;
    }
  }

  for(int i = 0; i < 26; i++){
    char ch = i+'a';
    while(lower[i]){
      l += ch;
      lower[i]--;
    }
  }

  int uidx = 0, lidx = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '#')
      s[i] = u[uidx++];
    else if(s[i] == '*')
      s[i] = l[lidx++];
  }

  return s;
}

int main() {
  // string str;
  // cout<<"Enter a string : ";
  // cin>>str;
  // str.sub
  // isRotated("p", "q");
  // cout<<checkIfPangram("thequickbrownfoxjumpsoverthelazydog")<<endl;
  // cout<<sortVowels(str)<<endl;

  // cout<<'0'-'0'<<endl;
  // cout<<'9'-'0'<<endl;
  // cout<<'8'-'0'<<endl;
  return 0;
}