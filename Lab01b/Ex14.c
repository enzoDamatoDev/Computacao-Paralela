#include <iostream>

using namespace std;

int main() {
	char str[100],novo;
	int posicao;
	cout<<"escreva sua mensagem:"<<endl;
	cin >> str;
	
	cout<<"qual posicao deseja substituir?"<<endl;
	cin >> posicao;
	while(posicao <0 || posicao > 99){
		cout<<"minimo 0 maximo 99"<<endl;
		cin >> posicao;
	}
	
	cout<<"substituir por"<<endl;
	cin >> novo;
	
	str[posicao] = novo;
	
	cout<<str<<endl;
    return 0;
}
