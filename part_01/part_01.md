# Parte 01

## Alocador de memória

void * mem_alloc(size_t size);

## Motivação

* Código mais simples e mais rápido, com menos bugs e menos vulnerabilidades;
* Alocadores genéricos não tem informações pra otimizar;
* A maioria das vezes um alocador genérico não é necessário;
* Implementar um alocador para o seu problema é relativamente simples e rápido;
* Implementar e entender os tipos de alocadores mais comuns:
  - Linear 
  - Pool
  - Arena
  - Slab

## Implementação
### Linear Allocator

```
Bloco de      [-------------------------------------------------------]
Memória

* -> endereços de memória retornados ao usuário 
^ -> bytes ocupados

mem_alloc(4)  [-------------------------------------------------------]
               *   ^ 
              
mem_alloc(2)  [-------------------------------------------------------]
               *   * ^ 

mem_alloc(16) [-------------------------------------------------------]
               *   * *               ^    
```
