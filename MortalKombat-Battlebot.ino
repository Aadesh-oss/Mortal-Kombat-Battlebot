int A=5;//Motor 1 Right Side
int B=6;
int C=3;//motor 2 Left Side
int D=4;

int Grinder=7;

int sensitivity=200; //defalut 250

int receiver_pins[] = {A0, A1, A2, A3};
int receiver_values[] = {0, 0, 0, 0};
int res_min = 1100;
int res_max = 1900;

int working_range = 255;// motor driver range

boolean prt = true;

int mode = 0;
int mode2 = 0;

int mode3 = 0;
//-1 - transmeter not connected or out of range
//0- trans connected and ready
//1 - low speed
//2 = high speed mode

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(A, OUTPUT);//motor 1 left
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);//motor 2
  pinMode(D, OUTPUT);

 pinMode(Grinder, OUTPUT);

  Serial.begin(115200);
  //Staring delay with LED



}

void loop() {
  receive();


  int m1 = 0;
  int m2 = 0;

  int rot = receiver_values[0];
///////////////////////////right
  if (mode == 1) {
  upR();
//downR();
Serial.println("down");
  } else if (mode == 2) {
Serial.println("up");
 downR();
//upR();

  }
  else if (mode == 3) {
 stopR();
  }
  else{
    Serial.println("LOW");
    }
//////////////////////////left
if (mode2 == 1) {
 // upL();
downL();
Serial.println("right");
  } else if (mode2 == 2) {

// downL();
  upL();
  Serial.println("left");
  }
  else if (mode2 == 3) {
 stopL();
// Serial.println("LOW");
  }
    
//////////left end


//Grinder//////
if (mode3 == 1) {
 // upL();

GrinderON();
Serial.println("G-ON");
  } else if (mode3 == 2) {

// downL();
GrinderOFF();
  Serial.println("G-OFF");
  }
//Grinder -- END//////


}
int rp = 0;
void receive() {

  receiver_values[rp] = map(pulseIn (receiver_pins[rp], HIGH), res_min, res_max, -1 * working_range, working_range);
  rp++;
  if (rp == 4) {
    rp = 0;
  }
  boolean activevalues = true;
  for (int i = 0; i < 4; i++) {
    if (prt) {
      Serial.print("CH");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print(receiver_values[i]);
      Serial.print(",\t");
    }
    if (receiver_values[i] < -1000) {
      activevalues = false;
    }
  }
  mode = 0;
  if (!activevalues) {
    mode = -1;
    /////////////////////////right
  } else if (receiver_values[1] >=sensitivity && receiver_values[1] <=350) {
    mode = 2;
  } else if (receiver_values[1] <= -sensitivity && receiver_values[1] >=-350) {
    mode = 1;
  }
  else if (receiver_values[1] < sensitivity && receiver_values[1] >-sensitivity) {
    mode = 3;
  }
  ///////////////////////////////left
  if (receiver_values[0] <= 350 && receiver_values[0] >=sensitivity) {//left up
    mode2 = 1;
  }
  else if (receiver_values[0] <= -sensitivity && receiver_values[0] >=-350) {//left dwn
    mode2 = 2;
  }
   else if (receiver_values[0] < sensitivity && receiver_values[0] >-sensitivity) {//left stop
    mode2 = 3;
    
  }

 //////////////////////////////
 if (receiver_values[2] <= 350 && receiver_values[2] >=sensitivity) {//left up
    mode3 = 1;
  }
  else if (receiver_values[2] <= -sensitivity && receiver_values[2] >=-350) {//left dwn
    mode3 = 2;
  }
   else if (receiver_values[2] < sensitivity && receiver_values[2] >-sensitivity) {//left stop
    mode3 = 2;
    
  }
  if (prt) {
    Serial.println("");
  }

}

