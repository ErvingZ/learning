#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> words2;
        for(string word:words)
        {
            int num=0;
            for(int i=0;i<word.size();i++)
            {
                num = num|(1<<(word[i]-'a'));
            }
            words2.emplace_back(num);
        }
        int product=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i;i<words.size();j++)
            {
                if((words2[i]&words2[j])==0)
                {
                    int cur_product = words[i].size()*words[j].size();
                    product = max(product,cur_product);
                }
            }
        }
        return product;
    }
};

int main()
{
    return 0;
}
