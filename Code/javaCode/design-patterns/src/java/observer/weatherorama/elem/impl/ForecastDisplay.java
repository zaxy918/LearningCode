package observer.weatherorama.elem.impl;

import observer.weatherorama.Observer;
import observer.weatherorama.WeatherData;
import observer.weatherorama.elem.DisplayElement;

public class ForecastDisplay implements DisplayElement, Observer {
    private WeatherData weatherData;
    private float lastPressure;
    private float currentPressure = 29.92f;

    public ForecastDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.print("Forecast: ");
        if (currentPressure > lastPressure) {
            System.out.println("Improving weather on the way!");
        } else if (currentPressure == lastPressure) {
            System.out.println("More of the same");
        } else if (currentPressure < lastPressure) {
            System.out.println("Watch out for cooler, rainy weather");
        }
    }

    @Override
    public void update() {
        this.lastPressure = this.currentPressure;
        this.currentPressure = weatherData.getPressure();
        display();
    }

}
