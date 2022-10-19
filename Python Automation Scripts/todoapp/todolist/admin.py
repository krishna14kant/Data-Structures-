from django.contrib import admin
from .models import*

# Register your models here.
class TodolistAdmin(admin.ModelAdmin) :
    list_display = ("title", "category", "due_date")

class CategoryAdmin(admin.ModelAdmin) :
       list_display = ("name",)

admin.site.register(Todolist, TodolistAdmin)
admin.site.register(Categories, CategoryAdmin)