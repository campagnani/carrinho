#include "includeDefines.h"


void inicializa_pinagem()
{
    pinMode(CLK_D                , INPUT );
    pinMode(CLK_E                , INPUT );
    pinMode(PWM_D_HORARIO        , OUTPUT);
    pinMode(PWM_D_ANTIHORARIO    , OUTPUT);
    pinMode(PWM_E_HORARIO        , OUTPUT);
    pinMode(PWM_E_ANTIHORARIO    , OUTPUT);
}

void ponteH_d (int pwm)
{
    if (pwm> 255) pwm =  255;
    if (pwm<-255) pwm = -255;

    if (pwm>0)
    {
        analogWrite(PWM_D_HORARIO      , pwm);
        analogWrite(PWM_D_ANTIHORARIO  , LOW);
    }
    else
    {
        analogWrite(PWM_D_HORARIO      , LOW);
        analogWrite(PWM_D_ANTIHORARIO  ,-pwm);
    }
}

void ponteH_e (int pwm)
{
    if (pwm> 255) pwm =  255;
    if (pwm<-255) pwm = -255;

    if (pwm>0)
    {
        analogWrite(PWM_E_HORARIO      , pwm);
        analogWrite(PWM_E_ANTIHORARIO  , LOW);
    }
    else
    {
        analogWrite(PWM_E_HORARIO      , LOW);
        analogWrite(PWM_E_ANTIHORARIO  ,-pwm);
    }
}

void contagem_E(void)
{
  pulse_counter++;
}
void contagem_D(void)
{
  pulse_counter++;
}

void inicializa_interrupcao_encoder()
{
  attachInterrupt(digitalPinToInterrupt(CLK_E), contagem_E, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CLK_D), contagem_D, CHANGE);
}

float mede_velocidade_D(int time)
{
  float distancia  = pulse_counter * 0.00145 / (time * 0.01);
  pulse_counter  = 0;
  return distancia;
}

float mede_velocidade_E(int time)
{
  float distancia  = pulse_counter * 0.00145 / (time * 0.01);
  pulse_counter  = 0;
  return distancia;
}
