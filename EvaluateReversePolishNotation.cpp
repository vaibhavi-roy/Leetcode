// Question Link- https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


//Code-

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s ;
        for(auto &i:tokens)
        { 
            if(i == "+" || i == "-" || i == "*" || i == "/") 
            {
                long long op1 = s.top() ; 
                s.pop() ;
                long long op2 = s.top() ; 
                s.pop() ;
                if(i == "+") 
                    op1 = op2 + op1 ;
                if(i == "-") 
                    op1 = op2 - op1 ;
                if(i == "*") 
                    op1 = op2*op1 ; 
                if(i == "/") 
                    op1 = op2/op1 ;  
                s.push(op1) ;
            }
            else 
                s.push(stoll(i)) ; // string to long long 
        }    
        return s.top() ; 

    }
};

