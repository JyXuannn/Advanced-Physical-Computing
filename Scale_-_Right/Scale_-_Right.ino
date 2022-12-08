
#include <Wire.h>
#include  <LiquidCrystal_I2C.h>引用I2C库

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <LiquidCrystal.h>
#include <Servo.h>

#define LM35 A0
#define Trig 8 //引脚Tring 连接 IO D8
#define Echo 9 //引脚Echo 连接 IO D9
const int fsrPin = A1;  // A0 接口  pressure
const int fsrPin2 = A2; // A1 接口  pressure
int fsrReading;
int fsrReading2;
//pressure
int led1 = 4;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int servoPin1 = 6; // Declare the Servo pin
int servoPin2 = 7;
int m1 = 0;
int m2 = 0;
int n = 0;

Servo Servo1; // Create a servo object
Servo Servo2;

int avFSR1;
int avFSR2;

float cm; //距离变量

//LiquidCrystal lcd(12,11,5,4,3,2);
int val = 0;        //存放AD变量值
float temp = 0;     //存放温度值的10倍

void setup()
{
  Serial.begin(9600);

  lcd.init();                  // 初始化LCD
  lcd.backlight();             //设置LCD背景等亮

  lcd.begin(16, 2);   //初始化LCD1602
  lcd.print("Welcome to use!");   //液晶显示Welcome to use！
  delay(1000);        //延时1000ms
  lcd.clear();        //液晶清屏
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  // Distance
  Servo1.attach(servoPin1); // Servo1
  Servo2.attach(servoPin2); // Servo2
}

void loop()
{
  //给Trig发送一个低高低的短时间脉冲,触发测距
  digitalWrite(Trig, LOW); //给Trig发送一个低电平
  delayMicroseconds(2);    //等待 2微妙
  digitalWrite(Trig, HIGH); //给Trig发送一个高电平
  delayMicroseconds(10);    //等待 10微妙
  digitalWrite(Trig, LOW); //给Trig发送一个低电平

  temp = float(pulseIn(Echo, HIGH)); //存储回波等待时间,
  //pulseIn函数会等待引脚变为HIGH,开始计算时间,再等待变为LOW并停止计时
  //返回脉冲的长度

  //声速是:340m/1s 换算成 34000cm / 1000000μs => 34 / 1000
  //因为发送到接收,实际是相同距离走了2回,所以要除以2
  //距离(厘米)  =  (回波时间 * (34 / 1000)) / 2
  //简化后的计算公式为 (回波时间 * 17)/ 1000


  cm = (temp * 17 ) / 1000; //把回波时间换算成cm

for(int i = 0; i<19; i++) {

  fsrReading = analogRead(fsrPin);
//  Serial.print("A1 = ");
//  Serial.print(fsrReading);
  avFSR1 = avFSR1 + fsrReading;

  fsrReading2 = analogRead(fsrPin2);
//  Serial.print(" A2 = ");
//  Serial.print(fsrReading2);
  avFSR2 = avFSR2 + fsrReading2;
}

avFSR1 = avFSR1 /19;
avFSR2 = avFSR2 /19;

Serial.print(" Av fsr1: ");
Serial.print(avFSR1);
Serial.print(" Av fsr2: ");
Serial.println(avFSR2);

  if (cm > 40) {
    lcd.clear();
    n = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    m1 = 0;
    m2 = 0;
    Servo1.write(0);
    Servo2.write(0);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
   
    Servo1.write(30);
    Servo2.write(30);

//    if (fsrReading < 10) {
//      Serial.println(" - No pressure-1");
//    } else if (fsrReading < 200) {
//      Serial.println(" - Light touch-1");
//    } else if (fsrReading < 500) {
//      Serial.println(" - Light squeeze-1");
//    } else if (fsrReading < 800) {
//      Serial.println(" - Medium squeeze-1");
//    } else {
//      Serial.println(" - Big squeeze-1");
//    }
//
//    if (fsrReading2 < 10) {
//      Serial.println(" - No pressure-1");
//    } else if (fsrReading2 < 200) {
//      Serial.println(" - Light touch-1");
//    } else if (fsrReading2 < 500) {
//      Serial.println(" - Light squeeze-1");
//    } else if (fsrReading2 < 800) {
//      Serial.println(" - Medium squeeze-1");
//    } else {
//      Serial.println(" - Big squeeze-1");
//    }



    if ((avFSR1 <5) && (avFSR2 < 5) && (n == 0)) {
      lcd.setCursor(0, 0);               //设置显示指针
      lcd.print("take betteries");     //输出字符到LCD1602上
      lcd.setCursor(0, 1);
      lcd.print(" on the trays");
      m1 = 0;
      m2 = 0;
      Servo1.write(30);
      Servo2.write(30);

    }

    if ((avFSR1 < 5) && (avFSR2 < 5) && (n == 1)) {
      lcd.print("Thanks!");
      m1 = 0;
      m2 = 0;
      Servo1.write(30);
      Servo2.write(30);

    }


    if ((avFSR1 > 5) && (avFSR2 < 5)) {
      lcd.print("another side!");
      m1 = 1;
      m2 = 0;
      n = 1;
      Servo1.write(180);
      Servo2.write(30);
    }

    if ((avFSR1 < 5) && (avFSR2 > 5)) {
      lcd.print("another side!");
      m1 = 0;
      m2 = 1;
      n = 1;
      Servo1.write(30);
      Servo2.write(180);
    }


    if ((avFSR1 > 5) && (avFSR2 > 5) && (m1 == 1)) {
      n = 1;
      lcd.setCursor(0, 0);               //设置显示指针
      lcd.print("evaluating value");     //输出字符到LCD1602上
      lcd.setCursor(0, 1);
      lcd.print("         ");

      Servo1.write(0);
      Servo2.write(180);
      delay(1500);
      Servo1.write(180);
      Servo2.write(0);
      delay(1500);


    }

    if ((avFSR1 > 5) && (avFSR2 > 5) && (m2 == 1)) {
      n = 1;
      lcd.setCursor(0, 0);               //设置显示指针
      lcd.print("evaluating value");     //输出字符到LCD1602上
      lcd.setCursor(0, 1);
      lcd.print("        ");

      Servo1.write(180);
      Servo2.write(0);
      delay(1500);
      Servo1.write(0);
      Servo2.write(180);
      delay(1500);
    }

    if ((avFSR1 > 5) && (avFSR2 > 5) && (m1 == 0) && (m2 == 0)) {
      n = 1;
      lcd.setCursor(0, 0);               //设置显示指针
      lcd.print("evaluating value");     //输出字符到LCD1602上
      lcd.setCursor(0, 1);
      lcd.print("        ");

      Servo1.write(180);
      Servo2.write(0);
      delay(1500);
      Servo1.write(0);
      Servo2.write(180);
      delay(1500);
    }

  }

}
