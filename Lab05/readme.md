para compilar o programa utilize os comandos "gcc -pthread -o pthreads pthreads.c"

parte 1<br>
Para rodar o programa em serial utilize "./pthreads 0 {ordem da matriz}".<br>
No exemplo a seguir foi usado o comando "time ./pthreads 0 500"<br>
![image](https://user-images.githubusercontent.com/79601694/230905474-087352b0-0c60-4281-b55a-d58860df9455.png)


parte 2<br>
Para rodar o programa em Paralelo utilize "./pthreads {ordem da matriz}". A ordem da matriz será também o número de threads criadas.<br>
No exemplo a seguir foi usado o comando "time ./pthreads 500".<br>
![image](https://user-images.githubusercontent.com/79601694/230905770-d7f1cb2e-77b7-4f12-a54c-aee4b673272d.png)

Parte 3:<br>
o speedup será dado pela divisão do tempo total serial (0,347s) pelo tempo total paralelo (0,081s)<br>
então o speedup foi de 4,28.
