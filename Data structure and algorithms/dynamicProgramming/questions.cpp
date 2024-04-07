#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int calculateFibo(int n, vector<int> &dp){
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = calculateFibo(n-1, dp) + calculateFibo(n-2,dp);
    return dp[n];
}
pair<int,vector<int>>getFibonacii(int n){
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    int nthFib = calculateFibo(n, dp);
    return make_pair(nthFib, dp);
}

int calcCost(int n, vector<int> &cost, vector<int> &dp){
    if(n == 1 || n == 0){
        return cost[n];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = min(calcCost(n-1, cost, dp), calcCost(n-1, cost, dp)) + cost[n];
    return dp[n];
}

int calcCost2(int n, vector<int> &cost){
    vector<int> dp(n+1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int calcCost3(int n, vector<int> &cost){
    int prev2 = cost[0];
    int prev1 = cost[1];
    int curr;

    for(int i = 2; i < n; i++){
        curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}
int minimumCostStairs(vector<int> &cost){
    int n = cost.size();
    vector<int>dp(n+1, -1);

    // return min(calcCost(n-1, cost, dp), calcCost(n-2, cost, dp));
    // return calcCost2(n, cost);
    return calcCost3(n, cost);
}

int main() {
    // int n;
    // cout<<"Enter a number : ";
    // cin>>n;

    // pair<int, vector<int>> ans = getFibonacii(n);
    // cout<<n<<"th fibonacii is "<<ans.first<<endl;
    // cout<<"All fibonacci are : ";
    // printVector(ans.second);

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<minimumCostStairs(cost)<<endl;
    return 0;
}