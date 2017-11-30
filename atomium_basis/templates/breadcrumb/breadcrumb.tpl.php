<?php

/**
 * @file
 * Contains template file.
 */
?>
<nav<?php print $atomium['attributes']['wrapper']->append('role', 'navigation')->append('class', 'breadcrumb'); ?>>
  <h2 class="element-invisible"><?php print t('You are here'); ?></h2>
  <?php print render($breadcrumb); ?>
</nav>
