<?php

/**
 * @file
 * Contains template file.
 */
?>
<abbr<?php print $atomium['attributes']['wrapper']->append('class', 'form-required')->append('title', t('This field is required.')); ?>>
  <?php print render($title); ?>
</abbr>
