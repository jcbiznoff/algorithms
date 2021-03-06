/*arrays.h:
 *
 * provides different algorithm interface for array ds.
 * */

/*countPairsDiffEqualK1:
 *  count all pairs within array difference = k. Not a naive approach
 *  1. sort an array
 *  2. maintain two indices one from left = i, one from right =j
 *  3. loop, if sum(arr[i] , arr[j]) > k then decrement j
 *  4. else increment i
 *  5. loop while i<j
 */
int countPairsDiffEqualK1(int arr[], int k);


/*countPairsDiffEqualK2:
 *  use binary search in an array for finding difference
 *  1. sort array
 *  2. search for elements arr[i]+k in a bst fashion
 */
int countPairsDiffEqualK2(int arr[], int k);

/*countPairDiffEqualK3:
 *  build a balanced BST, insert to array, look for that array
 *  1. initialize count =0
 *  2. inseart all elements of arr[] in AVL tree
 *  3. do the following for each arr[i]
 *  3. search for arr[i] + k in AVL, if found increment count
 *  4. search for arr[i] - k in AVL, if found increment count
 *  5. remove arr[i] from AVL
 */
int countPairDiffEqualK4(int arr[], int k);

/*countPairDiffEqualK4
 * use a hash map approach
 * 1. create/init a hash map with 0, size large
 * 2. each element  map[arr[i]]++;
 * 3. if map[arr[i] +k ] == 1 || map[arr[i] -k] == 1 (with boundary check) increase count
 * 4. return count
 */
int countPairDiffEqualK4(int arr[], int k);

/*moveZeros2End:
 * move all zeros to right side: maintain a count of zerose while looping.shift element to zero position as well.
 *  1. init count to zero
 *  2. loop through array
 *  3. if val ==0, store val at count idx
 *  4. inrement count
 *  5. after loop finishes, pad zeros from count to n-1
 */
void moveZeros2End(int **arr);

/*findMinimumInSortedRotated
 * find minimum in a sorted then rotated array
 *  0. base: if(l>h) return arr[0];
 *  0. leaf: if(l==h) return arr[l];
 *  1. find m = (1+h)/2;
 *  2. next element min? if arr[m] > arr[m+1] then return arr[m+1]
 *  3. cur element min? if arr[m] < arr[m-1] return arr[m]
 *
 3. if arr[l] < arr[h] recurse lower left
 *  4. else recur lower right
 */
int findMinimumInSortedRotated(int arr[], int l, int h);

/*printPermutation:
 *  print all possible arrangements of arr => use a bactrackig algorithm
 *
 *  if permuation ended, print eol
 *
 *  for given set of nodes
 */
void printPermutation(int arr[]);


/*hasArrayTwoCand
 * find pair with sum equal to specified value.
 * 1. sort array in ascending order
 * 2. set index i,j to start and end
 * 3. loop while i<j
 * 4. if sum > a[i] + a[j], decrease j
 * 5. else if sum < a[i] + a[j] increase i
 * 6. else return true
 * 7. return false.
 */

int hasArrayTwoCand(int arr[], int n, int sum);

/*hasArrayTwoCandHash
 * 1. create a hash map, set to 0
 * 2. traverse array
 * 3. check if M[sum - a[i]] is set to 1
 * 4. otherwise set M[a[i]] to 1
 */

 int findMajorityElement(int arr[], int n);

/*findNumberOddTimes
 * problem: all numbers occur even number of times except for one. find this one.
 * 1. do bitwise XOR of all elements.
*/

 int findNumberOddTimes(int arr[], int n);

 /*maxSubarraySum
  * problem: sum of contiguous subarray which has the largest sum => negative only affects outcom => negative only affects outcom => negative only affects outcomeee
  * 1. loop and cumulate sum
  */
 int maxSubArraySum(int a[], int n);

 /*findMissingNum
  * given 1 to n, find a missing number
  * 1. get sum of numbers.
  * 2. subtract each one.
  * 3. whatever is left is the number
  */


 /*findMedianSorted
  * prob: 2 sorted arrays, each size n, find median after merging
  *
  */
 int findMedianSorted(int a[], int b[], int n);
