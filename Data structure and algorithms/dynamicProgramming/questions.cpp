#include <iostream>
#include <vector>

#define MOD 1000000007

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


int calculateCoins(vector<int> &nums, int x){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT32_MAX;
    }

    int mini = INT32_MAX;
    int size = nums.size();
    for(int i = 0; i < size; i++){
        int ans = calculateCoins(nums, x-nums[i]);
        if(ans != INT32_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}

int calculateCoins2(vector<int> &nums, int x, vector<int> &dp){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT32_MAX;
    }
    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT32_MAX;
    int size = nums.size();
    for(int i = 0; i < size; i++){
        int ans = calculateCoins2(nums, x-nums[i], dp);
        if(ans != INT32_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    return dp[x];
}
int minimumCoins(vector<int> &nums, int x){
    // int ans = calculateCoins(nums, x);

    vector<int> dp(x+1, -1);
    int ans = calculateCoins2(nums, x, dp);
    if(ans == INT32_MAX){
        return -1;
    }
    return ans;
}

int calcSumRec(vector<int> &nums, int n){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return nums[0];
    }

    int inc = calcSumRec(nums, n-2) + nums[n];
    int exc = calcSumRec(nums, n-1) + 0;

    return max(inc, exc);
}
int calcSumRecMemo(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int inc = calcSumRecMemo(nums, n-2, dp) + nums[n];
    int exc = calcSumRecMemo(nums, n-1, dp) + 0;

    dp[n] = max(inc, exc);

    return dp[n];
}

int calcSumTabu(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int inc = dp[i - 2] + nums[i];
        int exc = dp[i - 1] + 0;
        dp[i] = max(inc, exc);
    }

    return dp[n-1];
}

int calcSumSpace(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0, prev1 = nums[0], curr;

    for(int i = 1; i < n; i++){
        int inc = prev2 + nums[i];
        int exc = prev1;
        curr = max(inc, exc);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n , -1);
    // int ans = calcSumRec(nums, n-1);
    // int ans = calcSumRecMemo(nums, n-1, dp);
    // int ans = calcSumTabu(nums);
    int ans = calcSumSpace(nums);

    return ans;
}

long long int houseRobber(vector<int>& valueInHouse){
    int n = valueInHouse.size();
    if(n == 1){
        return valueInHouse[0];
    }
    vector<int> one(n - 1);
    vector<int> two(n - 1);

    for(int i = 0; i < n; i++){
        if(i != 0){
            one.push_back(valueInHouse[i]);
        }

        if(i != n-1){
            two.push_back(valueInHouse[i]);
        }
    }

    long long int ans1 = calcSumSpace(one);
    long long int ans2 = calcSumSpace(two);

    return max(ans1, ans2);
}

int cutRodSolveRec(int n, int x, int y, int z){
    if(n == 0)
        return 0;

    if(n < 0)
        return INT32_MIN;

    int a = cutRodSolveRec(n-x, x, y, z) + 1;
    int b = cutRodSolveRec(n-y, x, y, z) + 1;
    int c = cutRodSolveRec(n-z, x, y, z) + 1;

    return max(a,max(b, c));
}

int cutRodSolveMem(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0)
        return 0;

    if(n < 0)
        return INT32_MIN;

    if(dp[n] != -1)
        return dp[n];

    int a = cutRodSolveMem(n-x, x, y, z, dp) + 1;
    int b = cutRodSolveMem(n-y, x, y, z, dp) + 1;
    int c = cutRodSolveMem(n-z, x, y, z, dp) + 1;
    dp[n] = max(a,max(b, c));
    return dp[n];
}

int cutRodSolveTab(int n, int x, int y, int z){
	vector<int> dp(n+1, INT32_MIN);
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		int a = i-x < 0 ? INT32_MIN : dp[i-x] + 1;
		int b = i-y < 0 ? INT32_MIN : dp[i-y] + 1;
		int c = i-z < 0 ? INT32_MIN : dp[i-z] + 1;

		dp[i] = max(a, max(b, c));
	}

    printVector(dp);

	return dp[n];
}
int cutRod(int n, int x, int y, int z){
    vector<int> dp(n+1, -1);
    // int ans = cutRodSolveMem(n, x, y, z, dp);
    // int ans = cutRodSolveRec(n, x, y, z);

    int ans = cutRodSolveTab(n, x, y, z);
    if(ans < INT32_MIN){
        return 0;
    }

    return ans;
}

long long int solveDerangementRec(int n){
    if(n == 1)
        return 0;

    if(n == 2)
        return 1;

    return ((n-1) * ((solveDerangementRec(n-1))%MOD + (solveDerangementRec(n-2))%MOD) )%MOD;
}
long long int solveDerangementMem(int n, vector<long long int> &dp){
    if(n == 1)
        return 0;

    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = ((n-1) * ((solveDerangementMem(n-1, dp))%MOD + (solveDerangementMem(n-2, dp))%MOD) )%MOD;
    return dp[n];
}

long long int solveDerangementTab(int n){
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        long long int a = dp[i-1]%MOD;
        long long int b = dp[i-2]%MOD;
        long long int sum = (a+b)%MOD;
        dp[i] = ((i-1) * sum)%MOD;
    }

    return dp[n];
}

long long int solveDerangementTabSpace(int n){
    long long int prev2 = 0;
    long long int prev1 = 1; 

    for(int i = 3; i <= n; i++){
        long long int a = prev1%MOD;
        long long int b =prev2%MOD;
        long long int sum = (a+b)%MOD;
        long long int ans = ((i-1) * sum)%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n){
    vector<long long int>dp(n+1, -1);
    return solveDerangementTabSpace(n);
    // return solveDerangementTab(n);
    // return solveDerangementMem(n, dp);
    // return solveDerangementRec(n);
}

int solveKnapSackRec(vector<int> &weight, vector<int> &value, int idx, int capacity){
    if(idx == 0){
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if(weight[idx] <= capacity)
        include = value[idx] + solveKnapSackRec(weight, value, idx-1, capacity-weight[idx]);

    int exclude = solveKnapSackRec(weight, value, idx-1, capacity);
    return max(include, exclude);
}

int solveKnapSackMem(vector<int> &weight, vector<int> &value, int idx, int capacity, vector<vector<int>> &dp){
    if(idx == 0){
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if(dp[idx][capacity] != -1)
        return dp[idx][capacity];

    int include = 0;
    if(weight[idx] <= capacity)
        include = value[idx] + solveKnapSackMem(weight, value, idx-1, capacity-weight[idx], dp);

    int exclude = solveKnapSackMem(weight, value, idx-1, capacity, dp);
    dp[idx][capacity] = max(include, exclude);
    return dp[idx][capacity];
}

int solveKnapSackTab(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	for(int i = weight[0]; i <= capacity; i++){
		if(weight[0] <= i)
			dp[0][i] = value[0];
		else
			dp[0][i] = 0;
	}

	for(int i = 1; i < n; i++){
		for(int w = 0; w <= capacity; w++){
			int include = 0;
			if(weight[i] <= w){
				include = value[i] + dp[i-1][w-weight[i]];
			}
			int exclude = dp[i-1][w];

			dp[i][w] = max(include, exclude);
		}
	}

	return dp[n-1][capacity];
}
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight){
    // return solveKnapSackRec(weight, value, n-1, maxWeight);

    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return solveKnapSackMem(weight, value, n-1, maxWeight, dp);
}

int main() {
    // int n;
    // cout<<"Enter a number : ";
    // cin>>n;

    // pair<int, vector<int>> ans = getFibonacii(n);
    // cout<<n<<"th fibonacii is "<<ans.first<<endl;
    // cout<<"All fibonacci are : ";
    // printVector(ans.second);

    // vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    // cout<<minimumCostStairs(cost)<<endl;

    // vector<int> nums = {1, 2, 3};
    // int amount = 7;
    // cout<<minimumCoins(nums, amount)<<endl;

    // vector<int> valueInHouse = {0};
    // cout<<valueInHouse.size()<<endl;
    // cout<<houseRobber(valueInHouse)<<endl;

    // cutRod(7, 5, 2, 2);

    return 0;
}