from django.conf.urls import url
from django.views.generic.base import RedirectView
from . import views

urlpatterns = [
    url(r'^$', views.index, name = 'index'),
    url(r'^about/$', views.about, name = 'about'),
    url(r'^stats/$', views.stats, name = 'stats'),
    url(r'^img/chesspieces/wikipedia/([b-w][A-Z]).png/$', views.getRedirectUrl),
    url(r'^solve/([4-8]+)/([a-zA-Z]+)/$', views.solve, name = 'solve'),
    url(r'^jsondata/', views.jsondata, name = 'jsondata'),
]
