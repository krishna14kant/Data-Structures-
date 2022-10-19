from django.db import models
from django.utils import timezone
# Create your models here.
'''


class - Table
variables - data field 



'''
class Categories(models.Model):

    # Field is for storing the names of categories
    name = models.CharField(max_length=100)

    # optional
    class Meta:
        verbose_name = ("Category")
        verbose_name_plural = ("Categories")

    def __str__(self):
        return self.name


class Todolist(models.Model):

    objects = None
    title = models.CharField(max_length=50)
    content = models.TextField(blank=True)
    created = models.DateTimeField(default=timezone.now().strftime("%Y-%m-%d"))
    due_date = models.DateTimeField(default=timezone.now().strftime("%Y-%m-%d"))
    category = models.ForeignKey(Categories, on_delete=models.CASCADE)

    class Meta:
        ordering = ["due_date"]

    def __str__(self):
        return self.title


