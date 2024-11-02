import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
import java.lang.String;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            String keylog = br.readLine();
            int l = keylog.length();

            LinkedList<Character> kl = new LinkedList<>();
            ListIterator<Character> iter = kl.listIterator();
            for (int j = 0; j < l; j++){
                char c = keylog.charAt(j);
                if (c == '<') {
                    if (iter.hasPrevious())
                        iter.previous();
                } else if (c == '>') {
                    if (iter.hasNext())
                        iter.next();
                } else if (c == '-') {
                    if (iter.hasPrevious()) {
                        iter.previous();
                        iter.remove();
                    }
                } else {
                    iter.add(c);
                }
            }

            StringBuilder sb = new StringBuilder();
            for (char s: kl) {
                sb.append(s);
            }
            System.out.println(sb.toString());
        }
    }
}