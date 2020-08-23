#시작시간을 기준으로 정리하고 시작시간이 같을 경우 끝나는 시간이 짧은 순으로 정렬한다

N = int(input())

times = []
for n in range(N):
    times.append(tuple(map(int, input().split(' '))))

times.sort(key=lambda x: (x[0], x[1]))

linkedTimes = [times[0]]
del times[0]
while len(times):
    if     
print(times)