// Wayne Pinnock, CSCI 211, Spring Semester 2023
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c);  // Returns true if the queen in column c is okay

void print(int q[]);  // Print the array

void backtrack(int & c);  // Backtrack

int main() {
  int q[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Initialize the array to 0.
  int c = 1;  // Start in the 1st row, 1st column

  bool reset = false;

  while(true) {  // End the loop if you backtrack from the first column
    while(c < 8) {
      if(reset == false) {
        q[c] = -1;
      }
      reset = false;
      while(q[c] < 8) {
        q[c]++;  // Move to the next column
        
        while(q[c]==8) {  // If you have passed the end of the column, backtrack
          backtrack(c); // Call the print function and backtrack
          q[c]++;
          }
        
        if(ok(q, c)) {  // Otherwise, call the ok function. If it returns true, go back to the beginning of the outer loop
          break;
          }
        }
      c++;
      }
    print(q);
    backtrack(c);
    reset = true;
    }
  return 0;
}

bool ok (int q[], int c) {
  for(int i = 0; i < c; i++) {
    if((q[i] == q[c]) || (abs(q[c] - q[i]) == (c-i))) {
      return false;
    }
  }
  return true;
}

void backtrack(int & c) {
  c--;
  if(c == -1) exit(1);
}

void print(int q[]) {
  static int numSolutions = 0;
  int board[8][8] = {0};
  cout << "Solution #" << ++numSolutions << ": ";
  for(int i = 0; i < 8; i++) {
    cout << q[i];
  }
  cout << endl;
  for(int i = 0; i < 8; i++) {
    board[q[i]][i] = 1;
  }
  
  for(int r = 0; r < 8; r++) {
    for(int c = 0; c < 8; c++) {
        cout << board[r][c] << " ";
      }
      cout << endl;
  }
  cout << endl;
}