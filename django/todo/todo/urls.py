from django.urls import path
from . import views

urlpatterns = [
    path('', views.todo_list, name='todo_list'),
    path('delete/?P<int:id>/', views.delete, name='delete'),
    path('update/?P<int:id>/',views.update , name='update'),
    path('markcompleted/?P<int:id>/',views.markcomplete , name='markcompleted'),
    path('markincompleted/?P<int:id>/',views.markincompleted , name='markincompleted'),


]