from django.shortcuts import render
from .models import Todolist, Categories
# Create your views here.




def index(request):

    todos = Todolist.objects.all()
    categories = Categories.objects.all()

    if request.method == "POST":
        if "taskAdd" in request.POST:
            title = request.POST["description"]
            date = request.POST["date"]
            category = request.POST["category_select"]

            content = title + "-------" + category + "------" + date

            Todo = Todolist(title=title, content=content, due_date=date, category=Categories.objects.get(name=category))
            Todo.save()
        if "taskDelete" in request.POST:
            checklist = request.POST["checkedbox"]
            for task_id in checklist :
               todo = Todolist.objects.get(id=task_id)
               todo.delete()

    return render(request, "index.html", {"todos": todos, "categories": categories})

