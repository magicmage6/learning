import pygame


background_color = (255, 255, 255)

pygame.init()

gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption('My first game')

space_ship_image = pygame.image.load('spaceship.png')

def show_space_ship(x, y):
    gameDisplay.blit(space_ship_image, (x, y))
    

gameover = False

x = 400
y = 300

while not gameover:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameover = True
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                x -= 5
            elif event.key == pygame.K_RIGHT:
                x += 5

    gameDisplay.fill(background_color)

    show_space_ship(x, y)
    pygame.display.update()


pygame.quit()
