#include <iostream>

using namespace std;

struct pessoa{
	char nome[25];
	int idade;
	float peso;
	float altura;
};

int main() {
	pessoa lista[3];
	for(int i=0;i<3;i++){
		cout<<"\nnome da pessoa "<<i+1<<endl;
		cin>>lista[i].nome;
		
		cout<<"idade da pessoa "<<i+1<<endl;
		cin>>lista[i].idade;
		
		cout<<"peso da pessoa "<<i+1<<endl;
		cin>>lista[i].peso;
		
		cout<<"altura da pessoa "<<i+1<<endl;
		cin>>lista[i].altura;
	}
    for(int i=0;i<3;i++){
    	cout<<"\npessoa "<<i+1<<endl;
		cout<<lista[i].nome<<endl;
		cout<<lista[i].idade<<endl;
		cout<<lista[i].peso<<endl;
		cout<<lista[i].altura<<endl;
	}
	
    return 0;
}
