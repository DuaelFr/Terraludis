// JavaScript Document
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