// ~MarkSPhilip31

class Solution {
public:
    unordered_map<int, vector<int>> prime2index;
    unordered_map<int, vector<int>> index2prime;
    void dfs(int index, vector<int>& visitedIndex, unordered_map<int,bool>& visitedPrime){
        if(visitedIndex[index] == true) return;
        visitedIndex[index] = true;

        for(auto &prime : index2prime[index]){
            if(visitedPrime[prime] == true) 
                continue;
            visitedPrime[prime] = true;
            for(auto &index1 : prime2index[prime]){
                if(visitedIndex[index1] == true) continue;
                dfs(index1, visitedIndex, visitedPrime);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int temp = nums[i];
            for (int j = 2; j*j <= nums[i]; j++) {
                if (temp % j == 0) {
                    prime2index[j].push_back(i);
                    index2prime[i].push_back(j);
                    while (temp % j == 0)
                      temp /= j;
                }
            }
            if (temp > 1) {
                prime2index[temp].push_back(i);
                index2prime[i].push_back(temp);
            }
        }

        vector<int> visitedIndex(nums.size(),0);
        unordered_map<int,bool> visitedPrime;
        dfs(0, visitedIndex, visitedPrime);     

        for(int i=0; i<visitedIndex.size(); i++) 
            if(visitedIndex[i] == false) 
                return false;
        return true;    
    }
};




// class DisjointSet{
//     private:
//         vector<int> parent, size;
//     public:
//         DisjointSet(int n){
//             parent.resize(n+1);
//             size.resize(n+1);
//             for(int i=0; i<n; i++)
//             {
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
    
//         int getUltParent(int node){
//             if(node == parent[node])
//                 return node;
//             return parent[node] = getUltParent(parent[node]);
//         }
    
//         void unionBySize(int u, int v){
//             int p1 = getUltParent(u);
//             int p2 = getUltParent(v);
//             if(p1 == p2)
//                 return;
//             else if(size[p1] >= size[p2])
//             {
//                 size[p1] += size[p2];
//                 parent[p2] = p1;
//                 parent[v] = p1;
//             }
//             else
//             {
//                 size[p2] += size[p1];
//                 parent[p1] = p2;
//                 parent[u] = p2;
//             }
//         }
    
//         int getSize(int node){
//             return size[node];
//         }
// };

// class Solution {
// public:
//     bool canTraverseAllPairs(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return true;
        
//         DisjointSet ds(n);
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i] == 1)
//                 return false;
//             for(int j=i+1; j<nums.size(); j++)
//             {
//                 int gcd = __gcd(nums[i], nums[j]);
//                 // if(gcd > 1)
//                     // cout<<nums[i]<<" "<<nums[j]<<endl;
//                 if(gcd > 1)
//                     ds.unionBySize(i, j);
//             }
//         }
        
//         set<int> st;
//         for(int i=0; i<n; i++)
//         {
//             int pp = ds.getSize(ds.getUltParent(i));
//             st.insert(pp);
//             // cout<<pp<<" "<<" "<<ds.getUltParent(i)<<endl;
//             if(pp == 1)
//                 return false;
//         }
//         // cout<<endl;
        
//         return st.size() == 1;
//     }
// };