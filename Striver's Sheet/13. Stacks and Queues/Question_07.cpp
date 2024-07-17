#include <bits/stdc++.h> 

// function that inserts the element at right place in a sorted stack
void sortElement(stack<int> &st, int element){
  if (st.empty()) {
    st.push(element);
  } else if (st.top() < element) {
    st.push(element);
  } else {
    int temp = st.top();
    st.pop();
    sortElement(st, element);
    st.push(temp);
  }
}

void helper(stack<int> &stack){
	if(stack.empty()) return;

	int num = stack.top();
	stack.pop();

	helper(stack);
	sortElement(stack, num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
	helper(stack);
}