// Claire Veasey cev4gx 3/14/17 wordPuzzle.cpp

//Big Theta: rows*columns*(maxlength-3)*8*length

// rows = amount of rows, columns = amount of columns
// maxlength-3 for the 3rd for loop, so get all words of length 3 to maxlength
// 8 for directions
// length = time complexity for getWordInGrid



#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);



bool readInGrid (string filename, int &rows, int &cols) {
    string line;
    ifstream file(filename.c_str());
    if ( !file.is_open() )
        return false;
    file >> rows;
    getline (file,line); // eats up the return at the end of the line
    file >> cols;
    getline (file,line); // eats up the return at the end of the line
    getline (file,line);
    file.close();
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
        }
    }
    return true;
}


char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    static char output[256];
    if ( len >= 255 )
        len = 255;
    int pos = 0, r = startRow, c = startCol;
    for ( int i = 0; i < len; i++ ) {
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        output[pos++] = grid[r][c];
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    output[pos] = 0;
    return output;
}

int countDict (string filename) {
    string line;
    int wordCount = 0;
    ifstream file(filename.c_str());
    if (!file.is_open()) {
      cout << "Unable to read dictionary file" << endl;
      return -1;
    }
    for (string l; getline(file, l);) {
      wordCount++;
    }
    file.close();
    
    //cout << wordCount << endl;
    return wordCount;
}

hashTable readInDict (string filename, hashTable ht) {
  string line;
  ifstream file(filename.c_str());
  if (!file.is_open()) {
    cout << "Unable to read dictionary file" << endl;
  }
  for (string l; getline(file, l);) {
    l.erase(remove(l.begin(), l.end(), ' '), l.end()); // remove whitespace
    if (l.length() > 2) { // only insert into hash table in 3 or more chars
      ht.insert(l);
    }
  }
  file.close();
  return ht;
}

hashTable readInPrefix (string filename, hashTable ht) {
  string line;
  ifstream file(filename.c_str());
   if (!file.is_open()) {
    cout << "Unable to read dictionary file" << endl;
  }
  for (string l; getline(file, l);) {
    l.erase(remove(l.begin(), l.end(), ' '), l.end()); // remove whitespace
    l = l.substr(0, 3);
    if (!ht.contains(l)) {
      ht.insert(l);
    }
  }
  file.close();
  return ht;
  // change 
}

int main(int argc, char* argv[]) {
  timer t;
  int rows, cols;
  int numWords = countDict(argv[1]);
  hashTable dict = hashTable(numWords);
  hashTable prefix = hashTable(numWords);
  dict = readInDict(argv[1], dict);
  prefix = readInPrefix(argv[1], prefix);

  bool result = readInGrid(argv[2], rows, cols);

  if (!result) {
    cout << "Error reading in file!" << endl;
    exit(1);
  }
  char* word;
  string getWord = "";
  int wordsFound = 0;
  string dir = "";
  vector<string> output;

  t.start();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < 8; k++) {
	for (int l = 3; l < 23; l++) {
	  word = getWordInGrid(i, j, k, l, rows, cols);
	  if (strlen(word) < l) {
	    break;
	  }
	  if (!prefix.contains((string(word)).substr(0,3))) {
	    break;
	  }
	  
	  if (dict.contains(word)) {
	    if (k == 0) {
	        dir = "N";
	    }
	    else if (k == 1) {
		dir = "NE";
	    }
	    else if (k == 2) {
		dir = "E";
	    }
	    else if (k == 3) {
		dir = "SE";
	    }
	    else if (k == 4) {
		dir = "S";
	    }
	    else if (k == 5) {
		dir = "SW";
	    }
	    else if (k == 6) {
		dir = "W";
	    }
	    else {
		dir = "NW";
	    }
	    wordsFound++;
	    output.push_back(dir + " (" + to_string(i) + ", " + to_string(j) + "):\t" + word);
	    
	  } // end if
	} // end length (l) for loop
      } // end direction (k) for loop
    } // end columns (j) for loop
  } // end rows (i) for loop
  t.stop();
  for (int n = 0; n < output.size(); n++) {
    cout << output[n] << endl;
  }
  cout << wordsFound << " words found" << endl;
  cout << "Found all words in " << t.getTime() << " seconds" << endl;
  cout << int(t.getTime()*1000) << endl; // This line is for averagetime.sh
  return 0;
}
