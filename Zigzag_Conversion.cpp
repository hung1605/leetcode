#include <fstream>

using namespace std;

ifstream inFile("in.txt");
ofstream outFile("out.txt");

pair<int, int> nextCell(pair<int, int> curr, int numRows) {
  if (curr.second % (numRows - 1) == 0) {
    if (curr.first < numRows - 1)
      return {curr.first + 1, curr.second};
    else if (curr.first == numRows - 1)
      return {curr.first - 1, curr.second + 1};
  }
  return {curr.first - 1, curr.second + 1};
}

string convert(string s, int numRows) {
  if (numRows == 1)
    return s;
  // init table a
  char a[numRows][s.size()];
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < s.size(); j++) {
      a[i][j] = ' ';
    }
  }

  pair<int, int> pos = {0, 0};
  for (int i = 0; i < s.size(); i++) {
    a[pos.first][pos.second] = s[i];
    pos = nextCell(pos, numRows);
  }

  string ans = "";

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < s.size(); j++) {
      if (a[i][j] != ' ')
        ans = ans + a[i][j];
    }
  }

  return ans;
}

int main() {
  string s;
  int numRows;
  inFile >> s;
  inFile >> numRows;
  s = convert(s, numRows);
  outFile << s;
}
