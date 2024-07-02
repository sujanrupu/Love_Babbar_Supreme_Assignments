class MyStack {
public:
queue <int> qq;
    MyStack() {
        
    }
    
    void push(int x) {
        qq.push(x);
        for(int i=0; i<qq.size()-1; i++) {
            qq.push(qq.front());
            qq.pop();
        }
    }
    
    int pop() {
        int front = qq.front();
        qq.pop();
        return front;
    }
    
    int top() {
        int front = qq.front();
        return front;
    }
    
    bool empty() {
        if(qq.empty())   return true;
        else    return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
