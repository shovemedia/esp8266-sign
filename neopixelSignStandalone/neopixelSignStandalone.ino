#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <FS.h>
//needed for library
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <WiFiClient.h>



#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 12
#define PIN2 13
#define PIN3 4
#define PIN4 5




// select wich pin will trigger the configuraton portal when set to LOW
// ESP-01 users please note: the only pins available (0 and 2), are shared 
// with the bootloader, so always set them HIGH at power-up
#define TRIGGER_PIN 0

const int led = 4;

ESP8266WebServer server(80);

int currentFrame = 0;
volatile int maxFrames = 0;


bool once = true;

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;

    

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(64, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(64, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(64, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(64, PIN4, NEO_GRB + NEO_KHZ800);



char charBuf[50];


void setPx (int stripIndex, int index, uint32_t c) {
    switch(stripIndex) {
      case 0:
      strip1.setPixelColor(index, c);      
      break;
      case 1:
      strip2.setPixelColor(index, c);      
      break;
      case 2:
      strip3.setPixelColor(index, c);      
      break;
      case 3:
      strip4.setPixelColor(index, c);      
      break;
    }
}

void handleRoot() {
//  int i = server.arg("n").toInt();
//  int _r = server.arg("r").toInt();
//  int _g = server.arg("g").toInt();
//  int _b = server.arg("b").toInt();
//
//  uint32_t c = strip.Color(_r, _g, _b);

int len = server.args();




  for(uint16_t i=0; i<len; i++) {
    String argName = server.argName(i);

    int delimIndex = argName.indexOf("_");
//
    int stripIndex = (argName.substring(0, delimIndex)).toInt();
    int index = (argName.substring(delimIndex+1, argName.length() )).toInt();

    uint32_t c;
    String arg = server.arg(argName);
    arg.toCharArray(charBuf, 50);
    sscanf(charBuf, "%x", &c);

    //(int) strtol(colorArg, NULL, 0);

    switch(stripIndex) {
      case 0:
      strip1.setPixelColor(index, c);      
      break;
      case 1:
      strip2.setPixelColor(index, c);      
      break;
      case 2:
      strip3.setPixelColor(index, c);      
      break;
      case 3:
      strip4.setPixelColor(index, c);      
      break;
      
    }




//        Serial.println(n);
//        Serial.println(server.arg(n));
//        
//        Serial.println(c);
//        Serial.println("--");
        
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "ok!");
}


void handleSet() {
    String currentFrame = server.arg("frame");

    setMaxframes(currentFrame);

    String path = "/frame_";
    String ext = ".json";
    String filename = path + currentFrame + ext;

    String data = "";

    if (SPIFFS.exists(filename)) {
      SPIFFS.remove(filename);
    }
  
    //file exists, reading and loading
    Serial.println("writing config file " + filename);
    File configFile = SPIFFS.open(filename, "w");
    if (configFile) {
      
//            
      int len = server.args();
        for(uint16_t i=0; i<len; i++) {
          String argName = server.argName(i);


          
          if (argName != "frame") {
            configFile.println(argName + "=" + server.arg(argName) );      
//                Serial.println( argName + "=" + server.arg(argName) );       
          }
      }
      
    } else {
        Serial.println( "Could not open for writing");    
      }



      server.sendHeader("Access-Control-Allow-Origin", "*");

      configFile.close();  
                


    


    server.send(200, "text/plain", filename + " " + "saved");
    
}

void handleGet() {

      String currentFrame = server.arg("frame");

      String path = "/frame_";
      String ext = ".json";
      String filename = path + currentFrame + ext;

        Serial.println("read config file " + filename);

      if (SPIFFS.exists(filename)) {
        //file exists, reading and loading

        File configFile = SPIFFS.open(filename, "r");
        if (configFile) {
          Serial.println(configFile);

            server.sendHeader("Access-Control-Allow-Origin", "*");

            size_t sent = server.streamFile(configFile, "text/plain"); // And send it to the client
            configFile.close();  
                    
            if (currentFrame.toInt() > maxFrames) {
              maxFrames = currentFrame.toInt();
            }

        }
      } else {
          server.send(200, "text/plain", filename + " " + "not configured");
      }
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}



void setMaxframes(String n) {
      // maxframes = n;

  String path = "/maxFrames";
  String ext = ".json";
  String filename = path + ext;

  if (SPIFFS.exists(filename)) {
    SPIFFS.remove(filename);
  }

  //file exists, reading and loading

  File configFile = SPIFFS.open(filename, "w");
  if (configFile) {
    configFile.println(n);      
    Serial.println("writing maxFrames file " + n);
    Serial.println("\n");
  
  } else {
    Serial.println( "Could not open for writing");  
  }
  configFile.close();
}






void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\n Starting");


  #ifdef ESP8266
  Serial.println("\n ESP8266 Mode");
  #endif // ESP8266

  pinMode(TRIGGER_PIN, INPUT);

  pinMode(led, OUTPUT);
  digitalWrite(led, 0);


  strip1.begin();
  strip1.show();
  
  strip2.begin();
  strip2.show();
  
  strip3.begin();
  strip3.show();
  
  strip4.begin();
  strip4.show();
  

  server.on("/", handleRoot);

    server.on("/get", handleGet);
    server.on("/set", handleSet);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.on("/led", []() {
    String state=server.arg("state");
    if (state == "on") digitalWrite(13, LOW);
    else if (state == "off") digitalWrite(13, HIGH);
    server.send(200, "text/plain", "Led is now " + state);
  });
  

  server.onNotFound(handleNotFound);



  
}





void loop() {
  // is configuration portal requested?
  if ( digitalRead(TRIGGER_PIN) == LOW ) {


    //reset settings - for testing
    //wifiManager.resetSettings();

    //sets timeout until configuration portal gets turned off
    //useful to make it all retry or go to sleep
    //in seconds
    //wifiManager.setTimeout(120);

    //it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration

    //WITHOUT THIS THE AP DOES NOT SEEM TO WORK PROPERLY WITH SDK 1.5 , update to at least 1.5.1
    //WiFi.mode(WIFI_STA);

    Serial.println("On Demand AP");
    
    
    if (!wifiManager.startConfigPortal("OnDemandAP")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.reset();
      delay(5000);
    } 
  }

  if (once)
  {
    once = false;

    wifiManager.autoConnect();
    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
    
    server.begin();
    Serial.println("HTTP server started");


    //read configuration from FS json
    Serial.println("mounting FS...");
  
    if (SPIFFS.begin()) {
      Serial.println("mounted file system");

      if (!SPIFFS.exists("/formatComplete.txt")) {
        Serial.println("Please wait 30 secs for SPIFFS to be formatted");
        SPIFFS.format();
        Serial.println("Spiffs formatted");
       
        File f = SPIFFS.open("/formatComplete.txt", "w");
        if (!f) {
            Serial.println("file open failed");
        } else {
            f.println("Format Complete");
        }
      } else {
        Serial.println("SPIFFS already formatted");
      }



      String path = "/maxFrames";
      String ext = ".json";
      String filename = path + ext;


      String dat = "";
      
      if (SPIFFS.exists(filename)) {
        //file exists, reading and loading
    //    Serial.println("reading config file");
        File configFile = SPIFFS.open(filename, "r");
        if (configFile) {

            while (configFile.available()){
  //            configData += char(configFile.read());
                dat = configFile.readStringUntil('\n');
            
  //              int delimIndex = dat.indexOf("_");
  //              int eqIndex = dat.indexOf("=");
            
                int stripIndex; //  = (dat.substring(0, delimIndex)).toInt();
                int index; //  = (dat.substring(delimIndex+1, eqIndex )).toInt();
                // String c_str = (dat.substring(eqIndex+1, dat.length() ));
                uint32_t c;
                
                dat.toCharArray(charBuf, 50);
                sscanf(charBuf, "%d", &maxFrames);
                  
                Serial.println("maxFrames " + maxFrames);
            }

        } else {
          Serial.println("maxFrames corrupt?");
        }
        
      } else {
        Serial.println("maxFrames unknown");
      }



    }
  }

  // put your main code here, to run repeatedly:
    server.handleClient();





    String path = "/frame_";
    String ext = ".json";
    String filename = path + currentFrame + ext;


    String dat = "";
    
    if (SPIFFS.exists(filename)) {
      //file exists, reading and loading
  //    Serial.println("reading config file");
      File configFile = SPIFFS.open(filename, "r");
      if (configFile) {
            while (configFile.available()){
  //            configData += char(configFile.read());
                dat = configFile.readStringUntil('\n');
            
  //              int delimIndex = dat.indexOf("_");
  //              int eqIndex = dat.indexOf("=");
            
                int stripIndex; //  = (dat.substring(0, delimIndex)).toInt();
                int index; //  = (dat.substring(delimIndex+1, eqIndex )).toInt();
                // String c_str = (dat.substring(eqIndex+1, dat.length() ));
                uint32_t c;
                
                dat.toCharArray(charBuf, 50);
                sscanf(charBuf, "p_%d_%d=%x", &stripIndex, &index, &c);
                  
                //(int) strtol(colorArg, NULL, 0);

                setPx (stripIndex, index, c);


            }

        }

        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
  
        configFile.close();

      }

      currentFrame++;
      
      if (currentFrame > maxFrames ) {
        currentFrame=0;
      }
      
  
}