class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        string eq;
        for(int i=0;i<tokens.size();i++)
        {

            if(tokens[i]=="+"|| tokens[i]=="-" ||tokens[i]=="*" || tokens[i]=="/")
            {
                int secNum=nums.top();
                nums.pop();
                int firstNum=nums.top();
                nums.pop();
                int res;
                if(tokens[i]=="+")
                    res=firstNum+secNum;
                else if(tokens[i]=="-")
                    res=firstNum-secNum;
                else if(tokens[i]=="*")
                    res=firstNum*secNum;
                else if(tokens[i]=="/")
                    res=firstNum/secNum;

                nums.push(res);
            }


            else
            {
               nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};