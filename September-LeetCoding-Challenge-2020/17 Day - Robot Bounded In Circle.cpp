class Solution {
public:
    void add_dir(char c, int &x, int &y, int &d) {
        switch(c) {
            case 'G':
                switch(d) {
                    case 0:
                        y += 1;
                        break;
                    case 1:
                        x -= 1;
                        break;
                    case 2:
                        y -= 1;
                        break;
                    case 3:
                        x += 1;
                        break;
                }
                break;
            case 'L':
                d = (d + 1) % 4;
                break;
            case 'R':
                d = (d + 3) % 4;
                break;
        }
    }
    
    bool isRobotBounded(string instructions) {
        int itr = 0, d = 0, x = 0, y = 0;
        for(itr = 0; itr < 4; itr++) {
            for(auto c: instructions) {
                add_dir(c, x, y, d);
            }
             if(x == 0 && y == 0) return true;
        }        
        return false;
    }
};

