double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* ans = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            ans[k++] = nums1[i++];
        } else {
            ans[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        ans[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        ans[k++] = nums2[j++];
    }

    int n = k;
    double median;
    
    if (n % 2 == 1) {
        median = ans[n / 2];
    } else {
        median = (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    }

    free(ans);
    return median;
}