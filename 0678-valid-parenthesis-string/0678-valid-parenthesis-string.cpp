class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> at;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open.push(i);
            }else if(s[i]=='*'){
                at.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(open.empty() && !at.empty()){
                    at.pop();
                }else{
                    return false;
                }
            }
        }
       while (!open.empty()) {
    if (at.empty()) {
        return false;
    }
    int openindex = open.top();  // Retrieve top element
    int asteriskindex = at.top(); // Retrieve top element
    open.pop();                  // Remove top element
    at.pop();                    // Remove top element

    if (openindex > asteriskindex) {
        return false;
    }
}

        return open.empty();
    }
};