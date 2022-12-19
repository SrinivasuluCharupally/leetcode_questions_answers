// source : https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/302-smallest-rectangle-enclosing-black-pixels-hard.html
//
//


void recusion(vector<vector<char>>& image, int x, int y, int& up, int& down, int& left, int& right) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != '1') return;
        up = min(x,up);
        down = max(x,down);
        left = min(left,y);
        right = max(right,y);
        image[x][y] = '2';
        recusion(image, x-1, y, up, down, left, right);
        recusion(image, x+1, y, up, down, left, right);
        recusion(image, x, y-1, up, down, left, right);
        recusion(image, x, y+1, up, down, left, right);
}

int main() {

}



