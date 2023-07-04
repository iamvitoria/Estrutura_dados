Disciplina: Estrutura de dados
Dupla: Giulia e Vitória
Trabalho: 2


Relatório - Atualização do Código do Heap Maximo


Modificações realizadas:

Adição da função printHeapWithChildren: imprime cada nó do heap com seus filhos correspondentes. Ela percorre todos os nós do heap e, para cada nó, verifica se ele possui filhos esquerdo e direito. Caso positivo, imprime os valores dos filhos. Essa função permite visualizar a estrutura do heap de forma mais completa, facilitando a verificação da corretude das inserções e remoções.

Modificação da função printHeap: imprime apenas os valores dos nós do heap, sem exibir os filhos. Essa função continua sendo útil para visualizar o heap em ordem de prioridade máxima sem as informações detalhadas dos filhos.

Atualização do cabeçalho do arquivo "heap.h": incluimos a nova função printHeapWithChildren;

Atualização do arquivo "main.c": chamada da função printHeapWithChildren após a inserção dos valores no heap. Isso permite visualizar a estrutura do heap com os filhos imediatamente após a inserção;