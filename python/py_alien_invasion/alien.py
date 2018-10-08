import pygame
from pygame.sprite import Sprite


class Alien(Sprite):
    """Class to handle an alien spacecraft"""

    def __init__(self, ai_settings, screen):
        """Initialise the alien spacecraft"""
        super().__init__()

        self.screen = screen
        self.ai_settings = ai_settings

        self.image = pygame.image.load('images/alien.bmp')
        self.rect = self.image.get_rect()

        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        self.x = float(self.rect.x)

    def check_edges(self):
        """Check if the alien has collided with the side of the screen"""
        screen_rect = self.screen.get_rect()
        return self.rect.right >= screen_rect.right or self.rect.left <= 0
        # if self.rect.right >= screen_rect.right:
        #     return True
        # elif self.rect.left <= 0:
        #     return True

    def update(self):
        """Update the position of the alien"""
        self.x += (self.ai_settings.alien_speed_factor * self.ai_settings.fleet_direction)
        self.rect.x = self.x

    def blitme(self):
        """Draw the alien to the screen"""
        self.screen.blit(self.image, self.rect)
