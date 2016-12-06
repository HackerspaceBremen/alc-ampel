unsigned int status = 1;

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

const long interval1base = 2000;
const long interval2base = 2*interval1base;

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
    float interval1 = (float)interval1base*speed;
    float interval2 = (float)interval2base*speed;
    clearAll();
    switch(status)
    {
        case 1:
            status1();
            if(currentMillis - previousMillis >= interval2)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 2:
            status2();
            if(currentMillis - previousMillis >= interval2)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 3:
            status3();
            if(currentMillis - previousMillis >= interval1)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 4:
            status4();
            if(currentMillis - previousMillis >= interval1)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 5:
            status5();
            if(currentMillis - previousMillis >= interval2)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 6:
            status6();
            if(currentMillis - previousMillis >= interval2)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 7:
            status7();
            if(currentMillis - previousMillis >= interval2)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 8:
            status8();
            if(currentMillis - previousMillis >= interval1)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 9:
            status9();
            if(currentMillis - previousMillis >= interval1)
            {
                status++;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
        case 10:
            status10();
            if(currentMillis - previousMillis >= interval2)
            {
                status = 1;
                previousMillis = currentMillis;
                digitalWrite(blink, !digitalRead(blink));
            }
            break;
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
    digitalWrite(A1gruen, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status3()
{
    digitalWrite(A1gelb, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status4()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status5()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(A2gelb, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2gruen, HIGH);
}

void status6()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2gruen, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2gruen, HIGH);
}

void status7()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2gruen, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status8()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2gelb, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status9()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1rot, HIGH);
    digitalWrite(F2rot, HIGH);
}

void status10()
{
    digitalWrite(A1rot, HIGH);
    digitalWrite(A1gelb, HIGH);
    digitalWrite(A2rot, HIGH);
    digitalWrite(F1gruen, HIGH);
    digitalWrite(F2rot, HIGH);
}
