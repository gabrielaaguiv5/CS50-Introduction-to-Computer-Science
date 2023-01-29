const carouselSlide = document.querySelector('.carousel-slide'); //Code to execute Slideshow of different pictures in different html pages
const carouselImages = document.querySelectorAll('.carousel-slide img');

const Prev = document.querySelector('#Prev');
const Next = document.querySelector('#Next');

let counter = 1;
const size = carouselImages[0].clientWidth; //Size of array with all images in carousel

carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)'; //Transform used to navigate through pictures in slides

Next.addEventListener('click', function() //Navigation button to next picture
{
    if (counter >= carouselImages.length -1) return;
    carouselSlide.style.transition ="transform 0.4s ease-in-out";
    counter++;
    carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
});

Prev.addEventListener('click', function() //Navigation button to previous picture
{
    if (counter <= 0) return;
    carouselSlide.style.transition ="transform 0.4s ease-in-out";
    counter--;
    carouselSlide.style.transform = 'translateX(' + (-size * counter ) + 'px)';
});

carouselSlide.addEventListener('transitionend', function() //Navigation in loop through pictures
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

