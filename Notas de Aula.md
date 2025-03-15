# Programação Competitiva - Professor: Vinícius Santos

## 10/03/2025 - Aula 1

Principal objetivo é implementar.

Estudar algoritmos e estruturas de dados que sejam úteis para competições de programação.

- Avaliação da disciplina:
  - Problemas: implementar. Se passar, ganha o ponto. Se não passar, não ganha o ponto.
  - Em torno de 5 listas valendo 20 pontos cada.
  - Ele tá considerando colocar alguns pontos para participação em sala.
  - Cogita também fazer uma prova no final.
  - Pelo menos 90% serão pontos de lista.
- Não há uma bibliografia da disciplina
  - Ele tem um conjunto de coisas que pode-se seguir, mas é só de referência
- Sites interessantes
  - codeforces.com
  - cp-algorithms.com
- Linguagem: tudo em C/C++ "C+" (C com algumas coisinhas de C++, como STL)
- > Uma coisa interessante da programação competitiva é que algumas vezes você passa muito mais tempo pensando do que Codando.
- NÃO DEIXAR PRA ÚLTIMA HORA
- Primeira lista: aproximadamente 25 problemas
  - Ele vai tentar enviar antes da quarta (ele viajará)
- Outras: de 10 a 15 problemas
- Ele gosta de pegar o problema e ir batendo cabeça junto. Começando pelas soluções ingênuas até chegar nas mais eficientes.
- Em Maio ele deve viajar por duas semanas. Talvez alguém dê aula pra gente nesse período.
- O simulado é para simular um campeonato de programação. O resultado do simulado é ponto extra.
- Devemos fazer de 1 a 3 simulados.

### Dijkstra

- Conceito:
  - pode ser em direcionado ou não direcionado e não pode ter peso negativo.
  - Depois do primeiro (source), adicionamos os vértices para os quais ele foi, comeando pelo menor.
  - O menor então atualiza as novas menores distâncias atingíveis.
- Pseudocódigo:
  - Inicialização
  - repita n -1 vezes
    - seja v o vértice desmarcado com o mentor dist[v]
    - marque v
    - para cada vizinho w de v
      - se dist[w] > dist[v] + peso(v, w)
        - dist[w] = dist[v] + peso(v, w)

- Como melhorar?
  - Usar lista de adjacência ao invés de matriz de adjacência.
    - O Loop de verificação de vizinhos é o somatórios dos vizinhos que é igual a 2|E(G)|.
  - Pode-se melhorar a verificação de qual é o vértice com menor distância.
  - Dá pra usar um heap que tenha um índice dizendo onde que tá cada nó, e sempre que atualizar a distância, atualiza também a lista de índices.
  - Complexidade: $O((m+n) \log n)$
  - [JV: Não entendi direito porque o máximo de vértices de uma heap caso adicionasse todos os vizinhos atualizados deve ser 2m e não nm]
  - $m \leq \binom{n}{2} < n^2$

#### Implementação

```c
#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <E MAIS UM MONTE DE COISA>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); //primeiro ele tá desligando a sincronização para tornar mais rápido; cin geralmente é mais lento. O cin.tie desliga algum algum tipo de buffer.

#define endl '\n' // o std::endl é mais lento que o '\n' porque o std::endl faz um flush no buffer.

// Lembrar ele de falar sobre o INF e LINF
#define ??? 0x3f3f3f3f // 1061109567
#define ??? 0x3f3f3f3fll // ???

vector <int> dist, marca; // distância e marcação
int n;

vector <vector <int> > adj; // lista de adjacência
vector <vector <int> > peso; // lista de adjacência

// OU

vector<vector<pair<int, int>>> adj; // lista de adjacência

// vecotr<vector<pair<int, int>>> adj; // lista de adjacência

void dijkstra(int s){
  dist.resize(n);
  marca.resize(n);
  for (int i = 0; i < n; i++){
    dist[i] = INF;
    marca[i] = 0;
  }

  priority_queue<pair<int, int>> fila; // heap

  dist[s] = 0;
  fila.push(make_pair(0, s));

  for (int i = 0; i < n; i++){
    int v;
    do{
      v = (fila.top()).second;
      fila.pop();
    } while (marca[v]);

    marca[v] = 1;

    for (int j = 0; j < adj[v].size(); j++){
      int w = adj[v][j].second;
      int c = adj[v][j].first;

      if (dist[w] > dist[v] + c){
        dist[w] = dist[v] + c;
        fila.push(make_pair(-dist[w], w));  
      }
    }
  }
}

int main (){ _
  int m;
  cin >> n >> m;

  adj.resize(n);
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;

    adj[a].push_back(make_pair(c, b));
    adj[b].push_back(make_pair(c, a));
  }

  dijkstra(5-1);

  for (int i = 0; i < n; i++){
    ...
  }

}

```

```txt
entrada do grafo

5 7
5 1 4
5 2 9
5 4 5
1 2 3
2 3 2
3 4 1
2 4 10
```

- O que é um pair?
  - É uma struct com dois valores em que o primeiro valor tá armazenado na chave first e o segundo na chave second

## 12/03/2025 - Aula 2 - Sem Aula
