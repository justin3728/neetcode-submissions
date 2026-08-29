class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, double>> st;
        //<pos, time>
        vector<pair<int ,double>> car;
        int ans = 0;

        for(int i = 0; i < position.size(); i++) {
            double time = double(target - position[i]) / speed[i];
            car.push_back({position[i], time});
        }

        sort(car.begin(), car.end(), greater<pair<int, double>>());

        for(int i = 0; i < position.size(); i++) {
            if(st.empty()) {
                st.push(car[i]);
                ans++;
            }
            else {
                //追趕上
                if(st.top().second >= car[i].second) {
                    continue;
                }
                else {
                    st.push(car[i]);
                    ans++;
                }
            }
        }

        return ans;
    }
};
