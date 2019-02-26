<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_admin_index() {
  return array(
    'admin_page' => array(
      'template' => 'admin-page',
      'variables' => array('blocks' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_admin_index(array &$variables, $hook) {
  $variables['toggle_link'] = array(
    '#theme' => _atomium_extend_theme_hook(
      'system_compact_link',
      $variables['theme_hook_original']
    ),
  );

  $container = array('left' => array(), 'right' => array());
  $flip = array('left' => 'right', 'right' => 'left');
  $position = 'right';

  // Iterate over all modules.
  foreach ($variables['menu_items'] as $module => $block) {
    list($description, $items) = $block;

    // Output links.
    if (0 === \count($items)) {
      continue;
    }

    $position = $flip[$position];

    // Output links.
    $block = array(
      'title' => $module,
      'content' => array(
        '#theme' => _atomium_extend_theme_hook(
          'admin_block_content',
          $variables['theme_hook_original']
        ),
        '#content' => $items,
      ),
      'description' => t('@description', array('@description' => $description)),
      'show' => TRUE,
      'position' => $flip[$position],
    );

    $container[$position][] = array(
      '#theme' => _atomium_extend_theme_hook(
        'admin_block',
        $variables['theme_hook_original']
      ),
      '#block' => $block,
    );
  }

  $variables['container'] = $container;
}
