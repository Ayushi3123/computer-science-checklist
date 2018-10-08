class GameStats:
    """Game statistics manager"""

    def __init__(self, ai_settings):
        """Initialize statistics"""
        self.ai_settings = ai_settings
        self.ships_left = self.ai_settings.ship_limit
        self.game_active = False
        self.score = 0
        self.high_score = 0
        self.level = 0

    def reset_stats(self):
        """Initialize game statistics"""
        self.ships_left = self.ai_settings.ship_limit
        self.score = 0
