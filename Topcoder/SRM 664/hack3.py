from math import log

const = log(2)

class BearSortsDiv2():

    def calc (self, seq):
        #seq: tuple(integer), len(seq) : [1, 40]

        if len(seq) == 1:
            return 0
        
        minseq = seq[0]
        maxseq = seq[0]
        for k in seq:
            if k < minseq:
                minseq = k
            if k > maxseq:
                maxseq = k
        mid = (minseq + maxseq - 1) //2

        small = filter (lambda x: x <= mid, seq)
        big = filter (lambda x: x > mid, seq)
        
        steps = 0
        fst = 0
        snd = 0
        while (fst < len(small)) and (snd < len(big)):
            if seq[steps] == small[fst]:
                fst += 1
            elif seq[steps] == big[snd]:
                snd += 1
            else:
                raise Exception()
            steps += 1

        delta = -steps * const
        return (self.calc(small) + self.calc(big) + delta)
        
    def getProbability(self, seq):
        #seq: tuple(integer), len(seq) : [1, 40]

        return self.calc (seq)

print BearSortsDiv2().getProbability([7, 6, 2, 11, 19, 5, 17, 15, 8, 4, 14, 3, 20, 9, 10, 18, 13, 12, 1, 16])
