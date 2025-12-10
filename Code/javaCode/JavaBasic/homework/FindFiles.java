import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FindFiles {
    public static void main(String[] args) {
        File filename = new File("D:/LearningCode/Code");
        List all = findAllJava(filename);
        all.forEach(System.out::println);
        System.out.println(all.size());
    }

    public static List findAllJava(File filename) {
        List<File> allJavaFiles = new ArrayList<>();
        File[] files = filename.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    allJavaFiles.addAll(findAllJava(file));
                } else if (file.isFile() && file.getName().endsWith(".java")) {
                    allJavaFiles.add(file);
                }
            }
        }
        return allJavaFiles;
    }
}
