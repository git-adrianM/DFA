#include <iostream>
#include <string>

using namespace std;

enum State { S0, S1, S2, S3, S4, S5 };

State transition(State current_state, char input_char) {
  switch (current_state) {
  case S0:
    if (input_char == 'A') return S4;
    if (input_char == 'G') return S1;
    if (input_char == 'T') return S2;
    return S5;
  case S1:
    if (input_char == 'A') return S4;
    if (input_char == 'T') return S2;
    if (input_char == 'G') return S1;
    return S5;
  case S2:
    if (input_char == 'T') return S3;
    return S5;
  case S3:
    if (input_char == 'T') return S2;
    if (input_char == 'A') return S4;
    if (input_char == 'G') return S1;
    return S5;
  case S4:
    return S5;
  case S5:
    return S5;
  default:
    return S5;
  }
}

bool is_valid_sequence(string sequence) {
  State current_state = S0;
  for (char c : sequence) {
    //cout << "current State " << current_state << " char " << c << endl;
    current_state = transition(current_state, c);
  }
  return current_state == S2 || current_state == S4;
}

int main() {
  string sequence;
  cout << "Input a DNA sequence: ";
  cin >> sequence;
  if (is_valid_sequence(sequence)) {
    cout << "The pattern " << sequence << " is valid for RE (TT+G)*(A+T)"
         << endl;
  } else {
    cout << "The pattern " << sequence << " is not valid for RE (TT+G)*(A+T)"
         << endl;
  }
  return 0;
}
