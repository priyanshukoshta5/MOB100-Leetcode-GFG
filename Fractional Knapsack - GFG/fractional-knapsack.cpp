//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool compare(pair<double,Item> a, pair<double,Item> b){
    return a.first > b.first;
}


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> items;
        for(int i=0; i<n; i++)
        {
            double itWt = arr[i].weight;
            double itVal = arr[i].value;
            items.push_back({itVal/itWt, arr[i]});
        }
        sort(items.begin(), items.end(), compare);
        
        double answer = 0;
        int wtLeft = W;
        for(int i=0; i<n && wtLeft>0; i++)
        {
            double itWt = items[i].second.weight;
            double itVal = items[i].second.value;
            if(wtLeft >= itWt)
            {
                answer += itVal;
                wtLeft -= itWt;
            }
            else
            {
                double wtFraction = wtLeft/itWt;
                answer += wtFraction*itVal;
                wtLeft = 0;
            }
        }
        
        return answer;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends