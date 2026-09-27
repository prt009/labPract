gosum:-
  write('Enter the first number: '),read(X),
  write('Enter the second number: '),read(Y),
  write('the sum is: '),
  summ(X,Y).


summ(X,Y):-
  W is X + Y,
  write(W).
