class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for(int i = 0;i<operations.size();i++){
            if(operations[i] == "+"){
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
            else if (operations[i] == "D"){
                scores.push_back(scores.back() * 2);
            }
            else if (operations[i] == "C"){
                scores.pop_back();
            }
            else {
                scores.push_back(stoi(operations[i]));
            }
        }
        int sum = 0;
        for (int i = 0;i <scores.size();i++){
            sum += scores[i];
        }
        return sum;
    }
};