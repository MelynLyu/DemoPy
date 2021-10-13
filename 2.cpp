#include <bits./stdc++.h>

using namespace std;

class Node {
public:
    int x;
    int y;
    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    int cnt;
    cin >> cnt;

    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    vector<vector<bool>> obstacle(m, vector<bool>(n, false));
    int obX, obY;

    for(int i = 0; i < cnt; ++i) {
        cin >> obX >> obY;
        obstacle[obX][obY] = true;
    }

    int pahtCnt = 0;
    int len = 0;
    queue<Node> q, secondQ;
    Node start = Node(startX, startY);
    q.push(start);

    while(!q.empty()) {
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            isVisited[node.x][node.y] = true;
            if(node.x == endX && node.y == endY) {
                pahtCnt += 1;
                continue;
            }

            if(node.x - 1 >= 0 && !isVisited[node.x-1][node.y] && !obstacle[node.x-1][node.y]) {
                secondQ.push(Node(node.x-1, node.y));
            }

            if(node.x + 1 < m && !isVisited[node.x+1][node.y] && !obstacle[node.x+1][node.y]) {
                secondQ.push(Node(node.x+1, node.y));
            }

            if(node.y - 1 >= 0 && !isVisited[node.x][node.y-1] && !obstacle[node.x][node.y-1]) {
                secondQ.push(Node(node.x, node.y-1));
            }

            if(node.y + 1 < n && !isVisited[node.x][node.y+1] && !obstacle[node.x][node.y+1]) {
                secondQ.push(Node(node.x, node.y+1));
            }
        }

        if(pahtCnt > 0) {
            cout << pahtCnt << " " << len << endl;
            return 0;
        }
        queue<Node> tmp = q;
        q = secondQ;
        secondQ = tmp;
        len += 1;
    }
    return 0;
}