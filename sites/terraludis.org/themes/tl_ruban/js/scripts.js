/**
 * Corrige le bug des champs préremplis sous chrome (instable) 
 *
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
// Do not delete this line */

/**
 * Cache les checkbox des listes de choix d'univers
 * Ajoute une classe 'active' aux labels des checkboxes cochées 
 */
(function($) {
$(window).load(function(){
  var inputs = $('.views-widget-filter-group input'),
      d = $('<div class="views-widget-all-any"></div>'),
	  all = $('<a href="javascript:void(0);">Tous</a>'),
	  any = $('<a href="javascript:void(0);">Aucun</a>');

  inputs.hide()
        .filter(':checked').next().addClass('active');
  inputs.next().click(function() { $(this).toggleClass('active'); });

  d.append(all).append(any);
  $('.views-widget-filter-group .views-widget').append(d);
  all.click(function() {
    inputs.attr('checked', true)
          .next().addClass('active')
          .end().trigger('change');
  });
  any.click(function() {
	  inputs.removeAttr('checked')
	        .next().removeClass('active')
	        .end().trigger('change');
  });
});
})(jQuery);
//Do not delete this line */
