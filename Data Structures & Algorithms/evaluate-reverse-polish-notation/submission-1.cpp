class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (int i = 0; i < tokens.size(); i++){
            if (isop(tokens[i])){
                int num1 = numbers.top();
                numbers.pop();
                int num2 = numbers.top();
                numbers.pop();
                numbers.push(operate(num2, num1, tokens[i]));
            }
            else numbers.push(stoi(tokens[i]));
        }
        return numbers.top();
    }

    int operate(int pre, int cur, string op){
        if (op == "+") return pre + cur;
        else if (op == "*") return pre * cur;
        else if (op == "-") return pre - cur;
        else return pre / cur;
    }

    bool isop(string op){
        return (op == "+" || op == "-" || op == "*" || op == "/");
    }
};
