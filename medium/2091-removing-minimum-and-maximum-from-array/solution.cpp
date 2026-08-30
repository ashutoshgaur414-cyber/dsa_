        int fromFront = j + 1;
        // Option 2: remove both from back
        int fromBack = n - i;
        // Option 3: remove one from front (up to i), one from back (from j)
        int mixed = (i + 1) + (n - j);
        
        return min({fromFront, fromBack, mixed});
    }
};
