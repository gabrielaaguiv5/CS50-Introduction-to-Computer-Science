const carouselSlide = document.querySelector('.carousel-slide');
const carouselImages = document.querySelectorAll('.carousel-slide img');

const Prev = document.querySelector('#Prev');
const Next = document.querySelector('#Next');

let counter = 1;
const size = carouselImages[0].clientWidth;

carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';

Next.addEventListener('click', function()
{
    carouselSlide.style.transition ="transform 0.4s ease-in-out";
    counter++;
    carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
});

Prev.addEventListener('click', function()
{
    carouselSlide.style.transition ="transform 0.4s ease-in-out";
    counter--;
    carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
});

carouselSlide.addEventListener('transitionend', function()
{
    if(carouselImages[counter].id == 'Last'){
        carouselSlide.style.transition ="none";
        counter = carouselImages.length -2;
        carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
    }
    if(carouselImages[counter].id == 'First'){
        carouselSlide.style.transition ="none";
        counter = carouselImages.length -counter;
        carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
    }
});

