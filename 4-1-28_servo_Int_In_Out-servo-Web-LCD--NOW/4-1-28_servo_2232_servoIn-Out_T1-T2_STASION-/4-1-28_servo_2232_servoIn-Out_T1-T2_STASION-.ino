//Train1_13_21_31_OK 4-1-16
//samkaku 追加
//3-10-5 collision  STR>>INT
//3-9-25 collision 追加
//3-9-24 Train3 Train4 スケッチ追加
//3-9-9#define PIN_PE2 19 ->23       // Servo Out/HIGH=>Sub LOW=>Main
//#define PIN_PE3 23 ->19
//3-8-29 SubSetTime22 = nowTime + 10000;  /5秒から10秒変更
//3-8-29   if(nowTime > SubSetTime22 && Train1 == "22" && Data6==1){//1 Sub>>Sub   
//3-8-24  TX-RX 変更　servoPin 変更
//Servo 追加
//3-8-23 LCD-monita完成
//3-8-12 monita追加
//3-8-4   localAP追加
//3-7-19  完成 //1=2ms 4ms err 6ms-OK Loop-4ms
//3-7-17  22 32 タイマー
//3-5-29_esp32_master_HOST_mflag-1ms
//***************************************
//Train1_go  : Send1=11
//Train1_stop: Send1=12
//Train1_slow: Send1=13
//Train1_odrain:Send1=14
//Train1_odrain:Send1=15
//Train2_go  : Send2=21
//Train2_stop: Send2=22
//Train2_slow: Send2=23
//Train2_odrain:Send2=24
//Train2_odrain:Send2=25
//Train3_go  : Send3=31
//Train3_stop: Send3=32
//Train3_slow: Send3=33
//Train3_odrain:Send3=34
//Train3_odrain:Send3=35
//Train4_go  : Send4=41
//Train4_stop: Send4=42
//Train4_slow: Send4=43
//Train4_odrain:Send4=44
//Train4_odrain:Send4=45
//９９，００，２２，００，００，０１，１６８４５，CRLF
#include <esp_now.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <Arduino.h>
#include "SPIFFS.h"
#define CHANNEL 0

/*uji
const char* ssid = "kumika_net";
const char* password = "wr58e36s";
//180-station 181-Train1 182-Train2 183-Train3 184-Train4 185-Train5

IPAddress ip(192, 168, 50, 180);     // IPアドレス（本機が利用するIP）
IPAddress gateway(192, 168, 50, 1);  // デフォルトゲートウェイ
IPAddress subnet(255, 255, 255, 0); // サブネットマスク
*/
/*
const char* ssid = "Xperia";
const char* password = "19601953";
IPAddress ip(192, 168, 43, 180);     // IPアドレス（本機が利用するIP）
IPAddress gateway(192, 168, 43, 69);  // デフォルトゲートウェイ
IPAddress subnet(255, 255, 255, 0); // サブネットマスク
*/
//kick
/*
const char* ssid = "KICK-event";
const char* password = "g6f5R9sP";
IPAddress ip(192, 168, 1, 180);     // IPアドレス（本機が利用するIP）
IPAddress gateway(192, 168, 1, 254);  // デフォルトゲートウェイ
IPAddress subnet(255, 255, 255, 0); // サブネットマスク
*/
//d-egg
/*
const char* ssid = "D-FAB2.4GHz";
const char* password = "0774681378";
IPAddress ip(192, 168, 11, 180);     // IPアドレス（本機が利用するIP）
IPAddress gateway(192, 168, 11, 1);  // デフォルトゲートウェイ
IPAddress subnet(255, 255, 255, 0); // サブネットマスク
*/
//ATERM

const char* ssid = "kick-ecce1b-g";
const char* password = "wr58e36s";
IPAddress ip(192, 168, 10, 180);     // IPアドレス（本機が利用するIP）
IPAddress gateway(192, 168, 10, 1);  // デフォルトゲートウェイ
IPAddress subnet(255, 255, 255, 0); // サブネットマスク

#define PIN_PE7 25          //PIN_PE7 51 LoopFlag(時間)>>>mega21
//=============
#define M_Train_go    36
#define S_Train_go    39
#define M_Timer_set   32
#define S_Timer_set   33
#define NANO_reset    27
byte Poji22  = 0;
byte Poji32  = 0;
byte Train1G = 0;
byte Train2G = 0;
byte Train3G = 0;
byte Train4G = 0;
byte T1MS    = 0;
byte T1SS    = 0;
byte T2MS    = 0;
byte T2SS    = 0;
byte T3MS    = 0;
byte T3SS    = 0;
byte T4MS    = 0;
byte T4SS    = 0;


//ADC-monita/===========
const byte LED_PIN = 26;  // LED黄色
const byte LED_MPIN = 0;  // LED_motor-B
String ledState;
int restart=0;
const int adcPin = 34;
const int R1 = 5100;
const int R2 = 2000;
float voltage;
//ADC-monita/===========
#define PIN_PE0 4          // Servo In/HIGH=>Sub  LOW=>Main
#define PIN_PE1 18          // Servo In
#define PIN_PE2 23         // Servo Out/HIGH=>Sub LOW=>Main
#define PIN_PE3 19          // Servo Out/Sub
#define StartSW 13
#define servoInt 15
byte ServoInFlag  = 0;       // ServoInFlag(0:Sub, 1:Main)
byte ServoOutFlag1 = 0;    // ServoOutFlag(0:Sub, 1:Main)
byte ServoOutFlag2 =0;
byte SubTimeResetFlag  = 0;  // SetTimeResetフラグ
byte MainTimeResetFlag = 0;  // SetTimeResetフラグ
byte Data6Flag=0;
byte startFlag=0;

String Termination,SInPoji,Train, Hedder,mTrain;
int  Train1, Train2, Train3,Train4;
String Train1s, Train2s, Train3s,Train4s;
int Stop1, Stop2, Stop3, Stop4;
int Slow1, Slow2, Slow3, Slow4;
int data5;
//===================
int first;//poji
int second;//poji
int third;//poji
int fourth;//poji
int Data1;//Train1
int Data2;//Train2
int Data3;//Train3
int Data4;//Train4
int Data5;//ServoIn
int Data6;//ServoOut
int Data7;
;//Sub
int Data8;//Main
int Main2=0;
int Send1;//One
int Send2;//Two
int Send3;//Three
int Send4;//Four
int ctr=0;
boolean direction = 0;
//====================
// Flag
volatile int Train1TimeSetFlag1=0;
volatile int Train2TimeSetFlag2=0;
volatile int Train3TimeSetFlag3=0;
volatile int Train4TimeSetFlag4=0;
volatile int Train1Flag1=0;
volatile int Train2Flag2=0;
volatile int Train3Flag3=0;
volatile int Train4Flag4=0;

// Timer
unsigned long nowTime;       // 現在時刻
unsigned long nowTimeOld;
unsigned long SubSetTime=0;    // "4""5""12"スタート時刻
unsigned long MainSetTime=0;    // "4""5""12"スタート時刻

unsigned long SubSetTime22=0;   // "32"スタート時刻　＊
unsigned long MainSetTime32=0;   // "32"スタート時刻　＊
unsigned long SubStartTime22=0;
unsigned long MainStartTime32=0;
unsigned long Sub=0;   // "32"スタート時刻　＊
unsigned long Main=0;   // "32"スタート時刻　＊
unsigned long SubSetTime21=0;    // "21"スタート時刻
unsigned long MainSetTime31=0;    // "21"スタート時刻
unsigned long SubSetTime4=0; 
unsigned long SubSetTime5=0;
unsigned long SubSetTime6=0; 
unsigned long SubSetTime7=0;
unsigned long SubSetTime8=0; 
unsigned long SubSetTime9=0;
unsigned long SubSetTime10=0; 
unsigned long SubSetTime11=0; 
unsigned long MainSetTime11=0; 
unsigned long SubSetTime12=0; 
unsigned long MainSetTime12=0; 
unsigned long SubSetTime13=0;   // "31"スタート時刻　＊
unsigned long MainSetTime13=0;   // "31"スタート時刻　＊
unsigned long Time22=0;
unsigned long Time32=0;



unsigned long MainServoTime32;
unsigned long SubServoTime22;
int SubServoTime22Flag=0;
int MainServoTime32Flag=0;
int cont = 0;             // 時間配列カウント(22 & 32)
int Lcont = 0;            // 時間配列カウント(10)
int lpcnt=0;
int lpcnt2=0;
int mc;
//char buf[250];30:AE:A4:97:5A:2C

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS[1]T5[2]T1[3]T2[4]T3
uint8_t broadcastAddress1[] = {0x7C,0x9E,0xBD,0x06,0x4B,0xD8};//Train_5-LCD
//uint8_t broadcastAddress2[] = {0x84,0xcc,0xA8,0x5D,0x10,0x78};//Train_1_mini
uint8_t broadcastAddress5[] = {0x84,0xcc,0xA8,0x5D,0x10,0x78};//Train_4_mini=4
//uint8_t broadcastAddress3[] = {0xC4,0x4F,0x33,0x0C,0x68,0x35};//Train_2_NEW=2
uint8_t broadcastAddress3[] = {0x4C,0x11,0xAE,0xCC,0x72,0xB8};//Train_2_ITOU=2
//uint8_t broadcastAddress4[] = {0xC8,0xC9,0xA3,0xC5,0xAC,0x5C};//Train_3_NEW
uint8_t broadcastAddress4[] = {0x94,0xB9,0x7E,0xDA,0x8B,0xF8};//Train_3_ITOU=3
uint8_t broadcastAddress2[] = {0xC8,0xC9,0xA3,0xC5,0xAC,0x5C};//Train_4_NEW-Train1=1
typedef struct test_struct {
  int One;//speed
  int Two;//speed
  int Three;//speed
  int Four;//speed
  int x;
  int first;//poji
  int second;//poji
  int third;//poji
  int fourth;//poji
  int SIn;   //servo In  Data5 1-sub 2-main
  int SOut;  //servo Out Data6 1-sub 2-main
  int SubLed;   //sub_start   1
  int MainLed;  //main_start  2
  //==============
  int Send1;
  int y; 
  //==============
  int Send2;
  int z; 
   //==============
  int Send3;
  int v; 
    //==============
  int Send4;
  int w; 
  } test_struct;
test_struct test;
//=====================


// callback when data is sent データ送信時のコールバック
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  //Serial.print("Packet to: ");
  // Copies the sender mac address to a string送信者のMACアドレスを文字列にコピーします
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2],mac_addr[3],mac_addr[4], mac_addr[5]);
 // Serial.println(test.x);
 // Serial.print(" send status:\t");
  //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
AsyncWebServer server(80);
//=============================
String readDHTTemperature() {//温度
  float value = analogRead(adcPin);
  //float value = analogRead(1234);
  Serial.println(value);
//float voltage = value * (R1+R2) / R2 *(3.6/4095);　 // 3.6 -> 3.9?
float voltage = value * (R1+R2) / R2 * (3.75/4095);
 //float t = dht.readTemperature();
 
 if (isnan(voltage)) {    
    //Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(voltage);
    return String(voltage);
  }
}
String processor(const String& var){
  Serial.println(var);
  if(var == "voltage"){
   return readDHTTemperature();
  }
   if(var == "STATE"){
    if(digitalRead(LED_MPIN)){
      ledState = "ON";
      } else{
      ledState = "OFF";
    }
    Serial.print(ledState);
    return ledState;
  }
  return String();
}
//========================
void result(); 
void control_1();
void control_2();
void control_3();
void control_4();
void setup_servo();
void Receive();
void setup() {
  Serial.begin(115200);   // USB_Moniter 
  Serial2.begin(1000000,SERIAL_8N1,16,17);        // 16Tx,17Rx Mega  18-RX1,17-RX2  serial 1
  //disableCore0WDT();
 // disableCore1WDT();
  pinMode(StartSW ,INPUT_PULLUP);
  pinMode(servoInt ,OUTPUT);
  pinMode(M_Train_go,INPUT);
  pinMode(S_Train_go,INPUT);
  pinMode(M_Timer_set,OUTPUT);
  pinMode(S_Timer_set,OUTPUT);
  pinMode(NANO_reset, OUTPUT);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(M_Timer_set,HIGH);
  digitalWrite(S_Timer_set,HIGH);
  digitalWrite(NANO_reset,  LOW);
  delay(500);
  digitalWrite(NANO_reset, HIGH);
 
    // SPIFFSのセットアップ
  if(!SPIFFS.begin(true)){
    //Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  WiFi.mode(WIFI_AP_STA);
   if (esp_now_init() != ESP_OK) {
    //Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);
   WiFi.config( ip, gateway, subnet );
   WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);                            //   0.5秒毎にチェック
      lpcnt += 1 ;                           //
      if (lpcnt > 6) {                       // 6回目(3秒) で切断/再接続
        WiFi.disconnect(true,true) ;         //
        WiFi.begin(ssid, password);    //
        lpcnt = 0 ;                          //
        lpcnt2 += 1 ;                        // 再接続の回数をカウント
      }                                      //
      if (lpcnt2 > 3) {                      // 3回 接続できなければ、
        ESP.restart() ;                      // ソフトウェアリセット
      }                                      //
      Serial.print(".");  
}
//Serial.print("Station IP Address: ");
//Serial.println(WiFi.localIP());
//Serial.print("Wi-Fi Channel: ");
//Serial.println(WiFi.channel());
 Receive();
 server.begin();
//============================================
 // サーバーのルートディレクトリにアクセスされた時のレスポンス
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // style.cssにアクセスされた時のレスポンス
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  // Onボタンが押された時のレスポンス
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(PIN_PE3, HIGH);
    restart=1;
    delay(10);
    restart=0;
    //Send2=22;
    //digitalRead(StartSW)=1;
    //Send1=13; 
   // Send2=24;
    //Send1=14;
   
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Offボタンが押された時のレスポンス
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED_PIN, LOW); 
     digitalWrite(PIN_PE3, LOW);
     restart=0;
   //Send2=25;
   //Send1=0;
 
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
   // VOLTボタンが押された時のレスポンス
  server.on("/temperture", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(LED_PIN, HIGH);
    Send1=888;
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
   server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });
//===============================================
  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  //Serial.println("HTTP server started");
   
  // register peer
  esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  // register first peer Train5 
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);//5
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
  // register second peer Train1 
  delay(100);
  if(Train1==22){
     esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);//1
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
  }
  /// register third peer Train2
  delay(100);
  if(Train2==32){
     esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, broadcastAddress3, 6);//2
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
  }
   /// register fourth peer Train3
   delay(100);
  if(Train3==21){ 
     esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, broadcastAddress4, 6);//3
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
  }
 
  // register five peer Train4
  //Serial.println(Train); 
  delay(100);
  if(Train4==31){
     esp_now_peer_info_t peerInfo;
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, broadcastAddress5, 6);//4
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
  }
  delay(100);
  /*
  Serial.print("T1===");
  Serial.println(Train1);
  Serial.print("T2===");
  Serial.println(Train2);
  Serial.print("T3===");
  Serial.println(Train3);
  Serial.print("T4===");
  Serial.println(Train4);
  */
 
 while(digitalRead(StartSW) == 0){}//1-0
 Serial2.write("R");
 delay(100);
 Serial2.write("4");//1=2ms 4ms  err 6ms-OK Loop-4ms
 Serial2.write("Z");
   setup_servo();
} 
uint8_t bs1[250];//1byteの符号付き整数
uint8_t bs2[250];//1byteの符号付き整数
void out_Servo_Contlor();
void Receive();
void sankaku();
void in_Servo_Contlor();
void emergency();
void In_home();
void FlagReset04();
void control_1();
void control_2();
void control_3();
void control_4();
void loop() {
   Receive();
   out_Servo_Contlor();
   in_Servo_Contlor();
   control_1();
   In_home();
   control_2();
   control_3();
   control_4();
   result();
   emergency();
   FlagReset04();
   sankaku();

   
  
  AsyncElegantOTA.loop();
 // Serial.print("digitalRead(StartSW)  ");
 // Serial.println(digitalRead(StartSW));
  ///Serial.println(Send1);
 // Serial.println(Send2);
 // Serial.println(Send3);
   unsigned long nowTime =  millis(); 
   Sub=SubSetTime22;   // "32"スタート時刻　＊
   Main=MainSetTime32; 
  //===========================
  /* 
  Serial.print("TrainTimeSetFlag1234==");
  Serial.print(Train1TimeSetFlag1);
  Serial.print(Train2TimeSetFlag2);
  Serial.print(Train3TimeSetFlag3);
  Serial.println(Train4TimeSetFlag4);
  Serial.print("SubSetTime22=");
  Serial.println(SubSetTime22);
  Serial.print("MainSetTime32=");
  Serial.println(MainSetTime32);

     Serial.println(digitalRead(S_Train_go));
     Serial.println(digitalRead(M_Train_go));
     Serial.println(Train);
     Serial.print("Train==");
     Serial.println(Train);
     Serial.print("Se1234==");
     Serial.print(Send1);
     Serial.print("-");
     Serial.print(Send2);
     Serial.print("-");
     Serial.print(Send3);
     Serial.print("-");
     Serial.println(Send4);
     Serial.print("Data5==");
     Serial.println(Data5);
     Serial.print("Data6==");
     Serial.println(Data6);
     Serial.print("Data7==");
     Serial.println(Data7);
 */   
 /*    
     Serial.print("Poji22>>32  ");
     Serial.print(Poji22);
     Serial.println(Poji32);
     
     Serial.print("T1SS-T4SS  ");
     Serial.print(T1SS);
     Serial.print(T2SS);
     Serial.print(T3SS);
     Serial.println(T4SS);
     Serial.print("T1MS-T4MS  ");
     Serial.print(T1MS);
     Serial.print(T2MS);
     Serial.print(T3MS);
     Serial.println(T4MS);
     
     Serial.print("Train1G>>4G  ");
     Serial.print(Train1G);
     Serial.print(Train2G);
     Serial.print(Train3G);
     Serial.println(Train4G);
     
     Serial.print("S_Train_go>M_Train   ");
     Serial.print(S_Train_go);
     Serial.println(M_Train_go);
  */  
    
    

}  
 

 

  
