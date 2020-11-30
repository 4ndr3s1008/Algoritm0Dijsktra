#include <stdio.h>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define maxi 50 //Numero maximo de vertices(porseaca)
#define infin 1<<30 //Defino valor infinito

struct Arista{
	int nodo;
	int peso;
	Arista(int _nodo, int _peso):nodo(_nodo), peso(_peso){}
	Arista():nodo(-1), peso(-1){}
};

struct Graf{
	vector<Arista> G[maxi];// lista
	int V;
	int A;
};

struct estado{
	int nodo;
	int peso;
	estado(int _nodo,int _peso):nodo(_nodo),peso(_peso){}
	bool operator<(const estado &b)const{
		return peso>b.peso;
	}
};

int algoritmo(const int begin,const int end,const Graf graf){
	priority_queue<estado> pq;
	vector<int> distancia(graf.V, infin);
	vector<bool> mark(graf.V, false);
	distancia[begin]=0;
	pq.push(estado(begin,0));
	while(!pq.empty()){
		estado st=pq.top();
		pq.pop();
		mark[st.nodo]= true;
		if (st.nodo== end){
			return st.peso;
			}
		int T=(int)graf.G[st.nodo].size();
		for(int i= 0; i<T; ++i){
                if (!mark[graf.G[st.nodo][i].nodo]&&((distancia[st.nodo]
                    +graf.G[st.nodo][i].peso)<distancia[graf.G[st.nodo][i].nodo])){
                        distancia[graf.G[st.nodo][i].nodo] = st.peso + graf.G[st.nodo][i].peso;
                        pq.push(estado(graf.G[st.nodo][i].nodo, st.peso + graf.G[st.nodo][i].peso));
                        }
        }
	}
	return -1;//Aqui si no existe algun camino, retorna -1
}

struct DijksProg{
	int V,A;
	int inicio,finn;
	void defGraf(Graf& graf){
		cout<<"Ingrese Cantidad de Vertices: "<< endl;
		cin>>V;
		cout<<"Ingrese Cantidad de Aristas: "<<endl;
		cin>>A;
		graf.V =V;
		graf.A =A;
	}
	void cargGraf(Graf& graf){
	    printf("=========================\n");
	    printf("Ahora ingresara cada par de nodos junto a su arista\n");
		for (int i=0; i<A; ++i){
			int n_origen,n_dest, peso;
			cout<<"Ingrese nodo origen: "<<endl;
			cin>>n_origen;
			cout<<"Ingrese nodo destino: " <<endl;
			cin >>n_dest;
			cout<<"Ingrese peso de la arista: "<<endl;
			cin>>peso;
			graf.G[n_origen].push_back(Arista(n_dest, peso));
		}
	}
	void Dijkstra(Graf graf){
	    unsigned t0, t1;
	    printf("===================\n");
	    printf("Por ultimo ingrese nodo inicial y final\n");
	    printf("del cual quiere saber el camino mas corto\n");
	    printf("\n");
		cout<<"Ingrese vertice inicial: "<<endl;
		cin>>inicio;
		cout<< "Ingrese vertice final: "<< endl;
		cin>> finn;
		t0=clock();
		int n=algoritmo(inicio,finn, graf);
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		printf("\n");
		cout<< "La longitud del camino mas corto es: "<<n<< endl;
	}
};

int main(){
    //unsigned t0, t1;
	//char resp;
	DijksProg dijksprog;
	Graf graf;

	printf("Algoritmo Dijkstra\n");
    printf("\n");
	dijksprog.defGraf(graf);
	dijksprog.cargGraf(graf);
	//t0=clock();
	dijksprog.Dijkstra(graf);
	//t1=clock();
    printf("\n");
    cout << "Tiempo de ejecucion: "<<time<< endl;
    printf("\n");

}
