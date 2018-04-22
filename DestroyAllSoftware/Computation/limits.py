# HALTING PROBLEM - https://en.wikipedia.org/wiki/Halting_problem

# this function is impossible to write


def halts(f):
    pass


def looper():
    while True:
        pass


def impossible():
    return halts(impossible) and looper()

# assume impposible halts
#   => impossible does not halt
# assume impossible does not halt
#   => impossible does halt


# ---------------------------------------------------------------------------

# COMPILERS

def f():
    return 1 + 2 + 3  # always six - optimisation f() => 6

# impossible to determine


def returns_constant(f):
    pass


def halts(f):
    def inner():
        f()
        return 0
    return returns_constant(inner)

# ---------------------------------------------------------------------------

# REFACTORING


def functions_are_equiv(f, g):
    pass


def halts(f):
    def inner():
        f()
        return 0

    def inner2():
        return 0
    return functions_are_equiv(inner, inner2)

# ---------------------------------------------------------------------------

# IDRIS (totality checker)


total def f():  # total - never go into infinite loop (totality check - only in idris)
    pass

# idris implementation does not solve the halting problem


def conservative_halts(f):
    pass
