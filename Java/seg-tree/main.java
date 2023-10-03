import java.util.Scanner;

public class SegmentTree {
    static int[] tree;
    static int[] extra;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        tree = new int[4 * n];
        extra = new int[4 * n];

        buildTree(1, 1, n, scanner);

        while (q-- > 0) {
            int op = scanner.nextInt();
            int l = scanner.nextInt();
            int r = scanner.nextInt();

            if (op == 1) {
                int k = scanner.nextInt();
                update(1, 1, n, l, r, k);
            } else {
                int result = query(1, 1, n, l, r, 0);
                System.out.println(result);
            }
        }
    }

    static int buildTree(int ind, int L, int R, Scanner scanner) {
        if (L == R) {
            tree[ind] = scanner.nextInt();
            return tree[ind];
        }
        int mid = (L + R) / 2;
        tree[ind] = buildTree(2 * ind, L, mid, scanner) + buildTree(2 * ind + 1, mid + 1, R, scanner);
        return tree[ind];
    }

    static int query(int ind, int L, int R, int l, int r, int ex) {
        if (l == L && r == R) {
            return tree[ind] + (ex + extra[ind]) * (R - L + 1);
        }
        int mid = (L + R) / 2;
        if (r <= mid) {
            return query(2 * ind, L, mid, l, r, ex + extra[ind]);
        } else if (l > mid) {
            return query(2 * ind + 1, mid + 1, R, l, r, ex + extra[ind]);
        } else {
            return query(2 * ind, L, mid, l, mid, ex + extra[ind])
                    + query(2 * ind + 1, mid + 1, R, mid + 1, r, ex + extra[ind]);
        }
    }

    static void update(int ind, int L, int R, int l, int r, int val) {
        if (l == L && r == R) {
            extra[ind] += val;
            return;
        }
        tree[ind] += val * (r - l + 1);
        int mid = (L + R) / 2;
        if (r <= mid) {
            update(2 * ind, L, mid, l, r, val);
        } else if (l > mid) {
            update(2 * ind + 1, mid + 1, R, l, r, val);
        } else {
            update(2 * ind, L, mid, l, mid, val);
            update(2 * ind + 1, mid + 1, R, mid + 1, r, val);
        }
    }
}
