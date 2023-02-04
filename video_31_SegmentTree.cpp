#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	int *arr;
	int arrSize;
	int *tree;
	int N;
	
	int getLeftChild(int index) {
		return 2 * index + 1;
	}
		int getRightChild(int index) {
		return 2 * index + 2;
	}	
	
	void buildTree(int nodeIndex, int start, int end){
		if(start == end) {
			this->tree[nodeIndex] = this->arr[start];
		} else {
			int mid=start+(end-start)/2;
			int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);
			buildTree(leftIndex, start, mid);
			buildTree(rightIndex, mid+1, end);
			
			this->tree[nodeIndex] = this->tree[leftIndex] + this->tree[rightIndex];			
		}
	}
	public:
	SegmentTree(int *arr, int arrSize){
		this->arrSize=arrSize;
		this->N = 4 * this->arrSize;
		this->arr = arr;
		this->tree = new int[this->N];
		for( int i=0;i<this->N;i++)
			this->tree[i] = 0;
		buildTree(0, 0, this->arrSize-1);
	}
	void PrintSegmentTree(){
		for(int i=0;i<this->N;i++){
			cout<<this->tree[i]<<", ";
		}
		cout<< "\n";
	}
};

int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};
	SegmentTree st(arr,6);
	st.PrintSegmentTree();
}
