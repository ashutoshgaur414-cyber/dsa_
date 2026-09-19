class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest point of the rectangle to the circle's center
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));

        // Distance from circle center to closest point
        int dx = x - xCenter;
        int dy = y - yCenter;

        return dx * dx + dy * dy <= radius * radius;
    }
};