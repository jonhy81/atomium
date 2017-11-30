<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($enabled): ?>
  <input id="<?php print $id; ?>" class="menu-toggle-state element-invisible" type="checkbox" aria-controls="<?php print $id; ?>" />
  <label class="menu-toggle-button" for="<?php print $id; ?>">
    <span class="menu-toggle-button-icon"></span>
    <span class="menu-toggle-button-text"><?php print $text; ?></span>
    <span class="menu-toggle-assistive-text element-invisible"><?php print t('Toggle menu visibility'); ?></span>
  </label>
<?php endif; ?>
