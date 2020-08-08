import pygame

pygame.init()

gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption('My first game')

gameover = False

while not gameover:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameover = True

    pygame.display.update()


pygame.quit()
