

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T=scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n=scanner.nextInt();
            int S =scanner.nextInt();
            int []v=new int[n];
            int vTimesMin[]=new int[S+1];
            int vTimesMax[]=new int[S+1];

            for (int i = 0; i < n; i++) {
                v[i]=scanner.nextInt();
            }

            vTimesMin[0]=0;
            vTimesMax[0]=0;
            for (int i = 1; i < vTimesMin.length; i++) {
                int min=10001,flag=0,max=0;
                for (int j = 0; j < v.length; j++) {
                    if (v[j] <= i){
                        if(vTimesMin[i-v[j]]!=-1){//判断面值能否刚好
                            min=Math.min(min,vTimesMin[i-v[j]]+1);
                            max=Math.max(max,vTimesMax[i-v[j]]+1);
                            flag=1;
                        }
                    }
                }
                if (flag==0){
                    vTimesMin[i]=-1;
                    vTimesMax[i]=-1;
                }else {
                    vTimesMin[i] = min;
                    vTimesMax[i] = max;
                }
            }
            System.out.println(vTimesMin[S] + " " + vTimesMax[S]);
        }
    }
}
