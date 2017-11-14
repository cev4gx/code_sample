// Claire Veasey cev4gx 3/14/17 hashTable.cpp

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "hashTable.h"

using namespace std;

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);

hashTable::hashTable(int arrayLength) {
  if (!checkprime(arrayLength*2)) {
    arrayLength = getNextPrime(arrayLength*2);
  }
  
  ht.resize(arrayLength);
  ht.assign(arrayLength, "");
  htLength = arrayLength;
}

int hashTable::hash(string word) {
  int hashVal = 0;
  for (int i = 0; i < word.length(); i++) {
    hashVal += word[i]*37;
  }
  return (hashVal*word.length()) % htLength;
}

void hashTable::insert(string word) {
  //unsigned
  int index = hash(word);
  while (!(ht.at(index)).empty()) {
    index++; // linear probing
    if (index == ht.capacity()) {
      index = 0; // wrap around
    }
    
  }
  ht.at(index) = word;
  numElements++;
}

bool hashTable::contains(string word) {
  //unsigned
  int index = hash(word);
  int start = index; // need this to check if you've been all the way around
  while (ht.at(index) != word) {
    index++;
    if (index == ht.capacity()) {
      index = 0; // wrap around
    }
    if (index == start || ht.at(index) == "") { // back to beginning of search
      return false;
    }
  }
  return true;
}

void hashTable::printHT() {
  for (int i = 0; i < ht.capacity(); i++) {
    cout << "Position " << i << " : " << ht.at(i) << endl;
  }
}




bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

