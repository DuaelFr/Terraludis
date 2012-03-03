/*
(function($) {
$(window).load(function(){
  $('input:-webkit-autofill').each(function(){
    var text = $(this).val();
    var name = $(this).attr('name');
    $(this).after(this.outerHTML).remove();
    $('input[name=' + name + ']').val(text);
  });
});
})(jQuery);
*/

/**
 * Cache les checkbox des listes de choix d'univers
 * Ajoute une classe 'active' aux labels des checkboxes cochées 
 */
(function($) {
$(window).load(function(){
  $('.views-widget-filter-group input').hide()
  .filter(':checked').next().addClass('active');
});
})(jQuery);