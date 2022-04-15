#include <DHT.h>


#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define NUMS 20

float average(float arr[], size_t len);
void update_array(float* array, size_t len, float value);


float nums[NUMS] = {0};

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  //  if(Serial.available()) {
  float temp = dht.readTemperature();
  update_array(nums, NUMS, temp);
  float avg = average(nums, NUMS);
  Serial.print(temp);
  Serial.print(" *C");
  Serial.print("\t / \t");
  Serial.println(avg);
  delay(2000);
  //  }
}

float average(float arr[], size_t len) {
  float acc = 0;
  for (size_t i = 0; i < len; i++) {
    acc += arr[i];
  }
  return acc / (float) len;
}

void update_array(float* array, size_t len, float value) {
  for (size_t i = len - 1; i > 0; i--) {
    array[i] = array[i - 1];
  }
  array[0] = value;
}
