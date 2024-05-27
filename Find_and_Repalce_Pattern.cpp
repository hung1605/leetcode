#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool match(string word, string pattern) {
  map<char, char> mp = {};
  for (int i = 0; i < word.length(); i++) {
    if (mp[word[i]] != '\0') {
      if (pattern[i] != mp[word[i]])
        return false;
    } else {
      for (auto anhxa : mp) {
        if (anhxa.second == pattern[i])
          return false;
      }
      mp[word[i]] = pattern[i];
    }
  }
  cout << "----------next word ---------------";
  return true;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
  vector<string> ans = {};
  for (string word : words)
    if (match(word, pattern))
      ans.push_back(word);
  return ans;
}

int main() {
  vector<string> i = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
  string j = "abb";
  i = findAndReplacePattern(i, j);
  for (string word : i)
    cout << word << " ";
}
