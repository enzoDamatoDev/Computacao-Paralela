Compilando:

Para compilar este programa use "gcc -O busca.c -fopenmp"

Rodando:

Para rodar em serial use "time ./a.out {alvo} {caminho do arquivo} 1"<br>
Para rodar em paralelo use "time ./a.out {alvo} {caminho do arquivo}"<br>

os exemplos a seguir usam:<br>
alvo = 165207 e caminho do arquivo = /home/ubuntu/Computacao-Paralela/Lab06c/vetor1.txt

tempos em serial<br>
![image](https://user-images.githubusercontent.com/79601694/235846180-4063906b-ba2c-4548-8cd6-254ea514f1b3.png)


tempos em paralelo<br>
![image](https://user-images.githubusercontent.com/79601694/235846285-7dcd0b70-9f4b-4b34-b48b-6b77a6752b72.png)
<br>

média dos tempos:<br>
serial (12+8+8)/3 = 0,0093s<br>
paralelo (9+8+9)/3 = 0,0086s<br>

speedup: 0,0093s/0,0086s = 1,081
