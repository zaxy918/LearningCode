import java.io.BufferedReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

public class AnimalUtil {
    private List<Animal> animals = new ArrayList<>();

    public void addAnimal(Animal animal) {
        animals.forEach(a -> {
            if (a.getId().equals(animal.getId())) {
                throw new DumplicateAnimalException("DumplicateAnimalException");
            }
        });
        animals.add(animal);
    }

    public void showAll() {
        animals.forEach(Animal::showInfo);
    }

    public void loadAnimalFromFile(String filename) {
        try (BufferedReader br = new BufferedReader(new Reader(filename))) {
            //Format like id,name,type,age,health
            String line;
            while (line = br.readLine()) {
                String[] info = line.split(",");
                String type = info[2];
                if ("Cat".equals(type)) {

                } else if ("Dog".equals(type)) {

                } else {

                }
            }
        } catch (Exception e) {
        }
    }
}
