#include "funcoes.h"

void setup() {
  Serial.begin(9600);
  inicializa_pinagem();
  millis();
}

void loop()
{
    static unsigned long tempo_anterior = 0, tempo_atual;

    float velocidadeAtual_E = mede_velocidade_D();
    
    
    int erro_E = velocidadeDesejada_E - velocidadeAtual_E;
    int sc_E = erro_E*k;
    ponteH_d(sc_E);
    
    int erro_D = velocidadeDesejada_D - velocidadeAtual_D;
    int sc_D = erro_D*k;
    ponteH_D(scD);
    
    do { tempo_atual = millis(); } while (tempo_atual - tempo_anterior < 10);
    tempo_anterior = tempo_atual;
}
