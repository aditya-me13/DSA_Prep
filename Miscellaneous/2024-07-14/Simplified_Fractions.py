# Problem Link:

class Solution:
    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def coprime(self, a, b):
        return self.gcd(a, b) == 1

    def simplifiedFractions(self, n: int) -> List[str]:
        L = set()

        for i in range(1,n+1):
            for j in range(i+1, n+1):
                if(self.coprime(i, j)):
                    L.add(f'{min(i,j)}/{max(i,j)}')
        
        return list(L)
