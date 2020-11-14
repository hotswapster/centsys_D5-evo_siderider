
//libraries
#include <SoftwareSerial.h>;

  //for temp sensors
    #include <OneWire.h>
    #include <DallasTemperature.h>
    #define ONE_WIRE_BUS 2 //sensor data connected to pin 2
    // Create a new instance of the oneWire class to communicate with any OneWire device:
    OneWire oneWire(ONE_WIRE_BUS);
    // Pass the oneWire reference to DallasTemperature library:
    DallasTemperature sensors(&oneWire);



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
  const int lightsensor_pin = A0;
  //outputs
  const int lockinpos_pin = 40; // serial 1 lock, 2 unlock
  const int lockopen_pin = 41;  // serial 3 lock, 4 unlock
  const int trig_pin = 42;      // serial 5 trigger
  const int lights_pin = 43;    // serial 7 on, 8 off
  

//statuses
  char gate_pos[9] = "unknown"; //open, opening, closed, closing
  char beam[9] = "unknown";                 //block, clear
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
  int lightlevel = 0; //from mlight dependent resistor
  unsigned long triggertimer = millis();   //timer for trigger pulse
  unsigned long startcycletime = millis();   //timer for measuring cycle time
  unsigned long endcycletime = 0;   //timer for calculating cycle time
  unsigned long cycletime = 0;   //timer for calculating cycle time
  unsigned long maxcycletime = 0;   //timer for calculating cycle time 
  float temperature;

void setup() {

      
  //serial over USB for program debugging
  Serial.begin(115200);
  Serial.println("");
  Serial.println("<Arduino is ready>");
  Serial.println("https://github.com/hotswapster/centsys_D5-evo_siderider");
  Serial.println("MIT License");

  //serial conneciton to nodemcu
  Serial1.begin(9600);

    
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
  pinMode(lightsensor_pin, INPUT);

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

  //one wire for temp
  sensors.begin();
}

void loop() {
  startcycletime = millis(); //measuring cpu cycle time
      
  //blink for testing
  //blink();

  //Make serial active
//  myserial();
  
  //Monitor gate inputs
  gateinputs();

  //Enable doorbell
  doorbell();

  //environ
  environ();

  //timed cycles
  thirtysec();
  tensec();
  fivesec();
  
  //turn trigger off after trigger length finished
    if ( trigger == true && ((millis () - triggertimer) >= triggerlength)) {
    digitalWrite(trig_pin, LOW);
    trigger = false;
    Serial.println("Trigger De-Activated");
    }

  mcuserial();


  //Calculate cycle time
    endcycletime = millis();
    cycletime = endcycletime - startcycletime;
    if(cycletime > maxcycletime){
      maxcycletime = cycletime;
    }
}
