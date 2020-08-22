// Time complexity :- O(log(n))
// Space complexity :- O(n)
class Solution {
    int total_pts = 0;
    vector<int>rect_cum_count;
    vector<vector<int> >rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(auto r: rects)
        {
            total_pts += (r[2] - r[0] + 1)* (r[3] - r[1] + 1);
            rect_cum_count.push_back(total_pts);
        }
    }
    
    vector<int> pick() {
        
        int pt_idx = rand()%total_pts;
        int rect_idx = upper_bound(rect_cum_count.begin(), rect_cum_count.end(), pt_idx) - rect_cum_count.begin();
        
        vector<int>rect = rects[rect_idx];
        
        int x_pts = rect[2] - rect[0] + 1;
        int y_pts = rect[3] - rect[1] + 1;
        
        int pts_rect = x_pts * y_pts;
        int pt_start = rect_cum_count[rect_idx] - pts_rect;
        
        int offset = pt_idx - pt_start;
        return {rect[0] + offset%x_pts, rect[1] + offset/x_pts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */