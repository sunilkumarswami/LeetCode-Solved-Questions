class Solution {
public:
    int maxPalindromes(string s, int k) {
        int count=0,n=s.size();
        int i=k-1,ind=0;
        while(i<n){
            for(int j=i-k+1;j>=max(0,ind);j--){
                int l=j,r=i;
                while(l<=r){
                    if(s[l]!=s[r]) break;
                    l++,r--;
                }
                if(l>=r){
                    count++;
                    ind=i+1;
                    i+=k-1;
                    break;
                }
            }
            i++;
        }
        return count;
    }
};