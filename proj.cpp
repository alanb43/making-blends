#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> // std::min

using std::cout, std::cin, std::endl, std::string, std::istringstream;

// Returns a string that is the overlap between two words provided as arguments
// or an empty string literal signifying no such overlap was found.
string CheckForOverlap(const string &word1, const string &word2) {
  int max_overlap = std::min(word1.size(), word2.size());
  for (int i = max_overlap; i > 0; i--) { // iterates largest->smallest overlap
    if (word1.substr(word1.size() - i) == word2.substr(0, i)) { // find overlap
      return word2.substr(0, i); // returns a substring of the overlap
    }
  }
  return "";
}

// Returns a string of the first parameter concatenated with the end of the 
// second word, from where the overlap ends in other words. If no overlap,
// returns the two words concatenated with an empty space between to preserve
// sentence formatting. Finds overlap by calling CheckForOverlap
string Squeeze(const string &word1, const string &word2) {
  string overlap = CheckForOverlap(word1, word2); 
  if (overlap == "") { // if no overlap
    return word1 + " " + word2;
  } // the string above/below is then compared to the next word in Compress   
  return word1 + word2.substr(overlap.size());
}

// Returns a string containing all of the words from the line with appropriate
// squeezes done when necessary, found by calling Squeeze within the function
// definition.
string Compress(const string &line) {
  istringstream line_contents(line);
  string result, word;
  line_contents >> result;  // Storing first word for use in Squeeze
  while (line_contents >> word) {  // brings in each additional word from line
    result = Squeeze(result, word); // keeps reassigning result til line end
  }
  return result;
}

// Main function, gets line of input using getline then calls Compress which in
// turn calls Squeeze and then CheckForOverlap in order to find the compressed
// line, which it then outputs before moving to the next line.
int main() {
  string line;
  while (getline(cin, line)) {
    string compressed_line = Compress(line);
    cout << compressed_line << endl;
  }
  return 0;
}
