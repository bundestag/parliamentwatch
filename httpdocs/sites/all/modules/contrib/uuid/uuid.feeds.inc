<?php
/**
 * @file
 * Feeds mapper for UUID module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function uuid_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  $info = entity_get_info($entity_type);
  if (isset($info['uuid']) && $info['uuid'] == TRUE && !empty($info['entity keys']['uuid'])) {
    $uuid_key = $info['entity keys']['uuid'];
    $targets['uuid:' . $uuid_key] = array(
      'name' => 'UUID',
      'callback' => 'uuid_feeds_set_target',
      'description' => t('The UUID property of the @type.', array('@type' => $info['label'])),
    );
  }
}

/**
 * Callback for UUID mapping.
 */
function uuid_feeds_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Only one value makes sense here, use the first one.
  if (is_array($value)) {
    $value = reset($value);
  }

  list( , $uuid_key) = explode(':', $target);
  if (uuid_is_valid($value)) {
    $entity->{$uuid_key} = $value;
  }
}
