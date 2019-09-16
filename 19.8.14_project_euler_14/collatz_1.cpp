// https://projecteuler.net/problem=14
// https://en.wikipedia.org/wiki/Collatz_conjecture
// https://www.dcode.fr/collatz-conjecture

#include <iostream>
#include <sstream>
#include <map>

#define MAX 1000000

std::map <unsigned int, unsigned int> progression_steps;

unsigned int collatz(unsigned int n)
{
  // if n is even
  if(n % 2 == 0) return n/2;

  // else if n odd
  return 3*n + 1;
}

unsigned int getNumSteps(unsigned int n)
{
  // base case
  if(n==1) return 0;

  // if getNumSteps(n) was already found and stored in the map
  std::map <unsigned int, unsigned int>::iterator itr = progression_steps.find(n);
  if(itr != progression_steps.end()) return itr->second;

  // if not found in the map
  unsigned int num_steps = getNumSteps(collatz(n)) + 1;
  progression_steps[n] = num_steps;
  return num_steps;
}

void longestProgression(unsigned int max)
{
  unsigned int longest_progression = 0, starting_number;
  for(unsigned int i = 1; i <= max; i++)
  {
    // std::cout << i << std::endl; 
    int num_steps = getNumSteps(i);
    
    if(num_steps > longest_progression)
    {
      longest_progression = num_steps;
      starting_number = i;
    }
    
  }

  std::cout << "Starting number: "<< starting_number << ". Longest progression: " << longest_progression << std::endl;
}

int main(int argc, char **argv)
{
  std::istringstream ss(argv[1]);
  int n;
  ss >> n;
 
  // longestProgression(n);
  
  const int number = 1000000;
 
  long sequenceLength = 0;
  long startingNumber = 0;
  long sequence;
  
  for (int i = 2; i <= number; i++) {
      int length = 1;
      sequence = i;
      while (sequence != 1) {
          if ((sequence % 2) == 0) {
              sequence = sequence / 2;
          } else {
              sequence = sequence * 3 + 1;
          }
          length++;
      }
  
      //Check if sequence is the best solution
      if (length > sequenceLength) {
          sequenceLength = length;
          startingNumber = i;
      }
  }

    std::cout << "Starting number: "<< startingNumber << ". Longest progression: " << sequenceLength << std::endl;


  return 0;
}