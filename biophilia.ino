// Test sketch for El Escudo Dos
// Turn each EL channel (A-H) on in sequence and repeat
// Mike Grusin, SparkFun Electronics



void setup() {                
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo, 
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);     
  pinMode(13, OUTPUT);    
}

void blink(int x, int y) {
  digitalWrite(x, HIGH);   // turn the EL channel on
  delay(y);              // wait for <y> miliseconds
  digitalWrite(x, LOW);    // turn the EL channel off
}

void shannon_blink_sequence(int x) {  
  int num_blinks = random(1, 3);
  int blink_length = 100;

  for (int i=0; i < num_blinks; i++) {
    blink(x, blink_length);
    delay(50); 
    blink(x, blink_length);
  }

  delay(random(500, 1000));
  
  for (int i=0; i < num_blinks; i++) {
    blink(x+1, blink_length);
    delay(50); 
    blink(x+1, blink_length);
  }
}

void loop() 
{
  int x,status;

  int my_array[100];
  int i;
  for (i = 0; i < 100; i++) {
      my_array[i] = rand();
  }

  
  shannon_blink_sequence(random(2, 9));

  digitalWrite(10, status);   // blink both status LEDs
  digitalWrite(13, status);
  status = !status; 

  delay(random(1000, 5000));
}

