#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

using std::vector;

double get_optimal_value(double capacity, double weights[] ,double values[] , int n) {
  double value = 0.0;


  for( int i=0 ; i<n ; i++)
  {


      if (capacity == 0 )
        return value;
      else if( n==1 && weights[i]<capacity )
        return values[i];


      else if(weights[i]<=capacity)
      {
          capacity = capacity - weights[i];
          //std::cout<<"\ncapacity="<<capacity;
          if(weights[i]==0)
            value = value+ values[i];
          else
          value = value + weights[i] * ((double)values[i] / weights[i]);
        //  std::cout<<"\nvalue="<<value;


      }

      else
      {
            value = value+values[i]*((double)capacity/weights[i]);
            capacity=0;
        //    std::cout<<"\nvalue="<<value;
      }
      //std::cout<<"\n\n________________________________________________________";
  }
  return value;
}

void pairsort(double a[], double b[], int n)
{
    pair<double, double > pairt[n];
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt, pairt + n);
    reverse(pairt , pairt+n);
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
int main()
{
  int n ;
  double capacity  =rand()+3;
	//std::cout<<capacity<<"\n"<<n;
  std::cin >> n>> capacity;
  double values[n];
  double weights[n];
  double v[n] , z[n];
  for (int i = 0; i < n; i++)
  {
      //values[i] = rand();
    //  weights[i] = rand();
    std::cin >> values[i] >> weights[i];
  }
  for(int i = 0 ; i< n ; i++)
  {
      if(values[i]==0)
        v[i]=0;
      else if (weights[i] == 0)
        v[i]=values[i];
      else
      v[i] = (float)values[i] /  weights[i];
      z[i] = v[i];
  }


    pairsort(v,values,n);
    pairsort(z,weights,n);
    //cout<<"\n\n\n";

  //for (int i = 0; i < n; i++)
    ////cout <<v[i]<<"-"<<values[i]<<"-"<<weights[i]<< "\n";

     double optimal_value = get_optimal_value(capacity, weights, values,n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}