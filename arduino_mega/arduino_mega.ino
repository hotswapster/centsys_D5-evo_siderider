
//assign names to pins

  const int bb_pin = 22;
  const int gc_pin = 23;
  const int go_pin = 24;
  const int stat_pin = 25;
  const int ding_pin = 26;
  const int dong_pin = 27;
  const int lockinpos_pin = 40;
  const int lockopen_pin = 41;
  const int trig_pin = 42;
  const int lights_pin = 42;
  

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

//variables
  int dingdelay = 1000; //how long ding latches in ms
  int dongdelay = 1000; //how long dong latches in ms

void setup() {
  // put your setup code here, to run once:
  //from blink
  pinMode(LED_BUILTIN, OUTPUT);

  //for project - INPUTS
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  pinMode(24,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);

  //for project - OUTPUTS
  pinMode(40,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //this calls the blink function on the next page
  blink();
}
