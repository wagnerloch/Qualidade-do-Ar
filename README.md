# Apresentação Módulo Detector de Partículas DSM-501

![DSM-501](../master/Docs/Dsm-501.jpg)

- Detecta poeira, pólen e partículas de até 1µm
- Sensibilidade customizável
- Excelente confiabilidade a longo prazo e fácil manutenção
- Tamanho compacto
- Saída PWM
- [Demais informações no DataSheet](https://www.elektronik.ropla.eu/pdf/stock/smy/dsm501.pdf)

### Aplicações

- Limpadores de Ar
- Ar Condicionado
- Sistemas de Ventilação
- Controle e Monitoramento IAQ (Indoor Air Quality)
- Detectores de Fumaça

### Como funciona o Módulo DSM-501?

- Mede a dispersão das luzes refletidas por partículas.
- Esta medida é então convertida em um sinal de saída PWM
- É capaz de detectar partículas tão pequenas, incluindo pó doméstico, pólen, ácaros, germes e fumaça de cigarro que são causas conhecidas de doenças respiratórias e alergias.

![Diagrama-de-Blocos](https://github.com/wagnerloch/Qualidade-do-Ar/blob/master/Docs/Block-Diagram%20DSM.png)

# Desenvolvendo um Medidor de Qualidade do Ar

![Diagrama-De-Blocos-Medidor](https://github.com/wagnerloch/Qualidade-do-Ar/blob/master/Docs/Block-Diagram.png)

- Utilize o Diagrama acima e o DataSheet do módulo DSM como base para montar o seu Medidor.

## Realizando Leituras

- No cartão de memória será criado um arquivo chamado 'DADOS.TXT' onde serão armazenadas todas as informações que o módulo obtiver.
- Neste caso, o que nos interessa é o último dado de cada linha, o AQI (Air Quality Index).
- Com esses dados em mãos, comparamos utilizando a tabela abaixo.

![AQI](https://github.com/wagnerloch/Qualidade-do-Ar/blob/master/Docs/AQI.png)

# Materiais Utilizados no Projeto

- Sensor DSM-501
- Arduino Uno
- Módulo SD Card
- Fonte 12v
- [Tutorial DSM-501](https://diyprojects.io/calculate-air-quality-index-iaq-iqa-dsm501-arduino-esp8266/#.Wp1cNejwbIU)
- [Biblioteca DSM-501](https://github.com/richardhmm/DIYRepo/tree/master/arduino/libraries/DSM501)
