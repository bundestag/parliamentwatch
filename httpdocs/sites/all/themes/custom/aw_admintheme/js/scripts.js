/**
 * Add function for preventing multiple form submissions
 */

jQuery.fn.preventMultiPost = function() {
    jQuery(this).on('submit',function(e){
        var $form = jQuery(this);

        if ($form.data('submitted') === true) {
            e.preventDefault();
        } else {
            $form.find('#edit-submit').addClass('form-submit--loading');
            $form.data('submitted', true);
        }
    });
    return this;
};

jQuery(document).ready(function() {
    // Trigger preventMultiPost() for user edit-formular
    jQuery('#user-profile-form').preventMultiPost();
});