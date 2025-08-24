Olá, seja bem vindo ao meu repositório sobre estruturas de dados!

O objetivo desse repositório é guardar as diferentes estruturas de dados clássicas, como arrays, arrays dinâmicos, listas encadeadas, pilhas, filhas, árvores e grafos.
A princípio, cada uma dessas estruturas e suas respectivas operações - como busca, inserção, deleção, etc -, bem como suas características (como a altura de uma árvore,
a cabeça de uma lista encadeada, etc), serão implementadas utilizando a linguagem de programação C.

À medida que os meus conhecimentos e domínio acerca do tema forem aumentando, estarei implementando diferentes abordagens e usos de cada uma dessas estruturas, e também 
estarei expandindo as suas implementações para outras linguagens. Espero que goste dos resultados - e, principalmente, do caminho até eles! 



Árvore Binária de Busca / Binary Search Tree (BST)

A árvore de busca binária é uma árvore binária - isto é, uma árvore em que cada nó pode possuir até, no máximo, 2 filhos - em que cada nó da sub-árvore à esquerda possui um valor menor ou igual do que o nó que a originou, e de maneira parecida, mas oposta, cada nó na sub-árvore formada à direita possui um valor maior do que esse nó. 



Pilhas / Stacks

As pilhas ou stacks são um tipo de coleção de dados em que o último item a ser adicionado é o primeiro que tem que sair - segue o princípio LIFO, que significa "Last-In-First-Out", em que o último a entrar é o primeiro a sair. De outro modo, uma pilha é uma lista de dados que possui a restrição de que o ato de inserir e de retirar os elementos de dentro dela deve ser performado apenas a partir de uma única entrada/saída (na verdade, as duas funcionam como uma coisa apenas), que nós podemos chamar de 'top'. 

A operação de inserir um novo elemento na pilha é nomeada 'push', e outra operação fundamental é a chamada 'pop', que consiste na remoção de um elemento da lista - mais precisamente, é a retirada do elemento mais recente da stack. A operação chamada 'top' simplesmente retorna o elemento que está no 'top' da pilha, e 'isEmpty' é uma possível operação que retorna verdadeiro se a pilha estiver vazia, e falso se a pilha conter algum elemento. Todas essas operações são performadas em tempo constante, ou seja, Big O de n - O(1). Algumas das aplicações de pilhas podem ser: usada para a execução de chamadas de funções em um programa, incluindo o fenômeno da recursão; implementar a operação de 'desfazer' em um editor, como CTRL + Z; e é usada em um número considerável de algoritmos, como o balanceamento de parênteses.

---

Algoritmos de Ordenação

### Selection Sort

O *Selection Sort* é um algoritmo simples que funciona escolhendo repetidamente o menor elemento da parte não ordenada do array e colocando-o na posição correta. Embora seja fácil de entender e implemente a ordenação "in place", sem necessidade de memória auxiliar significativa, ele não é estável, ou seja, pode alterar a ordem relativa de elementos iguais. Em termos de desempenho, apresenta tempo de execução quadrático em todos os cenários — melhor, médio e pior caso são sempre **O(n²)** — o que o torna pouco eficiente para grandes quantidades de dados. Por outro lado, sua complexidade espacial é mínima, apenas **O(1)**, já que não utiliza estruturas auxiliares.

---

### Merge Sort

O *Merge Sort* segue a estratégia de **Divisão e Conquista**, dividindo o array em metades até restarem subarrays com apenas um elemento e, em seguida, mesclando-os de forma ordenada. Esse processo garante que o algoritmo seja estável, preservando a ordem de elementos iguais, e extremamente eficiente para grandes volumes de dados. Seu tempo de execução é **O(n log n)** em todos os casos (melhor, médio e pior), mas em contrapartida ele exige memória auxiliar proporcional ao tamanho da entrada, resultando em uma complexidade espacial de **O(n)**.

---
