#include <WiFi.h> //wifi library that checks wheather wifi connection is intiated or not
//Depricated it conflicts with the existing Libraries
//#include <WiFiLink.h> //trying to create link with the wifi and stuff
#include <Adafruit_MPU6050.h> //MPU6050 six axis accel, Gyro Library
#include <Adafruit_Sensor.h> //sensor library create a layer of abstraction somehow
#include <Wire.h> //intitating the I2C communication protocol
//#include <NTPclient.h>//A library that remove the need of use of inaccurate data/readings from internal clock
//instead it uses External clock to store the information about the time then overwrites or flushes according to program structure
const char* wifi_ssid= "M3HIve-PTCL"; //Wifi_name
const char* passwd = "M3Hive$1966"; //password
Adafruit_MPU6050 mpu;//creating an instance of object class
//WiFiUDP; //create an object class that allow connectionless communication with the designated IP

struct acess_mode{
  char acessmodtype; //creating Acess Point type variable act like a WiFi device
  String inputString; //created a Seperated string to store the value of each incoming and outgoing variable store within the memory
  int WIFIscannetwork;
};
acess_mode a;//creating another object class to simplify the name
void ESPReboot(){
  Serial.print("Restarting ESP...");
  ESP.restart(); //restarting ESP if either wifi mode fails
}
void setup() {
Serial.begin(115200);  // put your setup code here, to run once:
while(!Serial){
  //check for serial port if any device is connected to it 
}
String url; //string variable that store URL value that maybe used to connect to the internet
String SOS; //Sending the error message in case the communication with the device fails entirely
const int battery_min_voltage = 2.8; //minimum voltage required in order to power up ever component to minimum level
//the blinking mechansim and SOS message might gave you enough idea where the error message is headed to
//SOS will prompt the message if it finds lower than acceptable threshold
const int battery_max_voltage = 4.2; //maximum voltage in  which all devices can operate without experiencing issues like burndown
// or excessive voltage
if(!mpu.begin()){
  Serial.print("failed to connect to the MPU"); //checking the state of MPU and identifying that this is in working condition or not
}
else{
  Serial.print("MPU is connected and working");
}
while(WiFi.status()!=WL_CONNECTED){   //condition will ilteratively checks if the Wifi insn't connected if it evalutes true then the WiFi stops working automatically
  Serial.print("."); //creating a dot sign that will execute each time the loop will run
  delay(1000); // 1 second delay to create an attractive presentation
}

//let's add little something to our code we will add WiFi.scannetworks();
// to check the available networks and connect them based on predefined 
// network name and id
Serial.println("Connected!"); //followed by an interactive connected sign once the wifi is connected and stuff
}

void loop() {
WiFi.begin(wifi_ssid, passwd);//now to check if the WiFi can be connected or not 
//referencing the name of wifi along with the password
Serial.print("Please check the acess mode?:\n");
if(Serial.available() > 0){
  char incoming_byte = Serial.read(); //reading the upcoming serial data 
  a.inputString += incoming_byte; //we concatinate the string with the upcoming byte and data
if(incoming_byte  == '\n')
{
  Serial.print("Please check acess mode");

}
else{
  Serial.print("please input the data once again"); //to break out of the loop
}
if(a.inputString =="A"){
WiFi.mode(WIFI_MODE_AP); //create another loop if you want to use hotspot type mode making your website act like wifi hotspot 
a.acessmodtype = 'A'; //Setting A to acess mode type 
//setting acessmodtype and storing them respectively on each character
//return ESPReboot();
}
if(a.inputString == "S"){
WiFi.mode(WIFI_MODE_STA); //WiFi will act as client type device
a.acessmodtype = 'S'; //Setting S to acessmodtype 
// what we actually did setting acessmodtype to each character
//return ESPReboot();
}

}
delay(100);
}

