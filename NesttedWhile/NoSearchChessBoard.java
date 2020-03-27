System.out.println((int) distance(ENDx - STARTx, ENDy - STARTy));    
public static double distance(int x, int y) {
        // axes symmetry
        x = Math.abs(x);
        y = Math.abs(y);
        // diagonal symmetry
        if (x < y) {
            int t = x;
            x = y;
            y = t;
        }
        // 2 corner cases
        if (x == 1 && y == 0) {
            return 3;
        }
        if (x == 2 && y == 2) {
            return 4;
        }

        // main formula
        int delta = x - y;
        if (y > delta) {
            return (delta - 2 * Math.floor((float) (delta - y) / 3));
        } else {
            return (delta - 2 * Math.floor((delta - y) / 4));
        }
    }