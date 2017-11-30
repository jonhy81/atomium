<?php

/**
 * @file
 * Contains template file.
 */
?>
<!DOCTYPE html>
<html<?php print $atomium['attributes']['html']; ?>>
<head>
  <?php print backdrop_get_html_head(); ?>
  <title><?php print $head_title; ?></title>
  <?php print backdrop_get_css(); ?>
  <?php print backdrop_get_js(); ?>
</head>
<body<?php print $atomium['attributes']['body']; ?>>
<?php print $page; ?>
<?php print $page_bottom; ?>
<?php print backdrop_get_js('footer'); ?>
</body>
</html>
