#include <iostream>

using namespace std;

int main() {
	char str[100];
	int posicao,i;
	cout<<"escreva sua mensagem:"<<endl;
	cin >> str;
	
	cout<<"qual posicao deseja remover?"<<endl;
	cin >> posicao;
	while(posicao <0 || posicao > 99){
		cout<<"minimo 0 maximo 99"<<endl;
		cin >> posicao;
	}
	
	for(i=posicao;i<100;i++){
		str[i] = str[i+1];
	}
	
	cout<<str<<endl;
    return 0;
}
