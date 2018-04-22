# one...
ONE = 1


def IS_ZERO(x): return x == 0  # IS_ZERO = lambda x: x == 0


def SUB1(x): return x - 1  # SUB1 = lambda x: x - 1


def MULT(x): return lambda y: x * y  # MULT = lambda x: lambda y: x * y


# IF = lambda cond: lambda t_func: lambda f_func: t_func(None) if cond else f_func(None)
def IF(cond): return lambda t_func: lambda f_func: t_func(
    None) if cond else f_func(None)


# lambda myself: (
#     lambda n: (
#         IF(
#             IS_ZERO(n)
#         )(
#             lambda _: ONE
#         )(
#             lambda _: MULT(n)(myself(myself)(SUB1(n)))
#         )
#     )
# )


print(
    (
        lambda myself: (
            lambda n: (
                IF(
                    IS_ZERO(n)
                )(
                    lambda _: ONE
                )(
                    lambda _: MULT(n)(myself(myself)(SUB1(n)))
                )
            )
        )
    )(
        lambda myself: (
            lambda n: (
                IF(
                    IS_ZERO(n)
                )(
                    lambda _: ONE
                )(
                    lambda _: MULT(n)(myself(myself)(SUB1(n)))
                )
            )
        )
    )(
        6
    )
)
