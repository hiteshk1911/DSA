//Complexity Analysis:
Each element is popped, inserted at bottom recursively.
Time: O(N^2) (since insertAtBottom itself may traverse O(N)).
Space: O(N) recursion depth.

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    // Base case: stack is empty, put x here
    if(st.empty()) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(temp); // push back the stored elements
}

void reverseStack(stack<int> &st) {
    // Base case: empty stack
    if(st.empty()) return;

    int x = st.top();
    st.pop();

    reverseStack(st);        // reverse the rest of the stack
    insertAtBottom(st, x);   // insert popped element at bottom
}
