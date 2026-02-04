# Milestone4 Cub3D

Este projeto faz parte do currículo da [42](https://42.fr) e tem como objetivo a criação de um **motor gráfico 3D simples**, inspirado no Wolfenstein 3D, utilizando **raycasting** e a biblioteca **MiniLibX**.

O projeto envolve parsing rigoroso, matemática aplicada e renderização gráfica em tempo real, respeitando regras estritas de configuração e interação com o usuário.

---

## 🎯 Objetivo do Projeto  

- Renderizar um labirinto 3D a partir de um arquivo `.cub`.
- Utilizar **raycasting (DDA)** para simular profundidade.
- Implementar movimentação, rotação e interação do jogador.
- Exibir texturas diferentes para cada face da parede (N, S, E, W).
- Gerenciar corretamente eventos de teclado e janela.

---

## 🔧 Regras Principais  

- Uso obrigatório da **MiniLibX**.
- O programa deve receber um arquivo `.cub` como argumento.
- O arquivo `.cub` deve conter:
  - Caminhos das texturas (NO, SO, WE, EA).
  - Cores do chão (F) e do teto (C).
  - Um mapa válido, fechado por paredes.
- O mapa deve ser o último elemento do arquivo.
- Controles obrigatórios:
  - `W A S D` → movimentação
  - `← →` → rotação da câmera
  - `ESC` ou clique no `X` → encerrar o programa corretamente

---

## 🚀 Minha Solução  

### 📂 Parsing e Validação  

1. **Validação do input**
   - Verifico se o programa recebe exatamente 2 argumentos.
   - Confiro se o segundo argumento é um arquivo `.cub` válido e existente.

2. **Leitura do arquivo `.cub`**
   - Utilizo `get_next_line` para ler o arquivo linha por linha.
   - Cada linha é analisada e usada para preencher a struct `game`.
   - A ordem dos elementos não importa, desde que:
     - estejam separados por linhas vazias;
     - o mapa seja o último elemento.

3. **Tratamento dos dados**
   - Cores:
     - Converto `R,G,B` para `int`.
     - Valido o intervalo `[0,255]`.
     - Transformo para hexadecimal antes de armazenar.
   - Texturas:
     - Verifico se o arquivo existe.
     - Extraio e salvo corretamente o caminho.
   - Qualquer elemento inválido encerra o programa com erro.

4. **Validação final**
   - Confiro se todos os elementos obrigatórios foram preenchidos.
   - Valido o mapa:
     - caracteres permitidos;
     - mapa fechado por paredes;
     - posição inicial única do jogador.
   - Armazeno a posição inicial `(x, y)` do player.

---

### 🖼️ Inicialização Gráfica  

5. **Carregamento das texturas**
   - Preencho a struct de cada textura.
   - Verifico se os arquivos `.xpm` possuem tamanho e conteúdo válidos.
   - Em caso de erro, toda a memória é liberada e o programa encerra.

6. **Inicialização da MiniLibX**
   - Apenas após toda a validação:
     - crio a conexão com a mlx;
     - crio a janela;
     - crio a imagem.

---

## 🎮 Loop do Jogo e Raycasting  

7. **Início da execução**
   - A parte visual começa ao chamar `game_keyboard` na `main`.

8. **Eventos e atualização**
   - Uso `mlx_hook` e `mlx_loop_hook` para capturar ações do teclado.
   - As ações do jogador atualizam a struct do player na função `action`.

9. **Frame Update (Core do Projeto)**
   - `frame_update` é responsável por todo o ciclo de renderização.
   - Executa continuamente enquanto o jogo está ativo.
   - Implementa o **DDA (Digital Differential Analysis)**.

10. **Renderização**
   - A cada frame:
     - o chão e o teto são desenhados;
     - a função `put_pixel_player` é chamada.

11. **Raycasting**
   - `put_pixel_player`:
     - cria o ponto de vista do jogador;
     - lança raios dentro de um **FOV de 60°**;
     - processa **1000 raios por frame**;
     - detecta colisões com paredes;
     - identifica a face da parede (N, S, E, W);
     - aplica a textura correta para cada raio.

12. **Atualização da imagem**
   - A imagem é criada, exibida, destruída e recriada a cada iteração,
     garantindo a atualização contínua da cena.

---

## 🛠️ Como usar  

Compilar:
```bash
make
````
```bash
./cub3D maps/map.cub
````
