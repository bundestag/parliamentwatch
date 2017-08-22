$(document).ready( function(){
  var pymChild = new pym.Child({id: 'awpym', polling: 1000});
  var questionButton = $('a[href="#question-form"]');
  if (questionButton) {
    questionButton.click(function(event){
      pymChild.scrollParentToChildEl('question-form');
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
});