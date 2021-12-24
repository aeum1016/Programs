package HackerRank;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'matrixRotation' function below.
     *
     * The function accepts following parameters:
     *  1. 2D_INTEGER_ARRAY matrix
     *  2. INTEGER r
     */

    public static void matrixRotation(List<List<Integer>> matrix, int r) {
        // Write your code here

        int[][] newMatrix = new int[matrix.size()][matrix.get(0).size()];

        for(int layer = 0; layer < matrix.size()/2 && layer < matrix.get(0).size()/2; layer++){

            int startRow = layer, startCol = layer;
            // System.out.println(layer);

            for(int i = 0;
                i < 2*(matrix.size()-(2*layer)) + 2*(matrix.get(0).size()-(2*(layer+1)));
                i++) {
                int curRow = translateOther(startRow, startCol, layer, i, matrix)[0];
                int curCol = translateOther(startRow, startCol, layer, i, matrix)[1];
                int[] newPos = translate(curRow, curCol, layer, r, matrix);
                // System.out.printf("curRow:%d curCol:%d newPos:%d,%d\n", curRow, curCol, newPos[0], newPos[1]);
                try {
                    newMatrix[newPos[0]][newPos[1]] = matrix.get(curRow).get(curCol);
                }
                catch(Exception e){
                    System.out.println(curRow + " " + curCol);
                }
            }
        }
        for(int i = 0; i < newMatrix.length; i++){
            for(int j = 0; j < newMatrix[0].length; j++){
                System.out.print(newMatrix[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static int[] translate(int curRow, int curCol, int layer, int translates, List<List<Integer>> matrix){
        translates = translates % (2*(matrix.size()-(2*layer)) + 2*(matrix.get(0).size()-(2*(layer+1))));
        while(translates > 0){
//            System.out.println(translates + " " + layer);
            if(curCol == layer && curRow != matrix.size() - layer - 1){
                curRow++;
            }
            else if(curRow == matrix.size() - layer - 1
                    && curCol != matrix.get(0).size() - layer - 1){
                curCol++;
            }
            else if(curCol == matrix.get(0).size() - layer - 1 && curRow != layer){
                curRow--;
            }
            else{
                curCol--;
            }
//            System.out.printf("CurCol: %d, CurRow: %d\n", curCol, curRow);
            translates--;
        }
        System.out.println();
        return new int[] {curRow, curCol};
    }
    public static int[] translateOther(int curRow, int curCol, int layer, int translates, List<List<Integer>> matrix){
        translates = translates % (2*(matrix.size()-(2*layer)) + 2*(matrix.get(0).size()-(2*(layer+1))));
        while(translates > 0){
            if(curCol == layer && curRow != matrix.size() - layer - 1){
                curRow++;
            }
            else if(curRow == matrix.size() - layer - 1
                    && curCol != matrix.get(0).size() - layer - 1){
                curCol++;
            }
            else if(curCol == matrix.get(0).size() - layer - 1 && curRow != layer){
                curRow--;
            }
            else{
                curCol--;
            }
            translates--;
        }
        return new int[] {curRow, curCol};
    }

}



public class MatrixLayerRotation {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int m = Integer.parseInt(firstMultipleInput[0]);

        int n = Integer.parseInt(firstMultipleInput[1]);

        int r = Integer.parseInt(firstMultipleInput[2]);

        List<List<Integer>> matrix = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            String[] matrixRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> matrixRowItems = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                int matrixItem = Integer.parseInt(matrixRowTempItems[j]);
                matrixRowItems.add(matrixItem);
            }

            matrix.add(matrixRowItems);
        }

        Result.matrixRotation(matrix, r);

        bufferedReader.close();
    }
}

