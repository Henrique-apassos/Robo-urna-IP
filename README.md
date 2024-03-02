# Robo-urna-IP
Projeto com um robô da cadeira de Introdução a Programação de Engenharia da computação do CIn da UFPE

Esse é um projeto que fiz utilizando o CoppeliaSin.
Um simulador que originalmente foi feito para Lua e Python mas consegumos codar em C e C++ com uma comunicação externa.
Ele lê um arquivo .txt e o robô executa os movimentos apertando nos botões na urna.

Serão 2 programas utilizados. O CoppeliaSin e o VS studio (o roxo). É necessário ter as extensões de desenvolvimento em C.

Para funionar, verifique se o robô do .ttt tem o comando:

  function sysCall_int()
    simRemoteApi.start(19999)
  end

  Para executar o código: d
  1 - Digite os botões a serem apertados em voto.txt
  c = Confirma
  b = Branco
  x = Corrige


  2- Inicie a simulação no copellia
  
  3- Compile o código no VS (o roxo)
  O código para rodar é o vrep.sln. Dentro desse arquivo tem um .cpp que é o código que faz o robô se movimentar.
