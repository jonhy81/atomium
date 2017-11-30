<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_page_components(&$variables) {
  $settings = $variables['settings'];
  $child_delta = $variables['child_delta'];
  $variables += array(
    'action_links' => NULL,
    'tabs' => NULL,
    'messages' => NULL,
    'title' => NULL,
  );

  if ($child_delta == 'title' || $child_delta == 'title_combo') {
    $variables['title'] = $settings['title'];
    $variables['title_tag'] = $settings['title_tag'];
    $variables['title_classes'] = $settings['title_classes'];
    $variables['title_attributes'] = array(
      'class' => array_filter(explode(' ', $settings['title_classes'])),
    );
  }

  if ($child_delta == 'tabs' || $child_delta == 'title_combo') {
    $menus = array();
    switch ($settings['tab_type']) {
      case 'primary':
        $menus = array(
          'primary' => menu_primary_local_tasks(),
        );
        break;

      case 'secondary':
        $menus = array(
          'secondary' => menu_secondary_local_tasks(),
        );
        break;

      case 'both':
        $menus = array(
          'primary' => menu_primary_local_tasks(),
          'secondary' => menu_secondary_local_tasks(),
        );
        break;
    }

    if ($settings['tab_type'] == 'hidden') {
      $variables['tabs'] = '';
    }
    else {
      $variables['tabs'] = array(
        '#theme' => _atomium_extend_theme_hook('menu_local_tasks', $variables['theme_hook_original']),
      ) + $menus;
    }
  }
  if ($child_delta == 'action_links' || $child_delta == 'title_combo') {
    $variables['action_links'] = menu_local_actions();
  }

  if ($child_delta == 'messages' || $child_delta == 'title_combo') {
    $variables['messages'] = array(
      '#theme' => _atomium_extend_theme_hook('status_message', $variables['theme_hook_original']),
    );
  }

  // Add specific suggestions that can override the default implementation.
  $variables['theme_hook_suggestions'] = array(
    'page_components__' . $child_delta,
  );
}
