package exercicios;

public class Number {
	private int limit;
	private int value;
	
	public Number(int limit) {
		this.limit = limit;
		this.value = 0;
	}
	
	public int getValue() {
		return this.value;
	}
	
	public void setValue(int newValue) {
		this.value = newValue;
	}
	
	public String getDisplayValue() {
		if (this.value < 10) {
			return "0" + this.value;
		}
		else {
			return String.valueOf(this.value);
		}
	}
	
	public void increment() {
		this.value = (this.value + 1) % this.limit;
	}
}
