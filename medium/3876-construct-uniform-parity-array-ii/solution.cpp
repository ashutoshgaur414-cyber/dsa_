                int oppositeMin = (parity == 0) ? minOdd : minEven;

                if (oppositeMin == INT_MAX || nums1[i] <= oppositeMin)
                    return false;

                // We can use nums1[i] - oppositeMin
                // which is positive and odd.
                if (parity == 0)
                    minEven = min(minEven, nums1[i]);
                else
                    minOdd = min(minOdd, nums1[i]);
            }
        }

        return true;
    }
};
