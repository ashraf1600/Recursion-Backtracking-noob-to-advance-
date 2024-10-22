#include<bits/stdc++.h>
using namespace std;
void subseq(vector<int>&v,int n,int ind,vector<int>&possible_sub_seq, vector<vector<int>>&all_subseq)
{
	//base case
	if(ind==n)
	{
		all_subseq.push_back(possible_sub_seq);
		return;
	}
	//Recursive call
	//option 1: Not take the current index
	subseq(v,n,ind+1,possible_sub_seq,all_subseq);
	//option 2: Take the current index
	possible_sub_seq.push_back(v[ind]);
	subseq(v,n,ind+1,possible_sub_seq,all_subseq);
	//backtracking [ to explore another comhination getting back]
	possible_sub_seq.pop_back();



}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
    vector<int>possible_sub_seq;
    vector<vector<int>>all_subseq;
	subseq(v,n,0,possible_sub_seq,all_subseq);
	cout<<"All Subsequence are......"<<endl;
	for( auto subseq : all_subseq)
	{
		cout<<"{";
		for(auto elem : subseq)
		{
			cout<<" "<<elem<<" ";
		}
		cout<<"}";
		cout<<endl;
	}

}
