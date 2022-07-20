from django.conf import settings
from django.db import models
from django.utils import timezone


class alltodos(models.Model):
    id = models.AutoField(primary_key=True)
    task = models.CharField(max_length=200)
    description = models.TextField()
    tag = models.CharField(max_length=15,default='General')
    Status = models.BooleanField(default=False)
    created_date = models.DateTimeField(default=timezone.now)

    def __str__(self):
        return self.task