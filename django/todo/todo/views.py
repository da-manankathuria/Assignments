from multiprocessing import context
from django.shortcuts import redirect, render
from pytz import timezone
from .models import alltodos
#from .forms import PostForm
# show all todo and add todo
def todo_list(request):
    todos = alltodos.objects.all()
    if request.method == "POST":
        db = alltodos()
        db.task = request.POST.get('task')
        db.description = request.POST.get('description')
        db.tag = request.POST.get('tag')
        if db.task and db.description != "":
            db.save()
        todos = alltodos.objects.all()
        return render(request, 'todo/todo_list.html',{'todos':todos})
    return render(request, 'todo/todo_list.html', {'todos':todos})

# delete a todo    
def delete(request,id):
    alltodos.objects.filter(id=id).delete()
    return redirect(todo_list)


# update a todo
def update(request,id):
   
    if request.method == "POST":
        db = alltodos.objects.get(id=id) 
        db.task = request.POST.get('task')
        db.description = request.POST.get('description')        
        db.tag=request.POST.get('tag')
        db.save()
        return redirect(todo_list)

    todo= alltodos.objects.all().filter(id=id)
    return render(request,'todo/update_todo.html', {'task':todo[0].task , 'description':todo[0].description, "tag":todo[0].tag})

# mark as complete
def markcomplete(request,id):
    todo = alltodos.objects.get(id=id)
    todo.Status=True
    todo.save()
    return redirect(todo_list)

#mark as incomplete

def markincompleted(request,id):
    todo = alltodos.objects.get(id=id)
    todo.Status=False
    todo.save()
    return redirect(todo_list)  

#sort a todo
def sort(request):
    todos = alltodos.objects.all().order_by('-created_date')
    return render(request, 'todo/todo_list.html',{'todos':todos})    
