import java.io.*;
import java.util.*;

public class 빈도정렬 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int COUNT = Integer.parseInt(st.nextToken());
        Map<Integer, FreNumber> numbers = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int now = Integer.parseInt(st.nextToken());
            FreNumber nowFreNumber = numbers.getOrDefault(now, new FreNumber(i, now));
            nowFreNumber.plusFre();
            numbers.put(now, nowFreNumber);
        }

        List<FreNumber> answer = new ArrayList<>(numbers.values());
        Collections.sort(answer);

        for (FreNumber f : answer) {
            for (int i = 0; i < f.fre; i++) {
                System.out.print(f.number + " ");
            }
        }
    }

    static private class FreNumber implements Comparable<FreNumber> {
        int number;
        int index;
        int fre = 0;

        public FreNumber(int index, int number) {
            this.index = index;
            this.number = number;
        }

        public void plusFre() {
            fre++;
        }

        @Override
        public int compareTo(FreNumber op) {
            if (this.fre == op.fre) {
                return Integer.compare(this.index, op.index);
            }
            return Integer.compare(op.fre, this.fre);
        }
    }
}
