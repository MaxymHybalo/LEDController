int pwm = 1;
char input = 0;

#define RED 9
#define GREEN 5
#define BLUE 3

void setup() {
    Serial.begin(9600);
    pinMode(RED, INPUT); 
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    delay(1000);
}

int low = 100;
void colorChange(int colors[], bool reverse) {
    int limit = reverse ? 255 : low;
    int predicate = reverse ? -1 : 1;
    int counter = 0;
    while (counter <= 255) {
      for (int j = 0; j <= sizeof(colors) - 1; j++) {
        limit = limit + predicate;
        analogWrite(colors[j], constrain(limit, low, 255));
      }
      counter++;
      delay(10);
    }
}

void loop() {
    pwm = analogRead(5);

    pwm = map(pwm, 0, 1023, 0, 255);
    pwm = constrain(pwm, 0, 255);
    Serial.print("value: " );
    Serial.println(pwm);
    int red_green[2] = { RED, GREEN };
    int red_blue[2] = { RED, BLUE };
    int green_red[2] = { GREEN, RED };
    int green_blue[2] = { GREEN, BLUE };

    int red[1] = { RED };
    int green[1] = { GREEN };
    int blue[1] = { BLUE };
    colorChange(red, false);
    colorChange(red, true);

    colorChange(green, false);
    colorChange(green, true);

    colorChange(blue, false);
    colorChange(blue, true);

    colorChange(red_green, false);
    colorChange(red_green, true);

    colorChange(red_blue, false);
    colorChange(red_blue, true);

    colorChange(green_red, false);
    colorChange(green_red, true);

    colorChange(green_blue, false);
    colorChange(green_blue, true);


    // for (int i = 0; i<=255; i++) {
    //   analogWrite(RED, i);
    //   delay(30);
    // }
 
    // analogWrite(RED, 0);


    // for (int i = 0; i<=255; i++) {
    //   analogWrite(GREEN, i);
    //   delay(30);

    // }
    // analogWrite(GREEN, 0);

    // for (int i = 0; i<=255; i++) {
    //   analogWrite(BLUE, i);
    //   delay(30);
    // }
      
    // analogWrite(BLUE, 0);
    
    // analogWrite(BLUE, pwm);

}

