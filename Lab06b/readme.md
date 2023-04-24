Compilando:

Matriz - para compilar este programa use "gcc matriz.c -o matriz -fopenmp -lm"
<br>Trapezio Critical - para compilar este programa use "gcc trapezioCrit.c -o trapezioCritical -fopenmp -lm"
<br>Trapezio Reduction - para compilar este programa use "gcc trapezioRed.c -o trapezioReduction -fopenmp -lm"

Rodando:

Matriz - para rodar este programa use "time ./matriz {número de threads}" <strong>\*o numero de threads também será a ordem da matriz(durante os testes são usados 500 threads)\*</strong>

<br>Trapezio Critical - para rodar este programa use "time ./trapezioCritical {número de threads} {lado A} {lado B} {número de trapezoides}" <strong>\*foram usados os parametros 10 10 50 100\*</strong>

<br>Trapezio Reduction - para rodar este programa use ""time ./trapezioReduction {número de threads} {lado A} {lado B} {número de trapezoides}" <strong>\*foram usados os parametros 10 10 50 100\*</strong>

<br>Tabela de Tempos
<table>
  <tr>
    <th>Programa</th>
    <th>Processadores</th>
    <th>tempo 1</th>
    <th>tempo 2</th>
    <th>tempo 3</th>
    <th>Média</th>
    <th>Resultado</th>
    <th>SpeedUp</th>
  </tr>
  <tr>
    <th rowspan="2">Matriz</th>
    <td>1 Processador</td>
    <td>0m0.621s</td>
    <td>0m0.619s</td>
    <td>0m0.616s</td>
    <td>0m0.618s</td>
    <td>Sem Resultado</td>
    <td rowspan="2">1,04</td>
  </tr>
  <tr>
    <td>2 processadores</td>
    <td>0m0.561s</td>
    <td>0m0.579s</td>
    <td>0m0.642s</td>
    <td>0m0.594s</td>
    <td>Sem Resultado</td>
  </tr>
  <tr>
    <th rowspan="2">Trapezio Critical</th>
    <td>1 Processador</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>5.25365129001867e+21</td>
    <td rowspan="2">1</td>
  </tr>
  <tr>
    <td>2 processadores</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>5.25365129001867e+21</td>
  </tr>
  <tr>
    <th rowspan="2">Trapezio Reduction</th>
    <td>1 Processador</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>5.25365129001867e+21</td>
    <td rowspan="2">1</td>
  </tr>
  <tr>
    <td>2 processadores</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>0m0.002s</td>
    <td>5.25365129001867e+21</td>
  </tr>
</table>

<br><br>
Análise:
<br>
Os SpeedUps observados não são muito efetivos, pois o numero de threads utilizadas foi baixo, e o numero de processadores não variou tanto. Também em decorrencia disso,
os resultados não foram diferentes, dificultando uma análise mais profunda.
