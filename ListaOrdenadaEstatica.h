#ifndef LISTAORDENADAESTATICA_H_INCLUDED
#define LISTAORDENADAESTATICA_H_INCLUDED
#define MAX 20
#include "Cliente.h"
//metodos utilizados para inclusao dos arquivos e definicao de uma constante
using namespace std;
//link para explicacao do codigo no YouTube: https://youtu.be/KyyKJ4styuU

class Lista{        //cria a classe lista
    public:         //o public especifica que os membros da classe sao acessiveis de qualquer funcao
        Lista(){        //contrutor que cria a classe lista com tamanho 0

            tam = 0;       //tamanho da lista inicialmente 0
        }
        ~Lista() {}     //destrutor da classe lista 

        Cliente clientes[MAX];      //criacao da variavel clientes do tipo Cliente com tamanho até 20
        unsigned tam;               //criacao da variavel que indica o tamaho do vetor lista

        void imprime(){     //funcao sem retorno que imprime todos itens de uma lista

            for (unsigned i = 0; i < tam; i++){
                
                cout << "<" << clientes[i].chave << " , " << clientes[i].nome << ">   " << endl;
            }
            cout << "\n" << endl;
        }

        void insere(const Cliente &clie){  /*funcao que ira inserir o cliente passado por parametro dentro da
                                            classe clientes*/

            if (tam == 0){      /*checa se o tamanho da lista é igual a 0 para fazer a inserçao do primeiro 
                                cliente na lista*/
                clientes[0] = clie;     //insercao do primeiro cliente
                tam++;      //incrementa o tamanho da lista
            }else{      //se nao for o primeiro cadastro

                int posicao = procuraposicao(clientes, 0, tam, clie.chave); /*executa a funcao procuraposicao 
                                                                            para olhar a posicao correta para 
                                                                            manter o vetor ordenado*/
                if (tam >= MAX){    /*se o tamanho da lista for maior ou igual ao maximo permitido no vetor
                                    nao sera inserido o cliente na lista e sera impressa a mensagem*/
                    cout << "A lista esta cheia" << endl;
                    return;
                }
                if (clientes[posicao].chave == clie.chave){     /*se a chave do cliente na posicao desejada 
                                                                for igual a chave do cliente a ser inserido
                                                                exibira a mensagem*/
                    cout << "Cliente ja cadastrado" << endl;
                    return;
                }
                for (int i = tam; i > posicao; i--){        /*executa um loop para mover os itens do vetor ate 
                                                            o momento da posicao desejada*/
                    clientes[i] = clientes[i - 1];
                }
                clientes[posicao] = clie;       //insere o cliente desejado na posicao correta
                tam++;                          //incrementa o tamanho da lista
                                                //1 2 3 4      
            }
        }
        /*verificar a posicao correta de maneira recursiva para manter o vetor ordenado
        utiliza como parametro a classe cliente, a posicao inicial, posicao final e a chave*/
        int procuraposicao(Cliente client[MAX], int comeco, int fim, unsigned chave){   
        
            int i = (comeco + fim) / 2;    //pega a posicao central do vetor

            if (fim - comeco <= 0){   /*condicao de parada da recursao, se entrar na condiçao, significa que 
                                        ja percorreu todas as posicoes necessaria para fazer a verificacao*/
                return comeco;        // se o fim-comeco <=0 significa que a posicao comeco e a posicao desejada
            }
            if (clientes[i].chave == chave){     // se entrar na condicao significa que a chave foi encontrad
                 
                return i;   //retorna a posicao da chave
            }
            if (clientes[i].chave < chave){ /*se entrar na condicao significa que a chave está no sub-vetor 
                                            à direita*/
                return procuraposicao(client, i + 1, fim, chave); /*chama novamente a funcao com o comeco na 
                                                                    posicao central +1 para nova checagem*/
            }else{ // clientes[i].chave > chave. chave está no sub-vetor à esquerda
                
                return procuraposicao(client, 0, i, chave);   /*chama novamente a funcao com o comeco na 
                                                            posicao 0 e fim na metade do veotor para nova 
                                                            checagem*/
            }
        }
         //funcao para procurar o cliente de acordo com sua chave
        Cliente procura(unsigned chav){    

            int k = 0;  //contador para inicializaçao e desativaçao do loop
            while (k < tam){  

                if (chav == clientes[k].chave){   /*se a chave procurada for igual a chave em alguma posicao
                                                    do vetor clientes*/

                    int posic = procuraposicao(clientes, 0, tam, chav);  /*chama a funcao procuraposicao para 
                                                                        procurar a posicao do cliente */
                    return clientes[posic];  //retorna o cliente que esta na posicao desejada
                }
                k++;    //incrimento no contador
            }
            Cliente nulo;  //caso nao encontre o cliente no vetor, retorna o cliente padrao(chave=0,nome=dummy)
            return nulo;
        }
        //funcao criada para substiruir a lista1 pela mescla da listaOE1 com a listaOE2
        void junta(const Lista &lista2){    //funcao sem retorno que recebe a listaOE2 como parametro

            int t2 = lista2.tam;  //criado uma variavel para receber o tamanho da listaOE2
            int k;          //contador para execucao do loop
            int posicao;    //variavel para armazenar a posicao retornada pela funcao procuraposicao

            if (((tam + t2) <= MAX)){   /*checar se o tamanho das duas listas juntas nao excede o maximo 
                                        permitido que e 20*/
            
                for (k = 0; k < t2; k++){       //loop para percorrer todas as posicoes da listaOE2   

                    posicao = procuraposicao(clientes, 0, tam, lista2.clientes[k].chave);/*procura a posicao 
                                                                                        correta para insercao da 
                                                                                        chave do cliente da listaOE2
                                                                                        na listaOE1e armazena 
                                                                                        na variavel posicao*/
                    for (int i = tam; i > posicao; i--){    /*executa um loop para mover os itens do vetor ate 
                                                            o momento da posicao desejada*/
                        clientes[i] = clientes[i - 1];  
                    }

                    clientes[posicao] = lista2.clientes[k];  /*insere o cliente da listaOE2 na listaOE1 na 
                                                              posicao desejada*/
                    tam++;  //incrementa o valor da listaOE1
                }
            }
            else  // se o tamanho exceder o maximo permitido exibe mensagem
            { 
                cout << "Nao e possivel juntar as listas" << endl;
            }
        }
};
#endif