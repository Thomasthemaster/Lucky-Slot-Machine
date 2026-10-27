/* LUCKY SLOT MACHINE
Made by Thomas
Oct 18, 2026

Press the button, the lights flash around. They start to slow down, 
and if you get all 4 LEDs on at the end, then luck's on your side!  :)

*/

int buzzer = A1;
int leds[] = {11, 8, 5, 12};
int a, b, c, d;

int buttonPin = A5;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  for(int i = 0; i < 4; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  randomSeed(analogRead(A0));
}

bool playNote(int freq, int duration)
{
  tone(buzzer, freq);

  unsigned long start = millis();

  while(millis() - start < duration)
  {
    if(digitalRead(buttonPin) == LOW)   // interrupt button
    {
      noTone(buzzer);
      return false;
    }
  }

  noTone(buzzer);
  return true;
}

void winSound()
{
  int notes[] = {523,659,784,1047,1319,1568};

  for(int i=0;i<6;i++)
    if(!playNote(notes[i],80)) return;

  for(int i=5;i>=0;i--)
    if(!playNote(notes[i],60)) return;
}

void jackpotSound()
{
  int notes[] = {
    523,659,784,1047,
    1319,1568,2093,
    1568,2093,2637
  };

  for(int i=0; i<10; i++)
  {
    if(!playNote(notes[i], 100))
      return;
  }

  for(int i=0; i<20; i++)
  {
    digitalWrite(leds[0], !digitalRead(leds[0]));
    digitalWrite(leds[1], !digitalRead(leds[1]));
    digitalWrite(leds[2], !digitalRead(leds[2]));
    digitalWrite(leds[3], !digitalRead(leds[3]));

    tone(buzzer, random(1200, 2500));

    delay(40);

    if(digitalRead(buttonPin) == LOW)
    {
      noTone(buzzer);
      return;
    }
  }

  noTone(buzzer);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH)
    return;

  // Spin animation
  // Spin animation
for(int i=0; i<60; i++)
  {
    digitalWrite(leds[0], random(0,2));
    digitalWrite(leds[1], random(0,2));
    digitalWrite(leds[2], random(0,2));
    digitalWrite(leds[3], random(0,2));

    tone(buzzer, 250 + i * 18);

    delay(15 + i * 4);   // slows down as it spins
  }

  noTone(buzzer);

  noTone(buzzer);

  // Custom odds
  int result = random(100);

  if(result < 2)          // 2%
  {
    a=1; b=1; c=1; d=1;
  }
  else if(result < 6)     // 4%
  {
    a=1; b=1; c=1; d=0;
  }
  else if(result < 10)    // 4%
  {
    a=0; b=1; c=1; d=1;
  }
  else
  {
    a=random(0,2);
    b=random(0,2);
    c=random(0,2);
    d=random(0,2);
  }

  digitalWrite(leds[0], a);
  digitalWrite(leds[1], b);
  digitalWrite(leds[2], c);
  digitalWrite(leds[3], d);

  // JACKPOT
  if(a && b && c && d)
  {
    jackpotSound();

    for(int i=0;i<10;i++)
    {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);

      delay(100);

      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);

      delay(100);
    }
  }

  // WIN
  else if((a && b && c && !d) || (!a && b && c && d))
  {
    winSound();
  }

  // LOSE
  else
  {
    tone(buzzer, 140);
    delay(250);
    noTone(buzzer);
  }

  while(digitalRead(buttonPin) == LOW);
  delay(100);
}
