package observer.weatherorama.elem.impl;

import observer.weatherorama.Observer;
import observer.weatherorama.WeatherData;
import observer.weatherorama.elem.DisplayElement;

public class HeatIndexDisplay implements DisplayElement, Observer {
    private WeatherData weatherData;
    private float T;
    private float RH;
    private float heatIndex = 0.0f;

    public HeatIndexDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("Heat index is " + heatIndex);
    }

    @Override
    public void update() {
        this.T = weatherData.getTemperature();
        this.RH = weatherData.getHumidity();
        heatIndex = (float) ((16.923 + (0.185212 * T) + (5.37941 * RH) - (0.100254 * T * RH) + (0.00941695 * (T * T)) + (0.00728898 * (RH * RH)) + (0.000345372 * (T * T * RH)) - (0.000814971 * (T * RH * RH)) + (0.0000102102 * (T * T * RH * RH)) - (0.000038646 * (T * T * T)) + (0.0000291583 * (RH * RH * RH)) + (0.00000142721 * (T * T * T * RH)) + (0.000000197483 * (T * RH * RH * RH)) - (0.0000000218429 * (T * T * T * RH * RH)) + 0.000000000843296 * (T * T * RH * RH * RH)) - (0.0000000000481975 * (T * T * T * RH * RH * RH)));
        display();
    }

}
