class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans;
        deque<int> dq;
        sort(deck.begin(),deck.end());
        reverse(deck.begin(),deck.end());
        dq.push_front(deck[0]);
        for(int i=1;i<deck.size();i++){
            int val=dq.back();
            dq.pop_back();
            dq.push_front(val);
            dq.push_front(deck[i]);
            
        }
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};