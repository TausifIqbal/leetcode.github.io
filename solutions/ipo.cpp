//https://leetcode.com/problems/ipo/description/

struct Project{
    int profit{};
    int capital{};
    Project(int _profit,int _capital):capital(_capital),profit(_profit){};
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<Project> projects;
        int n=profits.size();
        for(int i=0;i<n;i++){
            projects.emplace_back(profits[i],capital[i]);
        }
        sort(projects.begin(),projects.end(),[](const Project &a, const Project &b){
            return a.capital<b.capital; // descending order
        });
        auto cmp = [](const Project &a, const Project &b){
            return a.profit < b.profit; // max heap
        };
        priority_queue<Project,vector<Project>,decltype(cmp)> candidate_project(cmp);
        int total_capital=w;
        int idx=0;
        for(int i=0;i<k;i++){
            while(idx<n && projects[idx].capital<=total_capital){
                candidate_project.push(projects[idx]);
                idx++;
            }
            if(candidate_project.empty()){
                break;
            }

            auto  p = candidate_project.top();
            candidate_project.pop();
            total_capital += p.profit;
        }
        return total_capital;
    }
};
