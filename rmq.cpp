class RMQ
{
public:
    RMQ(vector<int> v) {
        log_table.assign(v.size() + 1, 0);
        for (int i = 2; i < log_table.size(); i++) 
            log_table[i] = log_table[i/2] + 1;

        sparse_table.assign(log_table.back() + 1, vector<int>(v.size()));
        sparse_table[0] = v;
        for (int row = 1; row < sparse_table.size(); row++) {
            for (int i = 0; i + (1 << row) <= v.size(); i++) {
                sparse_table[row][i] = min(sparse_table[row-1][i], sparse_table[row-1][i+(1<<(row-1))]);
            }
        }
    }

    int minimum(int l, int r) {
        int log = log_table[r - l];
        return min(sparse_table[log][l], sparse_table[log][r - (1 << log)]);
    }

private:
    vector<int> log_table;
    vector<vector<int>> sparse_table;
};


RMQ ob(g);
// for range l to r use [l,r+1];
