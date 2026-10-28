color(red).
color(blue).
color(green).

not_red(X) :-
    color(X),
    X = red,
    !.
    %fail.

%not_red(X) :-
%    color(X),
%    X \= red.