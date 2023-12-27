#include <iostream>
#include <map>
#include <vector>
using namespace std;

int romanToInt(string s) {
    map<char, int> mapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int total = 0;

    for(int i = 0; i < s.length(); i++){
        if(mapping[s[i]] >= mapping[s[i+1]]){
            total += mapping[s[i]];
        }else{
            total = total + mapping[s[i+1]] - mapping[s[i]];
            i++;
        }
    }

    return total;
}

int removeDuplicates(vector<int>& nums) {
    int j = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {

    // string roman = "XX";
    // cout<<romanToInt(roman)<<endl;

    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = removeDuplicates(v);
    cout<<ans<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}