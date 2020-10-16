class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {        
        set<int> st;
        for(auto &a : nums) st.insert(a);
        int Max = 0;
        for(auto &a : nums){
            int temp = 0;
			for (int itr = 30; itr >= 0; itr--){
				temp |= (~a & (1 << itr));
				auto it = st.lower_bound(temp);
				if (it == st.end() || (*it) - (1 << itr) >= temp)
                    temp ^= (1 << itr);
			}            
            Max = max(Max, a ^ temp);
        }
        return Max;
    }
};
