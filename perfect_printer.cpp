#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int k;
unsigned long long n;
void read(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
}
unsigned long long findItems(unsigned long long time) 
{ 
    unsigned long long ans = 0; 
    for (int i = 0; i < k; i++)
    {
       ans += (time/arr[i]);   
    } 
    return ans; 
} 
   
unsigned long long bs(unsigned long long high) 
{ 
    unsigned long long low = 1,mid;
  
    while (low < high) 
    { 
        mid = low+(high-low)/2;
        
        unsigned long long cnt=findItems(mid);

        if (cnt < n) low = mid+1; 
        else high = mid; 
    }
    return high;
} 
  
void solve() 
{ 
    int big = arr[0]; 
  
    for (int i = 1; i < k; i++) {
        if(arr[i]>big) big=arr[i];
    }
     
    cout<<bs(big*n)<<endl; 
} 
int main() {
    read();
    solve();
    return 0;
}
