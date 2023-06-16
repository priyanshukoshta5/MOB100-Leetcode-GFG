// class Solution {
// private:
//     long long MOD = 1000000007;

//     long long nCr(long long n, long long r){
//         if(r == 0 || r == n)
//             return 1LL;

//         long double val = 1;
//         for(long long i = 0; i < r; i++)
//             val = (val * (n-i)) / (i+1);
//         long long res = val;
//         // if(res == 0)
//         //     cout<<"nCr : "<<n<<" "<<r<<endl;
//         return res % 1000000007;
//     }

//     long long numOfWays(vector<int>& nums, long long lb, long long ub, long long cur){
//         if(cur == -1 || lb >= ub)
//             return 1;

//         long long left_elements = nums[cur] - lb;
//         long long right_elements = ub - nums[cur];
//         long long total_elements = left_elements + right_elements;

//         long long total_ways = nCr(total_elements, left_elements) % MOD;

//         long long just_chota_first_element_index = -1;
//         long long i = cur+1;
//         while(i < nums.size() && (nums[i] > nums[cur] || nums[i] < lb))
//             i++;
//         if(i < nums.size())
//             just_chota_first_element_index = i;

//         long long just_bada_first_element_index = -1;
//         i = cur+1;
//         while(i < nums.size() && (nums[i] < nums[cur] || nums[i] > ub))
//             i++;
//         if(i < nums.size())
//             just_bada_first_element_index = i;

//         long long left = numOfWays(nums, lb, nums[cur]-1, just_chota_first_element_index) % MOD;
//         long long right = numOfWays(nums, nums[cur]+1, ub, just_bada_first_element_index) % MOD;
//         long long total_left_right = (left * right) % MOD;

//         // cout<<nums[cur]<<" "<<left<<" "<<right<<" "<<total_ways<<" : "<<lb<<" "<<ub<<endl;

//         return (total_ways * total_left_right) % MOD;
//     }

// public:
//     int numOfWays(vector<int>& nums) {
//         long long lower_bound = 1;
//         long long upper_bound = nums.size();

//         return numOfWays(nums, lower_bound, upper_bound, 0) - 1;
//     }
// };


// Editorial
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int m = nums.size();
        // Table of Pascal's triangle
        table.resize(m + 1);
        for(int i = 0; i < m + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        return (dfs(nums) - 1) % mod;
    }
    
private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;
    
    long long dfs(vector<int> &nums){
        int m = nums.size();
        if(m < 3) {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for(int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
		
        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;
		
        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
};