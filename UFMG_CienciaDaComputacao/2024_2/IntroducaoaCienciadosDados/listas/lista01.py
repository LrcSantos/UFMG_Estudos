# -*- coding: utf-8 -*-
"""lista_01.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1T7sIEvE5HEJ3QUmH-W3jwVQceb7Wbjeu

# Lista 01 - Introdução e Revisão Numpy

[NumPy](http://numpy.org) é um pacote incrivelmente poderoso em Python, onipresente em qualquer projeto de ciência de dados. Possui forte integração com o [Pandas](http://pandas.pydata.org), outra ferramenta que iremos abordar na matéria. NumPy adiciona suporte para matrizes multidimensionais e funções matemáticas que permitem que você execute facilmente cálculos de álgebra linear. Este notebook será uma coleção de exemplos de álgebra linear computados usando NumPy.

## Numpy

Para fazer uso de Numpy precisamos importar a biblioteca
"""

# -*- coding: utf8

import numpy as np

"""Quando pensamos no lado prático de ciência de dados, um aspecto chave que ajuda na implementação de novos algoritmos é a vetorização. De forma simples, vetorização consiste do uso de tipos como **escalar**, **vetor** e **matriz** para realizar uma computação mais eficaz (em tempo de execução).

Uma matriz é uma coleção de valores, normalmente representada por uma grade 𝑚 × 𝑛, onde 𝑚 é o número de linhas e 𝑛 é o número de colunas. Os comprimentos das arestas 𝑚 e 𝑛 não precisam ser necessariamente diferentes. Se tivermos 𝑚 = 𝑛, chamamos isso de matriz quadrada. Um caso particularmente interessante de uma matriz é quando 𝑚 = 1 ou 𝑛 = 1. Nesse caso, temos um caso especial de uma matriz que chamamos de vetor. Embora haja um objeto de matriz em NumPy, faremos tudo usando matrizes NumPy porque elas podem ter dimensões maiores que 2.

1. **Escalar:** Um vetor de zero dimensões
"""

1

np.array(1)

"""2. **Vetor:** Representa uma dimensão

Abaixo vamos criar um vetor simples. Inicialmente, vamos criar uma lista.
"""

data_list = [3.5, 5, 2, 8, 4.2]

"""Observe o tipo da mesma."""

type(data_list)

"""Embora vetores e listas sejam parecidos, vetores Numpy são otimizados para operações de Álgebra Linear. Ciência de Dados faz bastante uso de tais operações, sendo este um dos motivos da dependência em Numpy.

Abaixo criamos um vetor.
"""

data = np.array(data_list)
print(data)
print(type(data))

"""Observe como podemos somar o mesmo com um número. Não é possível fazer tal operação com listas."""

data + 7

"""3. **Matrizes:** Representam duas dimensões."""

X = np.array([[2, 4],
              [1, 3]])
X

"""Podemos indexar as matrizes e os vetores."""

data[0]

X[0, 1] # aqui é primeira linha, segunda coluna

"""Podemos também criar vetores/matrizes de números aleatórios"""

X = np.random.randn(4, 3) # Gera números aleatórios de uma normal
print(X)

"""### Indexando

Pegando a primeira linha
"""

X[0] # observe que 0 é a linha 1, compare com o X[0, 1] de antes.

X[1] # segunda

X[2] # terceira

"""Observe como todos os tipos retornados são `array`. Array é o nome genérico de Numpy para vetores e matrizes.

`X[:, c]` pega uma coluna
"""

X[:, 0]

X[:, 1]

"""`X[um_vetor]` pega as linhas da matriz. `X[:, um_vetor]` pega as colunas"""

X[[0, 0, 1]] # observe que pego a primeira linha, indexada por 0, duas vezes

"""Abaixo pego a segunda a primeira coluna"""

X[:, [1, 0]]

"""### Indexação Booleana

`X[vetor_booleano]` retorna as linhas (ou colunas quando X[:, vetor_booleano]) onde o vetor é true
"""

X[[True, False, True, False]]

X[:, [False, True, True]]

"""### Reshape, Flatten e Ravel

Todo vetor ou matriz pode ser redimensionado. Observe como uma matriz abaixo de 9x8=72 elementos. Podemos redimensionar os mesmos para outros arrays de tamanho 72.
"""

X = np.random.randn(9, 8)

"""Criando uma matriz de 18x4."""

X.reshape((18, 4))

"""Ou um vetor de 72"""

X.reshape(72)

"""A chamada flatten e ravel faz a mesma coisa, criam uma visão de uma dimensão da matriz."""

X.flatten()

X.ravel()

"""As funções incorporadas ao NumPy podem ser facilmente chamadas em matrizes. A maioria das funções são aplicadas a um elemento de array (como a multiplicação escalar). Por exemplo, se chamarmos `log()` em um array, o logaritmo será obtido de cada elemento."""

np.log(data)

"""Mean tira a média"""

np.mean(data)

"""Algumas funções podem ser chamadas direto no vetor, nem todas serão assim. O importante é ler a [documentação](http://numpy.org) e aprender. Com um pouco de prática você vai se acostumando."""

data.mean()

"""Abaixo temos a mediana,"""

np.median(data) # por exemplo, não existe data.median(). Faz sentido? Não. Mas é assim.

"""Em matrizes as funções operam em todos os elemntos."""

np.median(X)

X.mean()

np.log(X + 10)

"""Porém, caso você queira a media de linhas ou colunas use `axis`. Antes, vamos ver o tamanho do vetor."""

X.shape

np.mean(X, axis=0) # média das colunas. como temos 8 colunas, temos 8 elementos.

np.mean(X, axis=0).shape

np.mean(X, axis=1) # média das linhas

np.mean(X, axis=1).shape

"""Lembre-se que eixo 0 é coluna. Eixo 1 é linas.

### Multiplicação de Matrizes

Para transpor uma matriz fazemos uso de .T
"""

X.shape

X.T.shape

X.T

"""Para multiplicar matrizes, do ponto de visto de multiplicação matricial como definido na álgebra linear, fazemos uso de `@`."""

X @ X.T

"""O uso de `*` realiza uma operação ponto a ponto"""

X * X

"""Observe a diferença de tamanhos"""

(X * X).shape

(X @ X.T).shape

"""**Pense:** Para o nosso `X` de tamanho `(9, 8)`, qual o motivo de `X * X.T` não funcionar? Qual o motivo de `X @ X` não funcionar?

## Correção Automática

Nossa correção automática depende das funções abaixo. Tais funções comparam valores que serão computados pelo seu código com uma saída esperada. Normalmente, vocês não fazer uso de tais funções em notebooks como este. Porém, elas são chave em ambientes de testes automáticos (fora do nosso escopo).

Observe como algumas funções comparam valores e outras comparam vetores. Além do mais, temos funções para comparar dentro de algumas casas decimais.
"""

from numpy.testing import assert_almost_equal
from numpy.testing import assert_equal

from numpy.testing import assert_array_almost_equal
from numpy.testing import assert_array_equal

# caso você mude um dos valores vamos receber um erro!
assert_array_equal(2, 2)

# caso você mude um dos valores vamos receber um erro!
assert_array_equal([1, 2], [1, 2])

# caso você mude um dos valores vamos receber um erro!
assert_almost_equal(3.1415, 3.14, 1)

"""Caso você mude um dos valores abaixo vamos receber um erro! Como o abaixo.

```
-----------------------------------------------------------------------
AssertionError                        Traceback (most recent call last)
<ipython-input-10-396672d880f2> in <module>
----> 1 assert_equal(2, 3) # caso você mude um dos valores vamos receber um erro!

~/miniconda3/lib/python3.7/site-packages/numpy/testing/_private/utils.py in assert_equal(actual, desired, err_msg, verbose)
    413         # Explicitly use __eq__ for comparison, gh-2552
    414         if not (desired == actual):
--> 415             raise AssertionError(msg)
    416
    417     except (DeprecationWarning, FutureWarning) as e:

AssertionError:
Items are not equal:
 ACTUAL: 2
 DESIRED: 3
 ```

É essencial que todo seu código execute sem erros! Portanto, antes de submeter clique em `Kernel` no menu acima. Depois clique em `Restart & Execute All.`

**Garanta que o notebook executa até o fim!** Isto é, sem erros como o acima.

## Funções em Python

Para criar uma função em Python fazemos uso da palavra-chave:
```python
def
```

Todos nossos exercícios farão uso de funções. **Mantenha a assinatura das funções exatamente como requisitado, a correção automática depende disso.** Abaixo, temos um exempo de uma função que imprime algo na tela!
"""

def print_something(txt):
    print(f'Voce passou o argumento: {txt}')

print_something('DCC 212')

"""Podemos também dizer o tipo do argumento, porém faremos pouco uso disto em ICD."""

def print_something(txt: str):
    print(f'Voce passou o argumento: {txt}')

print_something('DCC 212')

"""Abaixo temos uma função que soma, a soma, dois vetores"""

def sum_of_sum_vectors(array_1, array_2):
    return (array_1 + array_2).sum()

x = np.array([1, 2])
y = np.array([1, 2])

sum_of_sum_vectors(x, y)

"""Abaixo temos um teste, tais testes vão avaliar o seu código. Nem todos estão aqui no notebook!"""

assert_equal(6, sum_of_sum_vectors(x, y))

"""## Exercício 01

Inicialmente, crie uma função que recebe duas listas de números, converte as duas para um vetor numpy usando `np.array` e retorna o produto interno das duas listas.

__Dicas:__  
1. Tente fazer um código sem nenhum **for**! Ou seja, numpy permite operações em vetores e matrizes, onde: `np.array([1, 2]) + np.array([2, 2]) = np.array([3, 4])`.

__Funções:__
1. `np.sum(array)` soma os elementos do array. `array.sum()` tem o mesmo efeito!
"""

def inner(array_1, array_2):
    # Seu código aqui!
    vetor_1 = np.array(array_1)
    vetor_2 = np.array(array_2)
    result = vetor_1 * vetor_2
    return np.sum(result)

x1 = np.array([2, 4, 8])
x2 = np.array([10, 100, 1000])
assert_equal(20 + 400 + 8000, inner(x1, x2))

"""## Exercício 02

Implemente uma função utilizando numpy que recebe duas matrizes, multiplica as duas e retorne o valor médio das células da multiplicação. Por exemplo, ao multiplicar:

```
[1 2]
[3 4]

com

[2 1]
[1 2]

temos

[4  5 ]
[10 11]

onde a média de [4, 5, 10, 11] é

7.5, sua resposta final!
```


__Dicas:__  
1. Use o operador @ para multiplicar matrizes!
"""

def medmult(X_1, X_2):
    # Seu código aqui!
    array = X_1 @ X_2
    return array.mean()

X = np.array([1, 2, 3, 4]).reshape(2, 2)
Y = np.array([2, 1, 1, 2]).reshape(2, 2)
assert_equal(7.5, medmult(X, Y))