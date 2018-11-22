/**
 * Define the behavior related to the PW Embed Media widget
 */
(function ($) {
    // initialize the widget handling on click on the embed media widget slider
    Drupal.behaviors.pw_embed_media = {
        attach: function (context, settings) {
            $(".js-embed-media .js-embed-media-slider").click(function() {

                var container = $(this).parents('.js-embed-media');
                toggleEmbedMedia(container);
            });
        }
    };

    function toggleEmbedMedia (embedMediaContainer) {
        var embedMediaMarkup = $(getEmbedMediaMarkup(embedMediaContainer));
        console.log(embedMediaContainer);
        console.log(embedMediaMarkup);
        setTimeout(function () {
            embedMediaContainer.append(embedMediaMarkup);
        }, 500);
    }


    var getEmbedMediaMarkup = function(embedMediaContainer) {
        var controlCheckbox = embedMediaContainer.find('.js-embed-media-control'),
            mediaWidgetId = controlCheckbox.attr('id');
        return Drupal.settings.pw_embed_media.widgets[mediaWidgetId];
    };
})(jQuery);
