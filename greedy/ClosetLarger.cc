/**
 * Find a number larger than and closet to y, 
 * using exactly the same digits in x.
 */
int closetLarger(int x, int y) {
    int digit[10] = {};
    vector<int> sx, sy;
    do {
        digit[x%10]++;
        sy.push_back(y%10);
        x /= 10, y /= 10;
    } while(x);
    if (!dfs(sx, sy, sx.size()-1, digit))
        return -1;
    int ret = 0;
    for (int i = sx.size()-1; i >= 0; i--)
        ret = ret*10 + sx[i];
    return ret;
}

bool dfs(vector<int> &x, vector<int> &y, int p, int f[]) {
    if (p < 0)
        return false;
    if (f[y[p]] > 0) {
        x[p] = y[p];
        f[y[p]]--;
        if (dfs(x, y, p-1, f))
            return true;
        f[y[p]]++;
    }
    for (int i = y[p]+1; i < 10; i++) {
        if (f[i] > 0) {
            x[p] = i;
            f[i]--;
            for (int j = p-1; j >= 0; j--) {
                for (int k = 0; k < 10; k++) {
                    if (f[k] > 0) {
                        x[j] = k;
                        f[k]--;
                        break;
                    }
                }
            }
            return true;
        }
    }
    return false;
}
