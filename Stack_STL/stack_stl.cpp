#include <iostream>
#include <stack>
using namespace std;
int main() {
  
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	//30 is on top
	//order 30->20->10
  
	cout << s.top() << '\n';
	//gives the top element

	s.pop();
	//remove the top element
  
	s.top();
	//top becomes 20
  
	cout << s.size() << '\n';
	//gives stack size
  
	cout << s.empty() << '\n';
	//prints 0 as empty==false

	//traversing the stack
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
  cout << '\n';
  
	return 0;
}
