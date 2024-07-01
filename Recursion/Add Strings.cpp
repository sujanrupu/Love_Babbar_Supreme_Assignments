class Solution {
public:
    string addStrings(string num1, string num2) {
        int a = stoi(num1), b = stoi(num2);
        return to_string(a+b);
    }
};
