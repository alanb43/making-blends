#include <iostream>
#include <sstream>
#include <string> 
#include <algorithm> // std::min

/* A lot of the coments I write are because of new concepts I use, I sometimes write a short
explanation so I can remember the logic. Not necessarily for readability :) */

using std::cout, std::cin, std::endl, std::string, std::istringstream;

string CheckForOverlap(string word1, string word2) {
  
  int max_overlap = std::min(word1.size(), word2.size()); // std::min finds min size in 2 words
  for (int i = max_overlap; i > 0; i--) { // iterates from largest possible overlap to smallest
    if (word1.substr(word1.size() - i) == word2.substr(0, i)) { // if there is an overlap
      return word2.substr(0, i); // returns the substr that matches
    } 
  } 
  return "";  // if no overlap is found
}

string Squeeze(string word1, string word2) {
  string overlap = CheckForOverlap(word1, word2); // find substr of overlap
  if (overlap == "") { // if there isn't an overlap
    return word1 + " " + word2; // return a string of how the words word appear in the output
  } // the above/below string is what is then compared to the next word in Compress
  return word1 + word2.substr(overlap.size()); // returns the squeeze of the two words
}

string Compress(string line) {
  istringstream line_contents(line); 
  string result, word;
  line_contents >> result; // Storing first word for use in Squeeze
  while (line_contents >> word) { // compare first word to second
    result = Squeeze(result, word);  // continually reassign first word to be the result of squeeze
  }
  return result; 
}

int main() {
  string line;
  while (getline(cin, line)) { // get each line
    string compressed_line = Compress(line); // compress calls other functions
    cout << compressed_line << endl;  
  }
  return 0;
}
