class Solution {
public:

    int peakIndexInMountainArray(MountainArray &mountainArr, int n) {
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    // Increasing part
    int binarySearch(MountainArray &mountainArr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            } 
            else if (value > target) {
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return -1;
    }

    // Decreasing part
    int reverseBs(MountainArray &mountainArr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            } 
            else if (value > target) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peak = peakIndexInMountainArray(mountainArr, n);

        // Search increasing part first
        int result = binarySearch(mountainArr, 0, peak, target);

        if (result != -1) {
            return result;
        }

        // Search decreasing part
        return reverseBs(mountainArr, peak + 1, n - 1, target);
    }
};