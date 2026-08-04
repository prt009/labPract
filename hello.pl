wife(keeran, amir).
wife(gauri, amir).
parent(gauri, junaid).

stepmom(M,C):-
  wife(M,K),
  wife(X,K),
  parent(X,C).
