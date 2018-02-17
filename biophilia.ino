// sketch to drive the El wire installation part of the biophilia art installation using the SparkFun El Sequencer
// Bobb Amidon

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

void pulse(int channel_num, int pulse_length) {
  digitalWrite(channel_num, HIGH);   // turn the EL <channel_num> on
  delay(pulse_length);              // wait for <pulse_length> miliseconds
  digitalWrite(channel_num, LOW);    // turn the EL <channel_num> off
}

void biophilia_pulse_sequence(int x) {
  // generates random pulse sequence call and response
  
  int num_pulses = random(1, 3); // sets the number of flashes to be used in this loop; currently a random number between 1 and 3
  int pulse_length = 100;  // sets how long a channel is on
  int delay_length = 50;  // sets how long a channel is on

  for (int i=0; i < num_pulses; i++) {
    pulse(x, pulse_length);
    delay(delay_length); 
    pulse(x, pulse_length);
  }

  delay(random(500, 1000));
  
  for (int i=0; i < num_pulses; i++) {
    pulse(x+1, pulse_length);
    delay(delay_length); 
    pulse(x+1, pulse_length);
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

  
  biophilia_pulse_sequence(random(2, 9));

  digitalWrite(10, status);   // blink both status LEDs
  digitalWrite(13, status);
  status = !status; 

  delay(random(1000, 5000));
}

