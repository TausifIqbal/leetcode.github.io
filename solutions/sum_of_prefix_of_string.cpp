//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

// note difference between vector and array use
class Trie{
    int freq{};
    Trie* children[26];
    public: 
        Trie():freq(0){
        memset(children, 0, sizeof(children));
        }
    
    
    
    void insert(string& s){
        Trie* cur = this;
        for(char c: s){
            if(cur->children[c-'a']==nullptr){
                cur->children[c-'a'] = new Trie();
            }
            cur = cur->children[c-'a'];
            cur->freq++;
        }
        // is_end = truel
    }

    int get_count(string& s){
        int cnt =0;
        Trie* cur = this;

        for(char &c: s){
            if(cur->children[c-'a']==nullptr){
                return cnt;
            }
            cur = cur->children[c-'a'];
            cnt += (cur->freq);

        }

        return cnt;
    }

};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        // from trie of words

        // for each prefix get the score

        Trie* trie = new Trie();
        for(auto & word: words){
            trie->insert(word);
        }
        int n=words.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = trie->get_count(words[i]);
        }
        return ans;
    }
};
