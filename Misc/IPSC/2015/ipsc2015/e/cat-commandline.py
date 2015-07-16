from catlib import Game

G = Game()
N = G.N
print 'cat at {} {}'.format(N,N)
while True:
    r, c = [ int(x) for x in raw_input().split() ]
    G.next_move_player(r,c)
    if G.check_winner() == 'player':
        print 'player won'
        break
    r, c = G.next_move_cat()
    print 'cat to {} {}'.format(r,c)
    if G.check_winner() == 'cat':
        print 'cat won'
        break
