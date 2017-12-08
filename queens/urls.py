from django.conf.urls import url
from django.views.generic.base import RedirectView
from . import views

urlpatterns = [
    url(r'^$', views.index, name = 'index'),
    url(r'^about/$', views.about, name = 'about'),
    url(r'^contact/$', views.contact, name = 'contact'),
    url(r'^stats/$', views.stats, name = 'stats'),
    url(r'^img/chesspieces/wikipedia/([b-w][A-Z]).png/$', views.getRedirectUrl),
]
