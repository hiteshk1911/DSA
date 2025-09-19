//Complexity Analysis:
Each element is popped and inserted recursively.
Time: O(N^2) in worst case (like insertion sort).
Space: O(N) (recursion stack).


#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &st, int x) {
    // Base case: place x when stack empty OR top <= x
    if(st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    // Base case: empty stack
    if(st.empty()) return;

    int x = st.top();
    st.pop();

    sortStack(st);          // sort remaining stack
    insertSorted(st, x);    // insert popped element at right position
}
