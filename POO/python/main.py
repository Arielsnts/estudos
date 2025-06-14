from clockDisplay import ClockDisplay
from time import sleep

class Main:
    relogio = ClockDisplay()
    relogio.set_time(0, 0, 0)

    while True:
        relogio.time_tick()
        print(f"\r{relogio.get_time()}", end="", flush=True)
        sleep(0.1)