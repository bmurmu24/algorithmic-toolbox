#include <iostream>

int get_change(int m) {
  int count=0;
  
  while(m!=0){
      if(m>=10){
          m-=10;
          count++;
      }
      else if(m>=5){
          m-=5;
          count++;
      }
      else{
          m-=1;
          count++;
      }
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
