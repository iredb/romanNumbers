#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> symbolValues {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int romanToInt(string romanNumber) {
    int resultValue = 0;
    int previousSymbolValue = 0;

    for (char symbol: romanNumber) {
      int curSymbol = symbolValues[symbol];

      if (curSymbol > previousSymbolValue) {
        resultValue += curSymbol - previousSymbolValue * 2;
        previousSymbolValue = curSymbol;
      } else {
        resultValue += curSymbol;
        previousSymbolValue = curSymbol;
      }

    }

    return resultValue;
}

string intToRoman(int number) {
  string resultString = "";

  for (int supposedValueIndex = 0; supposedValueIndex < end(values) - begin(values); ++supposedValueIndex){
    
    while (number >= values[supposedValueIndex]){
      resultString += symbols[supposedValueIndex];
      number -= values[supposedValueIndex];
    }
    
  }
  
  return resultString;
}

int main() {
  int requestType;
  
  cout << "type 1 to int to roman" << endl
       << "type 2 to roman to int" << endl;
  cin >> requestType;
  
  switch (requestType) {
    case 1:
      {
      int request;
      
      cout << "enter number from 1 to 3999: ";
      cin >> request;
      
      cout << endl << request << " = " << intToRoman(request);
      break;
      }
    case 2:
      string request;
      
      cout << "enter roman number: ";
      cin >> request;
      
      int intRequest = romanToInt(request);
      
      string expectedRequest = intToRoman(intRequest);
      
      if (request != expectedRequest) {
        char confirm;
        
        cout << endl << "strange number" << endl << "do you mean " << expectedRequest << "? (y/n)" << endl;
        cin >> confirm;
        cout << endl;
        
        switch (confirm) {
          case 'y':
            cout << expectedRequest << " = " << intRequest;
            break;
          case 'n':
            cout << "wrong number" << endl;
            break;
        }
      } else {
        cout << expectedRequest << " = " << intRequest;
      }
  }
  
  return 0;
}
