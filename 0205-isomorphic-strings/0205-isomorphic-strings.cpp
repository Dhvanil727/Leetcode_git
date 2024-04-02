#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        if (s.length() != t.length()) {
            return false;
        }
        for(int i=0;i<s.length();i++){
            char original=s[i],replacement=t[i];
            if(m1.find(original)!=m1.end()){
                if(m1[original]!=replacement){
                    return false;
                }
            }else{
                if(m2.find(replacement)!=m2.end()){
                    return false;
                }
                m1[original]=replacement;
                m2[replacement]=original;
            }
        }
        return true;
        }

        
    
};
