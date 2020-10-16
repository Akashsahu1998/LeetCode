class Solution {
public:
    static bool comp(string &a, string &b){
        int itr = 0, asize = a.size(), bsize = b.size();
        int x = min(asize, bsize);

        for( ; itr < x; itr++){
            if(a[itr] != b[itr])
                return a[itr] > b[itr];
        }
        if(asize == bsize)
            return false;
            
        string s;
        if(asize < bsize)
            return comp(a, s = b.substr(itr));

        return comp(s = a.substr(itr), b);
    }

    
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        vector<string> vec(size);
        int itr = 0;
        for( ; itr < size; itr++)
            vec[itr] = to_string(nums[itr]);
        
        sort(vec.begin(), vec.end(), comp);
        
        string s;
        s.reserve(size);
		for(auto a : vec){
		   cout << a << " ";
		    s += a;
		}
        		 
        itr = 0; size = s.size();
        
        while(itr < size && s[itr] == '0')
            itr++;
        
        if(itr == size)
            return "0";
        
        return s.substr(itr);
    }
};

