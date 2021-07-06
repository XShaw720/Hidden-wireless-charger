/*author: Seth Shaw
 * Date: July 5, 2021
 * Description: wireless charger that only charges during a set time period or if the override button is pressed
 */

int charger=A0, timer=4, button=6, relay=5, range=400;
bool charged=false;

void setup() {
  pinMode(charger, INPUT);
  pinMode(timer, INPUT);
  pinMode(button, INPUT);
  pinMode(relay, OUTPUT);

}

void charge(){
  digitalWrite(relay, HIGH);  //powers the wireless charger
  while(analogRead(charger)<range); //waits until the phone starts charging
  while(analogRead(charger)>=range);  //waits until the phone stops charging
  charged=true;
  digitalWrite(relay, LOW); //powers down the relay
}

void loop() {
  if(digitalRead(button)==HIGH) //starts charging if the override button is pressed
    charge();
  if(digitalRead(timer)==HIGH){ //starts charging if session has started and the phone hasn't been charged yet
    if(!charged)
      charge();
  }
  else  //charging session is over and the flag var is reset
    charged=false;

}
