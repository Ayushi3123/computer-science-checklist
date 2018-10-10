from random import randint


class Die:
    """Class that represents a die"""

    def __init__(self, num_sides=6):
        """Init a die, with 6 sides by default"""
        self.num_sides = num_sides

    def roll(self):
        """Return a random number between one and the number of sides"""
        return randint(1, self.num_sides)
