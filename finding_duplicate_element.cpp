#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// This problem only works for values>0.

// function for finding duplicate element from mutable array in O(n) time and O(1) space
int find_duplicate_element_mutable(vector<int>arr,int n){
	// the concept is: Let's say we are at index i, so we will make the arr[abs(arr[i])] as negative
	// if my present index (i) value is only negative, it means this arr[i] is the answer.
	
	int ans=-1;
	for(int i=0;i<n;i++){
		int index= abs(arr[i]);
		if(arr[index]<0){
			ans= index;
			break;
		}
		else{
			arr[index] = - arr[index];
		}
	}
	return ans;
}

// function for finding duplicate element from immutable array in O(n) time and O(1) space
int find_duplicate_element_immutable(vector<int>arr,int n){
	// the concept is: we will take two pointers fast and slow.
	int fast= arr[0];
    int slow= arr[0];
	
	// first loop the fast pointer will move by two units and slow pointer moves by one unit.
    do{
           slow= arr[slow];
           fast= arr[arr[fast]];
       } while(fast!=slow);

     // when they matches we will break the loop and make the fast pointer to point to starting location.
     fast= arr[0];  

     // now fast and slow will move only by one step till they come at same point
     while(fast!=slow){
     	fast= arr[fast];
     	slow= arr[slow];
     }
     
     // the point where they match is the answer
     return slow;
}

int main(){
	// for fast input output
	ios_base::sync_with_stdio(false);  cin.tie(NULL);

	int n=7;
	vector<int>arr={3,4,1,6,3,2,5};
	// getting the duplicate element from array which can be mutated
	cout<<"duplicate element from mutable array is: "<<find_duplicate_element_mutable(arr,n)<<"\n";
	
	// getting the duplicate element from array which can be mutated
	cout<<"duplicate element from immutable array is: "<<find_duplicate_element_immutable(arr,n)<<"\n";
		
}
