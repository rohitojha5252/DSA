class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(high < 12)return {};

        vector<string>num;
        string start = "1";
        for(int i=2; i<10; i++){
            char c = i+'0';
            start += c;
            num.push_back(start);
            string numb = start;
            for(int j=i+1; j<10; j++){
                c = j+'0';
                numb += c;
                numb.erase(0, 1);
                num.push_back(numb);
            }
        }

        int i=0;
        while (i<num.size() && stoi(num[i]) < low)i++;
        int j = num.size()-1;
        while(j<num.size() && stoi(num[j]) > high)j--;

        if(i>=num.size())return {};

        vector<int>ans;

        for(int k = i; k<=j; k++){
            ans.push_back(stoi(num[k]));
        }
        return ans;
    }

};