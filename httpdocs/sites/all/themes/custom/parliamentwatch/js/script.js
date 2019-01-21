/**
 * @file
 * Provides behaviors for the parliamentwatch theme.
 */

(function ($) {

  "use strict";

  var windowWidth = window.innerWidth,
    windowHeight = window.outerHeight,

    breakpointXsMin = 480,
    breakpointXsMax = breakpointXsMin - 1,

    breakpointSMin = 768,
    breakpointSMax = breakpointSMin - 1,

    breakpointMMin = 992,
    breakpointMMax = breakpointMMin - 1,

    breakpointLMin = 1280,
    breakpointLMax = breakpointLMin - 1,

    beige = '#f3efe6',
    orange = '#f26a3b';

  var iterateTime = 200;
  var isIE11 = !!navigator.userAgent.match(/Trident.*rv\:11\./);

  /**
   * Calls given function after wait milliseconds.
   *
   * @param {Function} func
   *   The function to be debounced.
   * @param {String} wait
   *   The time in milliseconds to wait before the function is executed.
   * @param {Bool} immediate
   *   Indicates whether the function should be executed immediately.
   *
   * @see https://davidwalsh.name/javascript-debounce-function
   */
  function debounce(func, wait, immediate) {
    var timeout;
    return function () {
      var context = this;
      var args = arguments;
      var later = function () {
        timeout = null;
        if (!immediate) {
          func.apply(context, args);
        }
      };
      var callNow = immediate && !timeout;
      clearTimeout(timeout);
      timeout = setTimeout(later, wait);
      if (callNow) {
        func.apply(context, args);
      }
    };
  };

  /**
   * Adds class to html-tag for styling purpose
   */
  function docReadyClass() {
    $('html').addClass('docready');
  }

  /**
   * Adds loading animation to the given element.
   *
   * @param {jQuery} $element
   *   jQuery object containing the element.
   */
  function addLoadingAnimation($element) {
    $element.addClass('loading-overlay--active').append('<div class="loading-overlay__loader"><svg viewBox="0 0 65 65"> <g id="Page-1" stroke="none" stroke-width="1" fill="none" fill-rule="evenodd"> <g id="05_filter-textsuche" transform="translate(-744.000000, -698.000000)"> <g id="Loader" transform="translate(744.000000, 698.000000)"> <g id="Group-2"> <circle id="Oval" fill="none" cx="32.5" cy="32.5" r="32.5"></circle> <g id="Group" transform="translate(28.000000, 36.500000) scale(-1, -1) translate(-28.000000, -36.500000) translate(4.000000, 12.000000)" fill="#FFFFFF"> <path d="M35.0628019,13.4372093 C31.5458937,9.66976744 26.8985507,7.28372093 22,6.78139535 L22.3768116,0 C29.1594203,0.753488372 35.4396135,3.76744186 40.0869565,8.66511628 C44.8599034,13.6883721 47.6231884,19.9674419 48,27 L41.0917874,27 C40.7149758,22.1023256 38.5797101,17.2046512 35.0628019,13.4372093 Z M19.9055118,0 L19.6535433,6.875 C13.984252,6.875 8.69291339,9.125 4.66141732,13 L0,8 C5.29133858,2.75 12.3464567,0 19.9055118,0 C20.0314961,0 20.0314961,0 19.9055118,0 Z M34,44.1807229 C35.7906977,42.7349398 37.1976744,40.8072289 38.2209302,39 L45,41.0481928 C43.4651163,43.939759 41.2906977,46.7108434 38.7325581,49 L34,44.1807229 Z M46.3030303,38 L40,35.9701493 C40.8484848,34.1791045 41.2121212,32.1492537 41.3333333,30 L48,30 C47.8787879,32.8656716 47.3939394,35.6119403 46.3030303,38 Z" id="Combined-Shape"></path> </g> <g id="Group" transform="translate(13.000000, 4.000000)" fill="#FF6C36"> <path d="M35.0628019,13.4372093 C31.5458937,9.66976744 26.8985507,7.28372093 22,6.78139535 L22.3768116,0 C29.1594203,0.753488372 35.4396135,3.76744186 40.0869565,8.66511628 C44.8599034,13.6883721 47.6231884,19.9674419 48,27 L41.0917874,27 C40.7149758,22.1023256 38.5797101,17.2046512 35.0628019,13.4372093 Z M19.9055118,0 L19.6535433,6.875 C13.984252,6.875 8.69291339,9.125 4.66141732,13 L0,8 C5.29133858,2.75 12.3464567,0 19.9055118,0 C20.0314961,0 20.0314961,0 19.9055118,0 Z M34,44.1807229 C35.7906977,42.7349398 37.1976744,40.8072289 38.2209302,39 L45,41.0481928 C43.4651163,43.939759 41.2906977,46.7108434 38.7325581,49 L34,44.1807229 Z M46.3030303,38 L40,35.9701493 C40.8484848,34.1791045 41.2121212,32.1492537 41.3333333,30 L48,30 C47.8787879,32.8656716 47.3939394,35.6119403 46.3030303,38 Z" id="Combined-Shape"></path> </g> </g> </g> </g> </g> </svg> <svg viewBox="0 0 65 65"> <g id="Page-1" stroke="none" stroke-width="1" fill="none" fill-rule="evenodd"> <g id="05_filter-textsuche" transform="translate(-744.000000, -698.000000)"> <g id="Loader" transform="translate(744.000000, 698.000000)"> <g id="Group-4"> <circle id="Oval" fill="none" cx="32.5" cy="32.5" r="32.5"></circle> <g id="Group" transform="translate(29.000000, 34.000000) scale(-1, -1) translate(-29.000000, -34.000000) translate(13.000000, 18.000000)" fill="#FFFFFF"> <path d="M23,12.68 L28.2173913,8 C30.4347826,10.64 31.6086957,13.64 32,17 L24.826087,17 C24.4347826,15.44 23.9130435,14 23,12.68 Z M24.2926829,20 L31,20 C30.7560976,24.5 28.6829268,28.875 25.5121951,32 L21,27 C22.8292683,25.125 24.0487805,22.625 24.2926829,20 Z M0,5.125 C3.38,1.875 8.06,0 13,0 L12.61,6.875 C9.62,7 7.02,8.125 4.81,10 L0,5.125 Z M21.0116279,10 C19.3488372,8.48101266 17.1744186,7.34177215 15,6.96202532 L15.3837209,0 C19.3488372,0.506329114 23.0581395,2.40506329 26,5.18987342 L21.0116279,10 Z" id="Combined-Shape"></path> </g> <g id="Group" transform="translate(19.000000, 14.000000)" fill="#FF6C36"> <path d="M23,12.68 L28.2173913,8 C30.4347826,10.64 31.6086957,13.64 32,17 L24.826087,17 C24.4347826,15.44 23.9130435,14 23,12.68 Z M24.2926829,20 L31,20 C30.7560976,24.5 28.6829268,28.875 25.5121951,32 L21,27 C22.8292683,25.125 24.0487805,22.625 24.2926829,20 Z M0,5.125 C3.38,1.875 8.06,0 13,0 L12.61,6.875 C9.62,7 7.02,8.125 4.81,10 L0,5.125 Z M21.0116279,10 C19.3488372,8.48101266 17.1744186,7.34177215 15,6.96202532 L15.3837209,0 C19.3488372,0.506329114 23.0581395,2.40506329 26,5.18987342 L21.0116279,10 Z" id="Combined-Shape"></path> </g> </g> </g> </g> </g> </svg></div>')
  }

  /**
   * Removes loading animation from the given element.
   *
   * @param {jQuery} $element
   *   jQuery object containing the element.
   */
  function removeLoadingAnimation($element) {
    $element.removeClass('loading-overlay--active');
  }

  /**
   * Maps vote statistics to format expected by D3.
   *
   * @param {Object} votes
   *   Vote statistics to map to D3 data.
   *
   * @returns {Array}
   *   Vote statistics ready for D3.
   */
  function mapVotes(votes) {
    var map = {
      'yes': { name: Drupal.t('Voted yes'), color: '#9fd773', vote_id: 19667 },
      'no': { name: Drupal.t('Voted no'), color: '#cc6c5b', vote_id: 19668 },
      'abstain': { name: Drupal.t('Abstained'), color: '#e2e2e2', vote_id: 19669 },
      'no-show': { name: Drupal.t('Did not vote'), color: '#a6a6a6', vote_id: 19670 }
    };

    var data = [];

    for (var key in votes) {
      map[key].count = votes[key];
      data.push(map[key]);
    }

    return data;
  }

  /**
   * Deletes the long time Matomo cookies (_pk_id and _pk_rev).
   *
   * Using Matomo's deleteCookie does not work because it cannot figure out the
   * correct domain when cookies are already disabled.
   */
  (function deleteMatomoCookies(domain) {
    var cookieDomain = '.' + domain;
    var options = {path: '/', domain: cookieDomain};
    var cookies = ['_pk_id', '_pk_ref'];

    for (var i = 0; i < cookies.length; i++) {
      var name = '';

      if (cookieDomain === '.stage.abgeordnetenwatch.de') {
        name = cookies[i] + '.1.a126';
      }
      else if (cookieDomain === '.abgeordnetenwatch.de') {
        name = cookies[i] + '.1.4157';
      }

      if ($.cookie(name, options) !== undefined) {
        $.cookie(name, null, options);
      }
    }
  })(document.domain);

  /**
   * Returns dialogue statistics ready for D3.
   *
   * @returns {Array}
   *   Dialogue statistics ready for D3.
   */
  Drupal.parseDialogues = function () {
    var data = [];

    for (var key in window.dialogues) {
      data.push({'name': key, 'value': window.dialogues[key]});
    }

    return data;
  };

  /**
   * Returns vote statistics suitable for D3.
   *
   * @returns {Array}
   *   Vote statistics ready for D3.
   */
  Drupal.parseVotes = function () {
    var data = {'yes': 0, 'no': 0, 'abstain': 0, 'no-show': 0};

    window.votes.forEach(function (v) {
      data[v.vote]++;
    });

    return mapVotes(data);
  };

  /**
   * Returns votes statistics by party ready for D3.
   *
   * @param {Array}
   *   Vote details.
   *
   * @returns {Object}
   *   Vote statistics by party ready for D3.
   */
  Drupal.parseResultsByFaction = function (votes) {
    var data = {};
    var count = {};
    var factions = votes.reduce(function (accumulator, currentValue) {
      if (accumulator.indexOf(currentValue['politician_political_faction']) > -1) {
        return accumulator;
      } else {
        return accumulator.concat([currentValue['politician_political_faction']]);
      }
    }, []);

    factions.forEach(function (item) {
      count[item] = {'yes': 0, 'no': 0, 'abstain': 0, 'no-show': 0};
    });

    votes.forEach(function (item) {
      switch (item['field_vote']) {
        case 19667:
          count[item['politician_political_faction']]['yes']++;
          break;
        case 19668:
          count[item['politician_political_faction']]['no']++;
          break;
        case 19669:
          count[item['politician_political_faction']]['abstain']++;
          break;
        case 19670:
          count[item['politician_political_faction']]['no-show']++;
          break;
      }
    });

    factions.forEach(function (item) {
      data[item] = mapVotes(count[item]);
    });

    return data;
  };

  /**
   * Returns vote statistics suitable for D3.
   *
   * @param {Array}
   *   Number of votes by category.
   *
   * @returns {Array}
   *   Vote statistics ready for D3.
   */
  Drupal.parseResultsTotal = function (voteCount) {
    var data = {'yes': 0, 'no': 0, 'abstain': 0, 'no-show': 0};

    voteCount.forEach(function (item) {
      switch (item.filter) {
        case '"19667"':
          data['yes'] = item.count;
          break;
        case '"19668"':
          data['no'] = item.count;
          break;
        case '"19669"':
          data['abstain'] = item.count;
          break;
        case '"19670"':
          data['no-show'] = item.count;
          break;
      }
    });

    return mapVotes(data);
  };

  Drupal.dynatable = {
    PaginationLinks: function (obj, settings) {
      return {
        create: function () {
          var pageLinks = '<ul id="' + 'dynatable-pagination-links-' + obj.element.id + '" class="' + settings.inputs.paginationClass + '">',
            pageLinkClass = settings.inputs.paginationLinkClass,
            activePageClass = settings.inputs.paginationActiveClass,
            disabledPageClass = settings.inputs.paginationDisabledClass,
            pages = Math.ceil(settings.dataset.queryRecordCount / settings.dataset.perPage),
            page = settings.dataset.page,
            breaks = [
              settings.inputs.paginationGap[0],
              settings.dataset.page - settings.inputs.paginationGap[1],
              settings.dataset.page + settings.inputs.paginationGap[2],
              (pages + 1) - settings.inputs.paginationGap[3]
            ];

          for (var i = 1; i <= pages; i++) {
            if ((i > breaks[0] && i < breaks[1]) || (i > breaks[2] && i < breaks[3])) {
              // skip to next iteration in loop
              continue;
            } else {
              var li = obj.paginationLinks.buildLink(i, i, pageLinkClass, page == i, activePageClass),
                breakIndex,
                nextBreak;

              // If i is not between one of the following
              // (1 + (settings.paginationGap[0]))
              // (page - settings.paginationGap[1])
              // (page + settings.paginationGap[2])
              // (pages - settings.paginationGap[3])
              breakIndex = $.inArray(i, breaks);
              nextBreak = breaks[breakIndex + 1];
              if (breakIndex > 0 && i !== 1 && nextBreak && nextBreak > (i + 1)) {
                var ellip = '<li class="pager__item pager__item--ellipsis">&hellip;</li>';
                li = breakIndex < 2 ? ellip + li : li + ellip;
              }

              if (settings.inputs.paginationPrev && i === 1 && page !== 1) {
                var firstLi = obj.paginationLinks.buildLink(1, settings.inputs.paginationPrev, pageLinkClass + ' ' + settings.inputs.paginationFirstClass, page === 1, disabledPageClass);
                var prevLi = obj.paginationLinks.buildLink(page - 1, settings.inputs.paginationPrev, pageLinkClass + ' ' + settings.inputs.paginationPrevClass, page === 1, disabledPageClass);
                li = firstLi + prevLi + li;
              }
              if (settings.inputs.paginationNext && i === pages && page !== pages) {
                var nextLi = obj.paginationLinks.buildLink(page + 1, settings.inputs.paginationNext, pageLinkClass + ' ' + settings.inputs.paginationNextClass, page === pages, disabledPageClass);
                var lastLi = obj.paginationLinks.buildLink(pages, settings.inputs.paginationNext, pageLinkClass + ' ' + settings.inputs.paginationLastClass, page === pages, disabledPageClass);
                li += nextLi + lastLi;
              }

              pageLinks += li;
            }
          }

          pageLinks += '</ul>';

          // only bind page handler to non-active and non-disabled page links
          var selector = '#dynatable-pagination-links-' + obj.element.id + ' .' + pageLinkClass + ':not(.' + activePageClass + ',.' + disabledPageClass + ') > a';
          // kill any existing delegated-bindings so they don't stack up
          $(document).undelegate(selector, 'click.dynatable');
          $(document).delegate(selector, 'click.dynatable', function (e) {
            var $this = $(this);
            $this.closest(settings.inputs.paginationClass).find('.' + activePageClass).removeClass(activePageClass);
            $this.addClass(activePageClass);

            obj.paginationPage.set($this.data('dynatable-page'));
            obj.process();
            e.preventDefault();
          });

          return pageLinks;
        },
        buildLink: function (page, label, linkClass, conditional, conditionalClass) {
          var link = '<a data-dynatable-page="' + page + '"',
            li = '<li class="' + linkClass;

          if (conditional) {
            li += ' ' + conditionalClass;
          }

          link += '">' + label + '</a>';
          li += '">' + link + '</li>';

          return li;
        }
      }
    },
    Sorts: function (obj, settings) {
      return {
        functions: {
          string: function (a, b, attr, direction) {
            var aAttr = (a['dynatable-sortable-text'] && a['dynatable-sortable-text'][attr]) ? a['dynatable-sortable-text'][attr] : a[attr];
            var bAttr = (b['dynatable-sortable-text'] && b['dynatable-sortable-text'][attr]) ? b['dynatable-sortable-text'][attr] : b[attr];
            var comparison = aAttr.toLocaleLowerCase().localeCompare(bAttr.toLocaleLowerCase(), 'de');
            return direction > 0 ? comparison : -comparison;
          }
        }
      }
    },
    SortsHeaders: function (obj, settings) {
      return {
        appendArrowUp: function ($link) {
          this.removeArrow($link);
          $link.append('<i class="dynatable-arrow icon icon-arrow-up"></i>');
        },

        appendArrowDown: function ($link) {
          this.removeArrow($link);
          $link.append('<i class="dynatable-arrow icon icon-arrow-down"></i>');
        },

        toggleSort: function (e, $link, column) {
          var sortedByColumn = this.sortedByColumn($link, column),
            value = this.sortedByColumnValue(column);
          // Clear existing sorts unless this is a multisort event
          if (!settings.inputs.multisort || !obj.utility.anyMatch(e, settings.inputs.multisort, function (evt, key) {
              return e[key];
            })) {
            this.removeAllArrows();
            obj.sorts.clear();
          }

          // If sorts for this column are already set
          if (sortedByColumn) {
            // If ascending, then make descending
            if (value == 1) {
              for (var i = 0, len = column.sorts.length; i < len; i++) {
                obj.sorts.add(column.sorts[i], -1);
              }
              this.appendArrowDown($link);
              // If descending, then make ascending
            } else {
              for (var i = 0, len = column.sorts.length; i < len; i++) {
                obj.sorts.add(column.sorts[i], 1);
              }
              this.appendArrowUp($link);
            }
            // Otherwise, if not already set, set to ascending
          } else {
            for (var i = 0, len = column.sorts.length; i < len; i++) {
              obj.sorts.add(column.sorts[i], 1);
            }
            this.appendArrowUp($link);
          }
        }
      }
    }
  };

  /**
   * Attaches the main navigation behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   *   Converts the main navigation to a swiper.
   */
  Drupal.behaviors.mainNavigation = {
    attach: function () {
      var activeMenuItem = $('.header__bottom__inner .nav__item.nav__item--active').index();

      /* 2nd-Navigation level with optional swiper integration */
      var secondLevel = $('.header__bottom nav');
      secondLevel.append('<div class="swiper-button-prev"></div><div class="swiper-button-next"></div>');

      var mainNavSwiper = new Swiper('.header__bottom nav', {
        slideClass: 'nav__item',
        wrapperClass: 'nav',
        speed: 400,
        slidesPerView: 'auto',
        resistance: true,
        resistanceRatio: 0.5,
        nextButton: secondLevel.find('.swiper-button-next'),
        prevButton: secondLevel.find('.swiper-button-prev'),
        onInit: function (swiper) {
          resizeMainNavigation();
          swiper.update();
          swiper.slideTo(activeMenuItem);
        }
      });

      function resizeMainNavigation() {
        var secondLevel = $('.header__bottom nav');
        if ($('.header__subnav__indicator').length > 0) {
          var indicator = $('.header__subnav__indicator');
        } else {
          var indicator = $('.header__subnav__archive');
        }

        var subnavOffset = indicator.outerWidth() + 1;
        var wrapperPadding = parseInt($('.header__bottom__inner').css('padding-left'), 10);
        var indicatorPadding = parseInt(indicator.css('padding-left'), 10);

        if (wrapperPadding > 0) {
          var subnavOffsetValue = subnavOffset - indicatorPadding;
        } else {
          var subnavOffsetValue = subnavOffset;
        }
      }

      var windowResize = debounce(function () {
        resizeMainNavigation();
      }, 150);

      // Event-Listener
      window.addEventListener('resize', windowResize);
    }
  };

  /**
   * Attaches the feature hint behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   *   Triggers the Sidebar.
   */

  Drupal.behaviors.featureHint = {
    attach: function (context) {

      $('[data-feature-hint-content]').each(function( index ) {

        var hintID = $(this).attr('data-feature-hint-id');
        var hintContent = $(this).attr('data-feature-hint-content');

        if (!$.cookie('featureHint-'+ hintID)) {

          // add hint (initially hidden)
          $('<div class="feature-hint"><p>' + hintContent + '</p><i class="icon icon-close"></i></div>').insertAfter($(this));

          // show hint
          setTimeout(function () {
            $('.feature-hint').addClass('feature-hint--in');
          }, 200);
          // close hint
          $('.feature-hint .icon-close').click(function () {
            $('.feature-hint').removeClass('feature-hint--in');
            $.cookie('featureHint-'+ hintID, 1, {expires: 100, path: '/' });
          });
        }
      });
    }
  };

  /**
   * Attaches the mobile navigation-trigger behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   *   Triggers the Sidebar.
   */

  Drupal.behaviors.mainNavigationTrigger = {
    attach: function (context) {
      $('[data-sidebar-trigger]', context).once('mainNavigationTrigger', function () {
        $('[data-sidebar-trigger]').click(function () {
          $(this).toggleClass('lines-button-close');
          $('[data-sidebar-container]').parent('body').toggleClass('sidebar-open');
        });
      });
    }
  };

  /**
   * Attaches the dropdown behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.dropdown = {
    attach: function (context, settings) {
      $(window).click(function () {
        $('.dropdown__list--open').removeClass('dropdown__list--open');
      });

      $('.dropdown .dropdown__trigger').click(function (event) {
        var dropdownTrigger = $(this);
        var dropdown = dropdownTrigger.parent('.dropdown');

        event.preventDefault();

        if (dropdown.parents('.filterbar')) {
          dropdownTrigger.addClass('dropdown__trigger--active');
          if (dropdown.hasClass('dropdown--open')) {
            dropdown.removeClass('dropdown--open');
          } else {
            $('.filterbar').find('.dropdown').removeClass('dropdown--open');
            dropdown.addClass('dropdown--open');
          }
        }
      });
    }
  };

  /**
   * Attaches the dropdown hover behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.dropdownHover = {
    attach: function () {
      function dropdownOpen() {
        $(this).find('.dropdown__trigger').addClass('dropdown__trigger--active');
        $(this).addClass('dropdown--open');
      }

      function dropdownClose() {
        $(this).find('.dropdown__trigger').removeClass('dropdown__trigger--active');
        $(this).removeClass('dropdown--open');
      }

      $(".dropdown--hover").hoverIntent({
        over: dropdownOpen,
        out: dropdownClose
      });
      $('.dropdown__text').click(function (event) {
        event.preventDefault();
      });
    }
  };

  /**
   * Attaches the local scroll behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.initLocalScroll = {
    attach: function (context) {
      $('[data-localScroll]', context).once('initLocalScroll', function () {
        $(this).on('click', function (event) {
          var hrefValue = $(this).attr('href');
          $(window).scrollTo($(hrefValue), 800);

          // trigger possible tab-elements

          if ($('.tabs__navigation').length) {
            $('.tabs__navigation a[href=' + hrefValue + ']').trigger('click');
          }

          if (hrefValue == '#question-form-anchor') {
            $('.tabs__navigation a[href="#block-pw-dialogues-profile"]').trigger('click');
          }

          event.preventDefault();
        });
      });
    }
  };

  /**
   * Attaches local scroll behavior on page load.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.initLocalScrollPageLoad = {
    attach: function (context) {
      function scrollToAnchor(hash) {
        var target = $(hash);

        target = target.length ? target : $('[name=' + hash.slice(1) +']');

        if (target.length) {
          $('html,body').animate({
            scrollTop: target.offset().top
          }, 100);
          return false;
        }
      }

      if(window.location.hash) {
        scrollToAnchor(window.location.hash);
      }
    }
  };

  /**
   * Attaches the tooltip behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.tooltip = {
    attach: function (context) {
      $('[data-tooltip-content]', context).once('tooltip', function () {
        $(this).hover(function () {
          var tooltipContent = $(this).attr('data-tooltip-content'),
              tooltipPlacement = $(this).attr('data-tooltip-placement');
          $(this).append('<div class="tooltip tooltip--' + tooltipPlacement + '">' + tooltipContent + '</div>');
        }, function () {
          $(this).find('.tooltip').remove();
        });
      });
    }
  };

  function popover() {
    $('[data-popover-content]').toggle(function () {
      var tooltipContent = $(this).attr('data-popover-content'),
        tooltipPlacement = $(this).attr('data-popover-placement');
      $(this).append('<div class="tooltip tooltip--popover tooltip--' + tooltipPlacement + '">' + tooltipContent + '</div>');
      $('.tooltip--popover a').click(function (event) {
        event.stopImmediatePropagation();
      });
    }, function () {
      $(this).find('.tooltip').remove();
    });
  }

  /**
   * Attaches the popover behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.popover = {
    attach: function (context) {
      popover();
    }
  };

  /**
   * Attaches the figcaption-overlay behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.figcaptionOverlay = {
    attach: function (context) {
      $('.figcaption-overlay-trigger', context).once('figcaptionOverlay', function () {
        $(this).hover(function () {
          $(this).parents('.tile').find('.figcaption-overlay').toggleClass('figcaption-overlay--open');
        });
      });
    }
  };

  /**
   * Attaches the newsletter widget behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.newsletterWidget = {
    attach: function (context) {
      $('#newsletter-widget', context).once('newsletterWidget', function () {
        $(this).submit(function (event) {
          var inputValue = $('#newsletter-widget-mail').val();
          //var data = new FormData(document.getElementById('newsletter_form'));
          var xhr = new XMLHttpRequest();
          document.getElementById('newsletter-widget').setAttribute('class', 'form loading');
          document.getElementById('newsletter-widget-button').disabled = true;

          xhr.open('GET', '//www.abgeordnetenwatch.de/newsletter/subscribe?email=' + inputValue, true);
          xhr.onload = function () {
            // do something to response
            var newsletter_message = document.getElementById('newsletter-widget-message');
            newsletter_message.setAttribute('class', 'form__item form__item--alert');

            if (this.responseText == "success") {
              newsletter_message.innerHTML = "Anmeldung erfolgreich, sie erhalten eine Email mit Bestätigungslink.";
              newsletter_message.setAttribute('class', 'form__item show form__item--alert form__item--alert-success');
              _paq.push(['trackGoal', 2]);
            }
            else if (this.responseText == "email_error") {
              newsletter_message.innerHTML = "Ihre Email-Adresse konnte nicht angemeldet werden.";
              newsletter_message.setAttribute('class', 'form__item show form__item--alert form__item--alert-danger');
            }
            else if (this.responseText == "please_confirm") {
              newsletter_message.innerHTML = "Bitte bestätigen Sie Ihre Anmeldung.";
              newsletter_message.setAttribute('class', 'form__item show form__item--alert form__item--alert-info');
            }
            else if (this.responseText == "already_in_list") {
              newsletter_message.innerHTML = "Sie erhalten bereits unseren Newsletter.";
              newsletter_message.setAttribute('class', 'form__item show form__item--alert form__item--alert-info');
            }
            document.getElementById('newsletter-widget').setAttribute('class', 'form');
            document.getElementById('newsletter-widget-button').disabled = false;
          };
          xhr.send();
          event.preventDefault();
        });
      });
    }
  };

  /**
   * Attaches the tabs behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.tabs = {
    attach: function (context) {
      $('.tabs', context).once('tabs', function () {
        $('.tabs__navigation a').on('click', function (event) {
          event.preventDefault();
          var link = $(this);
          var id = link[0].hash;

          // add hash-value of the clicked link-element to url
          if (history.pushState) {
            history.pushState(id, null, id);
          }
          // Set nav-item classes
          link.parents('.tabs').find('.nav__item').removeClass('nav__item--active');
          link.parent('.nav__item').addClass('nav__item--active');

          // Set tab-content classes
          link.parents('.tabs').find('.tabs__content').removeClass('tabs__content--active');
          $(id).addClass('tabs__content--active');

          Drupal.attachBehaviors(link.parents('.tabs').find('.swiper-container--tile'));
        });

        if (history.pushState) {
          $(window).on('popstate', function (event) {
            var hashValue = window.location.hash;

            if ($('.nav__item__link[href="' + hashValue + '"]').length > 0) {
              // Set nav-item classes
              $('.tabs').find('.nav__item').removeClass('nav__item--active');
              $('.nav__item__link[href="' + hashValue + '"]').parents('.nav__item').addClass('nav__item--active');

              // Set tab-content classes
              $('.tabs').find('.tabs__content').removeClass('tabs__content--active');
              $(hashValue).addClass('tabs__content--active');
            }
          });
        }

        // Set initial tab by checking url for hash
        if ($('.tabs__navigation').length && window.location.hash) {
          $('.tabs__navigation a[href="' + window.location.hash + '"]').trigger('click');
        }

        $('.tabs__content__content .pager__item a').each(function () {
          $(this).prop('hash', $(this).parents('.tabs__content').attr('id'));
        });
      });
    }
  };

  /**
   * Attaches the swiper tile behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.swiperTile = {
    attach: function () {
      $('.swiper-container--tile').each(function (index, element) {
        var $this = $(this);
        $this.swiper({
          slideClass: 'tile',
          loop: false,
          spaceBetween: 20,
          slidesPerView: 3,
          slidesPerGroup: 3,
          nextButton: $this.find('.swiper-button-next'),
          prevButton: $this.find('.swiper-button-prev'),
          breakpoints: {
            550: {
              slidesPerView: 1,
              slidesPerGroup: 1
            },
            768: {
              slidesPerView: 2,
              slidesPerGroup: 2
            },
            992: {
              slidesPerView: 2,
              slidesPerGroup: 2
            },
            1200: {
              slidesPerView: 3,
              slidesPerGroup: 3
            }
          },
          onInit: function (swiper) {
            $('.question__question').matchHeight();
            $('.question__answer').matchHeight();
            swiper.update();
          },
          onAfterResize: function (swiper) {
            $('.question__question').matchHeight();
            $('.question__answer').matchHeight();
            swiper.update();
          }
        });

      });
    }
  };

  /**
   * Attaches the select2 behavior to select elements.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.select2init = {
    attach: function (context) {
      $('select.form__item__control', context).once('select2init', function () {
        if ($(this).parents('.form--pw-profiles-street-form').length > 0) {
          $(this).select2({
            ajax: {
              url: $(this).data('ajaxUrl'),
              data: function (params) {
                var query = {
                  term: params.term,
                };
                return query;
              },
              dataType: 'json'
            },
            delay: 250,
            dropdownParent: $('.page-container'),
            language: {
              errorLoading: function () {
                return 'Die Ergebnisse konnten nicht geladen werden.';
              },
              loadingMore: function () {
                return 'Lade mehr Ergebnisse…';
              },
              maximumSelected: function (e) {
                var t = 'Sie können höchstens eine Straße auswählen';
                return e.maximum != 1 && (t = 'Sie können höchstens ' + e.maximum + ' Straßen auswählen'), t
              },
              searching: function () {
                return 'Suche…';
              }
            },
            maximumSelectionLength: 1,
            multiple: true
          });
        } else if ($(this).parents('.filterbar__secondary').length) {
          $(this).select2({
            minimumResultsForSearch: 20,
            placeholder: 'Bitte wählen',
            dropdownParent: $('.filterbar__secondary__inner')
          });
        } else {
          $(this).select2({
            minimumResultsForSearch: 20,
            placeholder: 'Bitte wählen',
            dropdownParent: $('.page-container')
          });
        }
        $(this).on('select2:open', function (e) {
          // close all dropdowns
          $('.dropdown__list').removeClass('dropdown__list--open');
        });
      });
    }
  };

  /**
   * Attaches the typeahead plugin to the politician search.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.politicianSearch = {
    attach: function (context) {
      $('.form--pw-globals-politician-search-form .form__item__control--autosuggest', context).once('autosuggest', function () {
        if ($(this).data('autosuggest-url')) {
          var politicianIndex = new Bloodhound({
            initialize: true,
            prefetch: {
              url: $(this).data('autosuggest-url'),
              cache: false,
            },
            identify: function (obj) {
              return obj.id;
            },
            queryTokenizer: Bloodhound.tokenizers.whitespace,
            datumTokenizer: Bloodhound.tokenizers.obj.whitespace('politicianDatum'),
          });

          var politicianTemplates = {
            suggestion: function (query) {
              return '' +
                '<div class="autosuggest__item">' +
                '<div class="autosuggest__item__image">' +
                '<img src="' + query.picture_url + '" alt="">' +
                '</div>' +
                '<div class="autosuggest__item__info">' +
                '<div class="autosuggest__item__name">' + query.name + '</div>' +
                '<div class="autosuggest__item__subtitle">' + query.parliament + ' <i class="icon icon-arrow-right"></i> <span class="party-indicator">' + query.party + '</span></div>' +
                '<div class="autosuggest__item__constituency">' + query.constituency + '</div>' +
                '</div>' +
                '<a href="' + query.url + '#block-pw-dialogues-profile" class="btn--small">' + Drupal.t('Ask') + '</a>' +
                '</div>';
            }
          };

          var politicianDisplay = function (obj) {
            return obj.name;
          };

          $('.form__item__control--autosuggest').typeahead({
            minLength: 2,
            highlight: true
          }, {
            name: 'politicians',
            source: politicianIndex,
            display: politicianDisplay,
            templates: politicianTemplates
          });
        }
      });
    }
  };

  /**
   * Attaches the deputy detail behavior to deputy detail views.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.viewDeputyDetail = {
    attach: function () {
      function viewDeputyDetail() {
        windowWidth = window.innerWidth;
        var caption = $('.deputy.detail .deputy__image figcaption');
        var captionContent = $('.deputy.detail .deputy__image figcaption span').html();

        if (windowWidth >= breakpointSMin) {
          $('.deputy__intro__sidebar header').prependTo('.deputy__intro__content');
          caption.removeClass().addClass('figcaption-overlay').find('span').removeClass();
          caption.removeAttr('data-popover-content');
        } else {
          $('.deputy__intro__content header').prependTo('.deputy__intro__sidebar');
          caption.removeClass().addClass('figcaption-ext').find('span').addClass('sr-only');
          caption.attr('data-popover-content', captionContent);
          popover();
        }

        /*
         * Implement select mechanism for changing the viewed profile (election period)
         */
        $('.deputy__intro select').on('select2:select', function (evt) {
          window.location.href = evt.currentTarget.value;
        });
      }

      viewDeputyDetail();

      var windowResize = debounce(function () {
        viewDeputyDetail();
      }, 150);

      // Event-Listener
      window.addEventListener('resize', windowResize);
    }
  };


  /**
   * Attaches the item expander behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.expander = {
    attach: function (context) {
      $('[data-expander]', context).once('expander', function () {
        var itemCount = $(this).data('expander-count');
        var items = $(this).find('[data-expander-item]');
        var lastShowedItem = $(this).find('[data-expander-item]:nth-child(' + itemCount + ')');
        var showButton = $('<a class="btn btn--small-white">' + Drupal.t('Show more') + '</a>');
        var hideButton = $('<a class="btn btn--small-white" style="display: none;">' + Drupal.t('Show less') + '</a>');


        // Add cta
        showButton.insertAfter(lastShowedItem).click(function () {
          // Show hidden elements
          items.each(function (index) {
            index++;
            if (index > itemCount) {
              $(this).show();
            }
          });
          $(this).hide();
          hideButton.show();
        });

        hideButton.appendTo($(this)).click(function () {
          // Hide hidden elements
          items.each(function (index) {
            index++;
            if (index > itemCount) {
              $(this).hide();
            }
          });
          $(this).hide();
          showButton.show();
        });

        // Hide all items after cta
        items.each(function (index) {
          index++;
          if (index > itemCount) {
            $(this).hide();
          }
        });
      });
    }
  };

  /**
   * Attaches the single vertical bar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.verticalBar = {
    attach: function (context) {
      $('.vertical-bar').each(function () {
        var value = $(this).data('value');
        $(this).find('span').css('width', value + '%');
      });
    }
  };


  /**
   * Attaches the D3 vertical bars behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3BarsVertical = {
    attach: function (context) {
      $('[data-d3-bars-vert]', context).once('d3BarsVertical', function () {
        var wrapper = $(this)[0];
        var width = 600;
        var height = wrapper.dataset.height;
        var data = Drupal[wrapper.getAttribute('data-data')]();

        var colours = {
          fill: '#' + wrapper.dataset.fillColour,
          stroke: '#' + wrapper.dataset.strokeColour
        }
        // set the ranges
        var x = d3.scaleBand().rangeRound([0, width], .05);
        var y = d3.scaleLinear().range([height, 0]);

        // setup SVG wrapper

        var svg = d3.select(wrapper)
          .append("svg:svg")
          .attr("class", "chart")
          .attr('viewBox', '0 0 ' + width + ' ' + height)
          .attr('preserveAspectRatio', 'xMidYMid meet');

        // load the data
        data.forEach(function (d) {
          d.name = d.name;
          d.value = +d.value;
        });

        // scale the range of the data
        x.domain(data.map(function (d) {
          return d.name;
        }));
        y.domain([0, d3.max(data, function (d) {
          return d.value;
        })]);

        // ADD Group container
        var g = svg.append('g');

        // ADD Bars
        g.selectAll("bar")
          .data(data)
          .enter().append("rect")
          .attr("class", "bar")
          .attr('fill', colours.fill)
          .attr("x", function (d) {
            return x(d.name);
          })
          .attr("width", x.bandwidth() * .5)
          .attr("y", function (d) {
            return y(d.value);
          })
          .attr("height", function (d) {
            return height - y(d.value);
          })
          .on("mouseover", function (d) {
            var tooltip = $(this).parents('.d3').find('.d3__tooltip');
            tooltip.css("opacity", 1);
            if (d.value == 1) {
              tooltip.html(d.name + ' <span>(' + d.value + ' Frage)</span>').css("left", (d3.event.offsetX) + "px").css("bottom", height - y(d.value) + "px");
            } else {
              tooltip.html(d.name + ' <span>(' + d.value + ' Fragen)</span>').css("left", (d3.event.offsetX) + "px").css("bottom", height - y(d.value) + "px");
            }
          })
          .on("mouseout", function (d) {
            var tooltip = $(this).parents('.d3').find('.d3__tooltip');
            tooltip.css("opacity", 0);
          });
      });
    }
  };

  /**
   * Attaches the D3 horizontal bar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3BarHorizontal = {
    attach: function (context) {
      $('[data-bar-horizontal]', context).once('d3BarHorizontal', function () {
        var wrapper = $(this)[0];
        var chartBar = $(this).find('.bar');

        var dataValue = wrapper.dataset.value;
        var dataValueMax = wrapper.dataset.value_max;

        var barWidth = 100 / dataValueMax * dataValue;
        var barWidth = barWidth + '%';

        setTimeout(function () {
          chartBar.attr('style', 'width:' + barWidth + ';');
        }, iterateTime);
        iterateTime += 400;
      });
    }
  };

  /**
   * Attaches the D3 donut behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3Donut = {
    attach: function (context) {
      $('[data-d3-donut]', context).once('d3Donut', function () {
        var wrapper = $(this)[0];
        var dataset = JSON.parse(wrapper.getAttribute('data-data'));

        var width = 360;
        var height = 360;
        var radius = Math.min(width, height) / 2;
        var donutWidth = 75;

        var svg = d3.select(wrapper)
          .append('svg')
          .attr('viewBox', '0 0 ' + width + ' ' + height)
          .attr('preserveAspectRatio', 'xMidYMid meet')
          .append('g')
          .attr('transform', 'translate(' + (width / 2) +
            ',' + (height / 2) + ')');

        var arc = d3.arc()
          .innerRadius(radius - donutWidth)
          .outerRadius(radius);

        var pie = d3.pie()
          .value(function (d) {
            return d.count;
          })
          .sort(null);

        var path = svg.selectAll('path')
          .data(pie(dataset))
          .enter()
          .append('path')
          .attr('d', arc)
          .attr("fill", function (d) {
            return d.data.color;
          });
      });
    }
  };

  /**
   * Attaches the D3 donut with labels behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3DonutLabels = {
    attach: function (context) {
      $('[data-d3-donut-labels]', context).once('d3DonutLabels', function () {
        var wrapper = $(this)[0];
        var dataset = Drupal[wrapper.getAttribute('data-data')]();

        var width = 360;
        var height = 360;
        var radius = Math.min(width, height) / 2;
        var donutWidth = 75;

        var svg = d3.select(wrapper)
          .append('svg')
          .attr('viewBox', '0 0 ' + width + ' ' + height)
          .attr('preserveAspectRatio', 'xMidYMid meet')
          .append('g')
          .attr('transform', 'translate(' + (width / 2) +
            ',' + (height / 2) + ')');

        var arc = d3.arc()
          .innerRadius(radius - donutWidth)
          .outerRadius(radius);

        var pie = d3.pie()
          .value(function (d) {
            return d.count;
          })
          .sort(null);

        var path = svg.selectAll('path')
          .data(pie(dataset))
          .enter()
          .append('path')
          .attr('d', arc)
          .attr("fill", function (d) {
            return d.data.color;
          });

        // Define Labels

        var labelWrapper = d3.select(wrapper)
          .append("ul")
          .attr('class', 'd3__label');

        var labelItem = labelWrapper.selectAll('li')
          .data(pie(dataset))
          .enter()
          .append('li')
          .attr('class', 'd3__label__item')
          .html(function (d) {
            return d.data.count + ' ' + d.data.name;
          })
          .insert("span", ":first-child")
          .attr('class', 'd3__label__item__indicator')
          .attr('style', function (d) {
            return 'background-color:' + d.data.color;
          });
      });
    }
  };

  /**
   * Attaches the D3 donut with icon behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3DonutIcon = {
    attach: function (context) {
      $('[data-d3-donut-icon]', context).once('d3DonutIcon', function () {
        var wrapper = $(this)[0];
        var dataset = JSON.parse(wrapper.getAttribute('data-data'));
        var voteResult = d3.max(dataset, function (d) {
          return d.count;
        })

        var width = 360;
        var height = 360;
        var radius = Math.min(width, height) / 2;
        var donutWidth = 75;

        var svg = d3.select(wrapper)
          .append('svg')
          .attr('viewBox', '0 0 ' + width + ' ' + height)
          .attr('preserveAspectRatio', 'xMidYMid meet')
          .append('g')
          .attr('transform', 'translate(' + (width / 2) +
            ',' + (height / 2) + ')');

        var arc = d3.arc()
          .innerRadius(radius - donutWidth)
          .outerRadius(radius);

        var pie = d3.pie()
          .value(function (d) {
            return d.count;
          })
          .sort(null);

        var path = svg.selectAll('path')
          .data(pie(dataset))
          .enter()
          .append('path')
          .attr('d', arc)
          .attr("fill", function (d) {
            return d.data.color;
          });

        // Define Icon

        var iconWrapper = d3.select(wrapper)
          .append("i")
          .attr("class", "icon");

        dataset.forEach(function (d) {
          if (d.count == voteResult) {
            if (d.name == 'Ja') {
              iconWrapper
                .attr("class", "icon icon-ok")
                .attr("style", "color:" + d.color + ";");
            }
            if (d.name == 'Nein') {
              iconWrapper
                .attr("class", "icon icon-close")
                .attr("style", "color:" + d.color + ";");
            }
            if (d.name == 'Nicht beteiligt') {
              iconWrapper
                .attr("class", "icon icon-minus")
                .attr("style", "color:" + d.color + ";");
            }
            if (d.name == 'Enthalten') {
              iconWrapper
                .attr("class", "icon icon-circle-o")
                .attr("style", "color:" + d.color + ";");
            }
          }
        });
      });
    }
  };


  /**
   * Attaches the D3 radial gauge behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3RadialGauge = {
    attach: function (context) {
      $('[data-d3-gauge]', context).once('d3RadialGauge', function () {
        var wrapper = $(this)[0];
        var start = 0;
        var end = parseFloat(wrapper.dataset.percentage);

        var colours = {
          fill: '#' + wrapper.dataset.fillColour,
          track: '#' + wrapper.dataset.trackColour,
          text: '#' + wrapper.dataset.textColour,
          stroke: '#' + wrapper.dataset.strokeColour,
        }

        var radius = 100;
        var border = wrapper.dataset.trackWidth;
        var strokeSpacing = wrapper.dataset.strokeSpacing;
        var endAngle = Math.PI * 2;
        var formatText = d3.format('.0%');
        var boxSize = radius * 2;
        var count = end;
        var progress = start;
        var step = end < start ? -0.01 : 0.01;

        //Add Class to Wrapper
        wrapper.className += " d3--executed";

        //Define the circle
        var circle = d3.arc()
          .startAngle(0)
          .innerRadius(radius)
          .outerRadius(radius - border);


        //setup SVG wrapper
        var svg = d3.select(wrapper)
          .append('svg')
          .attr('width', boxSize)
          .attr('height', boxSize)
          .attr('viewBox', '0 0 ' + boxSize + ' ' + boxSize)
          .attr('preserveAspectRatio', 'xMidYMid meet');

        // ADD Group container
        var g = svg.append('g')
          .attr('transform', 'translate(' + boxSize / 2 + ',' + boxSize / 2 + ')');

        //Setup track
        var track = g.append('g');
        track.append('path')
          .attr('class', 'd3__background')
          .attr('fill', colours.track)
          .attr('stroke', colours.stroke)
          .attr('stroke-width', strokeSpacing + 'px')
          .attr('d', circle.endAngle(endAngle));

        //Add colour fill
        var value = track.append('path')
          .attr('class', 'd3__value')
          .attr('fill', colours.fill)
          .attr('stroke', colours.stroke)
          .attr('stroke-width', strokeSpacing + 'px');

        //Add text value
        var numberText = track.append('text')
          .attr('class', 'd3__text')
          .attr('fill', colours.text)
          .attr('text-anchor', 'middle')
          .attr('dy', '1rem');

        function update(progress) {
          //update position of endAngle
          value.attr('d', circle.endAngle(endAngle * progress));
          //update text value
          numberText.text(formatText(progress));
        }

        // Init animation
        (function iterate() {
          update(progress);
          if (count > 0) {
            count--;
            progress += step;
            setTimeout(iterate, 10);
          }
        })();
      })
    }
  };

  /**
   * Attaches the table seconday income behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.tableSecondaryIncome = {
    attach: function (context) {
      $('.table--secondary-income', context).once('tableSecondaryIncome', function () {
        $('.table--secondary-income').stupidtable();
      });
    }
  };

  /**
   * Attaches the D3 stacked horizontal bar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3BarHorizontalStacked = {
    attach: function (context) {
      $('[data-bar-horizontal-stacked]', context).once('d3BarHorizontalStacked', function () {
        var wrapper = $(this)[0];
        var barWrapper = d3.select(wrapper)
          .append('div')
          .attr('class', 'd3-bars');

        d3.json(wrapper.dataset.url, function (error, response) {
          var data = Drupal.parseResultsTotal(response.facets['field_vote']);
          var totalPollCount = d3.sum(data, function (d) {
            return d.count;
          });
          var totalLabelBefore = wrapper.dataset.labelTotalBefore;
          var totalLabelAfter = wrapper.dataset.labelTotalAfter;

          barWrapper.selectAll('div')
            .data(data)
            .enter().append('a')
            .attr('class', 'd3-bars__item')
            .attr('style', function (d) {
              var value = 100 / totalPollCount * d.count;
              return 'width:' + value + '%; background-color:' + d.color + ';';
            })
            .attr('href', function (o) {
              if (o.count > 0) {
                return window.location.pathname + encodeURI('?field_vote[' + o.vote_id + ']=' + o.vote_id + '#block-pw-vote-poll');
              } else {
                return null;
              }
            });

          // Define Total-Label
          var totalLabelWrapper = d3.select(wrapper)
            .append('p')
            .attr('class', 'd3__total-label')
            .html(function (d) {
              return totalLabelBefore + ' ' + totalPollCount + ' ' + totalLabelAfter;
            });

          // Define Labels
          var labelWrapper = d3.select(wrapper)
            .append('ul')
            .attr('class', 'd3__label d3__label--inline');

          var labelItem = labelWrapper.selectAll('li')
            .data(data)
            .enter()
            .append('li')
            .attr('class', 'd3__label__item')
            .append('a')
            .attr('href', function (o) {
              if (o.count > 0) {
                return window.location.pathname + encodeURI('?field_vote[' + o.vote_id + ']=' + o.vote_id + '#block-pw-vote-poll');
              } else {
                return null;
              }
            })
            .html(function (o) {
              return o.count + ' ' + o.name;
            })
            .insert('span', ':first-child')
            .attr('class', 'd3__label__item__indicator')
            .attr('style', function (d) {
              return 'background-color:' + d.color;
            });

        });
      });
    }
  };

  /**
   * Attaches the D3 stacked vertical poll behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.d3BarVerticalStackedPoll = {
    attach: function (context) {
      $('[data-bar-vertical-stacked-poll]', context).once('d3BarVerticalStackedPoll', function () {
        var wrapper = $(this)[0];

        d3.json(wrapper.dataset.url, function (error, response) {
          var data = Drupal.parseResultsByFaction(response.records);
          for (var key in data) {

            var obj = data[key];
            var totalPollCount = d3.sum(obj, function (o) {
              return o.count;
            });

            var chartwrapper = d3.select(wrapper)
              .append('div')
              .attr('class', 'd3-chart');

            var barWrapper = chartwrapper
              .append('div')
              .attr('class', 'd3-bars')
              .selectAll('div')
              .data(obj)
              .enter()
              .append('a')
              .attr('class', 'd3-bars__item')
              .attr('style', function (d) {
                var value = 100 / totalPollCount * d.count;
                return 'height:' + value + '%; background-color:' + d.color + ';';
              })
              .attr('href', function (o) {
                if (o.count > 0) {
                  return window.location.pathname + encodeURI('?political_faction[' + key + ']=' + key + '&field_vote[' + o.vote_id + ']=' + o.vote_id + '#block-pw-vote-poll');
                } else {
                  return null;
                }
              });

            // Define Labels
            var labelWrapper = chartwrapper
              .append('div')
              .attr('class', 'd3__label_outer')
              .html('<h3>' + key + ' <span>' + Drupal.formatPlural(totalPollCount, '1 deputy', '@count deputies') + '</span></h3>')
              .append('ul')
              .attr('class', 'd3__label');

            var labelItem = labelWrapper.selectAll('li')
              .data(obj)
              .enter()
              .append('li')
              .attr('class', 'd3__label__item')
              .append('a')
              .attr('href', function (o) {
                if (o.count > 0) {
                  return window.location.pathname + encodeURI('?political_faction[' + key + ']=' + key + '&field_vote[' + o.vote_id + ']=' + o.vote_id + '#block-pw-vote-poll');
                } else {
                  return null;
                }
              })
              .html(function (o) {
                return o.count + ' ' + o.name;
              })
              .insert('span', ':first-child')
              .attr('class', 'd3__label__item__indicator')
              .attr('style', function (o) {
                return 'background-color:' + o.color;
              });
          }
        });
      });
    }
  };

  /**
   * Attaches the poll timeline behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.pollTimeline = {
    attach: function (context) {
      $('.poll__timeline', context).once('pollTimeline', function () {
        var pollTimeline = $(this);
        var pollID = $('.poll.detail').attr('data-poll-id');
        var pollTimelineSlideItem = pollTimeline.find('.poll__timeline__item__poll[data-poll-id=' + pollID + ']');
        var pollTimelineSlide = pollTimelineSlideItem.parents('.poll__timeline__item');

        // Add Active class to timeline-item
        pollTimelineSlideItem.addClass('poll__timeline__item__poll--active');

        // Add Click-Behavior to timeline-items
        $('.poll__timeline__item__poll').click(function () {
          $('.poll__timeline__item__poll').removeClass('poll__timeline__item__poll--active');
          $(this).addClass('poll__timeline__item__poll--active');

          pollTimelineSwiper.update();
        });

        var pollTimelineSwiper = new Swiper(pollTimeline, {
          slideClass: 'poll__timeline__item',
          wrapperClass: 'poll__timeline__inner',
          speed: 400,
          initialSlide: pollTimelineSlide.index(),
          slidesPerView: 'auto',
          spaceBetween: 30,
          centeredSlides: true,
          nextButton: $('.poll__timeline .swiper-button-next'),
          prevButton: $('.poll__timeline .swiper-button-prev'),
        });
      });
    }
  };

  /**
   * Attaches the filterbar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.filterBar = {
    attach: function () {
      var $filterbar = $('.filterbar');
      var $filterBarSwiper = $('.filterbar__secondary');
      var $filterBarInner = $('.filterbar .filterbar__inner');
      var filterBarActive = false;

      function filterBarCreate() {
        var mySwiper = new Swiper('.filterbar__secondary', {
          freeMode: false,
          resistance: true,
          resistanceRatio: 0.5,
          slideClass: 'filterbar__item',
          wrapperClass: 'filterbar__secondary__inner',
          speed: 400,
          slidesPerView: 'auto',
          simulateTouch: true,
          nextButton: $filterBarSwiper.find('.swiper-button-next'),
          prevButton: $filterBarSwiper.find('.swiper-button-prev'),
          onInit: function (swiper) {
            filterBarSwiperSize();
            swiper.update();
            filterBarActive = true;
            $filterbar.removeClass('filterbar--expanded');
            $('body').removeClass('block-scrolling');
          },
          onDestroy: function (swiper) {
            $filterBarInner
              .css('padding-right', '')
              .css('padding-left', '');
            filterBarActive = false;
            filterBarWait();
          },
          onAfterResize: function (swiper) {
            if (windowWidth >= breakpointMMin) {
              filterBarSwiperSize();
              swiper.update();
            } else {
              swiper.destroy(false, true);
            }
          }
        });
      }

      function filterBarWait() {
        var windowResize = debounce(function () {
          windowWidth = window.innerWidth;

          if (windowWidth >= breakpointMMin && !filterBarActive) {
            filterBarCreate();
          }
        }, 150);

        // Event-Listener
        window.addEventListener('resize', windowResize);
      }

      function filterBarSwiperSize() {
        var filterBarOffsetRight = $('.filterbar__view_options').outerWidth();
        var filterBarOffsetLeft = $('.filterbar__primary').outerWidth();
        var filterBarOffsetRightValue = filterBarOffsetRight;
        var filterBarOffsetLeftValue = filterBarOffsetLeft;

        windowWidth = window.innerWidth;

        if (windowWidth >= breakpointMMin) {
          filterBarOffsetRightValue = filterBarOffsetRight + 20;
        }
        else if (windowWidth >= breakpointSMin) {
          filterBarOffsetRightValue = filterBarOffsetRight + 15;
        }
        else {
          filterBarOffsetRightValue = 0;
        }
        $filterBarInner
          .css('padding-right', filterBarOffsetRightValue + 'px')
          .css('padding-left', filterBarOffsetLeftValue + 'px');
      }

      if (windowWidth >= breakpointMMin) {
        filterBarCreate();
      } else {
        filterBarWait();
      }

      $('[data-filterbar-toggle], [data-filterbar-submit]').on('click', function (event) {
        $filterbar.toggleClass('filterbar--expanded');
        $('body').toggleClass('block-scrolling');
        event.preventDefault();
      });

      $('.filterbar__secondary .filterbar__item--dropdown .dropdown__trigger').on('click', function () {
        // var index = $(this).index();
        // mySwiper.slideTo(index, 300);
        $('.dropdown__list').removeClass('dropdown__list--open');
        if ($(this).hasClass('dropdown__trigger--active')) {
          $(this).parent('.filterbar__item--dropdown').find('.dropdown__list').addClass('dropdown__list--open');
        }
      });
    }
  };

  /**
   * Attaches the view-mode switch behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.viewModeSwitch = {
    attach: function (context) {
      var switchViewMode = function (hash) {
        if ($('.filterbar__view_options__item__link[href="' + hash + '"]').length > 0) {
          // Set nav-item classes
          $('.filterbar__view_options__item__link').parent('li').removeClass('active');
          $('.filterbar__view_options__item__link[href="' + hash + '"]').parents('li').addClass('active');

          // Toggle view mode visibility
          $('.view-mode').hide();
          $(hash).show();

          if ($(hash).hasClass('view-mode--has-filters')) {
            $('.filterbar').removeClass('filterbar--disabled');
          } else {
            $('.filterbar').addClass('filterbar--disabled');
          }
        }
      };

      $('.filterbar__view_options', context).once('view-mode', function () {
        $('.filterbar__view_options__item__link').on('click', function (event) {
          event.preventDefault();

          // add hash-value of the clicked link-element to url
          if (history.pushState) {
            history.pushState(this.hash, null, this.hash);
          }

          switchViewMode(this.hash);
        });

        if (history.pushState) {
          $(window).on('popstate', function (event) {
            switchViewMode(this.location.hash);
          });
        }

        if (window.location.hash) {
          $('.filterbar__view_options__item__link[href="' + window.location.hash + '"]').trigger('click');
        }
      });
    }
  };


  /**
   * Attaches the read more behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.readMore = {
    attach: function (context) {
      $('.readmore', context).once('readMore', function () {
        var readmoreHeight = $(this).outerHeight();

        if (readmoreHeight < 300) {
          $(this).addClass('readMore--expanded readMore--expanded-initial');
          $(this).find('.readmore__trigger').hide();
        }
        $('.readmore__trigger .readmore__trigger__more').click(function (event) {
          event.preventDefault();
          $(this).parents('.readmore').addClass('readMore--expanded');
        });
        $('.readmore__trigger .readmore__trigger__less').click(function (event) {
          event.preventDefault();
          $(this).parents('.readmore').removeClass('readMore--expanded');
        });
      });
    }
  };

  /**
   * Attaches the candidate check behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.candidateCheck = {
    attach: function (context) {
      $('.deputy__candidate_check .swiper-container', context).once('candidateCheck', function () {
        var candidateCheckSwiper = $(this).parents('.deputy__candidate_check');
        var mySwiper = new Swiper('.deputy__candidate_check .swiper-container', {
          speed: 400,
          slidesPerView: 1,
          autoHeight: 1,
          nextButton: candidateCheckSwiper.find('.swiper-button-next'),
          prevButton: candidateCheckSwiper.find('.swiper-button-prev'),
          pagination: candidateCheckSwiper.find('.swiper-pagination'),
          paginationType: 'fraction',
          paginationFractionRender: function (swiper, currentClassName, totalClassName) {
            return Drupal.t('Proposition') + ' <span class="' + currentClassName + '"></span> ' +
              Drupal.t('of') +
              ' <span class="' + totalClassName + '"></span>';
          }
        });
      });
    }
  };

  /**
   * Attaches the sidebar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.sidebar = {
    attach: function (context) {
      $('.sidebar__box__accordion__item__title', context).once('sidebar', function () {
        $(this).click(function () {
          $('.sidebar__box__accordion__item').removeClass('sidebar__box__accordion__item--open');
          $(this).parents('.sidebar__box__accordion__item').addClass('sidebar__box__accordion__item--open');
        });

        $(window).load(function () {
          if (windowWidth >= breakpointSMin) {
            // Init stickyKit
            if ($("body").hasClass("admin-menu")) {
              $(".sidebar").stick_in_parent({
                offset_top: 45,
                parent: '.sidebar-container'
              });
            } else {
              $(".sidebar").stick_in_parent({
                parent: '.sidebar-container'
              });
            }
          }
        });
      });
    }
  };

  /**
   * Attaches the footer behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.footer = {
    attach: function (context) {
      $('.footer__maincol__col', context).once('footer', function () {
        $(this).matchHeight();
      });
    }
  };

  /**
   * Attaches the landing page teaser behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.landingPageTeaser = {
    attach: function (context) {
      $('.lp-teaser__item', context).once('landingPageTeaser', function () {
        $(this).matchHeight();
      });
    }
  };

  /**
   * Attaches the match height behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.matchHeight = {
    attach: function (context) {
      $('.mh-item', context).matchHeight();
      $('.mh-item-nr', context).matchHeight({byRow: false});
      $.fn.matchHeight._applyDataApi();
    }
  };

  /**
   * Attaches the AJAX tracking behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.ajaxTracking = {
    attach: function (context, settings) {
      if (window.history && window.history.pushState && settings.url) {
        history.pushState({}, document.title, settings.url);
        _paq.push(['setCustomUrl', window.location.href]);
        _paq.push(['trackPageView']);
      }
    }
  };

  /**
   * Attaches the AJAX filterbar behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.ajaxFilterbar = {
    attach: function (context, settings) {
      $('.tile-wrapper').addClass('loading-overlay');
      hideIfEmpty();

      function loadResults($form) {
        var path = $form.attr('action');
        var search = $form.serialize();
        var target = $form.data('ajax-target');
        var url = path + '?' + search;
        var ajaxUrl = search ? url + '&ajax=' : '?ajax=';

        addLoadingAnimation($('.tile-wrapper'));

        $(target).load(ajaxUrl + ' ' + target + ' > *', function () {
          Drupal.attachBehaviors(target, {url: url});
          removeLoadingAnimation($('.tile-wrapper'));
          hideIfEmpty();
        });
      }

      function hideIfEmpty() {
        if (!$('.filterbar__secondary .filterbar__item').length) {
          $('.filterbar').addClass('filterbar--empty');
          $('.filterbar__trigger').hide();
        } else {
          $('.filterbar').removeClass('filterbar--empty');
          $('.filterbar__trigger').show();
        }
      }

      $('form[data-ajax-target] .form__item__control').change(function (event) {
        if ($(this).is('#edit-keys')) {
          window.location = '?keys=' + $(this).val();
        } else {
          if (!$(this).parents('.filterbar--expanded').length) {
            var dateInputs = $('#edit-date-0, #edit-date-1', $(this).parents('form'));
            if (this.id.startsWith('edit-date-') && dateInputs.length == 2) {
              if (dateInputs[0].value === '' || dateInputs[1].value === '') {
                return;
              }
            }
            loadResults($(this).parents('form'));
          } else {
            $('[data-filterbar-submit]').one('click', function (event) {
              loadResults($(this).parents('form'));
            });
          }
        }
      });

      $('a[data-ajax-target]').click(function (event) {
        event.preventDefault();
        addLoadingAnimation($('.tile-wrapper'));
        var target = $(this).data('ajax-target');
        var url = $(this).attr('href');
        var ajaxUrl = this.search ? url + '&ajax=' : '?ajax=';

        $(target).load(ajaxUrl + ' ' + target + ' > *', function () {
          Drupal.attachBehaviors(target, {url: url});
          removeLoadingAnimation($('.tile-wrapper'));
        });
      });
    }
  };

  /**
   * Attaches the AJAX block behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.ajaxBlock = {
    attach: function (context, settings) {
      $('[data-ajax-block-url]').each(function () {
        var container = this;
        $(container).addClass('loading-overlay')
        $('.pager a, .table--sortable th a', container).click(function (event) {
          event.preventDefault();
          var url = $(container).data('ajax-block-url') + this.search + '&path=' + this.pathname.substr(1);
          var target = '#' + $(container).attr('id');
          addLoadingAnimation($(target));
          $(container).load(url + ' ' + target + ' > *', function () {
            Drupal.attachBehaviors(target);
            removeLoadingAnimation($(target));
          });
        });
      });
    }
  };

  /**
   * Attaches the AJAX donation form behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.donationForm = {
    attach: function (context, settings) {
      $('.webform-component--fieldset-donationform-yourdonation--donation-frequency input[type=radio]').change(function() {
        var pw_interval = $('input:radio[name="submitted[fieldset_donationform_yourdonation][donation_frequency]"]:checked').val();
        var pw_amount_label = Drupal.t('Your donation amount');
        var $pw_amount_active = $('input[name*="donation_amount"]:checked');

        pw_interval = pw_interval == 0 ? 1 : pw_interval;

        $('#edit-submitted-fieldset-donationform-yourdonation-donation-amount-1 + label').text(pw_interval * 10 + ' €');
        $('#edit-submitted-fieldset-donationform-yourdonation-donation-amount-2 + label').text(pw_interval * 20 + ' €');
        $('#edit-submitted-fieldset-donationform-yourdonation-donation-amount-3 + label').text(pw_interval * 50 + ' €');
        $('#edit-submitted-fieldset-donationform-yourdonation-donation-amount-4 + label').text(pw_interval * 100 + ' €');

        switch (pw_interval) {
          case '1':
            pw_amount_label = Drupal.t('Your monthly donation amount');
            break;
          case '3':
            pw_amount_label = Drupal.t('Your quarterly donation amount');
            break;
          case '6':
            pw_amount_label = Drupal.t('Your half-yearly donation amount');
            break;
          case '12':
            pw_amount_label = Drupal.t('Your yearly donation amount');
            break;
        }

        $('label[for="edit-submitted-fieldset-donationform-yourdonation-donation-amount"]').contents().filter(function(){
          return (this.nodeType == 3);
        }).replaceWith(pw_amount_label + ' ');

        if ($pw_amount_active.length > 0 && $pw_amount_active.val() !== 'free') {
          $pw_amount_active.get(0).checked = false;
        }
      });

      $('.webform-component--fieldset-donationform-yourdonation--donation-amount input[type=radio]').change(function() {
        $('.form__item--submitted-fieldset-donationform-yourdonation-donation-free-amount').find('input').val('');
      });
    }
  };

  /**
   * Attaches lightbox behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.lightbox = {
    attach: function () {
      $(function() {
        lightbox.option({
          'resizeDuration': 400,
          'imageFadeDuration': 400,
          'fadeDuration': 400,
          'albumLabel': 'Bild %1 von %2',
          'alwaysShowNavOnTouchDevices': true
        });
      });
    }
  };

  /**
   * Attaches modal behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.modal = {
    attach: function () {
      $(function() {

        if (!$.cookie('clickCount')) {
          $.cookie('clickCount', 1, { path: '/' });
          var clickCount = parseInt($.cookie('clickCount'), 10);
          clickCount++;
        } else {
          var clickCount = parseInt($.cookie('clickCount'), 10);
          clickCount++;
          $.cookie('clickCount', clickCount, { path: '/' });
        }

        $('[data-modal-close]').click(function (event) {
          var attr = $(this).parents('.modal').attr('data-modal-cookie');
          var cookieExpires = $(this).parents('.modal').attr('data-modal-cookie-expires');
          $('.modal__close').parents('.modal').removeClass('modal--open');
          $('body').removeClass('block-scrolling');

          if (typeof attr !== typeof undefined && attr !== false) {
            var cookieName = $(this).parents('.modal').attr('data-modal-name');
            $.cookie(cookieName, '1', {expires: 7, path: '/'});
          }
          event.preventDefault();
        });

        $('.modal-overlay').click(function () {
          var modalName = $(this).attr('data-modal-name');
          var modal = $('.modal[data-modal-name=' + modalName + ']');
          var attr = modal.attr('data-modal-cookie');
          modal.removeClass('modal--open');
          $('body').removeClass('block-scrolling');
          if (typeof attr !== typeof undefined && attr !== false) {
            var cookieName = modalName;
            $.cookie(cookieName, '1', {expires: 7, path: '/'});
          }
        });

        // Control inital modals
        if ($('[data-modal-initial]').length) {
          $('[data-modal-initial]').each(function (index) {
            var cookieName = $(this).attr('data-modal-name');
            var clicksToShow = $(this).attr('data-modal-clicksToShow');
            if (!$.cookie(cookieName) == '1' && clickCount >= clicksToShow) {
              $('[data-modal-initial]').addClass('modal--open');
              $('body').addClass('block-scrolling');
            }
          });
        }
      });
    }
  };

  /**
   * Attaches votes table behavior.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.votesTable = {
    attach: function (context, settings) {
      if (settings.pw_vote && settings.pw_vote.node) {
        $('.poll__table').addClass('loading-overlay');

        var url = '/votes/' + settings.pw_vote.node;
        var search = window.location.search;

        $.ajax(url + search).done(function (data) {
          $('.table--poll-votes').bind('dynatable:init', function (event, dynatable) {
            var PaginationLinks = Drupal.dynatable.PaginationLinks(dynatable, dynatable.settings);
            dynatable.paginationLinks.create = PaginationLinks.create;
            dynatable.paginationLinks.buildLink = PaginationLinks.buildLink;
            var Sorts = Drupal.dynatable.Sorts(dynatable, dynatable.settings);
            dynatable.sorts.functions.string = Sorts.functions.string;
            if (Object.values(dynatable.settings.dataset.sorts).length == 0) {
              dynatable.sorts.add('field_vote', 1);
            }
            var SortsHeaders = Drupal.dynatable.SortsHeaders(dynatable, dynatable.settings);
            dynatable.sortsHeaders.appendArrowUp = SortsHeaders.appendArrowUp;
            dynatable.sortsHeaders.appendArrowDown = SortsHeaders.appendArrowDown;
            dynatable.sortsHeaders.toggleSort = SortsHeaders.toggleSort;

            // sorting on mobile devices

            $('#poll_detail_table_sorting').on('select2:select', function (e) {
              var selectValue = $(this).find(':selected').data('sort-value');
              var selectSortOrder = $(this).find(':selected').data('sort-order');

              dynatable.sorts.clear();
              dynatable.sorts.add(selectValue, selectSortOrder);
              dynatable.process();
            });

          }).dynatable({
            features: {
              perPageSelect: false,
              pushState: false,
              recordCount: false,
              search: false,
            },
            dataset: {
              perPageDefault: 10,
              records: data.records
            },
            inputs: {
              paginationClass: 'pager',
              paginationLinkClass: 'pager__item',
              paginationFirstClass: 'pager__item--first',
              paginationPrevClass: 'pager__item--previous',
              paginationNextClass: 'pager__item--next',
              paginationLastClass: 'pager__item--last',
              paginationActiveClass: 'pager__item--current',
              paginationDisabledClass: 'pager__item--disabled',
              paginationPrev: Drupal.t('previous'),
              paginationNext: Drupal.t('next'),
              paginationGap: [1, 2, 2, 1],
            }
          })
        });

        // Sync mobile sorting-select with table-view
        $('.table--poll-votes').bind('dynatable:afterProcess', function (event, dynatable) {
          var sortValue = String([Object.keys(dynatable.sorts)[0]]);
          var sortOrderInitial = dynatable.sorts[Object.keys(dynatable.sorts)[0]];
          var sortOrderAfter = '';
          if (sortOrderInitial == '-1') {
            sortOrderAfter = '_dsc';
          } else {
            sortOrderAfter = '_asc';
          }
          var newSortValue = sortValue + sortOrderAfter;
          if (windowWidth >= 768) {
            $('select#poll_detail_table_sorting').val(newSortValue);
            $('select#poll_detail_table_sorting').trigger('change.select2');
          }
        });

        $('.form--pw-vote-poll-filters .form__item__control').change(function (event) {
          var target = this.form;

          if ($(this).is('#edit-keys')) {
            window.location = '?keys=' + $(this).val() + window.location.hash;
          } else {
            if (!$(this).parents('.filterbar--expanded').length) {
              $(target).submit();
            } else {
              $('[data-filterbar-submit]').one('click', function (event) {
                $(target).submit();
              });
            }
          }
        });

        $('.form--pw-vote-poll-filters').submit(function (event) {
          addLoadingAnimation($('.poll__table'));

          search = '?' + $(this).serialize();

          $.ajax(url + search).done(function (data) {
            var dynatable = $('.table--poll-votes').data('dynatable');
            dynatable.records.updateFromJson(data);
            dynatable.records.init();
            dynatable.paginationPage.set(1);
            dynatable.process();

            if (window.history.pushState) {
              history.pushState({}, document.title, search + window.location.hash);
            }

            $('.filterbar__item--dropdown').each(function () {
              var countActive = $(this).find('input:checked').length;
              var $countBadge = $(this).find('.dropdown__trigger .badge');

              if (countActive > 0) {
                if ($countBadge.length) {
                  $countBadge.text(countActive);
                } else {
                  $(this).find('.dropdown__trigger .icon').before('<span class="badge">' + countActive + '</span>');
                }
              } else {
                $countBadge.remove();
              }

              $(this).removeClass('dropdown--open');
            });

            removeLoadingAnimation($('.poll__table'));
          });

          event.preventDefault();
        });
      }
    }
  }

  /**
   * Attaches behavior preventing multiple form submissions.
   *
   * @type {Drupal~behavior}
   *
   * @prop {Drupal~attachBehavior}
   */
  Drupal.behaviors.preventMultiPost = {
    attach: function (context) {
      $('form', context).once('preventMultiPost', function () {
        var $form = $(this);
        $form.submit(function (event) {
          $('[type="submit"]', $form).prop('disabled', true);
        });
      })
    }
  }

}(jQuery));
