maxm(X,Y,M):-
  M is X, X>Y,!;M is Y, Y>X.
