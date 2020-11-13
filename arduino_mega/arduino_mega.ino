
//libraries
#include <SoftwareSerial.h>;

//assign names to pins
  //inputs
  const int bb_pin = 22;
  const int gc_pin = 23;
  const int go_pin = 24;
  const int stat_pin = 25;
  const int ding_pin = 26;
  const int dong_pin = 27;
  //outputs
  const int lockinpos_pin = 40; // serial 1 lock, 2 unlock
  const int lockopen_pin = 41;  // serial 3 lock, 4 unlock
  const int trig_pin = 42;      // serial 5 trigger
  const int lights_pin = 43;    // serial 7 on, 8 off
  

//statuses
  char gate_pos[7] = "unknown"; //open, opening, closed, closing
  char beam[5];                 //block, clear
  char ledstatus[9];            //closed, notclosed, opening, closing, light, mains, battlow
  bool beamblock;
  bool ding;
  bool dong;
  bool gateopen;
  bool gateclosed;
  bool gateopening;
  bool gateclosing;
  bool lightson;
  bool lockedopen;
  bool lockedinpos;
  bool trigger;
  bool lightoverride;
  bool mainsok;
  bool battok;

//variables
  int dingdelay = 1000; //how long ding latches in ms
  int dongdelay = 1000; //how long dong latches in ms
  int relaydelay = 5000; //how long relay latches
  int triggerlength = 2000; //how long trigger output is active
  unsigned long triggertimer = millis();   //timer for trigger pulse

void setup() {

      
  //serial
  Serial.begin(115200);
  Serial.println("<Arduino is ready>");

    
  // put your setup code here, to run once:
  //from blink
  pinMode(LED_BUILTIN, OUTPUT);

  //for project - INPUTS
  pinMode(bb_pin,INPUT_PULLUP);
  pinMode(gc_pin,INPUT);
  pinMode(go_pin,INPUT);
  pinMode(stat_pin,INPUT);
  pinMode(ding_pin,INPUT);
  pinMode(dong_pin,INPUT);

  //for project - OUTPUTS
  pinMode(lockinpos_pin,OUTPUT);
  pinMode(lockopen_pin,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(lights_pin,OUTPUT);



}

void loop() {
  
  //this calls the blink function on the next page
  //blink();

  //Make serial active
  myserial();

  //turn trigger off after trigger lenght finished
    if ( trigger == true && ((millis () - triggertimer) >= triggerlength)) {
    digitalWrite(trig_pin, LOW);
    trigger = false;
    Serial.println("Trigger De-Activated");
    }
  //Monitor gate inputs
  gateinputs();
}
