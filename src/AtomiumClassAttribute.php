<?php

namespace Drupal\atomium;

use drupol\htmltag\Attribute\Attribute;

/**
 * Class AtomiumClassAttribute.
 */
class AtomiumClassAttribute extends Attribute {

  /**
   * {@inheritdoc}
   */
  public function preprocess(array $values, $name = NULL) {
    // Trim values.
    $values = \array_map('trim', $values);

    // Remove duplicated values.
    $values = \array_unique($values);

    // Sort values.
    \natcasesort($values);

    return parent::preprocess($values, $name);
  }

}
