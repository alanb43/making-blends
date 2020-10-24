#include <iostream>
#include <sstream>
#include <string> 
#include <algorithm> // std::min

using std::cout, std::cin, std::endl, std::string, std::istringstream;

string CheckForOverlap(string word1, string word2) {
  
  int max_overlap = std::min(word1.size(), word2.size()); 
  for (int i = max_overlap; i > 0; i--) { // iterates from largest possible overlap to smallest
    if (word1.substr(word1.size() - i) == word2.substr(0, i)) { // if there is an overlap
      return word2.substr(0, i); // returns a substring of the overlap
    } 
  } 
  return "";  // if no overlap is found
}

string Squeeze(string word1, string word2) {
  string overlap = CheckForOverlap(word1, word2); // find substr of overlap
  if (overlap == "") { 
    return word1 + " " + word2; 
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
  while (getline(cin, line)) { 
    string compressed_line = Compress(line);
    cout << compressed_line << endl;  
  }
  return 0;
}
