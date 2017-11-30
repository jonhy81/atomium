<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_layout(&$variables, $hook) {
  // Check if any Title Component blocks have been placed. These will override
  // the variables here.
  $block_exists = _layout_page_component_blocks_exist($variables);

  if (!$variables['admin']) {
    // Generate messages last in order to capture as many as possible for the
    // current page.
    if (!isset($variables['messages']) && !$block_exists['messages']) {
      $variables['messages'] = array('#theme' => array('status_messages'));
    }

    if (!$variables['admin']) {
      if (!$block_exists['action_links']) {
        $links = menu_local_tasks();

        $variables['action_links'] = array(
          '#theme' => _atomium_extend_theme_hook('menu_local_actions', $variables['theme_hook_original']),
          'actions' => $links['actions']['output'],
        );
      }
      if (!$block_exists['tabs']) {
        $variables['tabs'] = array(
          '#theme' => _atomium_extend_theme_hook('menu_local_tasks', $variables['theme_hook_original']),
          '#primary' => menu_primary_local_tasks(),
          '#secondary' => menu_secondary_local_tasks(),
        );
      }
    }
  }
}
