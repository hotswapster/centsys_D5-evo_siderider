
//libraries
#include <SoftwareSerial.h>;

//time to start
  int boottime = millis();
  int timesinceboot;

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
  char beam[7] = "unknown";                 //block, clear
  char ledstatus[9] = "unknown";            //closed, notclosed, opening, closing, light, mains, battlow
  bool beamblock;               //used
  bool ding;                    //used
  bool dong;                    //used
  bool gateopen;                //used
  bool gateclosed;              //used
  bool lightson;                //used
  bool lockedopen;              //used
  bool lockedinpos;             //used
  bool trigger;                 //used
  //from status led
  bool lightoverride;
  bool gateopening;
  bool gateclosing;
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
  Serial.println("");
  Serial.println("<Arduino is ready>");
  Serial.println("https://github.com/hotswapster/centsys_D5-evo_siderider");
  Serial.println("MIT License");

    
  // put your setup code here, to run once:
  //from blink
  pinMode(LED_BUILTIN, OUTPUT);

  //for project - INPUTS
  pinMode(bb_pin,INPUT_PULLUP);
  pinMode(gc_pin,INPUT_PULLUP);
  pinMode(go_pin,INPUT_PULLUP);
  pinMode(stat_pin,INPUT_PULLUP);
  pinMode(ding_pin,INPUT_PULLUP);
  pinMode(dong_pin,INPUT_PULLUP);

  //for project - OUTPUTS
  pinMode(lockinpos_pin,OUTPUT);
  pinMode(lockopen_pin,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(lights_pin,OUTPUT);
  
  timesinceboot = millis();// - boottime;
  Serial.println("Setup complete. Begin running program.");
  Serial.println("");
  Serial.print("Boot time was: ");
  Serial.println(String(String(timesinceboot) + "ms"));

}

void loop() {
  
  //blink for testing
  //blink();

  //Make serial active
  myserial();
  
  //Monitor gate inputs
  gateinputs();

  //Enable doorbell
  doorbell();
  
  //turn trigger off after trigger length finished
    if ( trigger == true && ((millis () - triggertimer) >= triggerlength)) {
    digitalWrite(trig_pin, LOW);
    trigger = false;
    Serial.println("Trigger De-Activated");
    }

}
