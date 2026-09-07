#include<bits/stdc++.h>
using namespace::std;

template<typename data_type>
struct Stack {
    struct StackNode {
        data_type data;
        StackNode* next;

        StackNode(data_type data) : data(data), next(nullptr) {}
    };

    StackNode* _top;

    Stack() {
        _top = nullptr;
    }

    void push(data_type value) {
        StackNode* new_node = new StackNode(value);
        new_node -> next = _top;
        _top = new_node;
    }

    void pop() {
        if (_top != nullptr) {
            _top = _top -> next;
        }
    }

    data_type top() {
        return _top == nullptr ? data_type() : _top -> data;
    }

    bool empty() {
        return _top == nullptr;
    }
};

bool match(char open, char close) {
    if (open == '(') return close == ')';
    if (open == '[') return close == ']';
    return close == '}';
}

int main() {
    
    int n; cin >> n;
    while(n--){
        Stack<char> s;
        string st;
        cin >> st;
        bool flag = true;
        for(int i=0; i<st.size();i++){
            char c = st[i];
            if(c == '}'){
                if(s.top() =='{') s.pop();
                else flag = false;
            }
            else if(c == ')'){
                if(s.top() =='(') s.pop();
                else flag = false;
            }
            else if(c == ']'){
                if(s.top() =='[') s.pop();
                else flag = false;
            }
            else{
                s.push(c);
            }
        }
        if(flag and s.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

