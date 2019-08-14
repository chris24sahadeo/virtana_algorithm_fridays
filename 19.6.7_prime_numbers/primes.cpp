#include <fstream>
#include <cmath>
// #include <bits/stdc++.h> 
#include <vector>
#include <chrono> 
#include <iostream>
using namespace std;
using namespace std::chrono; 



void print(vector<int> const &input){
    for(int i = 0; i < input.size(); i++){
        cout << input.at(i) << ' ';
    }
}


bool isPrime(int n, vector<int> P){
    // determines if n is prime by checking divsions of all primes less than the root of n

    vector<int>::iterator p = P.begin();
    while(*p <= sqrt(n)){
        if(n%(*p) == 0)
            return false;
        p++;
    }
    return true;

}


vector<int> getPrimes(int n){
    // gets all the primes form 2 to n and stores in the vector P

    vector<int> P;
    P.push_back(2);
    for(int i = 3; i <= n; i++){
        if(isPrime(i, P))
            P.push_back(i);
    }
    // print(P);
    return P;

}


vector<int> getPrimes2(int n){
    // gets all the primes form 2 to root n and stores in the vector P

    vector<int> P;
    P.push_back(2);
    // n = sqrt(n);
    vector<int>::iterator i = P.begin();
    while(*i <= sqrt(n)){
        if(isPrime(*i, P))
            P.push_back(*i);
        i++;
    }
    // print(P);
    return P;

}


int binary_search(const vector<int>& sorted_vec, int left, int right, int key) {
//    size_t mid, left = 0 ;
//    size_t right = sorted_vec.size(); // one position passed the right end
   while (left <= right) {
      int mid = left + (right - left)/2;
      if (key > sorted_vec[mid]){
          left = mid+1;
      }
      else if (key < sorted_vec[mid]){                                        
        right = mid;
      }
      else {                                                                  
        return mid;
     }                                                                                                               
   }

   return -1;      
}


void maximizeDistance(int n){
    // checks the left side of P and compares to a binary search on the right of P

    vector<int> P = getPrimes(10000);
    // int midPoint = binary_search(P, 0, P.size(), n/2);
    // cout << midPoint << endl;

    for(int i = 0; i <= n/2; i++){
        int a1 = P.at(i);
        int a2 = n - a1;

        // check if a2 is in P
        int l = 0;
        int r = P.size()-1;
        if(binary_search(P, l, r, a2) != -1){
            cout << "a1: " << a1 << " a2: " << a2 << endl;
            return;
        }
    }
    cout << "No primes exitst\n";

}


void maximizeDistance2(int n){
    // checks the left side of P and compares to a binary search on the right of P


    int limit = (int) sqrt(n);
    vector<int> P = getPrimes(1010);
    // print(P);
    // int midPoint = binary_search(P, 0, P.size(), n/2);
    // cout << midPoint << endl;

    for(int i = 2; i <= n/2; i++){
        int a1 = i;
        int a2 = n - i;

        // check if a2 is in P
        // int l = 0;
        // int r = P.size()-1;
        if(isPrime(a1, P) && isPrime(a2, P)){
            cout << "a1: " << a1 << " a2: " << a2 << endl;
            return;
        }
    }
    cout << "No primes exitst\n";
}


int main(){

        // cout << "Hi";


    ifstream fin("input.txt");
    if(!fin){
        // std::cout << "File error!\n";
        return (-1);
    }
    // cout << "Hi";

    

    int N, n;
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> n;

        // Get starting timepoint 
        auto start = high_resolution_clock::now(); 
        
        maximizeDistance2(n);
        // getPrimes(n);       

        // Get ending timepoint 
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 
  
        cout << "Time taken by function: "
            << duration.count() << " microseconds" << endl; 

        // getPrimes(n);       
    }



    fin.close();

    return 0;
}