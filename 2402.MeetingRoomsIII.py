from typing import List

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        from heapq import heapify, heappop, heappush

        no_of_meetings = [0] * n
        unused_rooms = [_ for _ in range(n)]
        heapify(unused_rooms)
        used_room_and_exit_time = [] # (exit_time, room_id)
        meetings.sort(key = lambda x: x[0])

        for start, end in meetings:
            while used_room_and_exit_time and used_room_and_exit_time[0][0] <= start:
                _, room = heappop(used_room_and_exit_time)
                heappush(unused_rooms, room)
            if len(unused_rooms):
                room = heappop(unused_rooms)
                heappush(used_room_and_exit_time, (end, room))
                no_of_meetings[room] += 1
                continue
            else:
                prev_end, room = heappop(used_room_and_exit_time)
                new_end = prev_end + end - start
                heappush(used_room_and_exit_time, (new_end, room))
                no_of_meetings[room] += 1
                

        max_meetings = 0
        max_room = -1

        for i, meetings in enumerate(no_of_meetings):
            if meetings > max_meetings:
                max_meetings = meetings
                max_room = i

        return max_room
        