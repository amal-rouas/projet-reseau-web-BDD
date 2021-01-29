!(function (r) {
    "use strict";
    r(window).on("load", function () {
        r("#preloader").fadeOut(1e3);
    }),
        r(window).on("load", function () {
            var t = r(".header"),
                a = t.find(".navbar"),
                o = 0,
                s = r(".navbar-sticky");
            r(window).scroll(function () {
                var e = r(this).scrollTop();
                o < e ? s.addClass("navbar-scrollUp") : s.removeClass("navbar-scrollUp"),
                    (o = e),
                    a.hasClass("navbar-sticky") && (r(this).scrollTop() <= 600 || r(this).width() <= 300)
                        ? (a.removeClass("navbar-scrollUp"), a.removeClass("navbar-sticky").appendTo(t), t.css("height", "auto"))
                        : !a.hasClass("navbar-sticky") &&
                          300 < r(this).width() &&
                          600 < r(this).scrollTop() &&
                          (t.css("height", t.height()), a.addClass("navbar-scrollUp"), a.css({ opacity: "0" }).addClass("navbar-sticky"), a.appendTo(r("body")).animate({ opacity: 1 }));
            }),
                r(window).trigger("resize"),
                r(window).trigger("scroll");
        }),
        991 < r(window).width() &&
            r(".navbar-expand-lg .navbar-nav .dropdown").hover(
                function () {
                    r(this).addClass("").find(".dropdown-menu").addClass("show");
                },
                function () {
                    r(this).find(".dropdown-menu").removeClass("show");
                }
            ),
        767 < r(window).width() &&
            r(".navbar-expand-md .navbar-nav .dropdown").hover(
                function () {
                    r(this).addClass("").find(".dropdown-menu").addClass("show");
                },
                function () {
                    r(this).find(".dropdown-menu").removeClass("show");
                }
            ),
        jQuery("#rev_slider_1")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [560, 500, 450, 350],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 5 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_2")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_3")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullscreen",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_4")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        r(".cart-dropdown a").on("click", function () {
            r(".cart-dropdown a .icon-small").toggleClass("d-none");
        }),
        r("body").on("click", function () {
            r(".cart-dropdown").hasClass("show") && (r(".shopping-icon").removeClass("d-none"), r(".close-icon").addClass("d-none"));
        }),
        r("#brands").owlCarousel({ loop: !0, margin: 30, autoplay: !0, autoplayTimeout: !(function (r) {
    "use strict";
    r(window).on("load", function () {
        r("#preloader").fadeOut(1e3);
    }),
        r(window).on("load", function () {
            var t = r(".header"),
                a = t.find(".navbar"),
                o = 0,
                s = r(".navbar-sticky");
            r(window).scroll(function () {
                var e = r(this).scrollTop();
                o < e ? s.addClass("navbar-scrollUp") : s.removeClass("navbar-scrollUp"),
                    (o = e),
                    a.hasClass("navbar-sticky") && (r(this).scrollTop() <= 600 || r(this).width() <= 300)
                        ? (a.removeClass("navbar-scrollUp"), a.removeClass("navbar-sticky").appendTo(t), t.css("height", "auto"))
                        : !a.hasClass("navbar-sticky") &&
                          300 < r(this).width() &&
                          600 < r(this).scrollTop() &&
                          (t.css("height", t.height()), a.addClass("navbar-scrollUp"), a.css({ opacity: "0" }).addClass("navbar-sticky"), a.appendTo(r("body")).animate({ opacity: 1 }));
            }),
                r(window).trigger("resize"),
                r(window).trigger("scroll");
        }),
        991 < r(window).width() &&
            r(".navbar-expand-lg .navbar-nav .dropdown").hover(
                function () {
                    r(this).addClass("").find(".dropdown-menu").addClass("show");
                },
                function () {
                    r(this).find(".dropdown-menu").removeClass("show");
                }
            ),
        767 < r(window).width() &&
            r(".navbar-expand-md .navbar-nav .dropdown").hover(
                function () {
                    r(this).addClass("").find(".dropdown-menu").addClass("show");
                },
                function () {
                    r(this).find(".dropdown-menu").removeClass("show");
                }
            ),
        jQuery("#rev_slider_1")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [560, 500, 450, 350],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 5 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_2")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_3")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullscreen",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        jQuery("#rev_slider_custom_4")
            .show()
            .revolution({
                delay: 5e3,
                sliderLayout: "fullwidth",
                sliderType: "standard",
                responsiveLevels: [1171, 1025, 769, 480],
                gridwidth: [1171, 1025, 769, 480],
                gridheight: [655, 605, 555, 450],
                navigation: { arrows: { enable: !0, style: "hesperiden", hide_onleave: !1 }, bullets: { enable: !1, style: "hesperiden", hide_onleave: !1, h_align: "center", v_align: "bottom", h_offset: 0, v_offset: 20, space: 15 } },
                disableProgressBar: "on",
            }),
        r(".cart-dropdown a").on("click", function () {
            r(".cart-dropdown a .icon-small").toggleClass("d-none");
        }),
        r("body").on("click", function () {
            r(".cart-dropdown").hasClass("show") && (r(".shopping-icon").removeClass("d-none"), r(".close-icon").addClass("d-none"));
        }),
        r("#brands").owlCarousel({ loop: !0, margin: 30, autoplay: !0, autoplayTimeout: 3e3, nav: !1, dots: !1, responsiveClass: !0, responsive: { 0: { items: 1 }, 768: { items: 3 }, 992: { items: 5 } } }),
        r("#testimonial").owlCarousel({ loop: !0, margin: 30, dots: !1, nav: !0, navText: ['<i class="fa fa-arrow-left"></i>', '<i class="fa fa fa-arrow-right"></i>'], items: 1 }),
        r(".categories-slider").owlCarousel({ margin: 20, loop: !0, autoplay: !1, nav: !0, navText: ['<i class="fa fa-arrow-left"></i>', '<i class="fa fa fa-arrow-right"></i>'], dots: !1, autoplayTimeout: 1e3, items: 1, center: !0 }),
        r(".team-slider").owlCarousel({
            loop: !0,
            margin: 30,
            dots: !1,
            nav: !0,
            navText: ['<i class="fa fa-arrow-left"></i>', '<i class="fa fa fa-arrow-right"></i>'],
            responsive: { 0: { items: 1 }, 600: { items: 3 }, 1e3: { items: 4 } },
        }),
        r(document).ready(function () {
            r(window).scroll(function () {
                100 < r(this).scrollTop() ? r("#back-to-top").css("opacity", 1) : r("#back-to-top").css("opacity", 0);
            });
        });
    var t = r(".grid").imagesLoaded(function () {
            t.isotope({ itemSelector: ".element-item", layoutMode: "fitRows" });
        }),
        a = {
            numberGreaterThan50: function () {
                var e = r(this).find(".number").text();
                return 50 < parseInt(e, 10);
            },
            ium: function () {
                return r(this).find(".name").text().match(/ium$/);
            },
        };
    r("#filters").on("click", "button", function () {
        var e = r(this).attr("data-filter");
        (e = a[e] || e), t.isotope({ filter: e });
    }),
        r("#sorts").on("click", "button", function () {
            var e = r(this).attr("data-sort-by");
            t.isotope({ sortBy: e });
        }),
        r(".button-group").each(function (e, t) {
            var a = r(t);
            a.on("click", "button", function () {
                a.find(".is-checked").removeClass("is-checked"), r(this).addClass("is-checked");
            });
        }),
        r(".video-box i").on("click", function () {
            var e = '<iframe class="embed-responsive-item"  allowfullscreen src="' + r(this).attr("data-video") + '"></iframe>';
            r(this).replaceWith(e);
        }),
        r(".select2-select").select2({ minimumResultsForSearch: -1 }),
        r(".box-video").click(function () {
            (r("iframe", this)[0].src += "&amp;autoplay=1"), r(this).addClass("open");
        }),
        r("#courseTimer").syotimer({ year: 2019, month: 11, day: 9, hour: 20, minute: 30 });
    var o = r("#counter");
    if (o.length) {
        var s = 0;
        r(window).scroll(function () {
            var e = o.offset().top - window.innerHeight;
            0 === s &&
                r(window).scrollTop() > e &&
                (r(".counter-value").each(function () {
                    var e = r(this),
                        t = e.attr("data-count");
                    r({ countNum: e.text() }).animate(
                        { countNum: t },
                        {
                            duration: 5e3,
                            easing: "swing",
                            step: function () {
                                e.text(Math.floor(this.countNum));
                            },
                            complete: function () {
                                e.text(this.countNum);
                            },
                        }
                    );
                }),
                (s = 1));
        });
    }
    r(window).scroll(function () {
        100 < r(this).scrollTop() ? r(".scrollup").fadeIn() : r(".scrollup").fadeOut();
    }),
        r(".scrollup").click(function () {
            return r("html, body").animate({ scrollTop: 0 }, 500), !1;
        }),
        r(window).scroll(function () {
            400 < r(this).scrollTop() ? r(".element-right-sidebar").addClass("sidebar-fixed") : r(".element-right-sidebar").removeClass("sidebar-fixed"),
                r(window).scrollTop() + r(window).height() > r(document).height() - 590
                    ? r(".element-right-sidebar").addClass("right-sidebar-absolute").removeClass("sidebar-fixed")
                    : r(".element-right-sidebar").removeClass("right-sidebar-absolute");
        }),
        r("#map").length &&
            google.maps.event.addDomListener(window, "load", function () {
                var e = {
                        zoom: 14,
                        scrollwheel: !1,
                        center: new google.maps.LatLng(53.385873, -1.471471),
                        styles: [
                            { featureType: "landscape", stylers: [{ color: "#eeddee" }] },
                            { featureType: "natural", stylers: [{ hue: "#ff0000" }] },
                            { featureType: "road", stylers: [{ hue: "#5500aa" }, { saturation: -70 }] },
                            { featureType: "building", elementType: "labels", stylers: [{ hue: "#000066" }] },
                            { featureType: "poi", stylers: [{ hue: "#0044ff" }] },
                        ],
                    },
                    t = new google.maps.Map(document.getElementById("map"), e);
                new google.maps.Marker({ position: { lat: 53.385873, lng: -1.471471 }, map: t, icon: "assets/img/marker.png" });
            });
    var l = r(".animated"),
        d = r(window);
    d.on("scroll resize", function () {
        var e = d.height(),
            i = d.scrollTop(),
            n = i + e;
        r.each(l, function () {
            var e = r(this),
                t = e.outerHeight(),
                a = e.offset().top,
                o = a + t,
                s = r(this).attr("data-animation");
            i <= o && a <= n ? e.addClass(s) : e.removeClass(s);
        });
    }),
        d.trigger("scroll"),
        r(".incr-btn").on("click", function (e) {
            var t,
                a = r(this),
                o = a.parent().find(".quantity").val();
            a.parent().find('.incr-btn[data-action="decrease"]').removeClass("inactive"),
                "increase" === a.data("action") ? (t = parseFloat(o) + 1) : 1 < o ? (t = parseFloat(o) - 1) : ((t = 1), a.addClass("inactive")),
                a.parent().find(".quantity").val(t),
                e.preventDefault();
        }),
        r('[data-toggle="tooltip"]').tooltip(),
        r('.scrolling  a[href*="#"]').on("click", function (e) {
            e.preventDefault(), e.stopPropagation();
            var t = r(this).attr("href");
            function a(e) {
                r(t).velocity("scroll", { duration: 800, offset: e, easing: "easeOutExpo", mobileHA: !1 });
            }
            r("#body").hasClass("up-scroll") || r("#body").hasClass("static") ? a(2) : a(-90);
        });
    var e = document.getElementById("slider-non-linear-step");
    e && noUiSlider.create(e, { connect: !0, start: [125, 750], range: { min: [0], max: [1e3] } });
    var i = [document.getElementById("lower-value"), document.getElementById("upper-value")];
    document.getElementById("price-range") &&
        e.noUiSlider.on("update", function (e, t) {
            i[t].innerHTML = "$" + Math.floor(e[t]);
        }),
        new WOW().init();
    var n = n || [];
    n.push(["_setAccount", "UA-71155940-5"]),
        n.push(["_trackPageview"]),
        (function () {
            var e = document.createElement("script");
            (e.type = "text/javascript"), (e.async = !0), (e.src = ("https:" == document.location.protocol ? "https://ssl" : "http://www") + ".google-analytics.com/ga.js");
            var t = document.getElementsByTagName("script")[0];
            t.parentNode.insertBefore(e, t);
        })();
})(jQuery);
