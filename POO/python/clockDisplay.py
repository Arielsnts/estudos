from number import Number

class ClockDisplay:
    def __init__(self):
        self.hour = Number(24)
        self.minute = Number(60)
        self.second = Number(10)
        self.display_string = ""
        self.update_display()

    def update_display(self):
        self.display_string = (
            self.hour.get_display_value() + ":" +
            self.minute.get_display_value() + ":" +
            self.second.get_display_value()
        )

    def set_time(self, hour, minute, second):
        self.hour.set_value(hour)
        self.minute.set_value(minute)
        self.second.set_value(second)
        self.update_display()

    def get_time(self):
        return self.display_string

    def time_tick(self):
        self.second.increment()
        self.update_display()
        if self.second.get_value() == 0:
            self.minute.increment()
            self.update_display()
            if self.minute.get_value() == 0:
                self.hour.increment()
                self.update_display()
