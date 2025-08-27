---

### Olá, seja bem vindo ao meu repositório sobre estruturas de dados!

O objetivo desse repositório é guardar as diferentes estruturas de dados clássicas, como arrays, arrays dinâmicos, listas ligadas, pilhas, filas, árvores e grafos.
A princípio, cada uma dessas estruturas e suas respectivas operações - como busca, inserção, deleção, travessia, etc -, bem como suas características (como a altura de uma árvore,
a cabeça de uma lista ligada, etc), serão implementadas utilizando a linguagem de programação C (e, às vezes, Golang). 

À medida que os meus conhecimentos e domínio acerca do tema forem aumentando, estarei implementando diferentes abordagens e usos de cada uma dessas estruturas, e também 
estarei expandindo as suas implementações para outras linguagens. Espero que goste dos resultados - e, principalmente, do caminho até eles! 

---

### Árvore Binária de Busca / Binary Search Tree (BST)

A árvore de busca binária é uma árvore binária - isto é, uma árvore em que cada nó pode possuir até, no máximo, 2 filhos - em que cada nó da sub-árvore à esquerda possui um valor menor ou igual do que o nó que a originou, e de maneira parecida, mas oposta, cada nó na sub-árvore formada à direita possui um valor maior do que esse nó. 

---

### Pilhas / Stacks

As pilhas ou stacks são um tipo de coleção de dados em que o último item a ser adicionado é o primeiro que tem que sair - segue o princípio LIFO, que significa "Last-In-First-Out", em que o último a entrar é o primeiro a sair. De outro modo, uma pilha é uma lista de dados que possui a restrição de que o ato de inserir e de retirar os elementos de dentro dela deve ser performado apenas a partir de uma única entrada/saída (na verdade, as duas funcionam como uma coisa apenas), que nós podemos chamar de 'top'. 

A operação de inserir um novo elemento na pilha é nomeada 'push', e outra operação fundamental é a chamada 'pop', que consiste na remoção de um elemento da lista - mais precisamente, é a retirada do elemento mais recente da stack. A operação chamada 'top' simplesmente retorna o elemento que está no 'top' da pilha, e 'isEmpty' é uma possível operação que retorna verdadeiro se a pilha estiver vazia, e falso se a pilha conter algum elemento. Todas essas operações são performadas em tempo constante, ou seja, Big O de n - O(1). Algumas das aplicações de pilhas podem ser: usada para a execução de chamadas de funções em um programa, incluindo o fenômeno da recursão; implementar a operação de 'desfazer' em um editor, como CTRL + Z; e é usada em um número considerável de algoritmos, como o balanceamento de parênteses.

---

### Algoritmos de Ordenação

### Selection Sort

O *Selection Sort* é um algoritmo simples que funciona escolhendo repetidamente o menor elemento da parte não ordenada do array e colocando-o na posição correta. Embora seja fácil de entender e implemente a ordenação "in place", sem necessidade de memória auxiliar significativa, ele não é estável, ou seja, pode alterar a ordem relativa de elementos iguais. Em termos de desempenho, apresenta tempo de execução quadrático em todos os cenários — melhor, médio e pior caso são sempre **O(n²)** — o que o torna pouco eficiente para grandes quantidades de dados. Por outro lado, sua complexidade espacial é mínima, apenas **O(1)**, já que não utiliza estruturas auxiliares.

---

## Bubble Sort  

O **Bubble Sort** é um dos algoritmos de ordenação mais simples e didáticos. Seu funcionamento se baseia em comparar pares de elementos adjacentes e trocá-los caso estejam fora de ordem. Esse processo é repetido diversas vezes até que todos os elementos estejam ordenados, como se os maiores valores "borbulhassem" para o fim da lista a cada passagem.  

Apesar de ser bastante intuitivo e fácil de implementar, o Bubble Sort não é eficiente em termos de desempenho. No pior e no caso médio, sua complexidade de tempo é **O(n²)**, o que o torna impraticável para grandes conjuntos de dados. Por outro lado, no melhor cenário — quando a lista já está ordenada — sua complexidade é **O(n)**, pois apenas uma varredura é suficiente para verificar que não há trocas necessárias. Em termos de espaço, é um algoritmo **in-place**, ou seja, não exige memória adicional significativa além da lista original (**O(1)**).  

O Bubble Sort é pouco utilizado em aplicações reais devido à sua baixa eficiência, mas permanece como um algoritmo importante do ponto de vista pedagógico. Ele ajuda iniciantes a compreender conceitos fundamentais de ordenação, comparação e troca de elementos em uma estrutura de dados.  

---

### Insertion Sort

O *Insertion Sort* é um algoritmo de ordenação que imita o processo de organizar cartas na mão: percorremos o array da esquerda para a direita e, a cada novo elemento, inserimos ele na posição correta em relação aos que já foram ordenados. Esse método faz com que, a cada iteração, a porção inicial do array esteja sempre ordenada. Trata-se de um algoritmo estável, pois mantém a ordem relativa de elementos iguais, e funciona "in place", utilizando apenas memória constante (**O(1)**). Seu maior ponto fraco é o desempenho: no pior e no caso médio, apresenta tempo quadrático (**O(n²)**), pois cada inserção pode exigir deslocar muitos elementos. No entanto, quando a entrada já está parcialmente ordenada, o desempenho melhora significativamente, podendo chegar a **O(n)** no melhor caso. Isso faz do *Insertion Sort* uma boa escolha para listas pequenas ou quase ordenadas, embora não seja adequado para grandes volumes de dados.

---

### Merge Sort

O *Merge Sort* segue a estratégia de **Divisão e Conquista**, dividindo o array em metades até restarem subarrays com apenas um elemento e, em seguida, mesclando-os de forma ordenada. Esse processo garante que o algoritmo seja estável, preservando a ordem de elementos iguais, e extremamente eficiente para grandes volumes de dados. Seu tempo de execução é **O(n log n)** em todos os casos (melhor, médio e pior), mas em contrapartida ele exige memória auxiliar proporcional ao tamanho da entrada, resultando em uma complexidade espacial de **O(n)**.