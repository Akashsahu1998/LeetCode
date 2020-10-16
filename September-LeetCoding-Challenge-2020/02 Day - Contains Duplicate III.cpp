class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
		vector<pair<int,int> > data;
		for(int i=0;i<n;i++)
			data.push_back(make_pair(nums[i], i));
		sort(data.begin(), data.end());
		int p1 = 0;
		int p2 = 1;
		while(p2 < n)
		{
			long long int d1 = data[p1].first;
			long long int d2 = data[p2].first;
			if(abs(data[p1].second - data[p2].second) <= k && abs(d1 - d2)<=t)
				return true;
			if(abs(data[p1].second - data[p2].second) > k)
				p2++;
			if(abs(d1 - d2) > t)
				p1++;
			if(p1 == p2)
				p2++;
		}
		return false;
    }
};
