fly(X) :- airplane(X).
fly(X) :- superman(X).
airplane(jet_plane).
airplane(helicopter).
superman(taro).

main1:-
    write('fly(jet_plane) -> '),nl,
    fly(jet_plane),!, write('true'),nl; write('false'),nl.

main2:-
    write('fly(taro) -> '),nl,
    fly(taro),!, write('true'),nl; write('false'),nl.

main3:-
    write('fly(Y) -> '),nl,
    fly(Y),write(Y),nl,fail.

main:-
    main1,main2,main3.
