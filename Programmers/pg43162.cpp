import java.util.*;
import java.io.*;

class Solution {
    static boolean visited[];
    static int g_cnt = 0;
    
    void bfs(int c, int n, int[][] com) {
        g_cnt++; // 네트워크 수 증가
        Queue <Integer> q = new ArrayDeque<>();
        q.offer(c);
        visited[c] = true;
        int cur, next;
        while(!q.isEmpty()) {
            cur = q.poll();
            for(int i=0; i<n; ++i) {
                if(!visited[i] && com[cur][i] == 1) { // 연결 되어있음
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        for(int i=0; i<n; i++) {
            if(visited[i] == false) {
                bfs(i, n, computers);
            }
        }
        answer = g_cnt;
        return answer;
    }
}
