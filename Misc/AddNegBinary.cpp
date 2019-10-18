class Solution {
public:
    void well(int &sum, int &bit, int &carry)
    {
        if(sum==-2)
        {
            bit = 0;
            carry = 1;
        }
        else if(sum==-1)
        {
            bit = 1;
            carry = 1;
        }
        else if(sum==0)
        {
            bit = 0;
            carry = 0;
        }
        else if(sum==1)
        {
            bit = 1;
            carry = 0;
        }
        else if(sum==2)
        {
            bit = 0;
            carry = -1;
        }
        else if(sum==3)
        {
            bit = 1;
            carry = -1;
        }
    }
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        while(arr1.size() < arr2.size()) arr1.push_back(0);
        while(arr2.size() < arr1.size()) arr2.push_back(0);
        vector<int> ans;
        int carry = 0;
        for(int i=0;i<arr1.size();++i)
        {
            int sum = arr1[i] + arr2[i] + carry;
            int bit = 0;
            well(sum,bit,carry);
            ans.push_back(bit);
        } 
        while(carry)
        {
            int sum = carry;
            int bit = 0;

            well(sum,bit,carry);
            ans.push_back(bit);
        }
        vector<int> ans2;
        bool ok = false;
        for(int i=ans.size()-1;i>=0;--i)
        {
            if(ans[i]==1) ok = true;
            if(ok)
            {
                ans2.push_back(ans[i]);
            }
        }
        if(ans2.size()==0)
        {
            ans2.push_back(0);
            return ans2;
        }
        return ans2;
    }
};