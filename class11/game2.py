import pygame


background_color = (255, 255, 255)

pygame.init()

gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption('My first game')
clock = pygame.time.Clock()

space_ship_image = pygame.image.load('spaceship.png')

def show_space_ship(x, y):
    gameDisplay.blit(space_ship_image, (x, y))
    

gameover = False

x = 400
y = 500
speed_x = 0
speed_y = 0

while not gameover:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameover = True
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                speed_x = -5
            elif event.key == pygame.K_RIGHT:
                speed_x = 5

    gameDisplay.fill(background_color)

    x += speed_x
    y += speed_y
    show_space_ship(x, y)
    pygame.display.update()
    clock.tick(60)


pygame.quit()
