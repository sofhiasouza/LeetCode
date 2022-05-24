class Solution:
    def simplifyPath(self, path: str) -> str:
        
        stack = []
        ans = "/"
        aux = ""
        for i in range(len(path)):
            if path[i] == '/':
                if len(aux) and aux != "..":
                    if aux != ".":
                        stack.append(aux)
                elif aux == ".." and len(stack):
                    stack.pop()
                aux = ""
            else:
                aux += path[i]
        
        if len(aux) > 0 and aux != ".":
            if aux != "..":
                stack.append(aux)
            elif len(stack) > 0:
                stack.pop()
        
        if len(stack)> 0:
            ans += stack[0]
        
        p = 1
        while p < len(stack):
            ans += '/'
            ans += stack[p]
            p += 1
        
        return ans
        