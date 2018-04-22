X_B = {
    ("B", "s1"): ("X", "R", "s2"),
    ("B", "s2"): ("B", "L", "s3"),
    ("X", "s3"): ("B", "R", "s4"),
    ("B", "s4"): ("B", "L", "s1"),
}


def simulate(instructions):
    tape = ["B", "B"]  # tape where data is stored
    head = 0  # current head/index position
    state = "s1"  # current state, should generally not be hardcoded

    # eight iterations, in a general machine you would want to make this infinite
    for _ in range(8):
        print(state.rjust(4) + ": " + "".join(tape))
        print("     " + " " * head + " ^")

        # apply tuple unpacking to retrieve the values required from the state
        # set the symbol at the current head of the tape equal to the symbol from the tuple
        # set the state to the new state
        tape[head], head_direction, state = instructions[(tape[head], state)]

        # add one to the head if the direction is right, otherwise move back one position (L)
        head += 1 if head_direction == "R" else -1


simulate(X_B)
