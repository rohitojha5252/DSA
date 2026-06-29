class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        int i,j;

        for(int k = 0; k<n; k++){
            i = 0;
            j = image[0].size()-1;

            while(i<=j){
                if(image[k][i] == image[k][j]){
                    if(image[k][i] == 1){
                        image[k][i] = 0;
                        image[k][j] = 0;
                    }
                    else{
                        image[k][i] = 1;
                        image[k][j] = 1;
                    }
                }
                i++,j--;
            }
        }
        return image;
    }
};