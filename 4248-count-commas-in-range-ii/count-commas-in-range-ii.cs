public class Solution {
    public long CountCommas(long n) {
        if(n <= 999) return 0;

        long totalCommas = 0;
        long rangeStart = 1000;
        long rangeEnd = rangeStart * 1000 - 1;
        int commas = 1;

        while(rangeStart <= n){
            long numbers = Math.Min(n, rangeEnd) - rangeStart + 1;
            totalCommas += commas * numbers;

            if(rangeEnd > n) break;

            rangeStart = rangeStart * 1000;
            rangeEnd = rangeStart * 1000 - 1;
            commas++;
        }
        return totalCommas;
    }
}