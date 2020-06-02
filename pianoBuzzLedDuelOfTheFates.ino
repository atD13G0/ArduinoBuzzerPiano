//Key Values
const int aVal = 10;
const int bVal = 12;
const int cVal = 1;
const int dVal = 3;
const int eVal = 5;
const int fVal = 6;
const int gVal = 8;

//sharp Key Values
const int cValS = 2;
const int dValS = 4;
const int fValS = 7;
const int gValS = 9;
const int aValS = 11;

int sharps[] = {cValS, dValS, fValS, gValS, aValS};

//Led Pins
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;
const int ledPin6 = 7;
const int ledPin7 = 8;

//Octave Decleration
double crntOctave = 4;


//get the frequcny method
int frequency(int val, int octave) {
  if (crntOctave == 0) {
    crntOctave = 1;
  }
  double octaveBase = ((crntOctave - 1) * 12) + 3;
  double note = octaveBase + val;

  double exponent = (note - 49) / 12;
  double power = pow(2, exponent);
  double frequency = power * 440;

  return frequency;
}

//turn no the corresponding LED
void light(int val) {

  for (int i = 0; i < 5; i++) {
    if (val == sharps[i]) {
      val -= 1;
    }
  }

  switch (val) {

    case aVal:
      digitalWrite(ledPin1, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      break;

    case bVal:
      digitalWrite(ledPin2, HIGH);
      delay(100);
      digitalWrite(ledPin2, LOW);
      break;

    case cVal:
      digitalWrite(ledPin3, HIGH);
      delay(100);
      digitalWrite(ledPin3, LOW);
      break;

    case dVal:
      digitalWrite(ledPin4, HIGH);
      delay(100);
      digitalWrite(ledPin4, LOW);
      break;

    case eVal:
      digitalWrite(ledPin5, HIGH);
      delay(100);
      digitalWrite(ledPin5, LOW);
      break;

    case fVal:
      digitalWrite(ledPin6, HIGH);
      delay(100);
      digitalWrite(ledPin6, LOW);
      break;

    case gVal:
      digitalWrite(ledPin7, HIGH);
      delay(100);
      digitalWrite(ledPin7, LOW);
      break;
  }
}

//activacte the buzzer
void buzz(int val) {
  tone(12, frequency(val, crntOctave));
  light(val);
  noTone(12);
}

//SETUP
void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);

  //led pinmodes
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);

}

//LOOP
void loop()
{
  delay(3000);
  crntOctave = 3;
  for (int i = 0; i <= 8; i++) {
    buzz(gVal);
    delay(100);
    buzz(aVal);
    delay(100);
    buzz(gVal);
    buzz(fValS);
    buzz(eVal);
    delay(100);
  }

  for (int i = 0; i < 4; i++) {
    crntOctave = 4;
    buzz(eVal);
    delay(100);
    buzz(fValS);
    delay(100);
    buzz(gVal);
    delay(300);
    buzz(aVal);
    delay(300);
    crntOctave = 3;
    buzz(bVal);
    delay(300);
    crntOctave = 4;
    buzz(aVal);
    delay(300);
    buzz(gVal);
    delay(100);
    buzz(fValS);
    delay(100);
    buzz(eVal);
    delay(700);
  }

  for (int i = 0; i < 2; i++) {
    for (int i = 0; i < 3; i++) {
      buzz(gVal);
      delay(100);
      buzz(gVal);
      delay(500);
    }
    buzz(aVal);
    delay(100);
    buzz(fValS);
    delay(500);
  }

  for (int i = 0; i <= 4; i++) {
    buzz(gVal);
    delay(100);
    buzz(aVal);
    delay(100);
    buzz(gVal);
    buzz(fValS);
    buzz(eVal);
    delay(100);
  }

  delay(700);
  buzz(gVal);
  delay(100);
  buzz(aVal);
  delay(100);
  buzz(gVal);
  buzz(fValS);
  buzz(eVal);
  delay(100);

}
