int input_data;
boolean LedOn = false;
boolean musicOn = false;

// LED : Christmas Lights
int ledPin1 = 3; // first LED on pin 3
int ledPin2 = 5; // second LED on pin 5
int ledPin3 = 6; // third LED on pin 6
int ledPin4 = 9; // fourth LED on pin 9
int ledPin5 = 10; // fifth LED on pin 10
int ledPin6 = 11; // sixth LED on pin 11
int brightness1 = 0; // minimum brightness
int brightness2 = 255; // maximum brightness
int fadeAmount = 51; // how many points to fade the LED by

// SONG : Jingle Bells
int length = 26;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(12, HIGH);
    delayMicroseconds(tone);
    digitalWrite(12, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) { 
  char names[] = { 'c', 'd', 'e', 'f', 's', 'g', 'a', 'v', 'b', 'C', 'D', 'E' };
  int tones[] = { 1915, 1700, 1519, 1432, 1352, 1275, 1136, 1073, 1014, 956, 852, 758 };
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

// setup code
void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  while(Serial.available())
  {
    input_data = Serial.readString().toInt();
    Serial.print(input_data);
  }

  // LED ON/OFF
  if(input_data == 1)
  {
    LedOn = true;
  }
  else if(input_data == 0)
  {
    LedOn = false;
    musicOn = false;
  }
  // MUSIC ON/OFF
  else if(input_data == 2)
  {
    musicOn = true;
  }
  else if(input_data == 3)
  {
    musicOn = false;
  }
  else if(input_data == 4)
  {
    musicOn = true;
    LedOn = true;
  }

  // LED
  if(LedOn == true)
  {
    // set the brightness of LED's:
    analogWrite(ledPin1, brightness1);
    analogWrite(ledPin2, brightness2);
    analogWrite(ledPin3, brightness1);
    analogWrite(ledPin4, brightness2);
    analogWrite(ledPin5, brightness1);
    analogWrite(ledPin6, brightness2);
    // change the brightness for next time through the loop:
    brightness1 = brightness1 + fadeAmount;
    brightness2 = brightness2 - fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness1 == 0 || brightness1 == 255){
      fadeAmount = -fadeAmount;
    }
  // wait for 30 milliseconds to see the dimming effect
    delay(30);
    }
  else if (LedOn == false){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
  }

  // MUSIC
  if(musicOn == true){
      for (int i = 0; i < length; i++) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
      // pause between notes
      delay(tempo / 2); 
    }
  }
  else if (musicOn == false){
    digitalWrite(12, LOW);
  }
}