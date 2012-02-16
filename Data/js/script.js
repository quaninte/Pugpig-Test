Doc = {
	file: null,
	filePrefix: 'images/img-',
	
	init: function(file) {
		Doc.file = Doc.filePrefix + file + '.jpg';
		Doc.process();
	},
	
	process: function() {
		var img = $('<img>');
		img.attr('src', Doc.file);
		img.attr('width', 688).attr('height', 944);
		
		$('body .back').append(img);
	},
	
	resize: function() {
		$('body img').attr('width', $(window).width()).attr('height', $(window).height());
	}
}

$(document).ready(function() {
	Doc.init(docNumber);
	Doc.resize();
	
	$(window).resize(function() {
		Doc.resize();
	});
});