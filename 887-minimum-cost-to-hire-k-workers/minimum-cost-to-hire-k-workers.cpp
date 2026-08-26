class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> chefs;
        for(int i=0; i<quality.size(); i++) {
            chefs.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(chefs.begin(), chefs.end());
        priority_queue<int> pq;
        double best=DBL_MAX;
        double sum_out = 0;
        for(int i=0; i<quality.size(); i++) {
            pq.push(chefs[i].second);
            sum_out += chefs[i].second;
            if(pq.size()>k) {
                sum_out-=pq.top();
                pq.pop();
            }

            if(pq.size()==k) {
                if(best>chefs[i].first*sum_out) best = chefs[i].first*sum_out;
            }
        }
        return best;
    }
};