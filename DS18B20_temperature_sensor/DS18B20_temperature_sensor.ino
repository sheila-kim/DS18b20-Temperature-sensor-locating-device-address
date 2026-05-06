//Code that reads temperature from several DS18b20 devices over a shared digital pin (OneWire)
//
#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 23

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// variable to hold device addresses
DeviceAddress Thermometer;

int deviceCount = 0;

void setup(void) {
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();
}

//copy your unique addresses here --add as many as you have
DeviceAddress sensor1 = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
DeviceAddress sensor2 = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void loop(void) {
  // Command all sensors on the bus to take a reading
  sensors.requestTemperatures();

  // Read specifically by the unique address
  float temp1 = sensors.getTempC(sensor1);
  float temp2 = sensors.getTempC(sensor2);

  // Check if sensor is actually connected
  if (temp1 == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor 1 not found!");
  } else {
    Serial.print("Sensor 1: ");
    Serial.print(temp1);
    Serial.println(" °C");
  }
  if (temp2 == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor 2 not found!");
  } else {
    Serial.print("Sensor 2: ");
    Serial.print(temp2);
    Serial.println(" °C");
  }

  delay(2000);
}
