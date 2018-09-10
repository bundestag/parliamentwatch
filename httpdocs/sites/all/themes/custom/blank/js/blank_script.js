(function ($) {
  $(document).ready( function(){
    var pymChild = new pym.Child({id: 'awpym', polling: 1000});
    var questionButton = $('a[href="#question-form-anchor"]');
    if (questionButton) {
      pymChild.scrollParentToChildEl("main-content");
      questionButton.click(function(event){
        event.preventDefault();
        pymChild.scrollParentToChildEl("question-form-anchor");
      });
    }
    var searchForm = $("form[action*='bundestag/profile']");
    if (searchForm) {
      searchForm.submit(function(event){
        pymChild.sendMessage('awSearchSubmit', searchForm.serialize());
      });
    }
    // account for async height change caused by twitter widget
    if (typeof(twttr) !== 'undefined'){
      twttr.ready(
        function(twttr){
          twttr.events.bind(
            'loaded',
            function(event){
              pymChild.sendHeight();
            }
          );
        }
      );
    }
    window.parent.postMessage({
      sentinel: 'amp',
      type: 'embed-size',
      height: document.body.scrollHeight
    }, '*');
  }());
}(jQuery));
