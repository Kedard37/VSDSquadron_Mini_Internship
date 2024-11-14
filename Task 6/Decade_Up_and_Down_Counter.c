// C++ code
// Written By: Kedar Desai
// Decade Up & Down Counter using VSDSquadron Mini Board

// Define segment and button pins
const int segmentPins[] = {PC1, PD2, PD3, PD4, PD5, PD6, PC7};
const int UpCountPin = PD0;  // UpCount button pin

// Digits from 0 to 9 mapped to segments A-G (assuming common cathode display)
// Format: {A, B, C, D, E, F, G}
//    ---A---
//   |       |
//   F       B
//   |       |
//    ---G---       
//   |       |
//   E       C
//   |       |
//    ---D--- 
const bool digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

int currentNumber = 0;  // Current number displayed
int delayTime = 500;    // Delay time

void setup() {
  // Set all segment pins as OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  pinMode(UpCountPin, INPUT);   // Set button pin as INPUT with pull-up resistor
  displayDigit(currentNumber);  // Display the initial number
  delay(delayTime);
}

void loop() {
  int UpCount = digitalRead(UpCountPin);

  if (UpCount == HIGH) {
    // Count up from 0 to 9
    currentNumber++;
    if (currentNumber > 9) {
      currentNumber = 0;  // Reset to 0 if it goes above 9
    }
  } else {
    // Count down from 9 to 0
    currentNumber--;
    if (currentNumber < 0) {
      currentNumber = 9;  // Reset to 9 if it goes below 0
    }
  }

  displayDigit(currentNumber);  // Display the current number
  delay(delayTime);
}

// Function to display a specific digit on the 7-segment display
void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}
