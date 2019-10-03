#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct meaningfulUnit {
  std::string category;
  std::string unit;
};

void saveUnit(meaningfulUnit &newUnit, std::vector<meaningfulUnit> &units) {
  units.push_back(newUnit);
}

void printUnits(std::vector<meaningfulUnit> &units) {
  std::cout << "\nPrinting Units:\n";
  std::cout << "Token \t\tLexeme\n";
  for (int i = 0; i < units.size(); i++) {
    std::cout << units[i].category << "\t" << units[i].unit << "\n";
  }
}
bool isFloat(std::string myString) {
    std::istringstream iss(myString);
    float f;
    iss  >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

void checkWord(std::string &word, std::vector<meaningfulUnit> &units) {
  //Checking for Valid Number
  if (isFloat(word)) {
    meaningfulUnit newUnit;
    newUnit.category = "Number\t";
    newUnit.unit = word;
    saveUnit(newUnit, units);
    word.erase();
    return;
  }

  //Checking for Keyword
  //Keywords included: int, float, bool, if, else, then, endif, while, whileend,
  //                   do, doend, for, forend, input, output, and, or, function
  std::string keywords[18] = {"int", "float", "bool", "if", "else", "then", "endif", "while", "whileend",
                              "do", "doend", "for", "forend", "input", "output", "and", "or", "function" };
  for (int i = 0; i < sizeof(keywords)/ sizeof(keywords[0]); i++) {
    if (word == keywords[i]) {
      meaningfulUnit newUnit;
      newUnit.category = "Keyword\t";
      newUnit.unit = word;
      saveUnit(newUnit, units);
      word.erase();
      return;
    }
  }

  //  Check for Valid Identifier
  //  Must include capital letters as well
  if (!word.empty()) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
              'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < sizeof(alphabet)/sizeof(alphabet[0]); i++) {
      if (word[0] == alphabet[i]) {
        meaningfulUnit newUnit;
        newUnit.category = "Identifier";
        newUnit.unit = word;
        saveUnit(newUnit, units);
        word.erase();
        return;
      }
    }
  }
  //Wasn't valid, therefore invalid identifier
  if (!word.empty()) {
    meaningfulUnit newUnit;
    newUnit.category = "Invalid Ident";
    newUnit.unit = word;
    saveUnit(newUnit, units);
    word.erase();
    return;
  }
  word.erase();
}

void checkSeperator(std::string &word, char &character, std::vector<meaningfulUnit> &units) {
  //Seperators included: ' ( ) { } [ ] , : ; !
  char seperators[11] = {'\'', '(', ')', '{', '}', '[', ']', ',',
    ':', ';', '!'};
  for (int i = 0; i < sizeof(seperators) / sizeof(seperators[0]); i++) {
    if (character == seperators[i]) {
      checkWord(word, units);
      meaningfulUnit newUnit;
      newUnit.category = "Seperator";
      newUnit.unit = character;
      saveUnit(newUnit, units);
      word.erase();
      return;
    }
  }

  //Operators included: * + - = / > < %
  char operators[8] = {'*', '+', '-', '=', '/', '>', '<', '%'};
  for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
    if (character == operators[i]) {
      checkWord(word, units);
      meaningfulUnit newUnit;
      newUnit.category = "Operator";
      newUnit.unit = character;
      saveUnit(newUnit, units);
      word.erase();
      return;
    }
  }
  //Check for spaces and tabs
  if (character == ' ' || character == '\t') {
    checkWord(word, units);
    return;
  }
  word += character;
}

void checkLine(std::string &line, std::vector<meaningfulUnit> &units) {
  std::string unit;
  //traverse the string
  for (int i = 0; i < line.length() ; i++) {
    checkSeperator(unit, line[i], units);       //stop at seperators
  }
}

int main() {
  //  *To Complete*
  std::ifstream inputFile ("test.txt");
  if (!inputFile.is_open()) {
    std::cout << "Error opening 'test.txt' file.\n";
    exit(0);
  }

  std::string line;
  std::vector<meaningfulUnit> units;
  if (inputFile.is_open()) {

    while (getline(inputFile, line)) {
      checkLine(line, units);
    }

    printUnits(units);
    inputFile.close();
  }

  std::ofstream outputFile ("output.txt");
  if (outputFile.is_open()) {
    outputFile << "Token \t\tLexeme\n";

    for (int i = 0; i < units.size(); i++) {
      outputFile << units[i].category << "\t" << units[i].unit << "\n";
    }
    outputFile.close();
  }

  return 0;
}
