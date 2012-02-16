<?php
$fileCount = 10;
$sample = file_get_contents('sample.html');

foreach (range(0, $fileCount) as $number) {
	$fileName = sprintf("%02d", $number) . '.html';
	$docNumber = sprintf("%04d", $number);
	
	$content = str_replace("0000", $docNumber, $sample);
	
	file_put_contents($fileName, $content);
}

?>