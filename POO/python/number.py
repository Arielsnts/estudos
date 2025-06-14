class Number:
    def __init__(self, limit):
        self.limit = limit
        self.value = 0

    def get_value(self):
        return self.value

    def set_value(self, new_value):
        self.value = new_value

    def get_display_value(self):
        if self.value < 10:
            return f"0{self.value}"
        else:
            return str(self.value)

    def increment(self):
        self.value = (self.value + 1) % self.limit
