package exercicios;

public class ClockDisplay {
	private Number hour = new Number(24);
	private Number minute = new Number(60);
	private Number second = new Number(60);
	private String displayString = "";
	
	private void updateDisplay() {
		this.displayString = this.hour.getDisplayValue()
				+":"+this.minute.getDisplayValue()
				+":"+this.second.getDisplayValue();
	}
	
	public void setTime(int hour, int minute, int second) {
		this.hour.setValue(hour);
		this.minute.setValue(minute);
		this.second.setValue(second);
		updateDisplay();
	}
	
	public String getTime() {
		return this.displayString;
	}
	
	public void timeTick() {
		this.second.increment();
		updateDisplay();
		if (this.second.getValue() == 0) {
			this.minute.increment();
			updateDisplay();
			if (this.minute.getValue() == 0) {
				this.hour.increment();
				updateDisplay();
			}
		}
	}
}
