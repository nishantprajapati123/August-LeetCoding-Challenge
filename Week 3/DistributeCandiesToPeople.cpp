// Time complexity :- O(log(C) + n)
// Space complexity :- O(1)
class Solution {
public:
    int sumFirst(int n)
    {
        return (n*(n+1))>>1;
    }
    vector<int> distributeCandies(int candies, int num_people) {
        
        vector<int>ans(num_people, 0);
        int turn = (-1 + sqrt(1 + ((double)8*candies)))/(double)(2 * num_people);

        
        for(int i=0;i<num_people;i++)
            ans[i] += (num_people * sumFirst(turn - 1)) + ((i+1) * turn);
        
        int remCand = candies - sumFirst(turn * num_people);

        if(remCand > 0)
        {
            int i = 0, c = turn*num_people + 1;
            while(remCand - c >= 0)
            {
                ans[i++] += c;
                remCand -= c;
                c++;
            }
            if(remCand > 0) ans[i] += remCand;
        }
        
        return ans;
    }
};