import math


class Star:
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y

    def rotate(self, rotate_angle):
        x = self.x * math.cos(rotate_angle) - self.y * math.sin(rotate_angle)
        y = self.x * math.sin(rotate_angle) + self.y * math.cos(rotate_angle)
        self.x = round(x)
        self.y = round(y)


class Stars:
    def __init__(self):
        self.stars = []

    def add_star(self, name, x, y):
        new_star = Star(name, x, y)
        self.stars.append(new_star)

    def rotate(self, rotate_angle):
        for star in self.stars:
            star.rotate(rotate_angle)

    def sort(self):
        self.stars.sort(key=lambda star: (star.y, star.x))

    def save_to_file(self, file_name):
        with open(file_name, 'w') as file:
            for star in self.stars:
                file.write(star.name + ' ')


def main():
    with open('input.txt', 'r') as file:
        n, rotate_angle = map(int, file.readline().split())

        stars_collection = Stars()

        for _ in range(n):
            name, x, y = file.readline().split()
            stars_collection.add_star(name, int(x), int(y))

        stars_collection.rotate(math.radians(rotate_angle))
        stars_collection.sort()
        stars_collection.save_to_file('output.txt')


if __name__ == "__main__":
    main()
