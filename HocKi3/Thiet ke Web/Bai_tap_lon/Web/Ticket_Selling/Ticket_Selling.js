

$(document).ready(() => {
    // $('#hamburger-menu').click(() => {
    //     $('#hamburger-menu').toggleClass('active')
    //     $('#nav-menu').toggleClass('active')
    // })

    // setting owl carousel

    let navText = ["<i class='bx bx-chevron-left'></i>", "<i class='bx bx-chevron-right'></i>"]

    $('#hero-carousel').owlCarousel({
        items: 1,
        dots: false,
        loop: true,
        nav:true,
        navText: navText,
        autoplay: true,
        autoplayHoverPause: true
    })

    $('#top-movies-slide').owlCarousel({
        items: 2,
        dots: false,
        loop: true,
        autoplay: true,
        autoplayHoverPause: true,
        responsive: {
            500: {
                items: 3
            },
            1280: {
                items: 4
            },
            1600: {
                items: 6
            }
        }
    })

    $('.movies-slide').owlCarousel({
        items: 2,
        dots: false,
        nav:true,
        navText: navText,
        margin: 15,
        loop: true,
        autoplay: true,
        responsive: {
            500: {
                items: 2
            },
            1280: {
                items: 4
            },
            1600: {
                items: 6
            }
        }
    })
})
const selects = document.querySelectorAll('.analysis-select');
const selectItem = document.querySelectorAll('.analysis-item');
const pan = document.querySelector('.analysis-item.active')
selects.forEach((select, index) => {
    const item = selectItem[index];
    select.onclick = () => {
        item.classList.add('active');
        pan.classList.remove('active');        

    }
})
window.onscroll = function() {scrollFunction()};

function scrollFunction() {
  if (document.body.scrollTop > 80 || document.documentElement.scrollTop > 80) {
    document.getElementById("nav").style.padding = "20px 10px";
    document.getElementById("logo").style.height = "25px";
  } else {
    document.getElementById("header").style.padding = "30px 10px";
    document.getElementById("logo").style.height = "35px";
  }
}
const bar = document.querySelector('.menu-bar');
const menu = document.querySelector('.mobile-menu');
bar.onclick = () =>{
    // menu.style.height = '50vh';
}