parte 1

para rodar o programa utilize os comandos "gcc -o matriz matriz.c" e "./matriz {ordem da matriz}"

parte 2<br>
Sem otimização testada com ordem = 1000. comandos: "gcc -O0 matriz.c" + "time ./a.out 1000"<br>
![image](https://user-images.githubusercontent.com/79601694/228638544-f1e1fbcd-1bcf-4638-93ca-f5bd99b51043.png)
<br><br>
Com otimização testada com ordem = 1000. comandos: "gcc -O3 matriz.c" + "time ./a.out 1000"<br>
![image](https://user-images.githubusercontent.com/79601694/228639395-c1612f24-d5ad-4220-bb49-80486c3547ac.png)

parte 3
Com utilização de caches l1 e l2 testada com ordem = 1000. comandos: "gcc -O0 matriz.c" + "time ./a.out 1000"<br>

![image](https://user-images.githubusercontent.com/79601694/228640919-646cedeb-36fc-4c38-80bd-3d3e552ebfdf.png)
