package com.observer.weatherorama.elem.impl;

import com.observer.weatherorama.Observer;
import com.observer.weatherorama.WeatherData;
import com.observer.weatherorama.elem.DisplayElement;

public class StatisticsDisplay implements DisplayElement, Observer {
    private WeatherData weatherData;
    private float maxTemp = 0.0f;
    private float avgTemp = 0.0f;
    private float minTemp = 200.0f;

    public StatisticsDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("Avg/Max/Min temperature = " + avgTemp + "/" + maxTemp + "/" + minTemp);
    }

    @Override
    public void update() {
        float temp = weatherData.getTemperature();
        if (temp > maxTemp) {
            maxTemp = temp;
        }
        if (temp < minTemp) {
            minTemp = temp;
        }
        avgTemp = (maxTemp + minTemp) / 2;
        display();
    }

}
