gofac:-
  write('enter the number: '),read(N),
  fact(N,F),
  write('the factorial is: '),write(F).
  

fact(0,1).
fact(N,F):-
  N>0,
  N1 is N-1,
  fact(N1,F1),
  F is F1*N.
