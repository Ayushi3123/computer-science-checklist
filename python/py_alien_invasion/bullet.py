import pygame
from pygame.sprite import Sprite


class Bullet(Sprite):
    """Class to handle bullets fired from the ship"""

    def __init__(self, ai_settings, screen, ship):
        """Create bullet at the current position of the ship"""
        super().__init__()
        self.screen = screen

        # Create bullet at origin and then set correct position
        self.rect = pygame.Rect(0, 0, ai_settings.bullet_width, ai_settings.bullet_height)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top

        self.y = float(self.rect.y)

        self.color = ai_settings.bullet_color
        self.speed_factor = ai_settings.bullet_speed_factor

    def update(self):
        """Move bullet upwards on the screen"""
        self.y -= self.speed_factor
        self.rect.y = self.y

    def draw_bullet(self):
        """Render the bullet"""
        pygame.draw.rect(self.screen, self.color, self.rect)
