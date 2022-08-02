
#include <iostream>
#include "ListaOrdenadaEstatica.h"

using namespace std;
int main(){
    //link para explicacao do codigo no YouTube: https://youtu.be/KyyKJ4styuU
    
    Lista listaOE;  //Aloca uma lista chamada listaOE
    Lista listaOE2; //Aloca uma segunda lista chamada listaOE2

    Cliente c1(1,"a");  //declarando um cliente c1
    Cliente c2(2,"b");  //declarando um cliente c2
    Cliente c3(3,"c");  //declarando um cliente c3
    Cliente c4(4,"d");  //declarando um cliente c4
    Cliente c5(5,"e");  //declarando um cliente c5
    Cliente c6(6,"f");  //declarando um cliente c6
    Cliente c7(7,"g");  //declarando um cliente c7
    Cliente c8(8,"h");  //declarando um cliente c8
    Cliente c9(9,"i");  //declarando um cliente c9

    listaOE.insere(c2);     //usa o metodo insere para incluir o cliente c2 dentro da lista listaOE
    listaOE.imprime();      //imprime os itens dentro da lista listaOE

    listaOE.insere(c5);     //usa o metodo insere para incluir o cliente c5 dentro da lista listaOE
    listaOE.imprime();      //imprime os itens dentro da lista listaOE

    listaOE.insere(c9);     //usa o metodo insere para incluir o cliente c9 dentro da lista listaOE
    listaOE.imprime();      //imprime os itens dentro da lista listaOE

    listaOE.insere(c7);     //usa o metodo insere para incluir o cliente c7 dentro da lista listaOE
    listaOE.imprime();      //imprime os itens dentro da lista listaOE

    listaOE.insere(c6);     //usa o metodo insere para incluir o cliente c6 dentro da lista listaOE
    listaOE.imprime();      //imprime os itens dentro da lista listaOE

    cout <<"xxxxxx" << "\n" << endl;    //imprime uma divisao para melhor visualizaçao do codigo

    listaOE.procura(2).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        2 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    listaOE.procura(9).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        9 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    listaOE.procura(5).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        5 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    listaOE.procura(1).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        1 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    listaOE.procura(8).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        8 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    listaOE.procura(4).mostraclient();  /*invoca o metodo procura na listaOE que ira procurar o cliente de chave 
                                        4 e retornar o cliente que sera impresso pelo metodo mostraclient*/

    cout << "\n" << "xxxxxx" << "\n" << endl;   //imprime uma divisao para melhor visualizaçao do codigo

    listaOE2.insere(c1);    //usa o metodo insere para incluir o cliente c1 dentro da lista listaOE2
    listaOE2.insere(c3);    //usa o metodo insere para incluir o cliente c3 dentro da lista listaOE2
    listaOE2.insere(c8);    //usa o metodo insere para incluir o cliente c8 dentro da lista listaOE2
    listaOE2.insere(c4);    //usa o metodo insere para incluir o cliente c4 dentro da lista listaOE2

    listaOE2.imprime();     //usa o metodo imprime para mostrar os itens dentro da lista listaOE2

    cout <<"xxxxxx" << "\n" << endl;        //imprime uma divisao para melhor visualizaçao do codigo

    listaOE.junta(listaOE2);        /*usa o metodo junta para substituir a listaOE pela mescla da listaOE 
                                    com a listaOE2 */

    listaOE.imprime();             /*usa o metodo imprime para mostrar os itens dentro da nova lista listaOE 
                                    gerada pela mescla da listaOE e listaOE2*/
                                    
    cout <<"xxxxxx" << "\n" << endl;        //imprime uma divisao para melhor visualizaçao do codigo

    listaOE2.imprime();     //usa o metodo imprime para mostrar os itens dentro da lista listaOE2

    return 0;      
}