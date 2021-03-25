class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        data.assign(rectangle.begin(), rectangle.end());
        row = rectangle.size();
        col = rectangle[0].size();
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i)
        {
            fill(data[i].begin()+col1, data[i].begin()+col2+1, newValue);
        }
    }
    
    int getValue(int row, int col) {
        return data[row][col];
    }
    
    private:
    vector<vector<int>> data;
    int row;
    int col;
};