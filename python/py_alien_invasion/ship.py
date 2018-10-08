import pygame
from pygame.sprite import Sprite


class Ship(Sprite):
    """Ship class for player"""

    def __init__(self, ai_settings, screen):
        """Init ship and set starting position"""
        super().__init__()

        self.screen = screen
        self.ai_settings = ai_settings
        self.image = pygame.image.load('images/ship.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # Store the center of the ship
        self.center = float(self.rect.centerx)

        self.moving_right = False
        self.moving_left = False

    def center_ship(self):
        """Center the ship on the screen"""
        self.center = self.screen_rect.centerx

    def update(self):
        """Update the postion of the ship based on the movement flag"""
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.center += self.ai_settings.ship_speed_factor
        if self.moving_left and self.rect.left > 0:
            self.center -= self.ai_settings.ship_speed_factor

        self.rect.centerx = self.center

    def blitme(self):
        """Draw the ship at it's current location"""
        self.screen.blit(self.image, self.rect)
