2. Média aritmética de três notas

ALGORITMO
DECLARE n1, n2, n3, media NUMERICO
LEIA n1, n2, n3
media = (n1 + n2 + n3) / 3
ESCREVA media
FIM_ALGORITMO.

3. Média ponderada

ALGORITMO
DECLARE n1, n2, n3, p1, p2, p3, media NUMERICO
LEIA n1, n2, n3, p1, p2, p3
media = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3)
ESCREVA media
FIM_ALGORITMO.

4. Salário com aumento de 25%

ALGORITMO
DECLARE salario, novoSalario NUMERICO
LEIA salario
novoSalario = salario + (salario * 0.25)
ESCREVA novoSalario
FIM_ALGORITMO.

5. Salário com percentual de aumento variável

ALGORITMO
DECLARE salario, percentual, aumento, novoSalario NUMERICO
LEIA salario, percentual
aumento = salario * (percentual / 100)
novoSalario = salario + aumento
ESCREVA aumento
ESCREVA novoSalario
FIM_ALGORITMO.

6. Salário-base com gratificação de 5% e imposto de 7%

ALGORITMO
DECLARE salarioBase, gratificacao, imposto, salarioReceber NUMERICO
LEIA salarioBase
gratificacao = salarioBase * 0.05
imposto = salarioBase * 0.07
salarioReceber = salarioBase + gratificacao - imposto
ESCREVA salarioReceber
FIM_ALGORITMO.

7. Salário-base com gratificação fixa de R$50 e imposto de 10%

ALGORITMO
DECLARE salarioBase, salarioReceber NUMERICO
LEIA salarioBase
salarioReceber = salarioBase + 50 - (salarioBase * 0.10)
ESCREVA salarioReceber
FIM_ALGORITMO.

8. Rendimento de um depósito

ALGORITMO
DECLARE deposito, taxa, rendimento, total NUMERICO
LEIA deposito, taxa
rendimento = deposito * (taxa / 100)
total = deposito + rendimento
ESCREVA rendimento
ESCREVA total
FIM_ALGORITMO.

9. Área do triângulo

ALGORITMO
DECLARE base, altura, area NUMERICO
LEIA base, altura
area = (base * altura) / 2
ESCREVA area
FIM_ALGORITMO.

10. Área do círculo

ALGORITMO
DECLARE raio, area NUMERICO
LEIA raio
area = 3.14159 * raio * raio
ESCREVA area
FIM_ALGORITMO.

11. Quadrado, cubo, raiz quadrada e raiz cúbica

ALGORITMO
DECLARE numero, quadrado, cubo, raizQuad, raizCub NUMERICO
LEIA numero
quadrado = numero ^ 2
cubo = numero ^ 3
raizQuad = numero ^ (1/2)
raizCub = numero ^ (1/3)
ESCREVA quadrado
ESCREVA cubo
ESCREVA raizQuad
ESCREVA raizCub
FIM_ALGORITMO.

12. Um número elevado ao outro

ALGORITMO
DECLARE n1, n2, resultado NUMERICO
LEIA n1, n2
resultado = n1 ^ n2
ESCREVA resultado
FIM_ALGORITMO.

13. Conversão de pés

ALGORITMO
DECLARE pes, polegadas, jardas, milhas NUMERICO
LEIA pes
polegadas = pes * 12
jardas = pes / 3
milhas = jardas / 1760
ESCREVA polegadas
ESCREVA jardas
ESCREVA milhas
FIM_ALGORITMO.

14. Idade da pessoa

ALGORITMO
DECLARE anoNascimento, anoAtual, idade, idade2050 NUMERICO
LEIA anoNascimento, anoAtual
idade = anoAtual - anoNascimento
idade2050 = 2050 - anoNascimento
ESCREVA idade
ESCREVA idade2050
FIM_ALGORITMO.

15. Custo do carro ao consumidor

ALGORITMO
DECLARE precoFabrica, percLucro, percImposto, lucro, imposto, precoFinal NUMERICO
LEIA precoFabrica, percLucro, percImposto
lucro = precoFabrica * (percLucro / 100)
imposto = precoFabrica * (percImposto / 100)
precoFinal = precoFabrica + lucro + imposto
ESCREVA lucro
ESCREVA imposto
ESCREVA precoFinal
FIM_ALGORITMO.

16. Salário por horas trabalhadas

ALGORITMO
DECLARE horas, salarioMinimo, valorHora, salarioBruto, imposto, salarioReceber NUMERICO
LEIA horas, salarioMinimo
valorHora = salarioMinimo / 2
salarioBruto = horas * valorHora
imposto = salarioBruto * 0.03
salarioReceber = salarioBruto - imposto
ESCREVA salarioReceber
FIM_ALGORITMO.

17. Saldo bancário com CPMF sobre saques

ALGORITMO
DECLARE salario, cheque1, cheque2, cpmf1, cpmf2, saldo NUMERICO
LEIA salario, cheque1, cheque2
saldo = salario
cpmf1 = cheque1 * 0.0038
cpmf2 = cheque2 * 0.0038
saldo = saldo - cheque1 - cpmf1 - cheque2 - cpmf2
ESCREVA saldo
FIM_ALGORITMO.

18. Ração restante após 5 dias

ALGORITMO
DECLARE pesoSaco, racaoPorGato, pesoSacoGramas, consumoDiario, consumoTotal, restante NUMERICO
LEIA pesoSaco, racaoPorGato
pesoSacoGramas = pesoSaco * 1000
consumoDiario = racaoPorGato * 2
consumoTotal = consumoDiario * 5
restante = pesoSacoGramas - consumoTotal
ESCREVA restante
FIM_ALGORITMO.
