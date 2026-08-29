class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //<pos, time>
        vector<pair<int ,double>> car;
        int n = position.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            double time = double(target - position[i]) / speed[i];
            car.push_back({position[i], time});
        }

        sort(car.begin(), car.end(), greater<pair<int, double>>());

        double time = 0;

        for(int i = 0; i < n; i++) {
            if(car[i].second > time) {
                time = car[i].second;
                ans++;
            }
        }

        return ans;
    }
};
