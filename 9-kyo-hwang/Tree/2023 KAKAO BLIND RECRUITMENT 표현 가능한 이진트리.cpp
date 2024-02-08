#include <bitset>
#include <string>
#include <vector>

using namespace std;

bool can_expressed_as_tree(string binary) {
  if (binary.size() <= 1) {
    return true;
  }

  int mid = binary.size() / 2;
  if (binary[mid] == '0' && binary.find('1') != string::npos) {
    return false;
  }

  return can_expressed_as_tree(binary.substr(0, mid)) &&
         can_expressed_as_tree(binary.substr(mid + 1));
}

string decimal_to_binary(long long &number) {
  string s = bitset<64>(number).to_string();
  s = s.substr(s.find('1'));

  int bin = 1;
  while (s.size() >= bin) {
    bin *= 2;
  }

  for (int repeat = bin - 1 - s.size(); repeat > 0; --repeat) {
    s = '0' + s;
  }

  return s;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;
  for (long long &number : numbers) {
    answer.emplace_back(can_expressed_as_tree(decimal_to_binary(number)));
  }
  return answer;
}