import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String start, end, tmp;
        int s_hour, s_min, e_hour, e_min, res = 0;
        for(int i=0; i<5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            start = st.nextToken();
            String[] ary = start.split(":");
            s_hour = Integer.parseInt(ary[0]);
            s_min = Integer.parseInt(ary[1]);
            end = st.nextToken();
            String[] ary2 = end.split(":");
            e_hour = Integer.parseInt(ary2[0]);
            e_min = Integer.parseInt(ary2[1]);

            res += ((e_hour*60+e_min) - (s_hour*60+s_min));
        }
        System.out.println(res);
    }
}
