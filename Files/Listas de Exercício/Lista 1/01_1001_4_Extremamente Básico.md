# [01_1001_4_Extremamente Básico][1001]

[1001]: <https://judge.beecrowd.com/pt/problems/view/1001>

## Descrição

Extremamente Básico

Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Leia 2 valores inteiros e armazene-os nas variáveis **A** e **B**. Efetue a soma de **A** e **B** atribuindo o seu resultado na variável **X**. Imprima **X** conforme exemplo apresentado abaixo. Não apresente mensagem alguma além daquilo que está sendo especificado e não esqueça de imprimir o fim de linha após o resultado, caso contrário, você receberá "_Presentation Error_".

## Entrada

A entrada contém 2 valores inteiros.

## Saída

Imprima a mensagem "X = " (letra X maiúscula) seguido pelo valor da variável **X** e pelo final de linha. Cuide para que tenha um espaço antes e depois do sinal de igualdade, conforme o exemplo abaixo.

## Código

```cpp
// #include <bits/stdc++.h>
// #include <string>
// #include <vector>

// #define _ ios_base::sync_with_stdio(0); cin.tie(0); //primeiro ele tá desligando a sincronização para tornar mais rápido; cin geralmente é mais lento. O cin.tie desliga algum algum tipo de buffer.

#include <stdio.h>
#include <iostream>

#define cout std::cout
#define cin std::cin

#define endl '\n' // o std::endl é mais lento que o '\n' porque o std::endl faz um flush no buffer.

int main (){
  int a, b, x;
  cin >> a >> b;
  cout << "X = " << a + b << endl;
  return 0;
}
```
