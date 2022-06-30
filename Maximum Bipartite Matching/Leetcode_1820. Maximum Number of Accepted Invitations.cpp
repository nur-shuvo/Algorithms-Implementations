// see note section
/*

[nur.shuvo] If a job is not assigned to anybody, we simply assign it to the applicant and return true. If a job is assigned to somebody else say x, then we recursively 
check whether x can be assigned some other job. To make sure that x doesn’t get the same job again, we mark the job ‘v’ as seen before we make recursive call for x. 
If x can get other job, we change the applicant for job ‘v’ and return true. We use an array maxR[0..N-1] that stores the applicants assigned to different jobs.
Link: https://www.geeksforgeeks.org/maximum-bipartite-matching/

*/

class Solution {
    /*
        Concept : Maximum Bipartite graph
    */
    public int maximumInvitations(int[][] grid) {
        int m = grid.length; // boys
        int n = grid[0].length; // girls

        int[] girlFixed = new int[n];

        for (int i = 0; i < n; i++) {
            girlFixed[i] = -1;
        }

        int invitations = 0;

        for (int i = 0; i < m; i++) {
            Set<Integer> seenGirl = new HashSet<>();

            if (dfs(grid, i, seenGirl, girlFixed)) {
                invitations++;
            }
        }
        return invitations;
    }

    private boolean dfs(int[][] grid, int boy, Set<Integer> seenGirl, int[] girlFixed) {
        int m = grid.length; // boys
        int n = grid[0].length; // girls

        for (int i = 0; i < n; i++) {
            if (grid[boy][i] == 1 && !seenGirl.contains(i)) {
                seenGirl.add(i);
                if (girlFixed[i] == -1 || dfs(grid, girlFixed[i], seenGirl, girlFixed)) {
                    girlFixed[i] = boy;
                    return true;
                }
            }
        }
        return false;
    }
}