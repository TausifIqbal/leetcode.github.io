//https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(const auto & ch: t){
            freq[ch]++;
        }
        int cnt=t.size();

        int n=s.size();
        int gl=n+1;
        int gs=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(freq[s[i]] > 0){
                cnt--;
            }
            freq[s[i]]--;
            
            while(cnt==0){
                int l = i-j+1;
                if(gl>l){
                    gs=j;
                    gl=l;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0){
                    cnt++;
                }
                j++;
            }
        }
        string ans = gl==(n+1)? "": s.substr(gs,gl);
        return ans;
    }
};
