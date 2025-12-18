package decorator.starbuzz.condiments;

import java.util.HashMap;
import java.util.Map;

import decorator.starbuzz.Beverage;

public class CondimentPrettyPrint extends CondimentDecorator {

    public CondimentPrettyPrint(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        String desc = beverage.getDescription();
        String[] parts = desc.split(", ");
        Map<String, Integer> counts = new HashMap<>();
        for (String part : parts) {
            counts.put(part, counts.getOrDefault(part, 0) + 1);
        }
        StringBuilder prettyDesc = new StringBuilder();
        for (Map.Entry<String, Integer> entry : counts.entrySet()) {
            if (entry.getValue() == 2) {
                prettyDesc.append("Double ");
            } else if (entry.getValue() == 3) {
                prettyDesc.append("Triple ");
            } else if (entry.getValue() > 3) {
                prettyDesc.append(entry.getValue()).append(" ");
            }
            prettyDesc.append(entry.getKey());
            prettyDesc.append(", ");
        }
        return prettyDesc.substring(0, prettyDesc.length() - 2);
    }

    @Override
    public double cost() {
        return beverage.cost();
    }

}
