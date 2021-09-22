class Solution {
public:
    struct comparator
    {
        bool operator()(vector<int> e1, vector<int> e2)
        { // Overloading the () operator
            return e1[0]<e2[0];
        }
    };



    int maxEnvelopes(vector<vector<int>>& envs)
    {

        sort(envs.begin(), envs.end(), comparator());



        for(vector<int> env: envs)
        {
            for(int val: env)
            {
                cout<<val<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};
