perm([],[]).
perm(Xs, [Z | Zs]) :- select(Z, Xs, Ys), perm(Ys, Zs).

safe([Qt|Qr]) :- not(attack(Qt, Qr)), safe(Qr).
safe([]).

attack(X, Xs) :- attack_sub(X, 1, Xs).
attack_sub(X, N, [Y|Ys]) :- (X =:= Y + N ; X =:= Y - N).
attack_sub(X, N, [Y|Ys]) :- N1 is N + 1, attack_sub(X, N1, Ys).

queen(Q) :- perm([1,2,3,4,5,6,7,8], Q), safe(Q).

main:-
    queen(Q), write(Q), nl, fail.
