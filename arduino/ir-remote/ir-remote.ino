#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
using namespace std;

struct Keys {
    static const unsigned long channel_negative = 0xFFA25D;
    static const unsigned long channel = 0xFF629D;
    static const unsigned long channel_positive = 0xFFE21D;
    static const unsigned long previous = 0xFF22DD;
    static const unsigned long next = 0xFF02FD;
    static const unsigned long play_pause = 0xFFC23D;
    static const unsigned long negative = 0xFFE01F;
    static const unsigned long positive = 0xFFA857;
    static const unsigned long eq = 0xFF906F;
    static const unsigned long key0 = 0xFF6897;
    static const unsigned long key100_plus = 0xFF9867;
    static const unsigned long key200_plus = 0xFFB04F;
    static const unsigned long key1 = 0xFF30CF;
    static const unsigned long key2 = 0xFF18E7;
    static const unsigned long key3 = 0xFF7A85;
    static const unsigned long key4 = 0xFF10EF;
    static const unsigned long key5 = 0xFF38C7;
    static const unsigned long key6 = 0xFF5AA5;
    static const unsigned long key7 = 0xFF42BD;
    static const unsigned long key8 = 0xFF4AB5;
    static const unsigned long key9 = 0xFF52AD;
};

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int xPin = A0;
int yPin = A1;
int btnPin = 2;
int irPin = 5;

IRrecv myIr(irPin);

decode_results irInput;

String text = "0";
int len;
int offset = 0;
bool direction = false;

int currentNum = 0;

int x = 0;
int y = 0;

bool redraw = false;

void setup(){
    pinMode(btnPin, INPUT_PULLUP);
    myIr.enableIRIn();
    Serial.begin(9600);
    len = text.length();
    lcd.init();
    lcd.backlight();
    lcd.setCursor(5, 1);
    lcd.setCursor(0, 1);
    // DEBUG: lcd.print("Bigham");
    lcd.setCursor(0, 0);
    Serial.println("ready and waiting...");
    lcd.print(text);
}

void loop(){

    int newRead = myIr.decode(&irInput);

    if(newRead){
        Serial.println(irInput.value, HEX);

        if(irInput.value == Keys::positive){
            currentNum++;
            redraw = true;
        }
        if(irInput.value == Keys::negative){
            currentNum--;
            redraw = true;
        }

        myIr.resume();
    }

    int btnState = digitalRead(btnPin);
    int yState = analogRead(yPin);
    int xState = analogRead(xPin);

    if(offset > 15 - len || offset <= 0){
        direction = !direction;
    }

    if(xState > 550 && x < 16 || (newRead && irInput.value == Keys::key6)){
        x++;
        redraw = true;
    }
    else if (xState < 450 && x > 0 || (newRead && irInput.value == Keys::key4)){
        x--;
        redraw = true;
    }

    if(yState > 550 && y == 0 || (newRead && irInput.value == Keys::key8)){
        y = 1;
        redraw = true;
    }
    else if (yState < 450 && y == 1 || (newRead && irInput.value == Keys::key2)){
        y = 0;
        redraw = true;
    }

    if(redraw){
        lcd.clear();
        lcd.setCursor(x, y);
        lcd.print(String(currentNum));
    }
    redraw = false;

    delay(500);
}