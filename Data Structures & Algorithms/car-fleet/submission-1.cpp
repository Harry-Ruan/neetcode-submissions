class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> cars;
        double pre = -1;
        int res = 0;
        for (int i = 0; i < position.size(); i++){
            cars[position[i]] = speed[i];
        }
        for (auto& car : cars){
                double curtime = 1.0 * (target - car.first) / car.second;
                if (curtime > pre){
                    res++;
                    pre = curtime;
                }
        }
        return res;
    }
};
