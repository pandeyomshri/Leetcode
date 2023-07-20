//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
         unordered_map<char,int>mp;
            char ans='$';

        for(int i=0;i<S.length();i++){
           if(mp.find(S[i])==mp.end()){
               mp.insert(make_pair(S[i],1));
           }
           else{
               mp[S[i]]++;
           }
        }
        for(int i=0;i<S.length();i++){
            if(mp[S[i]]==1)
            return S[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends