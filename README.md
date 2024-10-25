# ESP8266-Fauxmo-MultiLED-Control

Este projeto usa um ESP8266 para controlar até 5 LEDs ou relés de forma independente via comandos de voz com a Alexa, graças à biblioteca `fauxmoESP`. Cada dispositivo configurado no código pode ser ligado e desligado individualmente, o que permite controle de iluminação ou automação de dispositivos no ambiente de forma fácil e inteligente.

## Funcionalidades

- Conexão Wi-Fi para controle remoto de dispositivos.
- Controle de até 5 LEDs ou relés de forma independente.
- Integração com Alexa para comandos de voz.
- Feedback via Serial Monitor para monitoramento de estados.

## Hardware Necessário

- ESP8266 (NodeMCU ou outro modelo compatível)
- Módulo de relés ou LEDs conectados aos pinos de GPIO do ESP8266
- Fonte de alimentação adequada

## Instalação

1. **Clonar o Repositório**  
   Clone este repositório para obter o código fonte:

   ```bash
   git clone https://github.com/seuusuario/ESP8266-Fauxmo-MultiLED-Control.git
   ```

2. **Configuração de Bibliotecas**  
   No Arduino IDE, instale as bibliotecas necessárias:
   - [`fauxmoESP`](https://github.com/vintlabs/fauxmoESP)

3. **Configuração Wi-Fi e Nomes dos Dispositivos**  
   No código, configure suas credenciais Wi-Fi e defina os nomes dos dispositivos que deseja controlar:

   ```cpp
   #define WIFI_SSID "Sua_Rede"
   #define WIFI_PASS "Sua_Senha"
   #define LAMP_1 "LED 1"
   #define LAMP_2 "LED 2"
   #define LAMP_3 "LED 3"
   #define LAMP_4 "LED 4"
   #define LAMP_5 "LED 5"
   ```

4. **Upload do Código**  
   Carregue o código no ESP8266 usando o Arduino IDE.

## Uso

1. **Conectar os LEDs ou Relés aos Pinos**  
   Conecte os LEDs ou relés aos pinos D1, D2, D5, D6 e D7 no ESP8266, conforme o código.

2. **Configuração na Alexa**  
   Após iniciar o ESP8266, abra o app Alexa, vá até "Dispositivos" e procure por novos dispositivos. A Alexa reconhecerá os LEDs como lâmpadas.

3. **Controle dos LEDs/Relés**  
   Use comandos de voz como "Alexa, ligue o LED 1" ou "Alexa, desligue o LED 2" para controlar cada dispositivo.

## Exemplo de Uso

Ideal para controlar várias luzes de um ambiente, como fitas de LED em diferentes zonas de um quarto, ou pontos de luz individuais em uma sala. Com o controle de voz, fica fácil ligar e desligar cada dispositivo conforme desejado.

---

## Contribuição

Sinta-se à vontade para enviar pull requests para aprimorar o projeto ou adaptar funcionalidades.

## Licença

Este projeto está sob a licença MIT.
