/* Sam Irvin
  CMPSCI - 2250 - Project 4
*/

// This program tests input strings to verify the string contains valid sets of parentheses using a stack


/* Progrm Shall:
  - [ ] Contain a Stack class that:
    - [ ] Create a node
    - [ ] In each node store: 
      - [ ] a Character (char)
      - [ ] a line number (int)
      - [ ] a character count (int)
    - [ ] can either be a static or dynamic stack
  - [ ] Read user input
    - [ ] While the user has not entered the keyword "DONE":
      - [ ] accept user input using getline
      - [ ] store any left delimiter ( "{", "(", or "[" ) in the stack
        - [ ] store the delimiter character in the stack
        - [ ] store the line number the delimiter appears at
        - [ ] store the character count the delimiter appears at in the stack
      - [ ] compare any right delimiter ( "}", ")", or "]" ) to the item on top of the stack
        - [ ] if right delimiter corresponds to the left delimiter in on top of stack; continue
        - [ ] if right delimiter does not correspond to the left delimiter, return error
          - [ ] error example: Mismatched delimiter ( found at line 3, char 27 does not match } found at line 7, char 9
      - [ ] if stack is empty when right delimiter is entered, return error
        - [ ] error example: Right delimiter } had no left delimiter found at line 27, char 23
    - [ ] if user input is done, but stack is no empty
      - [ ] print the contents of the stack in a consistent format
*/

#include "DelimiterStack.h"
#include <iostream>
#include <string>

int main() {

  return 0; 
}