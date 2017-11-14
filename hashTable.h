// Claire Veasey cev4gx 3/14/17 hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
using namespace std;

class hashTable {
 public:
  hashTable(int arrayLength); // Constructor
  int hash(string word);
  void insert(string word);
  bool contains(string word);
  void printHT();
    
 private:
  vector<string> ht;
  int htLength;
  int numElements;
};

#endif
