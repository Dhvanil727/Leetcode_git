class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time=0;
        int count=0;
        int pos=k;
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]>=tickets[k]){
                time+=tickets[k];
                count++;
            }else{
                time+=tickets[i];
                if(i<k) pos--;
                
            }
        }
        time=(time-(count-pos-1));
        return time;
    }
};