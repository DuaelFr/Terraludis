<?php
/**
 * @file
 * uuid_node hooks on behalf of the taxonomy module.
 */

/**
 * Implements hook_uuid_node_features_export_render().
 */
function taxonomy_uuid_node_features_export_alter(&$export, &$pipe, $node) {
  if (!empty($node->taxonomy)) {
    foreach ($node->taxonomy as $term) {
      $vocabulary = taxonomy_vocabulary_load($term->vid);
      $voc_uuid = $vocabulary->machine_name;
      $pipe['uuid_vocabulary'][$voc_uuid] = $voc_uuid;

      $term_uuid = $term->uuid;
      $pipe['uuid_term'][$term_uuid] = $term_uuid;
    }
  }
}

/**
 * Implements hook_uuid_node_features_export_render_alter().
 */
function taxonomy_uuid_node_features_export_render_alter(&$export, &$node, $module) {
  if (!empty($node->taxonomy)) {
    $export->uuid_term = array();
    foreach ($node->taxonomy as $term) {
      $export->uuid_term[] = $term->uuid;
    }
  }
}

/**
 * Implements hook_uuid_node_features_rebuild_alter().
 * Build a taxonomy array suitable for node_save() from the uuid_term array.
 */
function taxonomy_uuid_node_features_rebuild_alter(&$node, $module) {
  if (!empty($node->uuid_term)) {
    $node->taxonomy = array();
    $tids = entity_get_id_by_uuid('taxonomy_term', $node->uuid_term);
    foreach ($node->uuid_term as $uuid) {
      if (empty($tids[$uuid])) {
        // If no tid was found, then the term doesn't exist, and most likely
        // the uuid_term rebuild needs to run first.
        // TODO: figure out how to weight feature components.
        uuid_term_features_rebuild($module);

        // Now try again.
        $tid = uuid_taxonomy_term_find($uuid);
        if (empty($tid)) {
          watchdog('uuid_features', 'The term specified by %uuid could not be found.', array('%uuid' => $uuid));
          continue;
        }
      } else {
        $tid = $tids[$uuid];
      }

      $node->taxonomy[] = $tid;
    }
  }
}