#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int idx1 = n-1, idx2 = n-1;
    
    
    while(idx1 >= 0 || idx2 >= 0) {
        
        while(deliveries[idx1] == 0 && idx1 >= 0) idx1--;
        while(pickups[idx2] == 0 && idx2 >= 0) idx2--;
        
        answer += max(idx1, idx2) + 1;
        
        int lcap, rcap;
        lcap = rcap = cap;
        
        while(lcap && idx1 >= 0) {
            if(deliveries[idx1] >= lcap) {
                deliveries[idx1] -= lcap; lcap = 0;
            }
            else {
                lcap -= deliveries[idx1]; idx1--;
            }
        }
        
        while(rcap && idx2 >= 0) {
            if(pickups[idx2] >= rcap) {
                pickups[idx2] -= rcap; rcap = 0;
            }
            else {
                rcap -= pickups[idx2]; idx2--;
            }
        }
    }
    
    return answer * 2;
}