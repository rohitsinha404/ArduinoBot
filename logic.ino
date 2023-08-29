Code #include<AFMotor.h>
    // intitlizaing motor objects
    AF_DCMotor mLeft(1); // left
AF_DCMotor mRight(2);    // right
AF_DCMotor brushes(3);
const int echo_L = 33; // initialize pin numbers for ultrasound sensors
const int trig_L = 35;
const int echo_M = 37;
const int trig_M = 39;
const int echo_R = 41;
const int trig_R = 43;
const int ir = 47;
int max_distance = 10000000; // max distance of ultrasonic sensors is set to
200 cm
    // initialize all the 3 sensors
    NewPing sonar_L(trig_L, echo_L, max_distance);
NewPing sonar_M(trig_M, echo_M, max_distance);
NewPing sonar_R(trig_R, echo_R, max_distance);
int dist_L = 0;
int dist_M = 0;
int dist_R = 0;
bool gnd = false;
int turn = 0;
int DistArr[2] = {
    0};
int min_D = 20;
void setup()
{
    // put your setup code here, to run once:
    mLeft.setSpeed(255);
    mRight.setSpeed(255);
    brushes.setSpeed(255);
    brushes.run(FORWARD);
    pinMode(ir, INPUT);
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    // Serial.begin(9600);
}
void loop()
{

    dist_L = readSensor_L(); // read distance from all the 3 sensors
    dist_M = readSensor_M();
    dist_R = readSensor_R();
    // gnd = ground(ir);
    Serial.print("left = ");
    Serial.println(dist_L);
    Serial.print("mid= ");
    Serial.println(dist_M);
    Serial.print("right = ");
    Serial.println(dist_R);

    if (dist_L <= 10 && dist_M <= 15 && dist_R <= 10)
    {
        turnAround();
        // Serial.println("right chalega");
    }
    else if (dist_L <= 10 && dist_M <= 15)
    {
        turnRight();
        // Serial.println("right chalega");
    }
    else if (dist_R <= 10 && dist_M <= 15)
    {
        turnLeft();
        Serial.println("left chalega");
    }
    else if (dist_M < 15)
    {
        if (turn == 0)
        {
            turnRight();
            Serial.println("right chalega");
        }
        else
        {
            turnLeft();
            Serial.println("left");
        }
    }
    else
    {
        moveForward();
        Serial.println("Jagah hi jagah hai");
    }
}
/ -- -- -- -- -- -- -- -- -- -functions-- -- -- -- -- -- -- -- -- /
    bool ground(int ir)
{
    if (digitalRead(ir) == LOW)
        return true;
    return false;
}
int readSensor_L() // read distance in centimeters from left sensor
{
    delay(70);
    int cm_L = sonar_L.ping_cm();
    if (cm_L < 4)
        return 40;
    return cm_L;
}
int readSensor_M() // read distance in centimeters from left sensor
{
    delay(70);
    int cm_M = sonar_M.ping_cm();
    if (cm_M < 4)
        return 40;
    return cm_M;
}
int readSensor_R() // read distance in centimeters from left sensor
{
    delay(70);
    int cm_R = sonar_R.ping_cm();
    if (cm_R < 4)
        return 40;
    return cm_R;
}
void moveForward()
{
    mRight.run(BACKWARD);
    mLeft.run(BACKWARD);
}
void moveBack()
{
    moveStop();
    delay(200);
    mRight.run(FORWARD);
    mLeft.run(FORWARD);
}
void turnLeft()
{
    moveStop();
    delay(200);
    moveBack();
    delay(1100);
    mRight.run(BACKWARD);
    mLeft.run(RELEASE);
    delay(6480);
    moveForward();
    delay(200);
    turn = 0;
}
void turnRight()
{
    moveStop();
    delay(200);
    moveBack();
    delay(1100);
    mRight.run(RELEASE);
    mLeft.run(BACKWARD);
    delay(6480);
    moveForward();
    delay(200);
    turn = 1;
}
void turnAround()
{
    moveStop();
    delay(200);
    // turnRight();
    mRight.run(BACKWARD);
    mLeft.run(FORWARD);
    delay(2530);
}
void moveStop()
{
    mRight.run(RELEASE);
    mLeft.run(RELEASE);
}
