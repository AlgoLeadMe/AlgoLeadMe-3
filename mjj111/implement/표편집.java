import java.util.*;

class 표편집 {
    public String solution(int n, int k, String[] cmd) {
        Stack<Integer> cancels = new Stack<>();
        int now = k;
        int totalRows = n;

        for (String c : cmd) {
            if (c.charAt(0) == 'U') {
                int value = Integer.parseInt(c.split(" ")[1]);
                now -= value;
                continue;
            }
            if (c.charAt(0) == 'D') {
                int value = Integer.parseInt(c.split(" ")[1]);
                now += value;
                continue;
            }
            if (c.charAt(0) == 'C') {
                cancels.push(now);
                totalRows--;
                if (now == totalRows) now--;
                continue;
            }
            if (c.charAt(0) == 'Z') {
                int cancelledRow = cancels.pop();
                if (cancelledRow <= now) now++;
                totalRows++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < totalRows; i++) {
            sb.append("O");
        }

        while (!cancels.isEmpty()) {
            sb.insert(cancels.pop().intValue(), "X");
        }

        return sb.toString();
    }
}
