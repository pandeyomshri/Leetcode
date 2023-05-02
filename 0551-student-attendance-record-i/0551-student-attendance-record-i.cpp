class Solution {
public:
    bool checkRecord(string s) {
        bool flag=false;
        int maxL=0,temp=0;
        int A=0;

        for(int i=0;i<s.length();i++){
            if(s[i] != 'L'){
               temp=0;
            }
            if(s[i]=='L'){
                temp++;
            }

            if(s[i]=='A')
            A++;

            maxL=max(temp, maxL);
        }
        return (maxL<3 and A<2);
        
    }
};