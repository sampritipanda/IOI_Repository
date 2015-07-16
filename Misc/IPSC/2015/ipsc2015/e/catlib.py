from Queue import Queue

class RNG:
    def __init__(self,seed): self.state = seed

    def value(self):
        self.state = (self.state*1103515245+12345) % (2**31)
        return self.state // 4

    def randrange(self,n):
        return self.value() % n

class Game:
    def __init__(self):
        self.N = 10
        self.blocked = set()
        self.catr, self.catc = self.N, self.N
        self.dirs = [ (0,-1), (-1,-1), (-1,0), (0,1), (1,1), (1,0) ]
        self.RNG = RNG(47)
        self.game_over = False
        self.log = []
        self.logged = False

    def valid_cell(self,r,c):
        if r < 1 or r >= 2*self.N: return False
        cmin = max( 1, r-self.N+1 )
        cmax = min( self.N+r-1, 2*self.N-1 )
        if c < cmin or c > cmax: return False
        return True

    def cell_on_border(self,r,c):
        if r == 1 or r == 2*self.N-1: return True
        cmin = max( 1, r-self.N+1 )
        cmax = min( self.N+r-1, 2*self.N-1 )
        if c == cmin or c == cmax: return True
        return False

    def save_log(self,winner):
        if self.logged: return
        self.logged = True
        f = open('log.txt','a')
        f.write('NEW GAME\n')
        for r,c in self.log: f.write('{} {}\n'.format(r,c))
        f.write('WINNER: {} (after {} moves)\n\n'.format(winner,len(self.log)))
        f.close()

    def check_winner(self):
        if self.cell_on_border(self.catr,self.catc):
            self.game_over = True
            self.save_log('cat')
            return 'cat'
        caught = True
        for dr, dc in self.dirs:
            r, c = self.catr+dr, self.catc+dc
            caught = caught and ( (r,c) in self.blocked )
        if caught:
            self.game_over = True
            self.save_log('player')
            return 'player'
        return None

    def next_move_player(self,r,c):
        self.check_winner()
        assert not self.game_over, 'Game already over.'
        assert self.valid_cell(r,c), 'Invalid cell.'
        assert (r,c) != (self.catr,self.catc), 'Cannot block the cat\'s cell.'
        assert (r,c) not in self.blocked, 'Cannot block an already blocked cell.'
        self.blocked.add( (r,c) )
        self.log.append( (r,c) )

    def next_move_random(self):
        while True:
            dr, dc = self.dirs[ self.RNG.randrange( len(self.dirs) ) ]
            r, c = self.catr+dr, self.catc+dc
            if (r,c) not in self.blocked:
                self.catr, self.catc = r, c
                return (r,c)

    def get_cat_distances(self,sr,sc):
        distance = {}
        distance[ (sr,sc) ] = 0
        Q = Queue()
        Q.put( (sr,sc) )

        while not Q.empty():
            r, c = Q.get()
            for dr, dc in self.dirs:
                nr, nc = r+dr, c+dc
                if (nr,nc) in self.blocked: continue
                if (nr,nc) in distance: continue
                distance[ (nr,nc) ] = distance[ (r,c) ] + 1
                Q.put( (nr,nc) )

        return distance

    def next_move_cat_bfs(self):
        best, best_dr, best_dc = 123456789, None, None
        for dr, dc in self.dirs:
            nr, nc = self.catr+dr, self.catc+dc
            if (nr,nc) in self.blocked: continue
            distance = self.get_cat_distances(nr,nc)
            curr = sum( distance[x] for x in distance )
            if curr < best:
                best, best_dr, best_dc = curr, dr, dc

        self.catr += best_dr
        self.catc += best_dc
        return (self.catr,self.catc)
    
    def get_border_distances(self):
        distance = {}
        Q = Queue()
        
        for r in range(1,2*self.N):
            for c in range(1,2*self.N):
                if not self.valid_cell(r,c): continue
                if not self.cell_on_border(r,c): continue
                if (r,c) in self.blocked: continue
                distance[ (r,c) ] = 0
                Q.put( (r,c) )

        while not Q.empty():
            r, c = Q.get()
            for dr, dc in self.dirs:
                nr, nc = r+dr, c+dc
                if not self.valid_cell(nr,nc): continue
                if (nr,nc) in self.blocked: continue
                if (nr,nc) in distance: continue
                distance[ (nr,nc) ] = distance[ (r,c) ] + 1
                Q.put( (nr,nc) )

        return distance

    def verify_cutvertex(self, distance, r, c, cr, cc):
        visited = set()
        visited.add( (r,c) )
        Q = Queue()
        Q.put( (r,c) )

        while not Q.empty():
            r, c = Q.get()
            for dr, dc in self.dirs:
                nr, nc = r+dr, c+dc
                if not (nr,nc) in distance: continue
                if (nr,nc) in visited: continue
                if (nr,nc) == (cr,cc): continue
                if distance[ (nr,nc) ] != distance[ (r,c) ] - 1: continue
                if distance[ (nr,nc) ] == 0: return False
                visited.add( (nr,nc) )
                Q.put( (nr,nc) )
        return True

    def has_cutvertex(self, distance, r, c):
        path = [ (r,c) ]
        while distance[ path[-1] ] > 0:
            for dr, dc in self.dirs:
                nr, nc = path[-1][0]+dr, path[-1][1]+dc
                if (nr,nc) not in distance: continue
                if distance[ (nr,nc) ] != distance[ path[-1] ] - 1: continue
                path.append( (nr,nc) )
        for cr,cc in path[1:]:
            if self.verify_cutvertex(distance,r,c,cr,cc):
                return True
        return False

    def get_hexant_sum(self,r0,c0,dr1,dc1,dr2,dc2):
        answer = 0
        visited = set()
        visited.add( (r0,c0) )
        distance = {}
        distance[ (r0,c0) ] = 0
        Q = Queue()
        Q.put( (r0,c0) )
        while not Q.empty():
            r, c = Q.get()
            for dr, dc in [ (dr1,dc1), (dr2,dc2) ]:
                nr, nc = r+dr, c+dc
                if not self.valid_cell(nr,nc): continue
                if (nr,nc) in visited: continue
                visited.add( (nr,nc) )
                distance[ (nr,nc) ] = distance[ (r,c) ] + 1
                if (nr,nc) in self.blocked:
                    answer += 2 ** (22 - distance[ (nr,nc) ])
                else:
                    Q.put( (nr,nc) )
        return answer

    def next_move_border_bfs(self):
        distance = self.get_border_distances()
        if (self.catr,self.catc) not in distance: return self.next_move_cat_bfs()

        best, best_dr, best_dc = 2**60, None, None
        for dr, dc in self.dirs:
            nr, nc = self.catr+dr, self.catc+dc
            if (nr,nc) not in distance: continue
            curr = (2 ** 30) * distance[ (nr,nc) ]
            if self.has_cutvertex( distance, nr, nc ): curr += 2 ** 29

            d = 0
            while self.dirs[d] != (dr,dc): d += 1
            pdr, pdc = self.dirs[(d-1)%6]
            ndr, ndc = self.dirs[(d+1)%6]
            curr += self.get_hexant_sum(nr,nc,pdr,pdc,dr,dc) + self.get_hexant_sum(nr,nc,dr,dc,ndr,ndc)

            if curr < best:
                best, best_dr, best_dc = curr, dr, dc
        
        self.catr += best_dr
        self.catc += best_dc
        return (self.catr,self.catc)

    def is_hexant_free(self,r0,c0,dr1,dc1,dr2,dc2):
        return self.get_hexant_sum(r0,c0,dr1,dc1,dr2,dc2) == 0
    
    def next_move_hexant(self):
        free_cnt = {}
        for dr, dc in self.dirs: free_cnt[ (dr,dc) ] = 0
        for d in range(6):
            dr1, dc1 = self.dirs[d]
            dr2, dc2 = self.dirs[ (d+1)%6 ]
            if self.is_hexant_free( self.catr, self.catc, dr1, dc1, dr2, dc2 ):
                free_cnt[ (dr1,dc1) ] += 1
                free_cnt[ (dr2,dc2) ] += 1
        
        best_dr, best_dc, best_cnt = None, None, 0
        for dr, dc in self.dirs:
            if free_cnt[ (dr,dc) ] > best_cnt:
                best_dr, best_dc, best_cnt = dr, dc, free_cnt[ (dr,dc) ]

        if best_cnt == 0: return self.next_move_border_bfs()
        self.catr += best_dr
        self.catc += best_dc
        return (self.catr,self.catc)

    def next_move_cat(self):
        self.check_winner()
        assert not self.game_over, 'Game already over.'
        if len(self.log) < 8:
            return self.next_move_hexant()
        else:
            return self.next_move_border_bfs()

