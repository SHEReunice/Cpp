package D2021_04_16;

/*Knapsack problem 动态规划*/
public class NO1 {
    /*Knapsack with repetition*/
    public static class KnapsackRep {
        private int[] valueKnapsack;
        private int[] value;
        private int[] size;
        public void printAllVal(){
            for (int i : valueKnapsack) {
                System.out.print(i+" ");
            }
        }
        public int getValKnapsack(int bagSize){
            valueKnapsack=new int[bagSize+1];
            valueKnapsack[0]=0;
            for (int i = 1; i <= bagSize; i++) {
                int max=0;
                for (int j = 0; j < size.length; j++) {
                    if (size[j]<=i){
                        max=Math.max(max,value[j]+valueKnapsack[i-size[j]]);
                    }
                }
                valueKnapsack[i]=max;
            }
            return valueKnapsack[bagSize];
        }
        KnapsackRep(int[]size,int []value){
            this.size=size;
            this.value=value;
        }
    }

    /*Knapsack without repetition*/
    public static class Knapsack01{
        private int []size,value;
        private int [][]valueKnapsack;
        Knapsack01(int [] size,int[] value){
            this.size=size;
            this.value=value;
        }
        public void printAllVal(){
            for (int[] ints : valueKnapsack) {
                for (int anInt : ints) {
                    System.out.print(anInt+"\t");
                }
                System.out.println("");
            }
        }
        public int getValKnapsack(int bagSize){
            valueKnapsack=new int[size.length][bagSize+1];
            for (int i = 0; i < valueKnapsack.length; i++) {
                valueKnapsack[i][0]=0;
            }
            for (int i = 0; i < bagSize+1; i++) {
                valueKnapsack[0][i]=0;
            }
            for (int i = 1; i < valueKnapsack.length; i++) {
                for (int j = 1; j < valueKnapsack[i].length; j++) {
                    if(size[i]>j)valueKnapsack[i][j]=valueKnapsack[i][j-1];
                    else valueKnapsack[i][j]=Math.max(valueKnapsack[i-1][j-size[i]]+value[i],valueKnapsack[i-1][j]);
                }
            }
            return valueKnapsack[valueKnapsack.length-1][bagSize];
        }
    }

    public static void main(String[] args) {
        int []value={2,4,7},size={2,3,5};
        KnapsackRep knapsackRep = new KnapsackRep(size, value);
        System.out.println(knapsackRep.getValKnapsack(22));
        knapsackRep.printAllVal();

        int []size01={0,2,3,5},value01={0,2,4,7};
        Knapsack01 knapsack01 = new Knapsack01(size01, value01);
        System.out.println(knapsack01.getValKnapsack(10));
        knapsack01.printAllVal();
    }
}
