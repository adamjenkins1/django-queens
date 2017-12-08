from django.shortcuts import render, redirect, HttpResponse
from django.views.generic.base import RedirectView

def getRedirectUrl(request, matchedString):
    url = '/static/img/chesspieces/wikipedia/' + matchedString + '.png'
    return redirect(url, content_type = 'image/png')

def index(request):
    return render(request, 'index.html')

def about(request):
    return render(request, 'about.html')

def contact(request):
    return render(request, 'contact.html')

def stats(request):
    return render(request, 'stats.html')
