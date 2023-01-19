#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
 
 int sum=0;
 if(n==1 || n==2){
     sum=n;
     summands.push_back(n);
 }
 int curr=1,next=curr+1;
 
 while(sum!=n){
     if(curr+next<=n-sum){
         summands.push_back(curr);
         sum+=curr;
         curr=next;
         next+=1;
         
     }
     else if(curr+sum==n){
        summands.push_back(curr);
        sum+=curr;
     }
    else{
        summands.push_back(n-sum);
        sum=n;
    }    
 }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}