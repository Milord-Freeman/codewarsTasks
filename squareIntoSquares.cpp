//https://www.codewars.com/kata/square-into-squares-protect-trees/train/cpp
#include <cmath>
#include <vector>

using namespace std;

class Decomp
{
  public:
  static vector<long long> decompose(long long number);
  static bool isSquare(long long number);
  static vector<long long> recDecompose(long long difference, long long prevSquare);
};

vector<long long> Decomp::decompose(long long number){
  vector<long long> resultVector = {};
  long long squaredNumber = pow(number, 2);
  while (resultVector.empty() and number>0) {
    number--;
    resultVector = recDecompose(squaredNumber - pow(number, 2), number);
  }
  return resultVector;
}

vector<long long> Decomp::recDecompose(long long difference, long long prevSquare){
  vector<long long> result;
  
  if (isSquare(difference)){ 
    result.push_back(sqrt(difference));
    result.push_back(prevSquare);
    return result;
  } else {
    for (long long nextSquare = prevSquare - 1; nextSquare > 1; nextSquare--){
      if ((difference - pow(nextSquare, 2)) >= 0) {
        result = recDecompose(difference - pow(nextSquare, 2), nextSquare);
        if (!result.empty()) {
          result.push_back(prevSquare);
          return result;
        }
      }
    }
  }
  return {}; 
}

bool Decomp::isSquare(long long number){
  if (pow(trunc(sqrt(number)), 2) == number) return true; else return false;
}
