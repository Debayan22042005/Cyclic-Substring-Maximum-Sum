#include <stdio.h>
#include <string.h>

int main() {
    char s[100], t[100];
    int n, i, right, idx, lidx;
    int freq[26] = {0};
    int left = 0;
    int curr_sum = 0;
    int max_sum = 0;
    
    scanf("%s", s);
    n = strlen(s);

    for (i = 0; i < n; i++) 
    {
        t[i] = s[i];
        t[i + n] = s[i];
    }

    for (right = 0; right < 2 * n; right++) 
    {
        idx = t[right] - 'a';
        
        while (freq[idx] > 0 || (right - left + 1) > n) 
        {
            lidx = t[left] - 'a';
            freq[lidx]--;
            curr_sum -= (lidx + 1);
            left++;
        }

        freq[idx]++;
        curr_sum += (idx + 1);

        if (curr_sum > max_sum) 
        {
            max_sum = curr_sum;
        }
    }

    printf("%d\n", max_sum);

    return 0;
}