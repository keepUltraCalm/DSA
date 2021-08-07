//STACK USING ARRAY

struct MYStack{
	int *arr;
	int cap;
	int top;
	MYStack(int c){
        cap = c;
        arr = new int[cap];
        top=-1;
	}
	void push(int x){
		top++;
		arr[top]=x;
	}
	int pop(){
		int res = arr[top];
		top--;
		return res;
	}
	int peek(){
		return arr[top];
	}
	int size(){
		return top+1;
	}
	bool empty(){
		return (top==-1);
	}
}
