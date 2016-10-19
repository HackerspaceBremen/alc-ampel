int status = 1;

const int F1rot = 2;
const int F1gruen = 3;
const int F2rot = 4;
const int F2gruen = 5;
const int A1rot = 6;
const int A1gelb = 7;
const int A1gruen = 8;
const int A2rot = 9;
const int A2gelb = 10;
const int A2gruen = 11;

const int blink = 13;

const int poti = 0;

unsigned long previousMillis = 0;

const long interval = 5000;

void setup() {
    pinMode(F1rot, OUTPUT);
    pinMode(F1gruen, OUTPUT);
    pinMode(F2rot, OUTPUT);
    pinMode(F2gruen, OUTPUT);
    pinMode(A1rot, OUTPUT);
    pinMode(A1gelb, OUTPUT);
    pinMode(A1gruen, OUTPUT);
    pinMode(A2rot, OUTPUT);
    pinMode(A2gelb, OUTPUT);
    pinMode(A2gruen, OUTPUT);
    pinMode(blink, OUTPUT);

}

void loop() {
    unsigned long currentMillis = millis();
    float speed = analogRead(poti)/1024.0;
    if (currentMillis - previousMillis >= (float)interval*speed)
    {
        previousMillis = currentMillis;
        digitalWrite(blink, !digitalRead(blink));
        clearAll();
        if( (status % 4 + 1) == 1 )
        {
            status1();
            status++;
        }
        else if( (status % 4 + 1) == 2 )
        {
            status2();
            status++;
        }
        else if( (status % 4 + 1) == 3 )
        {
            status3();
            status++;
        }
        else if( (status % 4 + 1) == 4 )
        {
            status4();
            status++;
        }
    }

}

void clearAll()
{
    digitalWrite(F1rot,   LOW);
    digitalWrite(F1gruen, LOW);
    digitalWrite(F2rot,   LOW);
    digitalWrite(F2gruen, LOW);
    digitalWrite(A1rot,   LOW);
    digitalWrite(A1gelb,  LOW);
    digitalWrite(A1gruen, LOW);
    digitalWrite(A2rot,   LOW);
    digitalWrite(A2gelb,  LOW);
    digitalWrite(A2gruen, LOW);
}

void status1()
{
    digitalWrite(A1gruen, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1gruen, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status2()
{
    digitalWrite(A1gelb, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(A2gelb, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status3()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2gruen, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2gruen, HIGH);
}

void status4()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A1gelb, HIGH);
    digitalWrite(A2gelb, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}
