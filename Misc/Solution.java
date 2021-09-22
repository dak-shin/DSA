import java.util.*;

public class Solution {
	public static void main(String[] args) {
		int result = solution();
		System.out.println(result);
	}
	public static int solution() {
		int[][] grid = new int[10][10];
		int[] target = {6, 7};
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				grid[i][j] = Integer.MAX_VALUE;
			}
		}
		Deque<Integer[]> q = new ArrayDeque<>();
		int a = 4;
		int b = 4;
		int k = 5;
		grid[a][b] = 0;
		q.addLast(new Integer[] {a, b});
		while (!q.isEmpty()) {
			// System.out.println(q);
			Integer[] coord = q.removeFirst();
			System.out.println("Coordinates: " + coord[0] + ", " + coord[1]);
			display(grid);
			System.out.println();
			findNei(coord[0], coord[1], k, grid, q);
		}
		return grid[target[0]][target[1]] == Integer.MAX_VALUE ? -1 : grid[target[0]][target[1]];
	}
	public static void findNei(int a, int b, int k, int[][] grid, Deque<Integer[]> q) {
		for (int i = -k; i <= k ; i++) {
			for (int j = -k; j <= k; j++) {
				if (isValid(a, b, i, j, k)) {
					int newval = grid[a][b] + 1;
					if (grid[a + i][b + j] > newval) {
						grid[a + i][b + j] = newval;
						q.addLast(new Integer[] {a + i, b + j});
					}
				}
			}
		}
	}
	public static boolean isValid(int a, int b, int i, int j, int k) {
		boolean flag = a + i < 10 && b + j < 10;
		boolean flag2 = a + i >= 0 && b + j >= 0;
		return flag && flag2 && (Math.abs(i) + Math.abs(j) == k);
	}
	public static void display(int[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				System.out.printf("%13d ", grid[i][j]);
			}
			System.out.println();
		}
	}
}