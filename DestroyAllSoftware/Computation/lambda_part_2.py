ADD1 = (
    lambda n: (lambda f: lambda x: f(n(f)(x)))
)

ADD = (
    lambda n: lambda m: n(ADD1)(m)
)

MULT = (
    lambda n: lambda m: n(lambda acc: ADD(m)(acc))(ZERO)
)

ZERO = (
    lambda f: lambda x: x
)

ONE = (
    ADD1(ZERO)
)

TWO = (
    ADD1(ADD1(ZERO))
)

THREE = (
    # lambda f: lambda x: f(f(f(x))) -- this pattern continues for higher numbers
    ADD1(ADD1(ADD1(ZERO)))
)

SIX = (
    ADD1(ADD1(ADD1(ADD1(ADD1(ADD1(ZERO))))))
)


print(
    MULT(
        TWO
    )(
        THREE
    )
    (lambda x: x + 1)(0)
)