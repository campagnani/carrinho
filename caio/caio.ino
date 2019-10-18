#include "funcoes.h"

void setup()
{
  Serial.begin(9600);
  inicializa_pinagem();
  millis();
}

void loop()
{
    static unsigned long tempo_anterior = 0, tempo_atual;

    //sc = controlador_Linha_PID (0);
    sc = sin_var();
    if(sc>0)
       controladores_Motores (REF_V-sc,REF_V);
    else
       controladores_Motores (REF_V,REF_V+sc);
    
    do {} while (millis() - tempo_anterior < 10);
    tempo_anterior = millis();
}
