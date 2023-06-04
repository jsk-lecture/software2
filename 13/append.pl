my_append([], Xs, Xs).
my_append([X | Ls], Ys, [X | Zs]) :- my_append(Ls, Ys, Zs).

main1:-
    write('my_append([a,b,c],[d,e,f],Z) -> '),nl,
    my_append([a,b,c],[d,e,f],Z),write(Z),nl,fail.

main2:-
    write('my_append(X,[c,d],[a,b,c,d]) -> '),nl,
    my_append(X,[c,d],[a,b,c,d]),write(X),nl,fail.

main3:-
    write('my_append(X,Y,[a,b,c,d]) -> '),nl,
    my_append(X,Y,[a,b,c,d]),write(X),write(' '),write(Y),nl,fail.

main:-
    main1;main2;main3.
