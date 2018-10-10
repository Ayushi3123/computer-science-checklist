from random import choice


class RandomWalk:
    """A class the will generate a random walk"""

    def __init__(self, num_points=5000):
        """Init the random walk"""

        self.num_points = num_points

        self.x_values = [0]
        self.y_values = [0]

    @staticmethod
    def direction_choice():
        """Returns a direction choice"""
        return choice([1, -1])

    @staticmethod
    def distance_choice():
        """Returns a distance choice"""
        return choice([0, 1, 2, 3, 4])

    def step(self):
        """Returns step based on direction and distance choices"""
        return self.direction_choice() * self.distance_choice()

    def fill_walk(self):
        """Calculate the points of the walk"""
        while len(self.x_values) < self.num_points:
            x_step = self.step()
            y_step = self.step()

            if x_step == 0 and y_step == 0:
                continue

            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            self.x_values.append(next_x)
            self.y_values.append(next_y)
