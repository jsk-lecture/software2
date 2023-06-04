map([A,B,C,D,E,F], Colors) :-
    next(A,B, Colors), next(A,C, Colors), next(A,D, Colors),
    next(B,C, Colors), next(C,D, Colors), next(E,F, Colors),
    next(B,E, Colors), next(C,E, Colors), next(C,F, Colors).

next(X, Y, Colors) :- %% two adjacent regions are colored differently
    member(X, Colors),
    member(Y, Colors),
    not(X == Y).

main1:-
    write('map(Solution, [red, blue]) ->'),nl,
    map(Solution, [red, blue]),write(Solution),nl,fail.

main2:-
    write('map(Solution, [red, blue, green]) ->'),nl,
    map(Solution, [red, blue, green]),write(Solution),nl,fail.

main:-
    main1; main2.
