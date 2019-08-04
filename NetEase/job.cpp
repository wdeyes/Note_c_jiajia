#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
/*
int main(){
    int job_num, per_num;
    cin >> job_num >> per_num;
    map<long,long> job;
    for(int i=0;i<job_num;++i){
        long dif_temp, pi_temp;
        cin >> dif_temp >> pi_temp;
        job[pi_temp]=dif_temp;
    }
    vector<long> max_pi(per_num,0);
    for(int i=0; i<per_num; ++i){
        long ai_temp;
        cin >> ai_temp;
        for(auto it=job.rbegin(); it!=job.rend(); ++it){
            if(it->second <= ai_temp){
                max_pi[i]=it->first;
                break;
            }
        }
    }
    for(auto val : max_pi)
        cout << val << endl;
    return 0;
}
*/


bool cmp(pair<int,int> x, pair<int,int> y){
    return x.first < y.first;
}
int main(){

    int job_num, per_num;
    cin >> job_num >> per_num;
    
    vector<pair<int,int> > job(job_num+1);
    job[0]=make_pair(0,0);
    for(int i=1; i<=job_num; ++i){
        cin >> job[i].first >> job[i].second;
    }

    vector<pair<int,int> > per(per_num);
    for(int i=0; i<per_num; ++i){
        cin >> per[i].first;
        per[i].second=i;
    }

    sort(job.begin(), job.end(), cmp); 
    sort(per.begin(), per.end(), cmp);
    
    int mx=0;
    for(int i=0; i<=job_num; ++i){
        job[i].second = max(mx, job[i].second);
        mx=job[i].second;
    }
    
    int i_job=0, i_per=0;
    vector<int> ans(per_num);
    while(i_job<=job_num && i_per<per_num){
        if(per[i_per].first >= job[i_job].first)
            ++i_job;
        else{
            ans[per[i_per].second]=job[i_job-1].second;
            ++i_per;
        }
    }
    
    while(i_per<per_num){
        ans[per[i_per].second] = job[job_num].second;
        ++i_per;
    }
    
    for(auto val : ans)
        cout << val << endl;
    return 0;
}



