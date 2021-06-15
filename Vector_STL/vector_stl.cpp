#include <iostream>
#include <vector>
using namespace std;
int main() {
	
vector<int> v {10, 20, 30};
  
 cout << v.size() << '\n';
  //prints size of the vector
  
  //vector<int> v = {10,20,30}; works as well
  
   //another way of traversal
 for(auto it=v.begin(); it!=v.end(); it++){
    cout<<*it<<" ";
  }
  cout<<'\n';
  
v.push_back(40);
  //insert 40 at last
  
for (auto x : v)
cout << x << " ";
cout << '\n';
  
v.pop_back();
  //removes last
  
	for (auto x : v)
	cout << x << " ";
	cout << '\n';
  
	cout << v.front() << " " << v.back() << '\n';
	v.front() = 15;
	v.back() = 25;
  //can change the front and back..as these two give reference
  
	for (auto x : v)
	cout << x << " ";
	cout << '\n';
  
	v.insert(v.begin(), 2, 100);
  //inserts 100 twice before ist element  
	
	v.insert(v.begin(),24);
	//insert just once
  
	for (auto x : v)
	cout << x << " ";
	cout << '\n';
  
	if (!v.empty())
    //to check vector empty??
	cout << "Not empty" << '\n';
  
  v.clear();
  //removes all elements
	for (auto x : v)
	cout << x << " ";
	cout << '\n';
  
	return 0;
}
