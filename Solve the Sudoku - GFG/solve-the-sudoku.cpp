//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    private:
    bool row[9][9];
    bool col[9][9];
    bool box[3][3][9];
    
    bool solve(int r, int c, int grid[N][N]){
        if(r == 9 && c == 0)    // answer found
            return true;
            
        int newR = r;
        int newC = c;
        if(c < 8)
            newC++;
        else
        {
            newR++;
            newC = 0;
        }
        
        if(grid[r][c] != 0)
            return solve(newR, newC, grid);
        
        for(int i = 1; i <= 9; i++)
        {
            if(row[r][i - 1] == false && col[c][i - 1] == false && box[r/3][c/3][i - 1] == false)
            {
                row[r][i - 1] = true;
                col[c][i - 1] = true;
                box[r/3][c/3][i - 1] = true;
                grid[r][c] = i;
                
                if(solve(newR, newC, grid) == true)
                    return true;
                    
                row[r][i - 1] = false;
                col[c][i - 1] = false;
                box[r/3][c/3][i - 1] = false;
                grid[r][c] = 0;
            }
        }
        
        return false;
    }
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(grid[i][j] != 0)
                {
                    // marking row
                    if(row[i][grid[i][j] - 1] != false) return false;
                    else row[i][grid[i][j] - 1] = true;
                    
                    // marking col
                    if(col[j][grid[i][j] - 1] != false) return false;
                    else col[j][grid[i][j] - 1] = true;
                    
                    // marking 3x3 box
                    if(box[i/3][j/3][grid[i][j] - 1] != false) return false;
                    else box[i/3][j/3][grid[i][j] - 1] = true;
                }
            }
        }
        
        return solve(0, 0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends