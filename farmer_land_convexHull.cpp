#define X first
#define Y second

using Point = pair<int,int>;


Point pivot;


int orientation(Point a, Point b, Point c) {
    int area = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    if (area >= 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int distance(Point a, Point b)  {
    int dx = a.X - b.X, dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = orientation(pivot, a, b);
    if (order == 0)
        return distance(pivot, a) < distance(pivot, b);
    return (order == -1);
}

stack<Point> grahamScan(Point *points, int N)    {
    stack<Point> hull;

    if (N < 3)
        return hull;

    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    pivot = points[0];

    
    sort(points + 1, points + N, POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        
        while (orientation(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}
