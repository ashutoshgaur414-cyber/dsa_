      rec2[0]);
      int overlapHeight = min(rec1[3], rec2[3]) - max(rec1[1], 
      rec2[1]);

      if(overlapWidth >0 && overlapHeight >0 )
      {
        return true;
      }
      else
      {
        return false;
      }
    }
      int overlapWidth  = min(rec1[2], rec2[2]) - max(rec1[0], 
    {
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
public:
class Solution {
