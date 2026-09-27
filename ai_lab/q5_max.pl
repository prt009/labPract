gomax:-
  write('enter the first number: '),read(X),
  write('enter the second number: '),read(Y),
  maxm(X,Y,M),
  write('the largest number is: '),write(M).

maxm(X,Y,M):-
  M is X, X>Y,!;M is Y, Y>X.
