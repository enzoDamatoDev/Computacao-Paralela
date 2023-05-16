Compilando:

Matriz - para compilar este programa use "!/opt/nvidia/hpc_sdk/Linux_x86_64/23.3/compilers/bin/nvc  -acc -gpu=managed -o matriz matriz.c"
<br>Trapezio - para compilar este programa use !/opt/nvidia/hpc_sdk/Linux_x86_64/23.3/compilers/bin/nvc  -acc -gpu=managed -o trapezio trapezio.c"

Rodando:

Matriz - para rodar este programa use "!time ./matriz {número de threads}" <strong>\*o numero de threads também será a ordem da matriz(durante os testes são usados 3000 threads)\*</strong><br>
![image](https://github.com/enzoDamatoDev/Computacao-Paralela/assets/79601694/14b52451-c4e1-4056-85ab-e9ddcd7108a3)


<br>Trapezio - para rodar este programa use "!time ./trapezio {número de threads} {lado A} {lado B} {número de trapezoides}" <strong>\*foram usados os parametros 2000 80 200 2000\*</strong><br>
![image](https://github.com/enzoDamatoDev/Computacao-Paralela/assets/79601694/f47507a4-fbca-40dd-a3cd-40c2e4399100)

<br><br>
Comandos adicionais:<br>
!nvidia-smi:
![image](https://github.com/enzoDamatoDev/Computacao-Paralela/assets/79601694/4a1eb62c-3500-4525-a6f0-8870b3016c8c)

<br><br>

!nvaccelinfo:
