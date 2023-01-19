#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using std::vector;

struct Segment {
  int start, end;
};

void sortv(vector<Segment> &segments){
    Segment temp;
    
    for(int i=0;i<segments.size();i++)
        for(int j=i+1;j<segments.size();j++){
            if(segments[i].end>segments[j].end){
                temp = segments[j];
                segments[j] = segments[i];
                segments[i]=temp;
            }
        }
}


vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sortv(segments);
  int n=segments.size(),curr;
  for (size_t i = 0; i < n; ++i) {
     
    curr = segments[i].end;
    
    while(curr>=segments[i+1].start && curr<=segments[i+1].end)
        i+=1;
    points.push_back(curr);
    // points.push_back(segments[i].start);
    // points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}