ADDER = {
    # operation definition
    ("B", "s1"): ("(", "R", "s2"),
    ("B", "s2"): ("1", "R", "s3"),
    ("B", "s3"): ("1", "R", "s4"),
    ("B", "s4"): ("+", "R", "s5"),
    ("B", "s5"): ("1", "R", "s6"),
    ("B", "s6"): ("1", "R", "s7"),
    ("B", "s7"): ("1", "R", "s7b"),
    ("B", "s7b"): ("1", "R", "s8"),
    ("B", "s8"): (")", "R", "s9"),
    # move back to remove plus, replace plus with 1
    ("B", "s9"): ("B", "L", "s9"),
    (")", "s9"): (")", "L", "s9"),
    ("1", "s9"): ("1", "L", "s9"),
    ("+", "s9"): ("1", "R", "s10"),
    # move forward and set last bracket to blank, tehn back one and set bracket in place of last 1
    ("1", "s10"): ("1", "R", "s10"),
    (")", "s10"): ("B", "L", "s11"),
    ("1", "s11"): (")", "R", "s12"),
    # move forward and keep blanks, to avoid crash
    ("B", "s12"): ("B", "R", "s12"),
}


def simulate(instructions):
    tape = ["B"] * 16  # tape where data is stored
    head = 0  # current head/index position
    state = "s1"  # current state, should generally not be hardcoded

    # eight iterations, in a general machine you would want to make this infinite
    for _ in range(24):
        print(state.rjust(4) + ": " + "".join(tape))
        print("     " + " " * head + " ^")

        # apply tuple unpacking to retrieve the values required from the state
        # set the symbol at the current head of the tape equal to the symbol from the tuple
        # set the state to the new state
        tape[head], head_direction, state = instructions[(tape[head], state)]

        # add one to the head if the direction is right, otherwise move back one position (L)
        head += 1 if head_direction == "R" else -1


simulate(ADDER)
