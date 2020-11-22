// Arduino pin assignment
#define PIN_SERVO 10
#define PIN_IR A0
#define PIN_LED 9

//filter
#define LENGTH 30
#define k_LENGTH 8
#define Horizontal_Angle 2160
#define Max_Variable_Angle 100

//ema
#define _DIST_ALPHA 0.42 // EMA weight of new sample (range: 0 to 1). Setting this value to 1 effectively disables EMA filter.


int a, b; // unit: mm
int correction_dist, iter;
float dist_list[LENGTH], sum, dist_ema, alpha;

void setup() {
// initialize serial port
  Serial.begin(57600);
  
  a = 68;
  b = 245;
  correction_dist = 0;
  iter = 0; sum = 0;
  alpha = _DIST_ALPHA;
}

float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}

float ir_distence_filter() {
  sum = 0;
  iter = 0;
  while (iter < LENGTH)
  {
    dist_list[iter] = 100 + 300.0 / (b - a) * (ir_distance() - a);
    sum += dist_list[iter];
    iter++;
  }

  for (int i = 0; i < LENGTH-1; i++){
    for (int j = i+1; j < LENGTH; j++){
      if (dist_list[i] > dist_list[j]) {
        float tmp = dist_list[i];
        dist_list[i] = dist_list[j];
        dist_list[j] = tmp;
      }
    }
  }
  
  for (int i = 0; i < k_LENGTH; i++) {
    sum -= dist_list[i];
  }
  for (int i = 1; i <= k_LENGTH; i++) {
    sum -= dist_list[LENGTH-i];
  }

  float dist_cali = sum/(LENGTH-2*k_LENGTH);
  
  return alpha*dist_cali + (1-alpha)*dist_ema;
}

void loop() {
  float ir_filtered_dist = ir_distence_filter();

  Serial.println(dist_ema);
  delay(20);
}
