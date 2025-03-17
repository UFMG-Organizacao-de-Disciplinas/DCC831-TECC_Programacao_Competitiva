/*
# [08_1357_2_Em Braille][1357]

[1357]: <https://judge.beecrowd.com/pt/problems/view/1357>

## Descrição

Em Braille

Por Vinicius Santos Brasil

Timelimit: 1

O sistema Braille, desenvolvido por Louis Braille em 1825, revolucionou a comunicação escrita para as pessoas cegas e visualmente debilitadas. Braille, um francês cego, desenvolveu uma linguagem tátil onde cada elemento é representado por uma célula com seis posições, arranjadas em três fileiras e duas colunas. Cada posição pode ser relevada ou não, permitindo 64 configurações diferentes que podem ser sentidas por dedos treinados. A figura abaixo mostra a representação Braille para os dígitos decimais (um ponto preto indica uma posição relevada).

![8_1357_2_braille][IMG_1357]

[IMG_1357]: <https://resources.beecrowd.com/gallery/images/novos/In%20Braille.png>

De modo a desenvolver um novo sistema de software para ajudar professores a lidar com estudantes cegos ou visualmente debilitados, um módulo de dicionário Braille é necessário. Dada uma mensagem, composta apenas por dígitos, seu trabalho é traduzi-la para ou do Braille. Você pode ajudar?

## Entrada

Entrada
Cada caso de teste é descrito usando três ou cinco linhas. A primeira linha contém um inteiro D representando o número de dígitos em uma mensagem (1 ≤ D ≤ 100). A segunda linha contém uma única letra maiúscula 'S' ou 'B'. Se a letra é 'S', a próxima linha contém uma mensagem composta de D dígitos decimais que seu programa deve traduzir para o Braille. Se a letra é 'B', as próxima três linhas contém uma mensagem composta de D células Braille que seu programa deve traduzir do Braille. As células Braille são separadas por espaços simples. Em cada célula Braille uma posição relevada é denotada pelo caractere '*' (asterisco), enquanto uma não relevada é denotada por um caractere '.' (ponto).

<!--
# Relevo = *|Preto; Sem relevo: .|Branco
cin >> D;
cin >> letra;
if (letra == 'S') {
    cin >> mensagem;
} else {
    char braille[3][D];
    for (int i = 0; i < 3; i++) {
        cin >> mensagem;
    }
}
-->

O último caso de teste é seguido por uma linha contendo um zero.

## Saída

Saída
Para cada caso de teste imprima apenas os dígitos da tradução correspondente, no mesmo formato que a entrada (veja os exemplos para maiores explicações).

<!-- &nbsp; -->
| Exemplos de Entrada | Exemplos de Saída             |
| ------------------- | ----------------------------- |
| 10                  | *. *. ** ** *. ** ** *. .* .* |
| S                   | .. *. .. .* .* *. ** ** *. ** |
| 1234567890          | .. .. .. .. .. .. .. .. .. .. |
| 3                   | 123                           |
| B                   | .* .*                         |
| *. *. **            | ** **                         |
| .. *. ..            | .. ..                         |
| .. .. ..            |                               |
| 2                   |                               |
| S                   |                               |
| 00                  |                               |
| 0                   |                               |
## Código

```cpp
```
*/


#include <stdio.h>
#include <iostream>
#include <string>

using std::string;

#define cout std::cout
#define cin std::cin

#define endl '\n'

int D = 0;
char blank = ' ';
char mensagem[3][400];

char B0[3][3] = {{'.', '*'}, {'*', '*'}, {'.', '.'}};
char B1[3][3] = {{'*', '.'}, {'.', '.'}, {'.', '.'}};
char B2[3][3] = {{'*', '.'}, {'*', '.'}, {'.', '.'}};
char B3[3][3] = {{'*', '*'}, {'.', '.'}, {'.', '.'}};
char B4[3][3] = {{'*', '*'}, {'.', '*'}, {'.', '.'}};
char B5[3][3] = {{'*', '.'}, {'.', '*'}, {'.', '.'}};
char B6[3][3] = {{'*', '*'}, {'*', '.'}, {'.', '.'}};
char B7[3][3] = {{'*', '*'}, {'*', '*'}, {'.', '.'}};
char B8[3][3] = {{'*', '.'}, {'*', '*'}, {'.', '.'}};
char B9[3][3] = {{'.', '*'}, {'*', '.'}, {'.', '.'}};

void addLetter(char braille[3][D+1], int i, char B[3][2]) {
  int index = i * 3;
  braille[0][index] = B[0][0]; braille[0][index+1] = B[0][1]; braille[0][index+2] = blank;
  braille[1][index] = B[1][0]; braille[1][index+1] = B[1][1]; braille[1][index+2] = blank;
  braille[2][index] = B[2][0]; braille[2][index+1] = B[2][1]; braille[2][index+2] = blank;
}

void makeBraille(int D) {
  // Lê os números e depois converte para Braille
  char braille[3][4*D];
  char digitos[D+1];
  scanf("%s", digitos);
  for (int i = 0; i < D; i++) {
    switch (digitos[i]) {
      case '0': addLetter(braille, i, B0); break;
      case '1': addLetter(braille, i, B1); break;
      case '2': addLetter(braille, i, B2); break;
      case '3': addLetter(braille, i, B3); break;
      case '4': addLetter(braille, i, B4); break;
      case '5': addLetter(braille, i, B5); break;
      case '6': addLetter(braille, i, B6); break;
      case '7': addLetter(braille, i, B7); break;
      case '8': addLetter(braille, i, B8); break;
      case '9': addLetter(braille, i, B9); break;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < D; j++) {
      cout << braille[i][j];
    }
    cout << endl;
  }
}

void readBraille(int D) {
  char ch;
  int index = 0;
  while(cin.get(ch) && ch != '\n' && index < 4*D) {
    braille[0][index++] = ch;
  }
  while(cin.get(ch) && ch != '\n' && index < 4*D) {
    braille[1][index++] = ch;
  }
  while(cin.get(ch) && ch != '\n' && index < 4*D) {
    braille[2][index++] = ch;
  }

}

void makeMessage(int D) {
  // Lê o Braille e depois converte para mensagem de inteiros 
  char mensagem[3][D+1];
  for (int i = 0; i < 3; i++) {
    cin >> mensagem;
  }
}

void main(){
  char letra;
  cin >> D;
  while (D != 0) {
    cin >> letra;
    if (letra == 'S') {
      makeBraille(D);
    } else if (letra == 'B') {
      makeMessage(D);
    }
  }
}
