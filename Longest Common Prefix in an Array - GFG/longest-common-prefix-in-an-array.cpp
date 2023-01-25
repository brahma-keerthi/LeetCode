//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string small = "zzz";
        string big = "aaa";
        
        for(int i = 0; i<N; ++i){
            if ( small > arr[i] )
                small = arr[i];
            if ( big < arr[i] )
                big = arr[i];
        }
        
        int i = 0;
        string ans = "";
        while ( big[i] == small[i] ){
            ans += big[i++];
        }
        
        if ( ans == "")
            return "-1";
        else
            return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends