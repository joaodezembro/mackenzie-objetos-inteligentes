README: Projeto de Monitoramento Ambiental

Descrição do Funcionamento e Uso

Este projeto consiste em um sistema de monitoramento ambiental baseado em ESP32 que lê dados de temperatura, umidade e luminosidade do ambiente e os envia para um servidor via protocolo MQTT. Para quem deseja reproduzir este projeto, o software e o hardware necessários são descritos nas seções abaixo.

Software Desenvolvido e Documentação de Código

O software foi desenvolvido utilizando a linguagem de programação C++ e é destinado para ser executado no microcontrolador ESP32. Este código é responsável por ler os dados dos sensores, fazer a lógica de controle e comunicar com um servidor MQTT.

O código completo está disponível no repositório e é bem comentado para facilitar o entendimento. As principais partes do código são a leitura dos sensores (temperatura, umidade e luminosidade), a lógica de controle e a comunicação MQTT.

Descrição do Hardware Utilizado

O hardware consiste em um microcontrolador ESP32, um sensor de temperatura e umidade DHT22 e um sensor de luminosidade LDR.

ESP32: É um microcontrolador com capacidade Wi-Fi integrada que é utilizado para ler os dados dos sensores e se comunicar com o servidor MQTT.
DHT22: Este sensor é utilizado para medir a temperatura e a umidade do ambiente.
LDR: É um sensor que mede a luminosidade do ambiente.
Todos os componentes são de baixo custo e podem ser facilmente encontrados em lojas de eletrônicos. Não foram necessários componentes impressos em 3D ou caixas específicas para este projeto.

Documentação das Interfaces, Protocolos e Módulos de Comunicação

Este projeto utiliza o protocolo MQTT para comunicação entre o ESP32 e o servidor. MQTT é um protocolo de mensagens leve que foi projetado para situações em que é necessária uma largura de banda mínima e um baixo consumo de energia, tornando-o ideal para o uso em IoT.

O ESP32 se conecta à rede Wi-Fi e se comunica com o servidor MQTT usando o protocolo TCP/IP. O servidor MQTT usado neste projeto é o mosquitto, um servidor MQTT open source.

Comunicação/Controle via Internet (TCP/IP) e Uso do Protocolo MQTT

A comunicação com o ESP32 é realizada através de TCP/IP sobre Wi-Fi, e a comunicação entre o ESP32 e o servidor MQTT é realizada através do protocolo MQTT.

O servidor MQTT recebe as mensagens do ESP32 e pode enviar mensagens de volta, permitindo o controle do sistema de monitoramento ambiental remotamente através da internet.
