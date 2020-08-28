// Time complexity :- O(1)
// Space complexity :- O(1)
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int r1, r2;
        do
        {
            r1 = rand7();
        }while(r1 >= 6);
        
        do
        {
            r2 = rand7();
        }while(r2 == 7);
        
        if(r2 <= 3)
            return r1;
        else
            return 5 + r1;
    }
};