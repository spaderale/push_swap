# push_swap

Projeto desenvolvido como parte do currículo da 42 Porto, focado em criar um algoritmo de ordenação altamente eficiente usando apenas operações permitidas e duas stacks (A e B). Este repositório implementa o método **Turkish Sorting Method (Turk Method)**, conhecido pela sua eficiência e flexibilidade para ordenar grandes listas com o menor número possível de movimentos.

---

## ✨ Objetivo

Receber uma lista de inteiros como entrada e gerar uma sequência otimizada de operações capazes de ordenar esses números em ordem crescente utilizando apenas as operações definidas pelo projeto.

### **Operações permitidas**

* `sa` : troca os dois primeiros elementos da stack A
* `sb` : troca os dois primeiros elementos da stack B
* `ss` : executa `sa` e `sb` simultaneamente
* `pa` : move o primeiro elemento da stack B para A
* `pb` : move o primeiro elemento da stack A para B
* `ra` : rotate A — move o primeiro elemento para o final
* `rb` : rotate B — move o primeiro elemento para o final
* `rr` : `ra` e `rb` simultâneos
* `rra`: reverse rotate A — último elemento vai para o topo
* `rrb`: reverse rotate B — último elemento vai para o topo
* `rrr`: `rra` e `rrb` simultâneos

---

## 🧠 Algoritmos Implementados

### **1. Caso de 3 números**

* Ordenação direta com no máximo 2 movimentos.
* Comparação simples dos valores.

### **2. Caso de 5 números**

* Move os 2 menores para a stack B.
* Ordena os 3 restantes em A.
* Reinsere os menores na posição correta.

### **3. Números maiores — Turk Method**

✔ Usa indexação para padronizar os valores.

✔ Empurra elementos para a stack B com base na posição ideal futura.

✔ Calcula custos individuais para cada elemento:

* rotacionar A
* rotacionar B
* combinação `rr`
* combinação `rrr`

✔ Escolhe sempre o elemento de **menor custo total** para ser reinserido.

✔ Realiza a rotação mais curta (top ou bottom).

**Não utiliza chunks** — o método é baseado **100% em custos e rotações combinadas**, garantindo máxima eficiência.

---

## 📊 Performance Estimada

| Quantidade  | Operações Máximas | Algoritmo            |
| ----------- | ----------------- | -------------------- |
| 3 números   | 2 ops             | Small Sort           |
| 5 números   | ~12 ops           | Small Sort otimizado |
| 100 números | ~620–750 ops      | Turk Method          |
| 500 números | ~4500–5500 ops    | Turk Method          |

---

## 🧪 Validação

O programa valida:

* ✔ Apenas números inteiros
* ✔ Ausência de duplicados
* ✔ Intervalo válido de 32 bits
* ✔ Argumentos múltiplos ou string única
* ✔ Stack já ordenada (retorna nada)

---

## 📁 Estrutura do Projeto

```
.
├── inc/
│   └── push_swap.h
├── libft/
│   ├── inc/
│   ├── libft.a
│   ├── Makefile
│   └── src/
│       ├── ft_printf/
│       └── libft/
├── src/
│   ├── main.c
│   ├── input_check.c
│   ├── parse_elements.c
│   ├── split.c
│   ├── stack_init.c
│   ├── stack_utils.c
│   ├── node_operations.c
│   ├── index_utils.c
│   ├── push.c
│   ├── push_cost_1.c
│   ├── push_cost_2.c
│   ├── rotate.c
│   ├── reverse.c
│   ├── swap.c
│   ├── small_sort.c
│   └── large_sort.c
├── Makefile
├── obj/
└── push_swap
```

---

## 🚀 Como Compilar

```
make
./push_swap 4 67 3 87 23
```

---

## 📊 Exemplo de Execução

Entrada:

```
./push_swap 4 2 3 1
```

Saída (exemplo):

```
pb
ra
pb
sa
pa
pa
```

---

## 🛠️ Funcionalidades

### ✔ Validação

* Números válidos
* Detecção de duplicatas
* Limites de inteiros
* Suporte a formatos variados

### ✔ Ordenação

* Algoritmos diferentes para cada tamanho
* Mínimo de operações
* Suporte a negativos

### ✔ Gestão de Memória

* Sem leaks
* Liberação completa

### ✔ Otimizações

* Indexação de valores
* Rotação combinada (`rr`, `rrr`)
* Cálculo preciso de custos
* Seleção do menor caminho

### ✔ Tratamento de Erros

* Argumentos inválidos
* Números duplicados
* Falha de malloc
* Stack já ordenada

---

## 📝 Exemplo Completo

```
$ ./push_swap 5 2 8 1 9

# Operações geradas (exemplo)
pb
ra
pb
ra
sa
pa
pa
ra

# Stack final
1 2 5 8 9
```

---

## 🏆 Skills Desenvolvidas

* Estruturas de dados
* Análise de complexidade
* Manipulação de listas ligadas
* Otimização de operações
* Estratégias avançadas de sorting


---

## 📫 Contato

Projeto por **Alexandre** — sugestões e issues são bem-vindas!
