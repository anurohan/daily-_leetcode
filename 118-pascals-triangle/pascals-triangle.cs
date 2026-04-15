public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        IList<IList<int>> triangle = new List<IList<int>>();
        
        for (int i = 0; i < numRows; i++) {
            IList<int> row = new List<int>(i + 1);
            
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.Add(1);                    // First and last element of each row is 1
                } else {
                    // Current element = element above-left + element above-right
                    int value = triangle[i-1][j-1] + triangle[i-1][j];
                    row.Add(value);
                }
            }
            
            triangle.Add(row);
        }
        
        return triangle;
    }
}