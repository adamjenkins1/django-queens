from django.db import models

class ChessData(models.Model):
  queens = models.IntegerField(default = 0)
  algorithm = models.CharField(max_length = 200, default = '0')
  time = models.FloatField(default = 0)

  def __str__(self):
    return self.algorithm + ', ' + str(self.queens)

  def as_dict(self):
    return {
        'queens': self.queens,
        'algorithm': self.algorithm,
        'time': self.time
    }
