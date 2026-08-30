%maxm(X,Y,M):-
%  M is X, X>Y;M is Y, Y>X.

% If X is greater than or equal to Y, X is the maximum
max(X, Y, X) :- X >= Y.

% Otherwise, Y is the maximum
max(X, Y, Y) :- X < Y.   
