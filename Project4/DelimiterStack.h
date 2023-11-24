#pragma once

class DelimiterStack {
private:
  struct DelimiterNode {
    char character;
    int lineNumber;
    int charCount;
  };

  // Define stack top
public:
  /* --- Constructor --- */
  DelimiterStack();
  
  /* --- Destructor --- */

  /* --- Accessors --- */
  bool isEmpty();
  void popDelimiter(char&, int&, int&); // reference variables because three variables cannot be returned through return statement

  /* --- Mutators --- */
  void push(char, int, int);
};