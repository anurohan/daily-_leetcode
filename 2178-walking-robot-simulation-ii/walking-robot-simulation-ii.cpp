class Robot {
public:
    int w, h;
    int pos = 0;
    bool moved = false;
    int perimeter;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        if (pos <= w - 1) 
            return {pos, 0}; // Bottom
        if (pos <= w + h - 2) 
            return {w - 1, pos - (w - 1)}; // Right
        if (pos <= 2 * w + h - 3) 
            // Top: moving from right to left
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        // Left: moving from top to bottom
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }
    
    string getDir() {
        // Special case for (0,0)
        if (pos == 0) {
            return moved ? "South" : "East";
        }
        
        // Use strict boundaries to determine direction
        if (pos <= w - 1) return "East";
        if (pos <= w + h - 2) return "North";
        if (pos <= 2 * w + h - 3) return "West";
        return "South";
    }
};