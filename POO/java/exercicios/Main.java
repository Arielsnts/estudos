package exercicios;

public class Main {
	public static void main(String[] args) throws InterruptedException {
		ClockDisplay relogio = new ClockDisplay();
		
		relogio.setTime(0, 59, 55);
		
		while (true) {
			relogio.timeTick();
			System.out.printf("\r%-10s", relogio.getTime());
			Thread.sleep(1000);
		}
	}
}
