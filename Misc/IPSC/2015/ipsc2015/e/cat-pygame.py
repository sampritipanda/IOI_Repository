import sys, pygame
from pygame.locals import *
from catlib import Game

pygame.init()
pygame.display.set_caption('Enclosure')

G      = Game()
N      = G.N
font   = pygame.font.Font(None, 24)
cat    = pygame.image.load('cat.png')
size   = width, height = 800, 600
screen = pygame.display.set_mode(size)

def valid_cell(r,c):
    if r < 1 or r >= 2*N: return False
    cmin = max( 1, r-N+1 )
    cmax = min( N+r-1, 2*N-1 )
    if c < cmin or c > cmax: return False
    return True

def draw_cell(surface,r,c,blocked):
    cellx = 40*c + 20*(N-r)
    celly = 300 + 30*(r-N)
    if blocked: pygame.draw.circle(surface,(100,0,0),(cellx,celly),18,0)
    pygame.draw.circle(surface,(0,0,0),(cellx,celly),18,1)

def draw_board():
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((255, 255, 255))

    if G.check_winner() == 'player':
        background.fill((200, 255, 200))
        background.blit( font.render('R to restart', 1, (0,0,0)) , (10,10) )
        background.blit( font.render('won in {} moves'.format(len(G.log)), 1, (0,0,0)) , (10,25) )
        background.blit( font.render('saved in log.txt'.format(len(G.log)), 1, (0,0,0)) , (10,40) )
    if G.check_winner() == 'cat':
        background.fill((255, 200, 200))
        background.blit( font.render('R to restart', 1, (0,0,0)) , (10,10) )

    for r in range(2*N):
        for c in range(2*N):
            if valid_cell(r,c):
                draw_cell(background,r,c,(r,c) in G.blocked)

    background.blit( cat, ( 40*G.catc + 20*(N-G.catr) - 16, 300 + 30*(G.catr-N) - 16 ) )
    screen.blit(background, (0,0))
    pygame.display.flip()

def process_click(x,y):
    if G.game_over: return

    cr, cc = None, None    
    for r in range(2*N):
        for c in range(2*N):
            if valid_cell(r,c):
                cellx, celly = 40*c+20*(N-r), 300+30*(r-N)
                if (x-cellx)**2 + (y-celly)**2 < 18**2: cr, cc = r, c

    if cr is None: return
    if (cr,cc) in G.blocked: return
    if (cr,cc) == (G.catr,G.catc): return

    G.next_move_player(cr,cc)
    draw_board()
    if G.check_winner() == 'player': return

    r, c = G.next_move_cat()
    draw_board()
    if G.check_winner() == 'cat': return

def main():
    global G
    draw_board()
    while 1:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.mouse.set_visible(1)
                pygame.event.set_grab(0)
                sys.exit()
            elif event.type == MOUSEBUTTONDOWN:
                process_click(*event.pos)
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE or event.key == 81 or event.key == 113: # Q
                    pygame.mouse.set_visible(1)
                    pygame.event.set_grab(0)
                    sys.exit()
                if event.key == 82 or event.key == 114: # R
                    G = Game()
                    draw_board()
        pygame.time.wait(10)

if __name__ == '__main__': main()
