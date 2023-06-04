a=10

foo() {
    local a=100
    printf "foo: a = $a\n"
    bar
}

bar() {
    printf "bar: a = $a\n"
}

foo
printf "global: a = $a\n"

