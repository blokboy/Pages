#include <stdio.h>
#include <stdlib.h>

int main()
{

    int frames[20], temp[20], pages[20];
    int total_pages, total_frames, pos, x, y, j, i;
    int a = 0, b = 0, page_fault = 0, page_hit = 0;

    printf("\nEnter total number of frames:\t");
    scanf("%d", &total_frames);

    printf("\nEnter total number of pages:\t");
    scanf("%d", &total_pages);

    //initialize all the available frames with "empty" values of -1
    for(x = 0; x < total_frames; x++) {
        frames[x] = -1;
    }

    printf("Enter values for the Reference String:\n");

    for(x = 0; x < total_pages; x++) {
        printf("Value No.[%d]:\t", x + 1);
        scanf("%d", &pages[x]);
    }

    for(x = 0; x < total_pages; x++) {
        a = 0, b = 0;
        for(y = 0; y < total_frames; y++) {
            if(frames[y] == pages[x]) {
                a = 1, b = 1;
                page_hit++;
                break;
            }
        }
        if(a == 0) {
            for(y = 0; y < total_frames; y++) {
                if(frames[y] == -1) {
                    frames[y] = pages[x];
                    b = 1;
                    break;
                }
            }
        }
        if(b == 0) {
            for(y = 0; y < total_frames; y++) {
                temp[y] = 0;
            }
            for(j = x - 1, i = 1; i <= total_frames - 1; i++, j--) {
                for(y = 0; y < total_frames; y++) {
                    if(frames[y] == pages[j]) {
                        temp[y] = 1;
                    }
                }
            }
            for(y = 0; y < total_frames; y++) {
                if(temp[y] == 0) { pos = y; }
            }
            frames[pos] = pages[x];
            page_fault++;
        }
        printf("\n");
        for(y = 0; y < total_frames; y++) {
            printf("%d\t", frames[y]);
        }
    }
    printf("\nTotal number of page faults:\t%d\n", page_fault);
    printf("\nTotal number of page hits:\t%d\n", page_hit);
    return 0;
}
