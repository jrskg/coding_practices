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

int value(char ch){
  if(ch == 'I') return 1;
  else if(ch == 'V') return 5;
  else if(ch == 'X') return 10;
  else if(ch == 'L') return 50;
  else if(ch == 'C') return 100;
  else if(ch == 'D') return 500;
  else return 1000;
}
int romanToInt(string s) {
  int ans = 0, n = s.size();
  for(int i = 0; i < n-1; i++){
    int first = value(s[i]);
    int second = value(s[i+1]);
    if(second > first)
      ans -= first;
    else
      ans += first;
  }
  ans += value(s[n-1]);
  return ans;
}

string intToRoman(int num) {
  unordered_map<int, string>map;
  map = {
    {1, "I"},{2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}, {10, "X"},
    {20, "XX"},{30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"}, {100, "C"},
    {200, "CC"},{300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {1000, "M"},
    {2000, "MM"},{3000, "MMM"}
  };

  string ans = "";
  int mod, val;
  if(num > 999){
    mod = num % 1000;
    val = num - mod;
    ans += map[val];
    num = mod;
  }
  if(num <= 999 && num > 99){
    mod = num % 100;
    val = num - mod;
    ans += map[val];
    num = mod;
  }
  if(num <= 99 && num > 9){
    mod = num % 10;
    val = num - mod;
    ans += map[val];
    num = mod;
  }
  ans += map[num];
  return ans;
}

vector<int> factorial(int N){
  vector<int> ans(1, 1);
  while(N > 1){
    int carry = 0, size = ans.size(), res;
    for(int i = 0; i < size; i++){
      res = (ans[i] * N) + carry;
      carry = res / 10;
      ans[i] = res % 10;
    }
    
    while(carry){
      ans.push_back(carry % 10);
      carry /= 10;
    }
    N--;
  }
  
  reverse(ans.begin(), ans.end());
  return ans;
}

int lengthOfLongestSubstring(string s) {
  int n = s.size(), ans = 0;
  int i = 0, j = 0;
  unordered_map<char, bool> map;

  while(i < n && j < n){
    if(map[s[j]]){
      while(s[i] != s[j]){
        map[s[i]] = false;
        i++;
      }
      i++;
    }
    map[s[j]] = true;
    j++;
    ans = max(ans, j-i);
  }

  return ans;
}

int findSubStringSamllestWindow(string s){
  unordered_map<char, int> map;
  int i = 0, j = 0, n = s.size(), ans = n;
  for(int i = 0; i < n; i++){
    map[s[i]] = 0;
  }
  int diff = map.size();

  while(j < n){
    while(diff > 0 && j < n){
      if(map[s[j]] == 0){
        diff--;
      }
      map[s[j]]++;
      j++;
    }
    
    while(diff == 0){
      ans = min(ans, j-i);
      map[s[i]]--;
      if(map[s[i]] == 0){
        diff++;
      }
      i++;
    }
  }
  
  return ans;
}

int smallestSubstring(string S) {
  //s = "11220012 only 0, 1, 2"
  vector<int> v(3, 0);
  int i = 0, j = 0, n = S.size(), diff = 3, ans  = n;
  
  while(j < n){
    while(diff > 0 && j < n){
      if(v[S[j]-'0'] == 0)
        diff--;
      v[S[j]-'0']++;
      j++;
    }
    
    while(diff == 0){
      ans = min(ans, j-i);
      v[S[i]-'0']--;
      if(v[S[i]-'0'] == 0)
        diff++;
      i++;
    }
  }
  
  if(i == 0 && j >= n && diff != 0) return -1;
  return ans;
}

int longestKSubstr(string s, int k) {
  unordered_map<char, int> map;
  int n = s.size(), i = 0, j = 0, ms = 0, ans = -1;
  
  for(int i = 0; i < n; i++){
    map[s[i]] = 0;
  }
  
  while(j < n){
    while(ms <= k && j < n){
      if(map[s[j]] == 0)
        ms++;
          
      map[s[j]]++;
      j++;
      if(ms == k)
        ans = max(ans, j-i);
    }
    
    while(ms > k){
      map[s[i]]--;
      if(map[s[i]] == 0)
        ms--;
          
      i++;
    }
  }
  
  return ans;
}

string revStr(string str, int size){
  string ans = "";
  for(int i = size-1; i >= 0; i--)
    ans.push_back(str[i]);

  return ans;
}
int longestPrefixSuffix(string s) {
  int n = s.size();
  int i = 0, j = n-1;
  string pre = "", suff = "";
  int ans = 0;
  
  while(i < n - 1 && j > 0){
    pre.push_back(s[i]);
    suff.push_back(s[j]);
    
    if(pre == revStr(suff, n-j)){
      ans = max(ans, i+1);
    }
      
    i++, j--;
  }
  
  return ans;
}

int lpsUsingKMP(string s) {
  int n = s.size();
  vector<int> v(n);
  v[0] = 0;
  int pre = 0, suff = 1;

  while(suff < n){
    if(s[pre] == s[suff]){
      v[suff] = pre + 1;
      pre++, suff++;
    }else{
      while(pre != 0){
        pre = v[pre-1];
        if(s[pre] == s[suff]){
          v[suff] = pre + 1;
          pre++;
          break;
        }
      }
      if(pre == 0)
        v[suff] = 0;
          
      suff++;
    }
  }

  return v[n-1];
}

int strStr(string haystack, string needle) {
  int len = needle.size();
  int len2 = haystack.size();
  vector<int> lps(len);
  lps[0] = 0;
  int pre = 0, suf = 1;

  while(suf < len){
    if(needle[pre] == needle[suf]){
      lps[suf] = pre + 1;
      pre++, suf++;
    }else{
      if(pre == 0){
        lps[suf] = 0;
        suf++;
      }else{
        pre = lps[pre-1];
      }
    }
  }

  int first = 0, second = 0;
  while(first < len2){
    if(haystack[first] == needle[second]){
      first++, second++;
    }else{
      if(second == 0){
        first++;
      }else{
        second = lps[second - 1];
      }
    }

    if(second == len){
      return first - second;
    }
  }
  
  return -1;
}

vector<int> buildLps(string &str){
  int size = str.size();
  vector<int>lps(size);
  lps[0] = 0;
  int pre = 0, suf = 1;
  
  while(suf < size){
    if(str[pre] == str[suf]){
      lps[suf] = pre + 1;
      pre++, suf++;
    }else{
      if(pre == 0){
        lps[suf] = 0;
        suf++;
      }else{
        pre = lps[pre-1];
      }
    }
  }
  
  return lps;
}
vector <int> search(string pat, string txt){
  vector<int> lps = buildLps(pat);
  vector<int> ans;
  int n = txt.size(), f = 0, s = 0, pSize = pat.size();
  
  while(f < n){
    if(txt[f] == pat[s]){
      f++, s++;
    }else{
      if(s == 0){
        f++;
      }else{
        s = lps[s-1];
      }
    }
    
    if(s == pSize){
      ans.push_back(f-s+1);
    }
  }
  
  return ans;
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
  // vector<int> ans = factorial(40);
  // printVector(ans);

  string stack, needle;
  int k;
  cout<<"Enter a stack : ";
  cin>>stack;
  cout<<"Enter a needle : ";
  cin>>needle;
  // cout<<"Enter a k : ";
  // cin>>k;
  // cout<<longestKSubstr(str, k)<<endl;
  // cout<<lpsUsingKMP(str)<<endl;
  cout<<strStr(stack, needle)<<endl;

  return 0;
}