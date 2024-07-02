#ifndef __SERVO_H
#define __SERVO_H

void Servo_Init(void);
void Servo_SetAngle1(float Angle);
void Servo_SetAngle2(float Angle);
void Servo_SetAngle3(float Angle);
void Servo_SetAngle4(float Angle);
void Servo_SetAngle5(float Angle);

void grab(void);
void claw_open_left(void);
void claw_open_right(void);
void claw_close(void);
void up_right(void);
void up_left(void);
void down(void);
void up(void);
void down_(void);

//void Servo_SlowChange(float angle1, float angle2);

#endif
