#!/usr/bin/env python3

au, bu, ar, br = map(int, input().split())

ans = ar*br
ans += min(au, br)
au -= min(au, br)
ans += min(bu, ar)
bu -= min(bu, ar)
ans += min(bu, au)
print(ans)
