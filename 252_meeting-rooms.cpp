#include<iostream>
#include<vector>

typedef struct Interval {
        int start;
        int end;
} Interval;

void canAttendMeetings(Interval[] intervals) {

        Arrays.sort(intervals, (a, b) -> a.start - b.start);

        for(int i = 0; i + 1 < intervals.length; i++){

            if(intervals[i].end > intervals[i + 1].start){
                return false;
            }
        }

        return true;
    }
}

