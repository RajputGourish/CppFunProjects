#include<iostream>
#include<vector>
using namespace std;

int Maximumprofit(vector<int>& prices){
    int n = prices.size();
    int mini = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxprofit = max(maxprofit, cost);
        mini = min(mini, prices[i]);
    }
    return maxprofit;
}
int main(){
    vector<int> prices{7,1,5,3,6,4};
    cout<<Maximumprofit(prices)<<endl;
    return 0;
}