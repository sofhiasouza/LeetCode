class Solution:
    def calculate(self, s: str) -> int:
        
        prev = ""
        arr = []
        for i in s:
            if i >= '0' and i <= '9':
                prev += i
            elif i != ' ':
                arr.append(int(prev))
                prev = ""
                arr.append(i)
                
        
        arr.append(int(prev))
        for i in range(len(arr)):
            if arr[i] == '*':
                arr[i+1] = arr[i+1]*arr[i-1]
                arr[i] = '*'
                arr[i-1] = '*'
            elif arr[i] == '/':
                arr[i+1] = int(arr[i-1]/arr[i+1])
                arr[i] = '*'
                arr[i-1] = '*'
                
        ans = 0
        op = '+'
        
        for i in range(len(arr)):
            if arr[i] == '+':
                op = '+'
            elif arr[i] == '-':
                op = '-'
            elif arr[i] != '*':
                if op == '+':
                    ans += arr[i]
                else:
                    ans -= arr[i]
                    
        return ans